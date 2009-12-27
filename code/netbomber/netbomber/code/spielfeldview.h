/***************************************************************************
                          spielfeldview.h  -  description
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

#ifndef SPIELFELDVIEW_H
#define SPIELFELDVIEW_H

#include <qcanvas.h>
#include <qevent.h>
#include <list>

class AbstractSpielElement;
class SpielfigurView;
class PDToGUIInterface;
class GUIToPDInterface;
class QTimer;
class PlayerListView;

class SpielFeldView : public QCanvasView
{
Q_OBJECT

public: 
	SpielFeldView(PlayerListView* plview, QCanvas * viewing=0, QWidget * parent=0, const char * name=0, WFlags f=0);
	~SpielFeldView();
	void moveXY(int id, int direction, int ax, int ay);
	void keyPressed(char key);
	void keyReleased(char key);
	void addBomb(int atx, int aty);
	void removeItem(int atx, int aty);
  void changeItem(int type, int tox, int toy);
  void drawFlamme(int atx, int aty);
  void newPlayer(int id, const char* name);
  void setDirection(int id, int direction);
  void drawWand(int x, int y);

  void removePlayer(int id);
  void showGame();
  void flushGame();

public slots:
  void timerDone();
	
private:
	QCanvas* _canvas;
	list<SpielfigurView*> _players;
	SpielfigurView* _player;
	GUIToPDInterface* _guitopdif;
	const char* _playername;
	int _direction;
  PlayerListView* _plview;

/*	QCanvasPixmapArray* _leftarray;
  QCanvasPixmapArray* _rightarray;
  QCanvasPixmapArray* _uparray;
  QCanvasPixmapArray* _downarray;*/

	QTimer* _timer;


//  SpielfigurView* figur;
};

#endif
