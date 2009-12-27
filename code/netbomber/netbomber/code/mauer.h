/***************************************************************************
                          mauer.h  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
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
