/***************************************************************************
                          spielelement.h  -  description
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


#ifndef SPIELELEMENT_H
#define SPIELELEMENT_H

#include <qobject.h>
#include "../global.h"

struct Position;

class SpielElement : public QObject {
  Q_OBJECT
public: 
	SpielElement(Position pos, int type);
	virtual ~SpielElement();

  virtual SpielElement*  die() = 0;
          int            getType();

protected:
  Position  position;
  int       elementType;
};

#endif
