/***************************************************************************
                          servertoclientdummy.h  -  description
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

#ifndef SERVERTOCLIENTDUMMY_H
#define SERVERTOCLIENTDUMMY_H

#include "../global.h"

class SpielfeldClient;

class ServerToClientDummy {
public: 
	ServerToClientDummy(SpielfeldClient* feld);
	~ServerToClientDummy();

  void setItem(Position pos, int item);
  void setPlayer(Position pos);
  void explode(Position pos, int reichweite);
  void sendAll();

private:
  SpielfeldClient* clientFeld;
};

#endif
