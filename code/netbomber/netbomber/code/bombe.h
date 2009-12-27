/***************************************************************************
                          bombe.h  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#ifndef BOMBE_H
#define BOMBE_H

#include "spielelement.h"

struct Position;
class Spielfigur;
class Spielfeld;
class QTimer;

class Bombe : public SpielElement {
  Q_OBJECT
public: 
	Bombe(Position pos, Spielfigur* player, Spielfeld* feld);
	~Bombe();

  SpielElement* die();
  int           getReichweite();

private:
  Spielfigur* dropper;
  Spielfeld* playfield;
  QTimer* explodeTimer;
  int reichweite;

public slots:
  void timeout();
};

#endif
