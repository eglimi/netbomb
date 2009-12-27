/***************************************************************************
                          mauer.cpp  -  description
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