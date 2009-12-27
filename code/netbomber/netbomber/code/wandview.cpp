/***************************************************************************
                          wandview.cpp  -  description
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

#include "wandview.h"
#include "../global.h"
//#include <qimage.h>
//#include <qpixmap.h>
#include <qpainter.h>

WandView::WandView(QCanvas* canvas, int xpos, int ypos)
: QCanvasRectangle(xpos*FIELD_WIDTH, ypos*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, canvas),
posX(xpos), posY(ypos)
{
}

WandView::~WandView()
{
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

void WandView::drawShape(QPainter &p)
{
	p.fillRect( posX*FIELD_WIDTH, posY*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, Qt::blue);
}

/*
WandView::WandView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage wandpic;
  bool ok = wandpic.load("/home/urs/netbomber/netbomber/ui/generated/wand0000.gif");
  if(ok)
  {
    setSize(wandpic.width(), wandpic.height());
    _pixmap.convertFromImage(wandpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
}
WandView::~WandView()
{
}


*/


