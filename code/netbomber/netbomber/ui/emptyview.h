/***************************************************************************
                          emptyview.h  -  description
                             -------------------
    begin                : Thu Jun 27 2002
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
	int posX;
	int posY;
};

#endif
