/***************************************************************************
                          spielerclient.cpp  -  description
                             -------------------
    begin                : Mon Apr 29 2002
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

#include "spielerclient.h"
#include "guitopdinterface.h"
#include "../network/clientinterface.h"
#include "../global.h"
#include <assert.h>

//-- constructor
SpielerClient::SpielerClient()
{
  oldDirection = STAY;
  guiInterface = GUIToPDInterface::getInterface();      // get GUI input interface
  guiInterface->setPlayer(this);                        // redirect input events to self
  netInterface = ClientInterface::getClientInterface(); // get Network output interface
  for ( int i = 0; i < 6; i++)                          // initialize keylist
  {
     keylist[i] = false;
  }
}

//-- destructor
SpielerClient::~SpielerClient()
{
  guiInterface->setPlayer(NULL);                      // unset input redirection
}

//-- react on keyPressed events
void SpielerClient::keyPressed(char key)
{
  assert( netInterface != NULL );

  switch(key)
  {
    case KEY_DOWN  : keylist[DOWN] = true;
                     computeDirection();
                     break;
    case KEY_LEFT  : keylist[LEFT] = true;
                     computeDirection();
                     break;
    case KEY_RIGHT : keylist[RIGHT] = true;
                     computeDirection();
                     break;
    case KEY_UP    : keylist[UP] = true;
                     computeDirection();
                     break;
    case KEY_BOMB  : netInterface->setBombPressed(true);
                     netInterface->sendAll();
                     break;
  }
}

//-- react on keyReleased events
void SpielerClient::keyReleased(char key)
{
  assert( netInterface != NULL );

  switch(key)
  {
    case KEY_DOWN  : keylist[DOWN] = false;
                     computeDirection();
                     break;
    case KEY_LEFT  : keylist[LEFT] = false;
                     computeDirection();
                     break;
    case KEY_RIGHT : keylist[RIGHT] = false;
                     computeDirection();
                     break;
    case KEY_UP    : keylist[UP] = false;
                     computeDirection();
                     break;
    case KEY_BOMB  : netInterface->setBombPressed(false);
                     netInterface->sendAll();
                     break;
  }
}

//-- computes the current walking direction
void SpielerClient::computeDirection()
{
  int dir = STAY;
  int count = 0;

  for( int i = 1; i <= 4; i++)           // check which key(s) are pressed
  {
    if ( keylist[i] == true )
    {
      dir = i;
      count++;
    }
  }

  if ( (count <= 1) )                    // only one of the moving keys shoud be pressed
  {
    if ( dir != oldDirection )           // send direction only if it has changed
    {
      netInterface->setDirection(dir);   // sent new direction to server
      netInterface->sendAll();
      oldDirection = dir;
    }
  }
}


