/***************************************************************************
                          wand.cpp  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "wand.h"

//-- constructor
Wand::Wand(Position pos)  :SpielElement(pos, WAND)
{

}

//-- destructor
Wand::~Wand()
{
}

//-- destroy the Wand
SpielElement* Wand::die()
{
  return (NULL);
}

//--
int Wand::getPowerupType()
{
  return (0);
}

