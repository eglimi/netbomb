/***************************************************************************
                          mauer.h  -  description
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


#ifndef MAUER_H
#define MAUER_H

#include <spielelement.h>

struct Position;

class Mauer : public SpielElement  {
public: 
	Mauer(Position pos);
	~Mauer();

  SpielElement* die();
};

#endif
