/***************************************************************************
                          wand.cpp  -  description
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

