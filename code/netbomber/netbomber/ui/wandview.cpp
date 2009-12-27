/***************************************************************************
                          wandview.cpp  -  description
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

#include "wandview.h"
#include "../global.h"
#include <qimage.h>
#include <qpixmap.h>
#include <qpainter.h>


WandView::WandView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage wandpic;
  bool ok = wandpic.load(SPRITE_WAND);
  if(ok)
  {
    setSize(wandpic.width(), wandpic.height());
    _pixmap.convertFromImage(wandpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
  setX(posX*FIELD_WIDTH);
  setY(posY*FIELD_WIDTH);
  setZ(3000);
}
WandView::~WandView()
{
}

void WandView::drawShape(QPainter &p)
{
	p.drawPixmap( posX*FIELD_WIDTH, posY*FIELD_WIDTH, _pixmap);
}



int WandView::getPosX() const
{
  return posX;
}

int WandView::getPosY() const
{
  return posY;
}

int WandView::rtti() const
{
  return RTTI_WAND;
}


