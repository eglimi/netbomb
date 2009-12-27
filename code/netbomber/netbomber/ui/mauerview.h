/***************************************************************************
                          mauerview.h  -  description
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

#ifndef MAUERVIEW_H
#define MAUERVIEW_H

#include <qcanvas.h>
#include <qimage.h>

class QPixmap;

class MauerView : public QCanvasRectangle
{
public: 
	MauerView(QCanvas * canvas, int xpos, int ypos);
	~MauerView();
	virtual int rtti() const;
	int getPosX() const;
	int getPosY() const;
	
protected:
  virtual void drawShape(QPainter &p);	

private:
	int posX;
	int posY;
	QPixmap _pixmap;
	QImage image;
};

#endif
