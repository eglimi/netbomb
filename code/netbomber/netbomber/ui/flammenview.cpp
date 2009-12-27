/***************************************************************************
                          flammenview.cpp  -  description
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


#include "flammenview.h"
#include "../global.h"
#include <qpixmap.h>
#include <qpainter.h>


FlammenView::FlammenView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage flammenpic;
  bool ok = flammenpic.load(SPRITE_FLAMME);
  if(ok)
  {
    setSize(flammenpic.width(), flammenpic.height());
    _pixmap.convertFromImage(flammenpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }

  setX(posX*FIELD_WIDTH);
  setY(posY*FIELD_WIDTH);
  setZ(200);
}
FlammenView::~FlammenView()
{
}

int FlammenView::rtti() const
{
	return RTTI_FLAMME;
}

void FlammenView::drawShape(QPainter &p)
{
	p.drawPixmap( posX*FIELD_WIDTH, posY*FIELD_WIDTH, _pixmap);
}

int FlammenView::getPosX() const
{
	return posX;
}

int FlammenView::getPosY() const
{
	return posY;
}