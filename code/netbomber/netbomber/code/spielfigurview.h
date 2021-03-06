/***************************************************************************
                          spielfigurview.h  -  description
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

#ifndef SPIELFIGURVIEW_H
#define SPIELFIGURVIEW_H

#include <qcanvas.h>

class SpielfigurView : public QCanvasRectangle //QCanvasSprite
{
public: 
//	SpielfigurView(QCanvasPixmapArray* array, QCanvas * canvas, int startx, int starty, int id, const char* name);
  SpielfigurView(QCanvas* canvas, int startx, int starty, int id, const char* name);
	~SpielfigurView();
  void moveXY(int ax, int ay);
  int getID() const;
  const char* getPlayerName() const;
 // virtual void advance(int stage);
  virtual int rtti() const;

private:
 // QCanvas* _canvas;
 // int deltax, deltay;
  int _x;
  int _y;
  int _id;
  const char* _playername;
};

#endif
