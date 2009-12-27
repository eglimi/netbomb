/***************************************************************************
                          pdkontroller.cpp  -  description
                             -------------------
    begin                : Tue May 21 2002
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



#include "pdkontroller.h"
#include "../global.h"
#include "spielfeld.h"
#include "spielfigur.h"
#include "spielfeldclient.h"
#include "spielmanager.h"
#include <qthread.h>


//-- initialize static member
PDKontroller* PDKontroller::m_pdkontroller = NULL;

//-- static member function
PDKontroller* PDKontroller::getKontroller()
{
  if(m_pdkontroller == NULL)
  {
    m_pdkontroller = new PDKontroller;
  }
  m_pdkontroller->rCount++;
  return m_pdkontroller;
}

//--  Constructor (private)
PDKontroller::PDKontroller()
{
  spielManager = NULL;
  for (int i=0; i < MAX_PLAYERS; i++)
  {
    serverFigur[i] = NULL;
  }
  clientFeld = NULL;
  rCount = 0;
}

//-- Destructor
PDKontroller::~PDKontroller()
{
}

//--
void PDKontroller::release()
{
  rCount--;
  if ( rCount == 0 )
  {
    m_pdkontroller = NULL;
    delete this;
  }
}

//-- register the Manager
void PDKontroller::setManager(SpielManager* manager)
{
  spielManager = manager;
}

//-- register the Playfield of the Client
void PDKontroller::setClientFeld(SpielfeldClient* feld)
{
  clientFeld = feld;
}

//-- register the players
void PDKontroller::setSpielfigur(int playerID, Spielfigur* figur)
{
  serverFigur[playerID] = figur;
}


// **** Messages to Manager ****

//-- Register new player, that has connected
void PDKontroller::newPlayer(int playerID, string playerName)
{
  playerID--;
  if ( (spielManager != NULL) && (playerID <= MAX_PLAYERS-1) && (playerID >= 0) )
  {
    spielManager->newPlayer(playerID, playerName);
  }
}

//-- removes a player from the list (on the server)
void PDKontroller::disconnect(int playerID)
{
  playerID--;
  if ( (spielManager != NULL) && (playerID <= MAX_PLAYERS-1) && (playerID >= 0) )
  {
    spielManager->removePlayer(playerID);
  }

}

//-- indicates that the player is ready to play
void PDKontroller::ready(int playerID)
{
  playerID--;
  if ( (spielManager != NULL) && (playerID <= MAX_PLAYERS-1) && (playerID >= 0) )
  {
    spielManager->ready(playerID);
  }
}

//-- tells the client to init his playfield
void PDKontroller::run()
{
  if ( spielManager != NULL )
  {
    spielManager->run();
  }

}

//-- tells the client to destroy his playfield
void PDKontroller::endGame()
{
  if ( spielManager != NULL )
  {
    spielManager->endGame();
  }
}

//-- tells the client that the connection to the server is set up
void PDKontroller::connectConfirm()
{
  if ( spielManager != NULL )
  {
    spielManager->connectConfirm();
  }
}

//-- the server has disconnected
void PDKontroller::disconnect()
{
  if ( spielManager != NULL )
  {
    spielManager->disconnect();
  }
}

//-- sets the name of a Player (on the Client)
void PDKontroller::setPlayerName(int playerID, string playerName)
{
  playerID--;
  if ( (spielManager != NULL) && (playerID <= MAX_PLAYERS-1) && (playerID >= 0) )
  {
    spielManager->setPlayerName(playerID, playerName);
  }
}

//-- an error message from the Network
void PDKontroller::errorMsg(int msgNumber, string addInfo)
{
  if ( spielManager != NULL )
  {
    spielManager->errorMsg(msgNumber, addInfo);
  }

}

//-- an info message from a client to the server (to broadcast)
void PDKontroller::receiveMsg(string msg, int playerID)
{
  if ( spielManager != NULL )
  {
    spielManager->distributeMsg(msg);
  }

}

//-- an info message from the server
void PDKontroller::receiveMsg(string msg)
{
  if ( spielManager != NULL )
  {
    spielManager->infoMsg(msg);
  }

}


// **** Messages to Server ****

//--
void PDKontroller::setDirection(int direction, int playerID)
{
  playerID--;
  if ((playerID <= MAX_PLAYERS-1) && (playerID >= 0))
  {
    if ( serverFigur[playerID] != NULL )
    {
      serverFigur[playerID]->setDirection(direction);
    }
  }
}

//--
void PDKontroller::setBombPressed(bool keypressed, int playerID)
{
  playerID--;
  if ((playerID <= MAX_PLAYERS-1) && (playerID >= 0))
  {
    if ( serverFigur[playerID] != NULL )
    {
      serverFigur[playerID]->setBombPressed(keypressed);
    }
  }
}


// **** Messages to Client ****

//-- initializes the entire playfield at once
void PDKontroller::setPlayfield(vector<int> feldinfo, int zeilenbreite)
{
  if ( clientFeld != NULL )
  {
    clientFeld->setPlayfield(feldinfo, zeilenbreite);
  }
}

//-- sets an object on the playfield
void PDKontroller::setItem(Position position, int item)
{
  if ( clientFeld != NULL )
  {
    clientFeld->setField(position, item);
  }
}

//-- sets a player to a new position
void PDKontroller::setPlayer(int playerID, Position position)
{
  playerID--;
  if ( clientFeld != NULL )
  {
    clientFeld->setPlayer(playerID, position);
  }
}

//-- removes a player from the playfield
void PDKontroller::delPlayer(int playerID)
{
  playerID--;
  if ( clientFeld != NULL )
  {
    clientFeld->delPlayer(playerID);
  }
}

//-- starts an explosion
void PDKontroller::explode(Position position, int reichweite)
{
  if ( clientFeld != NULL )
  {
    clientFeld->explode(position, reichweite);
  }
}


