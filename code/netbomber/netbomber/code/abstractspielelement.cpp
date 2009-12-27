/***************************************************************************
                          abstractspielelement.cpp  -  description
                             -------------------
    begin                : Fri Apr 26 2002
    copyright            : (C) 2002 by Stefan Kuenzle
    email                : skuenzle@hsr.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "abstractspielelement.h"
#include "../global.h"

AbstractSpielElement::AbstractSpielElement(QCanvas * canvas, int xpos, int ypos)
	: QCanvasRectangle(xpos*FIELD_WIDTH, ypos*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, canvas),
	  posX(xpos), posY(ypos){
}

AbstractSpielElement::~AbstractSpielElement()
{
}

int AbstractSpielElement::getPosX() const
{
	return posX;
}

int AbstractSpielElement::getPosY() const
{
	return posY;
}
