/***************************************************************************
                          bombenview.cpp  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#include "bombenview.h"
#include "../global.h"
#include <qpainter.h>
//#include <qpixmap.h>


BombenView::BombenView(QCanvas* canvas, int xpos, int ypos)
: QCanvasRectangle(xpos*FIELD_WIDTH, ypos*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, canvas),
  posX(xpos), posY(ypos)

{
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
	p.fillRect( posX*FIELD_WIDTH, posY*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, Qt::black);
}

int BombenView::getPosX() const
{
	return posX;
}

int BombenView::getPosY() const
{
	return posY;
}

/*
BombenView::BombenView(QCanvas* canvas, int xpos, int ypos)
 : QCanvasRectangle(canvas), posX(xpos), posY(ypos)
{
  QImage bombenpic;
  bool ok = bombenpic.load("/home/urs/netbomber/netbomber/ui/generated/bombe.png");
  if(ok)
  {
    setSize(bombenpic.width(), bombenpic.height());
    _pixmap.convertFromImage(bombenpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
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

*/