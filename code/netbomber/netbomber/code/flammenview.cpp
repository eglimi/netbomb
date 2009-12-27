/***************************************************************************
                          flammenview.cpp  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#include "flammenview.h"
#include "../global.h"
//#include <qpixmap.h>
#include <qpainter.h>


FlammenView::FlammenView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(xpos*FIELD_WIDTH, ypos*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, canvas),
   posX(xpos), posY(ypos)
{

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
	p.fillRect( posX*FIELD_WIDTH, posY*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, Qt::red);
}

int FlammenView::getPosX() const
{
	return posX;
}

int FlammenView::getPosY() const
{
	return posY;
}




/*
FlammenView::FlammenView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage flammenpic;
  bool ok = flammenpic.load("/home/urs/netbomber/netbomber/ui/generated/flame.png");
  if(ok)
  {
    setSize(flammenpic.width(), flammenpic.height());
    _pixmap.convertFromImage(flammenpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
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

void FlammenView::timerDone()
{
  //TODO
}
*/