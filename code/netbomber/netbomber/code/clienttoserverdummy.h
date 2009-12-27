/***************************************************************************
                          clienttoserverdummy.h  -  description
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

#ifndef CLIENTTOSERVERDUMMY_H
#define CLIENTTOSERVERDUMMY_H


class Spielfigur;


class ClientToServerDummy {
public: 
	ClientToServerDummy(Spielfigur* fig);
	~ClientToServerDummy();

  void setDirection(int dir);
  void setBombPressed(bool bomb);

private:
  Spielfigur* figur;
};

#endif
