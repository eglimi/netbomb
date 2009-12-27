/***************************************************************************
                          guitopdinterface.cpp  -  description
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
  return m_pInterface;
}

//-- constructor : private
GUIToPDInterface::GUIToPDInterface()
{
  spieler = NULL;
  manager = NULL;
  pdMutex = NULL;
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
    cerr << "GUI2PD: keyPressed(" << key << ");  --  player not set!" << endl;
    return;
  }
  pdMutex->lock();
  spieler->keyPressed(key);
  //cout << "GUI2PD: keyPressed(" << key << ");" << endl;
  pdMutex->unlock();
}

//-- keyreleased event from GUI
void GUIToPDInterface::keyReleased(char key)
{
  assert(pdMutex != NULL);

  if ( spieler == NULL)
  {
    cerr << "GUI2PD: keyReleased(" << key << ");  --  player not set!" << endl;
    return;
  }
  pdMutex->lock();
  spieler->keyReleased(key);
  pdMutex->unlock();
  //cout << "GUI2PD: keyReleased(" << key << ");" << endl;
}


// **** Manager functions ****

//-- creates a new game as Server
void GUIToPDInterface::startServer(const char* playerName)
{
  assert(pdMutex != NULL);

  if ( manager == NULL )
  {
    cerr << "GUI2PD: startServer();  --  manager not set!" << endl;
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
    cerr << "GUI2PD: joinServer();  --  manager not set!" << endl;
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
    cerr << "GUI2PD: startGame();  --  manager not set!" << endl;
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
    cerr << "GUI2PD: killGame();  --  manager not set!" << endl;
    return;
  }
  pdMutex->lock();
  manager->killGame();
  pdMutex->unlock();
}
