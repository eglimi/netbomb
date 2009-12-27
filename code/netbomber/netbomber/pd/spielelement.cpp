/***************************************************************************
                          spielelement.cpp  -  description
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