/***************************************************************************
                          spiel.h  -  description
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

#ifndef SPIEL_H
#define SPIEL_H

#include "../global.h"
#include <string>

class Spielfeld;
class Spielfigur;

class SpielfeldClient;
class SpielerClient;


class Spiel {
public: 
	Spiel();
	~Spiel();

  void initServer(bool activePlayers[MAX_PLAYERS], string playerNames[MAX_PLAYERS]);
  void initClient();
  bool ready();
  void run();
  void killPlayer(int playerID);

  void exAll();  // testfunction

private:
  void destroyServer();
  void destroyClient();

private:
  Spielfeld* serverFeld;
  Spielfigur* figur[MAX_PLAYERS];

  SpielerClient* spieler;
  SpielfeldClient* clientFeld;
};

#endif
