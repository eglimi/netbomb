/***************************************************************************
                          wand.h  -  description
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


#ifndef WAND_H
#define WAND_H

#include <spielelement.h>
#include "../global.h"

class Wand : public SpielElement  {
public: 
	Wand(Position pos);
	~Wand();

  SpielElement* die();
  int getPowerupType();

private:
  int powerupType;

};

#endif
