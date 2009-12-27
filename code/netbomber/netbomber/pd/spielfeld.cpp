/***************************************************************************
                          spielfeld.cpp  -  description
                             -------------------
    begin                : Thu Apr 18 2002
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


#include "spielfeld.h"
#include "spielfigur.h"
#include "spiel.h"
#include "spielelement.h"
#include "mauer.h"
#include "wand.h"
#include "bombe.h"
#include "../network/serverinterface.h"
#include <string>
#include <stdlib.h>
#include <time.h>


//-- constructor
Spielfeld::Spielfeld()
{
  netInterface = ServerInterface::getServerInterface();

  minPlayers = MIN_PLAYERS;
  for (int i=0; i < MAX_PLAYERS; i++)
  {
    player[i] = NULL;
  }

  for(int y = 0 ; y < FELD_HEIGHT ; y++)
  {
    for(int x = 0 ; x < FELD_WIDTH ; x++)
    {
        feld[x][y] = NULL;
    }
  }
}

//-- destructor
Spielfeld::~Spielfeld()
{
  stopGame();

  for(int y = 0 ; y < FELD_HEIGHT ; y++)
  {
    for(int x = 0 ; x < FELD_WIDTH ; x++)
    {
      if ( feld[x][y] != NULL )
      {
        delete( feld[x][y] );
      }
    }
  }
  netInterface->release();
}

//-- start the game
void Spielfeld::startGame()
{
  for (int i=0; i < MAX_PLAYERS; i++)
  {
    if ( player[i] != NULL )
    {
      player[i]->wakeup();             // wake the player
    }
  }
}

//-- stop the game
void Spielfeld::stopGame()
{
  minPlayers = 0;
  for (int i=0; i < MAX_PLAYERS; i++)
  {
    if ( player[i] != NULL )
    {
      player[i]->die();             // kills the player
    }
  }
}

//-- register new player
void Spielfeld::setPlayer(int playerID, Spielfigur* newPlayer)
{
  player[playerID] = newPlayer;
}

//-- remove player
void Spielfeld::delPlayer(int playerID)
{
  player[playerID] = NULL;
  netInterface->delPlayer(playerID+1);

  string livingPlayers = "";
  int playerCount = 0;
  for (int i=0; i < MAX_PLAYERS; i++)
  {
    if ( player[i] != NULL )
    {
      playerCount++;
      livingPlayers += player[i]->getName();
    }
  }
  if ( playerCount < minPlayers )
  {
    string won = MSG_GAME_FINISHED;
    if (playerCount == 0)
    {
      won += MSG_NO_WINNER;
    }
    else
    {
      won += MSG_WINNER;
      won += livingPlayers;
      won += MSG_EXCLEMATION;
    }
    netInterface->sendMsg(won);
    netInterface->endGame();
  }

  netInterface->sendAll();
}

//-- return type of object on position (x,y)
int Spielfeld::getField(Position pos)
{
  if ( feld[pos.x][pos.y] == NULL )
  {
    return ( FREI );
  }
  else
  {
    return ( feld[pos.x][pos.y]->getType() );
  }
}

//-- sets object on position (x,y)
void Spielfeld::setField(Position pos, int item, Spielfigur* figur = NULL)
{
  if ( feld[pos.x][pos.y] != NULL )
  {
    delete ( feld[pos.x][pos.y] );
  }

  switch ( item )
  {
    case FREI           : feld[pos.x][pos.y] = NULL;
                          break;
    case MAUER          : feld[pos.x][pos.y] = new Mauer(pos);
                          break;
    case WAND           : feld[pos.x][pos.y] = new Wand(pos);
                          break;
    case BOMBE          : feld[pos.x][pos.y] = new Bombe(pos, figur, this);
                          break;
  }

}

//-- calculates the explosion of one or more bombs
void Spielfeld::explode(Position pos, int reichweite, queue<Position>* toDie = NULL)
{
  feld[pos.x][pos.y]->die();                    // Bombe aufräumen
  setField(pos, FREI);                          // Bombe löschen
  netInterface->setItem(pos, FREI);
  netInterface->explode(pos, reichweite);       // Meldung an Clients senden

  // Treffer erkennen (Spielfiguren)
  for ( int pID = 0; pID < MAX_PLAYERS; pID++)
  {
    if ( player[pID] != NULL )
    {
      if ( pos.x == player[pID]->getPosition().x && pos.y == player[pID]->getPosition().y)
      {
        player[pID]->die();
      }
    }
  }


  bool firstBomb = false;
  if ( toDie == NULL )                          // erste Bombe (bei kettenreaktion)
  {
    toDie = new queue<Position>;
    firstBomb = true;
  }


  int distance;
  Position temppos;

  for ( int direction = UP; direction <= LEFT; direction++)
  {
    distance = 0;
    temppos  = pos;
    while ( distance < reichweite )
    {
      switch ( direction )
      {
        case UP   : temppos.y--;
                    break;
        case DOWN : temppos.y++;
                    break;
        case RIGHT: temppos.x++;
                    break;
        case LEFT : temppos.x--;
                    break;
      }
      distance++;

      // Treffer erkennen (Spielelemente)
      if ( feld[temppos.x][temppos.y] != NULL )
      {
        if ( feld[temppos.x][temppos.y]->getType() == BOMBE )
        {
          explode(temppos, ((Bombe*)(feld[temppos.x][temppos.y]))->getReichweite(), toDie);
        }
        else
        {
          toDie->push(temppos);
        }
        distance = reichweite;
      }

      // Treffer erkennen (Spielfiguren)
      for ( int pID = 0; pID < MAX_PLAYERS; pID++)
      {
        if ( player[pID] != NULL )
        {
          if ( temppos.x == player[pID]->getPosition().x && temppos.y == player[pID]->getPosition().y)
          {
            player[pID]->die();
          }
        }
      }

    }
  }


  if ( firstBomb == true)                                   // gesprengte Objekte löschen
  {
    clearKilledElements(toDie);
    delete ( toDie );
    netInterface->sendAll();
  }
}

//-- removes the destroyed elements from the playfield
void Spielfeld::clearKilledElements(queue<Position>* toDie)
{
  SpielElement* tempElement;
  Position      pos;

  while ( toDie->empty() == false )
  {
    pos = toDie->front();
    if ( feld[pos.x][pos.y] != NULL )                   // if there is an element
    {
      tempElement = feld[pos.x][pos.y]->die();          // kill element
      if ( tempElement != feld[pos.x][pos.y] )          // if new element is diffrent to the old one
      {
        delete ( feld[pos.x][pos.y] );                  // delete the old one

        if ( tempElement == NULL )                      // send changes to clients
        {
          netInterface->setItem(pos, FREI);
        }
        else
        {
          netInterface->setItem(pos, tempElement->getType());
        }
      }
      feld[pos.x][pos.y] = tempElement;                 // set new element (can be NULL)
    }
    toDie->pop();
  }
}


//-- creates the Items on the playfield
void Spielfeld::createPlayfield()
{
  Position pos;
  vector<int> feldinfo;
  int element;
  srand((unsigned int)time((time_t *)NULL));


  // generate Playfield
  for( pos.y = 0 ; pos.y < FELD_HEIGHT ; pos.y++)
  {
    for( pos.x = 0 ; pos.x < FELD_WIDTH ; pos.x++)
    {
      if(  ((pos.x % 2) == 0 && (pos.y % 2) == 0 ) ||    // schachbrettmuster
           (pos.x == 0) || (pos.y == 0) ||               // linker und oberer Rand
           (pos.x == FELD_HEIGHT - 1) ||                 // unterer Rand
           (pos.y == FELD_WIDTH - 1) )                   // rechter Rand
      {
        setField(pos, MAUER);
        feldinfo.push_back(MAUER);
      }
      else if( (pos.x + pos.y <= 3) ||                                 // linke obere ecke frei
               (pos.x + pos.y >= FELD_HEIGHT + FELD_WIDTH - 5) ||      // rechte untere ecke frei
               (pos.x == 1 && pos.y == FELD_HEIGHT - 3) ||             // linke untere ecke frei
               (pos.x == 1 && pos.y == FELD_HEIGHT - 2) ||             //   "
               (pos.x == 2 && pos.y == FELD_HEIGHT - 2) ||             //   "
               (pos.x == FELD_WIDTH - 3 && pos.y == 1) ||              // rechte obere ecke frei
               (pos.x == FELD_WIDTH - 2 && pos.y == 1) ||              //   "
               (pos.x == FELD_WIDTH - 2 && pos.y == 2) )               //   "
      {
        setField(pos, FREI);
        feldinfo.push_back(FREI);
      }
      else
      {
        element = (rand()%2)*2;
        setField(pos, element);
        feldinfo.push_back(element);
      }
    }
  }

  // send player positions to Clients
  for (int id=0; id < MAX_PLAYERS; id++)
  {
    if(player[id] != NULL)
    {
      netInterface->setPlayer(id+1, player[id]->getPosition());
    }
  }
  netInterface->setPlayfield(feldinfo, FELD_WIDTH);  // send Playfieldinfo to Clients
  //netInterface->sendAll();
  //printToConsole();   // testfunction
}



//--  Testfunction
/*
void Spielfeld::printToConsole(){
  Position feldpos;
  Position playerpos[MAX_PLAYERS];

  cout << "Server playfield.." << endl;
  for(int i=0; i < MAX_PLAYERS; i++)
  {
    if(player[i] != NULL)
    {
      playerpos[i] = player[i]->getPosition();
      cout << "Player " << i << " : (" << playerpos[i].x << "," << playerpos[i].y << ")" << endl;
    }
    else
    {
       playerpos[i].x = 0;
       playerpos[i].y = 0;
    }
  }

  for(feldpos.y=0 ; feldpos.y < FELD_HEIGHT ; feldpos.y++){
    for(feldpos.x=0 ; feldpos.x < FELD_WIDTH ; feldpos.x++){
      if( (playerpos[0].x == feldpos.x && playerpos[0].y == feldpos.y) ||
          (playerpos[1].x == feldpos.x && playerpos[1].y == feldpos.y) ||
          (playerpos[2].x == feldpos.x && playerpos[2].y == feldpos.y) ||
          (playerpos[3].x == feldpos.x && playerpos[3].y == feldpos.y) )
      {
        cout << "P ";
      }
      else{
        cout << getField(feldpos) << " ";
      }
    }
    cout << endl;
  }
}
*/

//-- testfunction
/*
void Spielfeld::explodeAll()
{
  Position pos;
  for(pos.y=0 ; pos.y < FELD_HEIGHT ; pos.y++){
    for(pos.x=0 ; pos.x < FELD_WIDTH ; pos.x++){
      if( getField(pos) == BOMBE )
      {
        explode(pos, ((Bombe*)feld[pos.x][pos.y])->getReichweite());
      }
    }
  }
  printToConsole();
}
 */
