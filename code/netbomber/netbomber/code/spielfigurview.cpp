/***************************************************************************
                          spielfigurview.cpp  -  description
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

#include "spielfigurview.h"
#include "../global.h"
#include <qpainter.h>

SpielfigurView::SpielfigurView(QCanvas* canvas, int startx, int starty, int id, const char* name)
: QCanvasRectangle(startx*FIELD_WIDTH, starty*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, canvas),
   _x(startx), _y(starty), _id(id), _playername(name)
{
  cout << "Constructor SpielfigurView" << endl;
}

SpielfigurView::~SpielfigurView()
{
  cout << "Destructor SpielfigurView" << endl;
}

/*
void SpielfigurView::drawShape(QPainter &p)
{
	p.fillRect(_x*FIELD_WIDTH, _y*FIELD_WIDTH, FIELD_WIDTH, FIELD_WIDTH, Qt::white);
} */

int SpielfigurView::rtti() const
{
	return RTTI_FIGUR;
}

int SpielfigurView::getID() const
{
  return _id;
}

const char* SpielfigurView::getPlayerName() const
{
  return _playername;
}

void SpielfigurView::moveXY(int ax, int ay)
{
  cout << "Move SpielfigurView" << endl;
  move(ax*FIELD_WIDTH, ay*FIELD_WIDTH);
}


/*
SpielfigurView::SpielfigurView(QCanvasPixmapArray* array, QCanvas * canvas, int startx, int starty, int id, const char* name)
: QCanvasSprite(array, canvas), _canvas(canvas),
  deltax(0), deltay(0), _x(startx), _y(starty), _id(id), _playername(name)
{
 // move(startx*FIELD_WIDTH, starty*FIELD_WIDTH);
  move(30,30);
  _x = 1;
  _y = 1;
  show();
}

SpielfigurView::~SpielfigurView()
{
}

void SpielfigurView::moveXY(int ax, int ay)
{
  deltax = (FIELD_WIDTH+1)*(ax - _x);
  deltay = (FIELD_WIDTH+1)*(ay - _y);
  _x = ax;
  _y = ay;

  if((deltax==0) && (deltay==0))
    setVelocity(0,0);

  if(deltax>0)
  {
    setVelocity(VELOCITY,0);
   }
  else
  if(deltax<0)
  {
    setVelocity(-VELOCITY,0);
  }

  if(deltay>0)
  {
    setVelocity(0,VELOCITY);
  }
  else
  if(deltay<0)
  {
  	setVelocity(0,-VELOCITY);
  }
}


void SpielfigurView::advance(int stage)
{
		if(!stage)   // berechnungen vornehmen
		{
		   if(deltax > 0)
		     deltax--;
		   else if(deltax < 0)
		     deltax++;
		   if(deltay > 0)
		     deltay--;
		   else if(deltay < 0)
		     deltay++;
		}
		else if (stage && animated())
		{
		  if ((deltax!=0) || (deltay!=0))
      {
		  		move(x()+xVelocity(), y()+yVelocity());
         // _canvas->setAllChanged();
      }
      else
      {
          setAnimated(false);
      }
	  	//setFrame((frame()+1) % frameCount());
		}
}


void SpielfigurView::advance(int stage)
{
  if(!(stage))
  {

  }
  else
	if(stage && animated())
	{
		setFrame((frame()+1) % frameCount());
	}
  QCanvasSprite::advance(stage);
}


void SpielfigurView::draw(QPainter &p)
{
	QCanvasPixmap* pix = image();
	p.drawPixmap(QPoint(x(), y()), *pix);
}

int SpielfigurView::rtti() const
{
	return RTTI_FIGUR;
}

int SpielfigurView::getID() const
{
  return _id;
}

const char* SpielfigurView::getPlayerName() const
{
  return _playername;
}
*/

