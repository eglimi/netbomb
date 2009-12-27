/***************************************************************************
                          mauer.cpp  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "mauer.h"
#include "../global.h"

//-- constructor
Mauer::Mauer(Position pos) : SpielElement(pos, MAUER)
{
}

//-- destructor
Mauer::~Mauer()
{
}

//-- a Mauer can't be destroied
SpielElement* Mauer::die()
{
  return (this);
}