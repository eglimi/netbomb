/***************************************************************************
                          spiel.cpp  -  description
                             -------------------
    begin                : Mon Apr 29 2002
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


#include "spiel.h"

#include "spielfeld.h"
#include "spielfigur.h"
#include "spielfeldclient.h"
#include "spielerclient.h"


//-- constructor
Spiel::Spiel()
{
  serverFeld = NULL;
  clientFeld = NULL;
  spieler    = NULL;
  for( int i=0; i < MAX_PLAYERS; i++)
  {
    figur[i] = NULL;
  }
}

//-- destructor
Spiel::~Spiel()
{
  destroyClient();
  destroyServer();
}

//-- initialize the server
void Spiel::initServer(bool activePlayers[MAX_PLAYERS], string playerNames[MAX_PLAYERS])
{
  serverFeld = new Spielfeld();
  for ( int i=0; i < MAX_PLAYERS; i++)
  {
    if ( activePlayers[i] == true )
    {
      figur[i] = new Spielfigur(i, serverFeld, playerNames[i]);
    }
    else
    {
      figur[i] = NULL;
    }
  }
  serverFeld->createPlayfield();

}

//-- initialize the client
void Spiel::initClient()
{
  clientFeld = new SpielfeldClient();
  spieler = new SpielerClient();
}


//-- destroy the server
void Spiel::destroyServer()
{
  if ( serverFeld != NULL )
  {
    delete serverFeld;
    serverFeld = NULL;
  }

  for ( int i=0; i < MAX_PLAYERS; i++)
  {
    if ( figur[i] != NULL )
    {
      delete figur[i];
      figur[i] = NULL;
    }
  }
}

//-- destroy the client
void Spiel::destroyClient()
{
  if ( clientFeld != NULL )
  {
    delete clientFeld;
    clientFeld = NULL;
  }
  if ( spieler != NULL )
  {
    delete spieler;
    spieler = NULL;
  }
}

//--
bool Spiel::ready()
{
  if( clientFeld != NULL )
  {
    if( clientFeld->ready() == true )
    {
      return( true );
    }
  }
  return( false );
}
//-- start the game
void Spiel::run()
{
  serverFeld->startGame();
}

//-- kills a player, when he has disconnected
void Spiel::killPlayer(int playerID)
{
  if ( figur[playerID] != NULL )
  {
    figur[playerID]->die();
  }
}


//-- testfunction
//void Spiel::exAll()
//{
//  if (serverFeld != NULL)
//  {
//    serverFeld->explodeAll();
//  }
//}
