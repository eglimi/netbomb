/***************************************************************************
                          abstractspielelement.h  -  description
                             -------------------
    begin                : Fri Apr 26 2002
    copyright            : (C) 2002 by S.Kuenzle
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ABSTRACTSPIELELEMENT_H
#define ABSTRACTSPIELELEMENT_H

#include <qcanvas.h>

class AbstractSpielElement : public QCanvasRectangle
{
public: 
	AbstractSpielElement(QCanvas * canvas, int xpos, int ypos);
	~AbstractSpielElement();
	int getPosX() const;
	int getPosY() const;
private:
	int posX;
	int posY;
};

#endif
