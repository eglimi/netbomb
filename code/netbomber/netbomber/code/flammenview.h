/***************************************************************************
                          flammenview.h  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#ifndef FLAMMENVIEW_H
#define FLAMMENVIEW_H

#include <qcanvas.h>
#//include <qimage.h>

/**
  *@author Stefan Kuenzle
  */

class FlammenView : public QCanvasRectangle
{

public:
	FlammenView(QCanvas * canvas, int xpos, int ypos);
	~FlammenView();
	virtual int rtti() const;
	int getPosX() const;
	int getPosY() const;

protected:
  virtual void drawShape(QPainter &);

private:
	int posY;
	int posX;
	//QPixmap _pixmap;
	//QImage image;
};

#endif
