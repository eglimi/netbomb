/***************************************************************************
                          emptyview.h  -  description
                             -------------------
    begin                : Thu Jun 27 2002
    copyright            : (C) 2002 by S. Künzle
 ***************************************************************************/


#ifndef EMPTYVIEW_H
#define EMPTYVIEW_H

#include <qcanvas.h>


class EmptyView : public QCanvasRectangle
{
public:
	EmptyView(QCanvas * canvas, int xpos, int ypos);
	~EmptyView();
	virtual int rtti() const;
	int getPosX() const;
	int getPosY() const;

protected:
  virtual void drawShape(QPainter &);

private:
	int posY;
	int posX;
};

#endif
