/***************************************************************************
                          bombe.cpp  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
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
  cout << "Bombe::~Bombe("<< position.x << "," << position.y <<")" << endl;
  delete explodeTimer;
}

//--
SpielElement* Bombe::die()
{
  cout << "Bombe::die("<< position.x << "," << position.y <<")" << endl;
  explodeTimer->stop();
  dropper->addBomb();
  return (NULL);
}

//--
void Bombe::timeout()
{
  cout << "Bombe::timeout("<< position.x << "," << position.y <<")" << endl;
  playfield->explode(position, reichweite);
}

//--
int Bombe::getReichweite()
{
  return reichweite;
}
