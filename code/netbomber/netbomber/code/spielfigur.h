/***************************************************************************
                          spielfigur.h  -  description
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

#ifndef SPIELFIGUR_H
#define SPIELFIGUR_H

#include <qobject.h>
#include "../global.h"
#include <string>

struct Position;
class Spielfeld;
class PDKontroller;
class ServerInterface;
class QTimer;

class Spielfigur : public QObject {
  Q_OBJECT
public: 
	Spielfigur(int ID, Spielfeld* feld, string name);
	~Spielfigur();

  void     setDirection(int newdirection);
  void     setBombPressed(bool bomb);
  Position getPosition();
  string   getName();
  int      getReichweite();
  bool     move();
  void     addBomb();
  void     die();
  void     wakeup();


private:
  Spielfeld*            spielfeld;
  PDKontroller*         pdKontroller;
  ServerInterface*      netInterface;

  int      playerID;
  string   playerName;
  bool     alive;
  Position position;
  int      direction;
  bool     bombPressed;
  int      numberOfBombs;
  int      reichweite;
  QTimer*  moveTimer;

  int   checkField(int posx, int posy);
  void  dropBomb();

public slots:
  void timerDone();
};

#endif
