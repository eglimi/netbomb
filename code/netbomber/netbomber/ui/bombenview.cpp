/***************************************************************************
                          bombenview.cpp  -  description
                             -------------------
    begin                : Fri May 24 2002
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


#include "bombenview.h"
#include "../global.h"
#include <qpainter.h>
#include <qpixmap.h>

BombenView::BombenView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage bombenpic;
  bool ok = bombenpic.load(SPRITE_BOMBE);
  if(ok)
  {
    setSize(bombenpic.width(), bombenpic.height());
    _pixmap.convertFromImage(bombenpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
  setX(posX*FIELD_WIDTH);
  setY(posY*FIELD_WIDTH);
}

BombenView::~BombenView()
{
}

int BombenView::rtti() const
{
	return RTTI_BOMBE;
}

void BombenView::drawShape(QPainter &p)
{
	p.drawPixmap( posX*FIELD_WIDTH, posY*FIELD_WIDTH, _pixmap);
}

int BombenView::getPosX() const
{
	return posX;
}

int BombenView::getPosY() const
{
	return posY;
}