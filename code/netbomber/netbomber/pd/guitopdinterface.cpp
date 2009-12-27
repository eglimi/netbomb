/***************************************************************************
                          guitopdinterface.cpp  -  description
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


#include "guitopdinterface.h"
#include "spielerclient.h"
#include "spielmanager.h"
#include <qthread.h>
#include <assert.h>

// initialize static member
GUIToPDInterface* GUIToPDInterface::m_pInterface = NULL;


//-- static function returns pointer to interface
GUIToPDInterface* GUIToPDInterface::getInterface()
{
  if(m_pInterface == NULL)
  {
    m_pInterface = new GUIToPDInterface;
  }
  m_pInterface->rCount++;
  return m_pInterface;
}

//--
void GUIToPDInterface::release()
{
  rCount--;
  if ( rCount == 0 )
  {
    m_pInterface = NULL;
    delete this;
  }
}

//-- constructor : private
GUIToPDInterface::GUIToPDInterface()
{
  spieler = NULL;
  manager = NULL;
  pdMutex = NULL;
  rCount  = 0;
}

//-- destructor
GUIToPDInterface::~GUIToPDInterface()
{
}

//-- set connection to the player object
void GUIToPDInterface::setPlayer(SpielerClient* player)
{
  spieler = player;
}

//-- set connection to the gamemanager object
void GUIToPDInterface::setManager(SpielManager* man, QMutex* pdMut = NULL)
{
  manager = man;
  pdMutex = pdMut;
}


// **** Client functions ***

//-- keypressed event from GUI
void GUIToPDInterface::keyPressed(char key)
{

  assert(pdMutex != NULL);

  if ( spieler == NULL)
  {
    return;
  }
  pdMutex->lock();
  spieler->keyPressed(key);
  pdMutex->unlock();
}

//-- keyreleased event from GUI
void GUIToPDInterface::keyReleased(char key)
{
  assert(pdMutex != NULL);

  if ( spieler == NULL)
  {
    return;
  }
  pdMutex->lock();
  spieler->keyReleased(key);
  pdMutex->unlock();
}


// **** Manager functions ****

//-- creates a new game as Server
void GUIToPDInterface::startServer(const char* playerName)
{
  assert(pdMutex != NULL);

  if ( manager == NULL )
  {
    return;
  }
  pdMutex->lock();
  manager->startServer(playerName);
  pdMutex->unlock();
}

//-- creates a new game as Client
void GUIToPDInterface::joinServer(const char* ipAdress, const char* playerName)
{
  assert(pdMutex != NULL);

  if ( manager == NULL )
  {
    return;
  }
  pdMutex->lock();
  manager->joinServer(ipAdress, playerName);
  pdMutex->unlock();
}

//-- starts the game
void GUIToPDInterface::startGame()
{
  assert(pdMutex != NULL);

  if ( manager == NULL )
  {
    return;
  }
  pdMutex->lock();
  manager->startGame();
  pdMutex->unlock();
}

//-- ends the game (at any time)
void GUIToPDInterface::killGame()
{
  assert(pdMutex != NULL);

  if ( manager == NULL )
  {
    return;
  }
  pdMutex->lock();
  manager->killGame();
  pdMutex->unlock();
}
