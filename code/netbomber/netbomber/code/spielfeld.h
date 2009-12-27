/***************************************************************************
                          spielfeld.h  -  description
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

#ifndef SPIELFELD_H
#define SPIELFELD_H

#include "../global.h"
#include <queue>

class Spiel;
class Spielfigur;
class SpielElement;
class ServerInterface;

class Spielfeld {
public: 
	Spielfeld();
	~Spielfeld();

  void startGame();
  void stopGame();
  void setField(Position pos, int item, Spielfigur* figur = NULL);
  void setPlayer(int playerID, Spielfigur* newPlayer);
  void delPlayer(int playerID);
  int  getField(Position pos);
  void createPlayfield();

  void explode(Position pos, int reichweite, queue<Position>* toDie = NULL);

  void printToConsole();  // testfunction
  void explodeAll();      // testfunction

private:
  SpielElement*     feld[FELD_WIDTH][FELD_HEIGHT];     // playfield
  Spielfigur*       player[MAX_PLAYERS];               // player(s) on the playfield
  ServerInterface*  netInterface;                      // output interface to Network
  int               minPlayers;
  void clearKilledElements(queue<Position>* toDie);

};

#endif
