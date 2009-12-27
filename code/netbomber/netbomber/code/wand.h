/***************************************************************************
                          wand.h  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
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
