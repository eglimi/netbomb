/***************************************************************************
                          bombenview.h  -  description
                             -------------------
    begin                : Fri May 24 2002
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


#ifndef BOMBENVIEW_H
#define BOMBENVIEW_H

#include <qcanvas.h>
#include <qimage.h>

/**
  *@author Stefan Kuenzle
  */

class BombenView : public QCanvasRectangle
{

public:
	BombenView(QCanvas * canvas, int xpos, int ypos);
	~BombenView();
	virtual int rtti() const;
	int getPosX() const;
	int getPosY() const;

protected:
  virtual void drawShape(QPainter &);

private:
	int posX;
	int posY;
	QPixmap _pixmap;
	QImage image;
};

#endif
