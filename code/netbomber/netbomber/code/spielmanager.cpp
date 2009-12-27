/***************************************************************************
                          spielmanager.cpp  -  description
                             -------------------
    begin                : Mon May 27 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "spielmanager.h"
#include "../global.h"

#include "guitopdinterface.h"
#include "../ui/pdtoguiinterface.h"
#include "pdkontroller.h"
#include "../network/clientinterface.h"
#include "../network/serverinterface.h"

#include "spiel.h"
#include "serverthread.h"
#include "clientthread.h"

#include <assert.h>
#include <qthread.h>
#include <unistd.h>

#include <qtimer.h>
#include "../network/client.h"

//-- Constructor
SpielManager::SpielManager()
{

  pdMutex = new QMutex(true);                                // synchronisation objects
  serverMutex = new QMutex(false);
  clientMutex = new QMutex(false);
  serverThread = NULL;                                       // network listening threads
  clientThread = NULL;

  guiOutputInterface = PDToGUIInterface::instance();       // interfaces
  guiInputInterface = GUIToPDInterface::getInterface();
  guiInputInterface->setManager(this, pdMutex);
  netInputInterface = PDKontroller::getKontroller();
  netInputInterface->setManager(this, pdMutex);
  netOutClientInterface = ClientInterface::getClientInterface();
  netOutServerInterface = ServerInterface::getServerInterface();

  serverGame = false;
  game = NULL;

  connected = false;                                         // clear player attributes
  for (int i=0; i < MAX_PLAYERS; i++)
  {
    playerConnected[i] = false;
    playerName[i] = "";
    playerReady[i] = 0;
  }

}

//-- Destructor
SpielManager::~SpielManager()
{
  pdMutex->lock();

  killNetworkClient();                         // destroy network listening threads
  killNetworkServer();
  endGame();                                   // destroy game environment
  pdMutex->unlock();


  guiInputInterface->setManager(NULL);         // unregister interfaces
  netInputInterface->setManager(NULL);

  delete pdMutex;                              // destroy synchronisation objects
  delete serverMutex;
  delete clientMutex;
}


// **** Gamehandling functions ****

//-- creates new server game
void SpielManager::startServer(string playerName)
{
  if(serverGame) return;

  serverGame = true;

  createNetworkServer();                                     // start network listening threads
  createNetworkClient();

  netOutServerInterface = ServerInterface::getServerInterface();
  sleep(1);
  cout << "Spielmanager::startServer() : connect(" << playerName << ", " << LOCALHOST << ")" << endl;
  netOutClientInterface->connect(playerName, LOCALHOST);     // connect as client to local server
  netOutClientInterface->sendAll();

}

//-- creates new client game
void SpielManager::joinServer(string ipAdress, string playerName)
{
  if(serverGame) return;

  serverGame = false;

  createNetworkClient();                                         // start network listening thread

  netOutClientInterface->connect(playerName, ipAdress.data());   // connect to remote server
  netOutClientInterface->sendAll();
}

//-- start the game
void SpielManager::startGame()
{
  if(!serverGame) return;


  for ( int i=0; i < MAX_PLAYERS; i++)
  {
    playerReady[i] = 0;
  }
  cout << "SpielManager::StartGame()" << endl;
  cout << "send run()...";
  netOutServerInterface->run();
  netOutServerInterface->sendAll();
  cout << "done." << endl;
}

//-- ends the game
void SpielManager::endGame()
{
  guiOutputInterface->endGame();
  if (game != NULL)
  {
    delete game;
    game = NULL;
  }
}

//-- ends the game (at any time)
void SpielManager::killGame()
{
  if ( serverGame )
  {
    serverGame = false;                     // destroy server
    cout << "send endGame()...";
    netOutServerInterface->endGame();       // send endGame to clients
    netOutServerInterface->disconnect();
    netOutServerInterface->sendAll();
    cout << "done." << endl;


    killNetworkClient();                    // destroy network listening threads
    killNetworkServer();
  }
  else                                      // destroy client
  {
    netOutClientInterface->disconnect();    // disconnect from server
    killNetworkClient();                    // destroy network listening thread
  }

  if (game != NULL)
  {
    endGame();                              // destroy game environment
  }


  for (int i=0; i < MAX_PLAYERS; i++)       // clear player attributes
  {
    playerConnected[i] = false;
    playerName[i] = "";
    playerReady[i] = 0;
  }
}

//-- recieve a errormessage
void SpielManager::errorMsg(int msgNumber, string addInfo)
{
  cout << "SpielManager::errorMsg(" << msgNumber << ", " << addInfo << ")" << endl;
}


// **** Server functions ****

//-- add new player to the game
void SpielManager::newPlayer(int playerID, string name)
{
  if(!serverGame) return;

  playerConnected[playerID] = true;                          // add new player to playerlist
  playerName[playerID] = name;
  guiOutputInterface->newPlayer(playerID+1, name.data());
  for( int id = 0; id < MAX_PLAYERS; id++ )
  {
    netOutServerInterface->setPlayerName(id+1, playerName[id]);    // send playerlist to clients
  }
  netOutServerInterface->sendAll();
}

//-- indicates that player is ready to play
void SpielManager::ready(int playerID)
{
  if(!serverGame) return;

  playerReady[playerID]++;

  bool allSetUp = true;
  bool allReady = true;

  for ( int i=0; i < MAX_PLAYERS; i++)
  {
    if ( (playerConnected[i] == true) && (playerReady[i] != 1) )
    {
      allSetUp = false;
    }
  }
  if ( allSetUp )                                  // ready to recieve playfield
  {
    cout << "Initialize PD-Server..." << endl;
    game->initServer(playerConnected, playerName);
    cout << "PD-Server initialized." << endl;
    cout << "send run()...";
    netOutServerInterface->run();
    netOutServerInterface->sendAll();
    cout << "done." << endl;
    return;
  }


  for ( int i=0; i < MAX_PLAYERS; i++)
  {
    if ( (playerConnected[i] == true) && (playerReady[i] != 2) )
    {
      allReady = false;
    }
  }

  if ( allReady )                                  // ready to play
  {
    game->run();
  }
}

//-- remove player from the game
void SpielManager::removePlayer(int playerID)
{

  if(!serverGame) return;

  if (game != NULL)                                        // if game running...
  {
    game->killPlayer(playerID);                            // kill the player
  }
  string msg = playerName[playerID];
  msg += " has disconnected.";
  playerConnected[playerID] = false;                       // remove player from playerlist
  playerName[playerID]      = "";
  //guiOutputInterface->removePlayer(playerID+1);    <------------------------
  cout << "send setPlayerName()...";
  netOutServerInterface->setPlayerName(playerID+1, "");    // send changes to clients
  netOutServerInterface->sendMsg(msg);
  netOutServerInterface->sendAll();
  cout << "done." << endl;

}

//-- send a message to all clients
void SpielManager::distributeMsg(string info)
{
  if(!serverGame) return;

  netOutServerInterface->sendMsg(info);
  netOutServerInterface->sendAll();
}


// **** Client Functions ****

//-- the connection to the server is set up
void SpielManager::connectConfirm()
{
  connected = true;
  guiOutputInterface->connConf();
}

//-- the server has disconnected
void SpielManager::disconnect()
{
  connected = false;
  killGame();
}

//-- set the name of a player
void SpielManager::setPlayerName(int playerID, string name)
{
  if ( serverGame == false )
  {
    if ( playerName[playerID] == name )         // if name has not changed...return
    {
      return;
    }
    playerName[playerID] = name;
    if ( name.size() > 1 )
    {
      cout << "PD2GUI::newPlayer(" << playerID+1 << ", " << name << ")" << endl;
      guiOutputInterface->newPlayer(playerID+1, name.data());
    }
    else
    {
      cout << "PD2GUI::removePlayer(" << playerID+1 << ")" << endl;
      if (playerID == 0)             // server has disconnected
      {
        killGame();
      }
      else
      {
        //guiOutputInterface->removePlayer(playerID+1); <-----------------------
      }
    }
  }
}


//-- start the game
void SpielManager::run()
{
  if ( game == NULL )
  {
    //guiOutputInterface->beginGame();
    game = new Spiel;                        // create new game environment
    cout << "Initialize Client...";
    game->initClient();
    cout << "done." << endl;
    cout << "send ready()...";
    netOutClientInterface->ready();          // send ready to recieve playfield
    netOutClientInterface->sendAll();
    cout << "done." << endl;
  }
  else
  {
    if ( game->ready() == true )
    {
      cout << "send ready()...";
      guiOutputInterface->beginGame();
      netOutClientInterface->ready();         // send ready to run
      netOutClientInterface->sendAll();
      cout << "done." << endl;
    }
    else
    {
      killGame();
    }
  }
}

//-- recieve a infomessage
void SpielManager::infoMsg(string info)
{
  cout << "SpielManager::infoMsg(" << info << ")" << endl;
  guiOutputInterface->infoMsg(info.c_str());
}



//-- creates a new process for the server
void SpielManager::createNetworkServer()
{
  if (serverThread != NULL)
  {
     cout << "Server-Thread already running!!!" << endl;
     return;
  }
  cout << "Start Network-Server...";
  serverMutex->lock();
  serverThread = new ServerThread(serverMutex);
  serverThread->start();
  cout << "done." << endl;
}

//-- destroys the server process
void SpielManager::killNetworkServer()
{
    cout << "Kill Network-Server...";
    bool died;
    if (serverThread != NULL)
    {

      serverMutex->unlock();
      died = serverThread->wait(200);

      if (died == false)
      {
        cout << " unlock PD...";
        pdMutex->unlock();
        died = serverThread->wait(200);
        pdMutex->lock();
      }

      if (died == true)
      {
        cout << "done." << endl;
      }
      else
      {
        cout << "failed!!" << endl;
      }
      delete serverThread;
      serverThread = NULL;
    }
    else
    {
      cout << "not running." << endl;
    }
}

//-- creates a new thread for the client
void SpielManager::createNetworkClient()
{
/*  if (clientThread != NULL)
  {
     cout << "Client-Thread already running!!!" << endl;
     return;
  }
  cout << "Start Network-Client...";
  clientMutex->lock();
  clientThread = new ClientThread(clientMutex);
  clientThread->start();
  cout << "done." << endl;
*/
  clientTimer = new QTimer;
  connect( clientTimer, SIGNAL(timeout()), this, SLOT(clientTimeout()) );
  clientTimer->start(50);

}

//-- test
void SpielManager::clientTimeout()
{
  pdMutex->lock();
//  cout << "read from client Socket..." << endl;
  Client::instance()->readString();
//  cout << "read from client Socket...finished." << endl;
  pdMutex->unlock();
}

//-- destroys the client thread
void SpielManager::killNetworkClient()
{
    cout << "Kill Network-Client...";
/*    bool died;
    if (clientThread != NULL)
    {

      clientMutex->unlock();
      died = clientThread->wait(2000);

      if (died == false)
      {
        cout << "unlock PD...";
        pdMutex->unlock();
        died = clientThread->wait(2000);
        pdMutex->lock();
      }

      if (died == true)
      {
        cout << "done." << endl;
      }
      else
      {
        cout << "failed!!" << endl;
      }

      delete clientThread;
      clientThread = NULL;

    }
    else
    {
      cout << "not running." << endl;
    }
*/
  clientTimer->stop();
  delete clientTimer;
}

//-- testfunction for console version
void SpielManager::exAll()
{
  if(game != NULL)
  {
    game->exAll();
  }
}