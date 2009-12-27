/***************************************************************************
                          bombenview.h  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#ifndef BOMBENVIEW_H
#define BOMBENVIEW_H

#include <qcanvas.h>
//#include <qimage.h>

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
	int posY;
	int posX;
//	QPixmap _pixmap;
//	QImage image;
};

#endif
