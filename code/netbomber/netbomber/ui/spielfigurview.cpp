/***************************************************************************
                          spielfigurview.cpp  -  description
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

#include "spielfigurview.h"
#include "../global.h"
#include <qpainter.h>
#include <qpixmap.h>

SpielfigurView::SpielfigurView(QCanvas* canvas, int startx, int starty, int id, const char* name)
: QCanvasRectangle(canvas), _x(startx), _y(starty), _id(id), _playername(name)
{
  setPlayer(SPRITE_DOWN_P1);
  setX(_x*FIELD_WIDTH);
  setY(_y*FIELD_WIDTH);

}

SpielfigurView::~SpielfigurView()
{
}


void SpielfigurView::drawShape(QPainter &p)
{
	p.drawPixmap( x(), y(), _pixmap);
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

void SpielfigurView::moveXY(int ax, int ay)
{
  move(ax*FIELD_WIDTH, ay*FIELD_WIDTH);
//  cout << "Spielfigur:" << x() << " " << y() << endl;
}

void SpielfigurView::setPlayer(const char* player)
{
  QImage figurpic;
  bool ok = figurpic.load(player);
  if(ok)
  {
    setSize(figurpic.width(), figurpic.height());
    _pixmap.convertFromImage(figurpic, OrderedAlphaDither);
  }
  else
  {
    cerr << "Image processing error.";
  }
}

void SpielfigurView::setDirection(int dir)
{
  switch(dir)
  {
    case UP:
      switch(_id)
      {
         case 1:
           setPlayer(SPRITE_UP_P1);
           break;
         case 2:
					 setPlayer(SPRITE_UP_P2);
           break;
         case 3:
           setPlayer(SPRITE_UP_P3);
           break;
				 case 4:
           setPlayer(SPRITE_UP_P4);
           break;
         default:
           break;
      }
        break;
    case DOWN:
      switch(_id)
      {
         case 1:
           setPlayer(SPRITE_DOWN_P1);
           break;
         case 2:
					 setPlayer(SPRITE_DOWN_P2);
           break;
         case 3:
           setPlayer(SPRITE_DOWN_P3);
           break;
				 case 4:
           setPlayer(SPRITE_DOWN_P4);
           break;
         default:
           break;
      }
        break;
    case RIGHT:
      switch(_id)
      {
         case 1:
           setPlayer(SPRITE_RIGHT_P1);
           break;
         case 2:
					 setPlayer(SPRITE_RIGHT_P2);
           break;
         case 3:
           setPlayer(SPRITE_RIGHT_P3);
           break;
				 case 4:
           setPlayer(SPRITE_RIGHT_P4);
           break;
         default:
           break;
      }
        break;
    case LEFT:
      switch(_id)
      {
         case 1:
           setPlayer(SPRITE_LEFT_P1);
           break;
         case 2:
					 setPlayer(SPRITE_LEFT_P2);
           break;
         case 3:
           setPlayer(SPRITE_LEFT_P3);
           break;
				 case 4:
           setPlayer(SPRITE_LEFT_P4);
           break;
         default:
           break;
      }
        break;
    default:
      break;
  }
}



