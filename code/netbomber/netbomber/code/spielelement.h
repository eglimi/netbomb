/***************************************************************************
                          spielelement.h  -  description
                             -------------------
    begin                : Wed May 8 2002
    copyright            : (C) 2002 by U.Heimann
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
