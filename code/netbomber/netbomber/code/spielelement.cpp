/***************************************************************************
                          spielelement.cpp  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "spielelement.h"
#include "../global.h"

//-- constructor
SpielElement::SpielElement(Position pos, int type) : position(pos), elementType(type)
{
}

//-- destructor
SpielElement::~SpielElement()
{
}

//-- returns type of spielelement
int SpielElement::getType()
{
  return (elementType);
}