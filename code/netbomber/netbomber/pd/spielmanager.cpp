/***************************************************************************
                          spielmanager.cpp  -  description
                             -------------------
    begin                : Mon May 27 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
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
#include "../network/client.h"

#include <assert.h>
#include <qthread.h>
#include <qtimer.h>
#include <unistd.h>

//-- Constructor
SpielManager::SpielManager()
{

  pdMutex = new QMutex(true);                                // synchronisation objects
  serverMutex = new QMutex(false);
  serverThread = NULL;                                       // network listening threads
  client = Client::instance();
  clientTimer  = NULL;

  guiOutputInterface = PDToGUIInterface::instance();       // interfaces
  guiInputInterface = GUIToPDInterface::getInterface();
  guiInputInterface->setManager(this, pdMutex);
  netInputInterface = PDKontroller::getKontroller();
  netInputInterface->setManager(this);
  netOutClientInterface = ClientInterface::getClientInterface();
  netOutServerInterface = ServerInterface::getServerInterface();

  serverGame = false;
  game = NULL;

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
  client->release();
  killNetworkServer();
  endGame();                                   // destroy game environment
  pdMutex->unlock();


  guiInputInterface->setManager(NULL);         // unregister interfaces
  guiInputInterface->release();                //

  guiOutputInterface->release();

  netInputInterface->setManager(NULL);
  netInputInterface->release();

  netOutClientInterface->release();
  netOutServerInterface->release();

  delete pdMutex;                              // destroy synchronisation objects
  delete serverMutex;
}


// **** Gamehandling functions ****

//-- creates new server game
void SpielManager::startServer(string playerName)
{
  if(serverGame) return;

  serverGame = true;

  createNetworkServer();                                     // start network listening threads
  createNetworkClient();

  sleep(1);
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
  netOutServerInterface->run();
  netOutServerInterface->sendAll();
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
    netOutServerInterface->endGame();       // send endGame to clients
    netOutServerInterface->disconnect();
    netOutServerInterface->sendAll();


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
  guiOutputInterface->infoMsg(addInfo.c_str());
}


// **** Server functions ****

//-- add new player to the game
void SpielManager::newPlayer(int playerID, string name)
{
  if(!serverGame) return;

  playerConnected[playerID] = true;                          // add new player to playerlist
  playerName[playerID] = name;
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
    game->initServer(playerConnected, playerName);
    netOutServerInterface->run();
    netOutServerInterface->sendAll();
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
  msg += MSG_DISCONNECT;
  playerConnected[playerID] = false;                       // remove player from playerlist
  playerName[playerID]      = "";
  netOutServerInterface->setPlayerName(playerID+1, "");    // send changes to clients
  netOutServerInterface->sendMsg(msg);
  netOutServerInterface->sendAll();

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
  guiOutputInterface->connConf();
}

//-- the server has disconnected
void SpielManager::disconnect()
{
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
      guiOutputInterface->newPlayer(playerID+1, name.c_str());
    }
    else
    {
      if (playerID == 0)             // server has disconnected
      {
        for ( int p = 1; p <= MAX_PLAYERS; p++ )
        {
          guiOutputInterface->removePlayer(p);
        }
        killGame();
      }
      else
      {
        guiOutputInterface->removePlayer(playerID+1); //<-----------------------
      }
    }
  }
  else
  {
    if ( name.size() > 1 )
    {
      guiOutputInterface->newPlayer(playerID+1, name.c_str());
    }
    else
    {
      guiOutputInterface->removePlayer(playerID+1); //<-----------------------
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
    game->initClient();
    netOutClientInterface->ready();          // send ready to recieve playfield
    netOutClientInterface->sendAll();
  }
  else
  {
    if ( game->ready() == true )
    {
      guiOutputInterface->beginGame();
      netOutClientInterface->ready();         // send ready to run
      netOutClientInterface->sendAll();
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
  guiOutputInterface->infoMsg(info.c_str());
}



//-- creates a new process for the server
void SpielManager::createNetworkServer()
{
  if (serverThread != NULL)
  {
     return;
  }
  serverMutex->lock();
  serverThread = new ServerThread(serverMutex, pdMutex);
  serverThread->start();
}

//-- destroys the server process
void SpielManager::killNetworkServer()
{
    bool died;
    if (serverThread != NULL)
    {

      serverMutex->unlock();
      died = serverThread->wait(400);

      if (died == false)
      {
        pdMutex->unlock();
        died = serverThread->wait(400);
        pdMutex->lock();
      }

      delete serverThread;
      serverThread = NULL;
    }
}

//-- creates timer for the client socket
void SpielManager::createNetworkClient()
{

  clientTimer = new QTimer;
  connect( clientTimer, SIGNAL(timeout()), this, SLOT(clientTimeout()) );
  clientTimer->start(CLIENT_WAIT_TIME);

}

//-- reads the client network socket
void SpielManager::clientTimeout()
{
  pdMutex->lock();
  client->readString();
  pdMutex->unlock();
}

//-- destroys the client timer
void SpielManager::killNetworkClient()
{
  if ( clientTimer != NULL )
  {
    clientTimer->stop();
    delete clientTimer;
    clientTimer = NULL;
    clientTimeout();
  }
}

//-- testfunction for console version
//void SpielManager::exAll()
//{
//  if(game != NULL)
//  {
//    game->exAll();
//  }
//}