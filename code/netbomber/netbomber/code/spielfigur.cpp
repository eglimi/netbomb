/***************************************************************************
                          spielfigur.cpp  -  description
                             -------------------
    begin                : Thu Apr 18 2002
    copyright            : (C) 2002 by U.Heimann
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "spielfigur.h"
#include "spielfeld.h"
#include "pdkontroller.h"
#include "../network/serverinterface.h"
#include <qtimer.h>

#include "../global.h"

//-- Constructor
Spielfigur::Spielfigur(int ID, Spielfeld* feld, string name)
{
  playerID = ID;
  playerName = name;
  pdKontroller = PDKontroller::getKontroller();               // get Network input interface
  pdKontroller->setSpielfigur(playerID, this);                // register at Network interface
  netInterface = ServerInterface::getServerInterface();       // get Network output interface

  spielfeld     = feld;                                       // set Playfield
  alive         = false;                                      // disable player
  position      = START_POSITION[playerID];                   // set startposition
  reichweite    = START_REICHWEITE;                           // set start-reichweite of the bombs
  numberOfBombs = START_BOMBS;                                // set initial bomb arsenal

  spielfeld->setPlayer(playerID, this);                       // register player on the playfield

  moveTimer = new QTimer();                                   // initialize move-delay-timer
  connect( moveTimer, SIGNAL(timeout()), this, SLOT(timerDone()) );
}

//-- Destructor
Spielfigur::~Spielfigur()
{
  if ( alive == true )                                        // if player still is alive, remove it from playfield
  {
    spielfeld->delPlayer(playerID);
  }
  pdKontroller->setSpielfigur(playerID, NULL);                // detach player from the network interface
  delete moveTimer;
}


//-- drops a bomb if the bomb-key was pressed
void Spielfigur::setBombPressed(bool bomb)
{
  bombPressed = bomb;
  if ( (bombPressed == true) && (alive == true) )
  {
    dropBomb();
  }
}

//-- returns the range of the players bombs
int Spielfigur::getReichweite()
{
  return (reichweite);
}

//-- returns the current position of the player
Position Spielfigur::getPosition()
{
  return (position);
}

//-- returns the current position of the player
string Spielfigur::getName()
{
  return (playerName);
}

//-- sets a new moving direction for the player
void Spielfigur::setDirection(int newdirection)
{
  direction = newdirection;
  if ( moveTimer->isActive() == false )      // player is not moving at the moment
  {
    if ( direction != STAY )
    {
      if ( move() == true )
      {
        moveTimer->start(MOVE_DELAY);
      }
    }
  }
}

//-- moves the player when the timer runs out and a direction is set
void Spielfigur::timerDone()
{
  if ( direction == STAY )
  {
    moveTimer->stop();
  }
  else
  {
    if ( move() == false )
    {
      moveTimer->stop();
    }
  }
}

//-- moves the player to the next field
bool Spielfigur::move()
{
  bool moved = false;

  if ( alive == false )
  {
    return (false);
  }

  switch(direction){
    case UP    : if (checkField(position.x, position.y -1) == FREI)
                 {
                   position.y -= 1;
                   moved = true;
                 }
                 break;
    case DOWN  : if (checkField(position.x, position.y +1) == FREI)
                 {
                   position.y += 1;
                   moved = true;
                 }
                 break;
    case RIGHT : if (checkField(position.x + 1, position.y) == FREI)
                 {
                   position.x += 1;
                   moved = true;
                 }
                 break;
    case LEFT  : if (checkField(position.x - 1, position.y) == FREI)
                 {
                   position.x -= 1;
                   moved = true;
                 }
                 break;
  }

  if ( moved )
  {
    netInterface->setPlayer(playerID+1, position);        // send new position to clients
    netInterface->sendAll();
    if ( bombPressed == true )
    {
      dropBomb();
    }
  }

  return ( moved );
}

//-- drops a bomb at the current position
void Spielfigur::dropBomb()
{
  if ( (numberOfBombs > 0) && (checkField(position.x, position.y) == FREI) )
  {
//    cout << "Spielfigur::dropBomb("<< position.x << "," << position.y <<")" << endl;
    spielfeld->setField(position, BOMBE, this);
    netInterface->setItem(position, BOMBE);
    netInterface->sendAll();
    numberOfBombs--;
  }
}

//-- returns the type of a specific field
int Spielfigur::checkField(int posx, int posy)
{
  Position pos = {posx, posy};
  return (spielfeld->getField(pos));
}

//-- kills the player
void Spielfigur::die()
{
  alive = false;
  spielfeld->delPlayer(playerID);
}

//-- activates the player when the game starts
void Spielfigur::wakeup()
{
  alive = true;
}

//-- adds a bomb to the players arsenal
void Spielfigur::addBomb()
{
  numberOfBombs++;
}

