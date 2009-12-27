/***************************************************************************
                          guitopdinterface.h  -  description
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


#ifndef GUITOPDINTERFACE_H
#define GUITOPDINTERFACE_H

#include "../global.h"

class SpielerClient;
class SpielManager;
class QMutex;

class GUIToPDInterface {    // Singleton
public:
  static GUIToPDInterface* getInterface();
  void release();
	~GUIToPDInterface();

  void setPlayer(SpielerClient* player);             // registers the Player
  void setManager(SpielManager* man, QMutex* pdMut = NULL);  // registers the Manager

// Spieler functions
  void keyPressed(char key);                         // player presses key
  void keyReleased(char key);                        // player releases key

// Manager functions
  void startServer(const char* playerName);          // creates a new game as Server
  void joinServer(const char* ipAdress, const char* playerName);  // creates a new game as Client
  void startGame();                                  // starts the Game (server)
  void killGame();                                   // ends the Game (at any time)

private:
	GUIToPDInterface();                                // private constructor (Singleton)
  static GUIToPDInterface* m_pInterface;
  int rCount;                                        //	reference count

  SpielerClient*  spieler;                           // pointer to the player class
  SpielManager*   manager;                           // pointer to the manager

  QMutex*         pdMutex;
};

#endif
