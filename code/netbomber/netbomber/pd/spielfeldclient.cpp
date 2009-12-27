/***************************************************************************
                          spielfeldclient.cpp  -  description
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


#include "spielfeldclient.h"
#include "pdkontroller.h"
#include "../ui/pdtoguiinterface.h"
#include <assert.h>

//-- constructor
SpielfeldClient::SpielfeldClient()
{
// initialize interfaces
  guiInterface = PDToGUIInterface::instance();       // get GUI output interface
  pdKontroller = PDKontroller::getKontroller();      // get Network input interface
  pdKontroller->setClientFeld(this);                 // attach at input interface
  readySet = false;
  for(int i=0; i < MAX_PLAYERS; i++)
  {
    playerPosition[i].x = 0;
    playerPosition[i].y = 0;
  }

}

//-- destructor
SpielfeldClient::~SpielfeldClient()
{

  pdKontroller->setClientFeld(NULL);                 // detach at network input interface
  pdKontroller->release();
  guiInterface->release();
}

//-- sets player to a new position
void SpielfeldClient::setPlayer(int playerID, Position pos)
{
  int direction = STAY;
  if ( playerPosition[playerID].x < pos.x )
  {
    direction = RIGHT;
  }
  else if ( playerPosition[playerID].x > pos.x )
  {
    direction = LEFT;
  }
  else if ( playerPosition[playerID].y < pos.y )
  {
    direction = DOWN;
  }
  else if ( playerPosition[playerID].y > pos.y )
  {
    direction = UP;
  }

  playerPosition[playerID] = pos;
  assert( guiInterface != NULL );

  guiInterface->movePlayer(playerID+1, direction, pos.x, pos.y);            // send new position to GUI
  //printToConsole();   // Testfunction
}

//--
void SpielfeldClient::delPlayer(int playerID)
{
  playerPosition[playerID].x = -1;
  playerPosition[playerID].y = -1;

  guiInterface->movePlayer(playerID+1, UP, 0, 0);

  //printToConsole();   // Testfunction
}

//-- set an object on the playfield
void SpielfeldClient::setField(Position pos, int item)
{
  feld[pos.x][pos.y] = item;
  guiInterface->setItem(item, pos.x, pos.y);

  //printToConsole();   // Testfunction
}

//-- calculate the range of an explosion
void SpielfeldClient::explode(Position pos, int reichweite)
{
  int distance;
  Position temppos;

  //feld[pos.x][pos.y] = EXPLOSION;  // for testing
  guiInterface->setItem(EXPLOSION, pos.x, pos.y);

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

      if ( feld[temppos.x][temppos.y] != FREI )
      {
        distance = reichweite;
      }
      if ( feld[temppos.x][temppos.y] != MAUER )
      {
        //feld[temppos.x][temppos.y] = EXPLOSION;  // for testing
        guiInterface->setItem(EXPLOSION, temppos.x, temppos.y);
      }
    }
  }
  //printToConsole();   // Testfunction
  //clearFire();        // Testfunction
}

//--
void SpielfeldClient::setPlayfield(vector<int> feldinfo, int zeilenbreite)
{
  Position pos = {0,0};

  while ( feldinfo.empty() == false )
  {
    if( pos.x >= zeilenbreite )
    {
      pos.x = 0;
      pos.y++;
    }
    setField(pos, feldinfo.front());
    feldinfo.erase(feldinfo.begin());
    pos.x++;
  }
  readySet = true;
//  printToConsole();
}

//--
bool SpielfeldClient::ready()
{
  return( readySet );
}



//--  Testfunction
/*
void SpielfeldClient::printToConsole(){

  cout << "Client playfield.." << endl;
  for(int i=0; i < MAX_PLAYERS; i++)
  {
    if (playerPosition[i].x != 0)
    {
      cout << "Player " << i << " : (" << playerPosition[i].x << "," << playerPosition[i].y << ")" << endl;
    }
  }
  for(int y=0 ; y < FELD_HEIGHT ; y++){
    for(int x=0 ; x < FELD_WIDTH ; x++){
      if( (playerPosition[0].x == x && playerPosition[0].y == y) ||
          (playerPosition[1].x == x && playerPosition[1].y == y) ||
          (playerPosition[2].x == x && playerPosition[2].y == y) ||
          (playerPosition[3].x == x && playerPosition[3].y == y) )
      {
        cout << "P ";
      }
      else
      {
        cout << feld[x][y] << " ";
      }
    }
    cout << endl;
  }
}
*/

//--  Testfunction
/*
void SpielfeldClient::clearFire()
{
  for(int y = 0 ; y < FELD_HEIGHT ; y++)
  {
    for(int x = 0 ; x < FELD_WIDTH ; x++)
    {
      if(feld[x][y] == EXPLOSION)
      {
        feld[x][y] = FREI;
      }
    }
  }
}
*/
