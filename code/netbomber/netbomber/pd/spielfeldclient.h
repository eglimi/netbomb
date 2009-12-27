/***************************************************************************
                          spielfeldclient.h  -  description
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


#ifndef SPIELFELDCLIENT_H
#define SPIELFELDCLIENT_H

#include "../global.h"
#include <vector>

class PDToGUIInterface;
class PDKontroller;

class SpielfeldClient {

public: 
	SpielfeldClient();
	~SpielfeldClient();

  void setField(Position pos, int item);
  void setPlayfield(vector<int> feldinfo, int zeilenbreite);
  void setPlayer(int playerID, Position pos);
  void delPlayer(int playerID);
  void explode(Position pos, int reichweite);

  bool ready();

//  void printToConsole();       // Testfunction
//  void clearFire();            // Testfunction
private:

  int feld[FELD_WIDTH][FELD_HEIGHT];        // playfield
  Position playerPosition[MAX_PLAYERS];     // position  of the player
  PDToGUIInterface* guiInterface;           // output interface to GUI
  PDKontroller* pdKontroller;

  bool readySet;

};

#endif
