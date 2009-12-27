/***************************************************************************
                          wandview.h  -  description
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

#ifndef WANDVIEW_H
#define WANDVIEW_H

#include <qcanvas.h>
#include <qimage.h>

class QPixmap;

class WandView : public QCanvasRectangle
{
public:
	WandView(QCanvas * canvas, int xpos, int ypos);
	~WandView();
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
