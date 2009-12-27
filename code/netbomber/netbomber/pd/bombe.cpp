/***************************************************************************
                          bombe.cpp  -  description
                             -------------------
    begin                : Wed May 8 2002
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



#include "bombe.h"
#include "spielfigur.h"
#include "spielfeld.h"
#include <qtimer.h>
#include "../global.h"



//-- constructor
Bombe::Bombe(Position pos, Spielfigur* player, Spielfeld* feld)
           : SpielElement(pos, BOMBE), dropper(player), playfield(feld)
{
  explodeTimer = new QTimer;
  connect( explodeTimer, SIGNAL(timeout()), this, SLOT(timeout()) );
  explodeTimer->start(BOMB_DELAY, TRUE);
  reichweite = dropper->getReichweite();
}

//-- destructor
Bombe::~Bombe()
{
  delete explodeTimer;
}

//-- aufräumen
SpielElement* Bombe::die()
{
  explodeTimer->stop();
  dropper->addBomb();
  return (NULL);
}

//-- timer abgelaufen
void Bombe::timeout()
{
  playfield->explode(position, reichweite);
}

//--
int Bombe::getReichweite()
{
  return reichweite;
}
