/***************************************************************************
                          emptyview.cpp  -  description
                             -------------------
    begin                : Thu Jun 27 2002
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


#include "emptyview.h"
#include <qpainter.h>
#include "../global.h"

EmptyView::EmptyView(QCanvas* canvas, int xpos, int ypos)
: QCanvasRectangle(xpos*FIELD_WIDTH, ypos*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, canvas),
  posX(xpos), posY(ypos)

{
  setZ(1);
}

EmptyView::~EmptyView()
{
}

int EmptyView::rtti() const
{
	return 3213;
}

void EmptyView::drawShape(QPainter &p)
{
	p.fillRect( posX*FIELD_WIDTH, posY*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, Qt::yellow);
}

int EmptyView::getPosX() const
{
	return posX;
}

int EmptyView::getPosY() const
{
	return posY;
}