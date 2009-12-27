/***************************************************************************
                          mauerview.cpp  -  description
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

#include "mauerview.h"
#include "../global.h"
#include <qpainter.h>
#include <qimage.h>
#include <qpixmap.h>

MauerView::MauerView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage mauerpic;
  bool ok = mauerpic.load(SPRITE_MAUER);
  if(ok)
  {
    setSize(mauerpic.width(), mauerpic.height());
    _pixmap.convertFromImage(mauerpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
  setX(posX*FIELD_WIDTH);
  setY(posY*FIELD_WIDTH);
  setZ(3000);
}

MauerView::~MauerView()
{
}

void MauerView::drawShape(QPainter &p)
{
	p.drawPixmap( posX*FIELD_WIDTH, posY*FIELD_WIDTH, _pixmap);
}



int MauerView::getPosX() const
{
	return posX;
}

int MauerView::getPosY() const
{
	return posY;
}

int MauerView::rtti() const
{
	return RTTI_MAUER;
}
