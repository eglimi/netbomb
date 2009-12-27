/***************************************************************************
                          spielfeldview.cpp  -  description
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

#include <qimage.h>
#include <qtimer.h>

#include "spielfeldview.h"
#include "mauerview.h"
#include "wandview.h"
#include "bombenview.h"
#include "flammenview.h"
#include "spielfigurview.h"
#include "spielview.h"
#include "playerlistview.h"
#include "../pd/guitopdinterface.h"
#include "../global.h"





SpielFeldView::SpielFeldView(PlayerListView* plview, QCanvas * viewing, QWidget * parent, const char * name, WFlags f)
: QCanvasView(viewing,parent,name,f), _canvas(viewing), _playername(NULL), _direction(STAY), _plview(plview)
{
  int i,j;

  for(i=0; i<= FELD_WIDTH-1; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,i,0); //top walls
  	amauer->show();
  }
  for(i=0; i<= FELD_WIDTH-1; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,i,FELD_HEIGHT-1);  // bottom walls
  	amauer->show();
  }
  for(i=1; i<= FELD_HEIGHT-2; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,0,i); // left walls
  	amauer->show();
  }
  for(i=1; i<= FELD_HEIGHT-2; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,FELD_WIDTH-1,i); // right walls
  	amauer->show();
  }
  for(i=0; i<= NR_VERT_MAUERN-1; i++)
  {
    for(j=0; j<=NR_HORI_MAUERN-1; j++)
    {
  		MauerView* amauer = new MauerView(_canvas,2+2*i,2+2*j);
  	  amauer->show();
  	}
  }

  //get the interface instances
  _guitopdif = GUIToPDInterface::getInterface();

  _timer = new QTimer();

  cout << "Constructor SpielFeldView" << endl;

 /* _rightarray = new QCanvasPixmapArray();
  _rightarray->readPixmaps("/home/urs/netbomber/netbomber/ui/generated/right%3.png",3);
  _leftarray = new QCanvasPixmapArray();
  _leftarray->readPixmaps("/home/urs/netbomber/netbomber/ui/generated/left%3.png",3);
  _uparray = new QCanvasPixmapArray();
  _uparray->readPixmaps("/home/urs/netbomber/netbomber/ui/generated/up%3.png",3);
  _downarray = new QCanvasPixmapArray();
  _downarray->readPixmaps("/home/urs/netbomber/netbomber/ui/generated/down%3.png",3);*/
}

SpielFeldView::~SpielFeldView()
{
  cout << "Destructor SpielFeldView" << endl;
}
	
void SpielFeldView::keyPressed(char key)
{	
  _guitopdif->keyPressed(key);
}

void SpielFeldView::keyReleased(char key)
{
  _guitopdif->keyReleased(key);
}

void SpielFeldView::moveXY(int id, int direction, int ax, int ay)
{
  list<SpielfigurView*>::iterator iter;
  cout << "Moving Player with ID: " << id << endl;
  cout << "GUI Playerlist.size: " << _players.size() << endl;
  for(iter=_players.begin(); iter!=_players.end(); ++iter)
  {
    if( ((*iter)->getID()) == id)
    {
      (*iter)->moveXY(ax, ay);
    }
  }	
  _canvas->update();

}

void SpielFeldView::changeItem(int type, int tox, int toy)
{

  switch(type)
  {
    case FREI:
      removeItem(tox,toy);
      break;
    case BOMBE:
      addBomb(tox,toy);
      break;
    case EXPLOSION:
      drawFlamme(tox,toy);
      break;
    case WAND:
      drawWand(tox,toy);
    default:
      break;
  }
}

void SpielFeldView::drawWand(int x, int y)
{
  WandView* wand = new WandView(_canvas, x, y);
  cout << "SpielFeldView::drawWand(" << x << "," << y << ");" << endl;
// wand->show();
}

void SpielFeldView::removeItem(int atx, int aty)
{
  QCanvasItemList list = canvas()->allItems();
  QCanvasItemList::Iterator it = list.begin();
  for(; it != list.end(); ++it)
  {
    if( ((*it)->x() == atx*FIELD_WIDTH) && ((*it)->y() == aty*FIELD_WIDTH) && ((*it)->rtti() != RTTI_FIGUR))
      delete (*it);
  }
  _canvas->update();
}

void SpielFeldView::addBomb(int atx, int aty)
{
  BombenView* bombe = new BombenView(_canvas, atx, aty);
  bombe->show();
  _canvas->update();
}

void SpielFeldView::drawFlamme(int atx, int aty)
{
  FlammenView* flamme = new FlammenView(_canvas, atx, aty);
  flamme->show();
  _canvas->update();
  QObject::connect( _timer, SIGNAL(timeout()), this, SLOT(timerDone()) );
  _timer->start( 100, TRUE );
}

void SpielFeldView::timerDone()
{
  QCanvasItemList list = canvas()->allItems();
  QCanvasItemList::Iterator it = list.begin();
  for(; it != list.end(); ++it)
  {
    if((*it)->rtti() == RTTI_FLAMME)
      delete (*it);
  }
  _canvas->update();
}

void SpielFeldView::newPlayer(int id, const char* name)
{
  _plview->addPlayer(name, id);
  QColor col;
  cout << "Adding a new player." << endl;
  int ax, ay;
  switch(id)
  {
  case 1:
    ax=1;
    ay=1;
    col.setRgb(123,123,23);
    break;
  case 2:
    ax=FELD_WIDTH-1;
    ay=FELD_HEIGHT-1;
    col.setRgb(123,23,23);
    break;
  case 3:
    ax=1;
    ay=FELD_HEIGHT-1;
    col.setRgb(123,123,232);
    break;
  case 4:
    ax=FELD_WIDTH-1;
    ay=1;
    col.setRgb(12,223,23);
    break;
  }

  cout << "GUI Playerlist.size: " << _players.size() << endl;
  SpielfigurView* figur = new SpielfigurView(/*_rightarray,*/ _canvas, ax, ay, id, name);
  figur->setBrush(col);
  _players.push_back(figur);

  cout << "GUI Playerlist.size: " << _players.size() << endl;
}

void SpielFeldView::removePlayer(int id)
{
  list<SpielfigurView*>::iterator iter;
  for(iter=_players.begin(); iter!=_players.end(); ++iter)
  {
    if( ((*iter)->getID()) == id)
      _players.erase(iter);
  }
}

void SpielFeldView::showGame()
{
  cout << "SpielFeldView::showGame()" << endl;

 /* list<SpielfigurView*>::iterator itp;
  for(itp=_players.begin(); itp!=_players.end(); ++itp)
    (*itp)->show();*/

  QCanvasItemList list = canvas()->allItems();
  QCanvasItemList::Iterator it = list.begin();
  for(; it != list.end(); ++it)
  {
    (*it)->show();
  }


  _canvas->update();


 // list<SpielfigurView*>::iterator it;
 // for(it=_players.begin(); it!=_players.end(); ++it)
 // {
  //  (*it)->show();
 // }

}

void SpielFeldView::flushGame()
{
}

void SpielFeldView::setDirection(int id, int direction)
{
 /*   list<SpielfigurView*>::iterator it;
    cout << "GUI Playerlist.size: " << _players.size() << endl;
    for(it=_players.begin(); it!=_players.end(); ++it)
    {
      if((*it)->getID() == id)
        _player = (*it);
    }
    switch(direction)
    {
    case UP:
      //  _player->setSequence(_uparray);
      break;
    case DOWN:
      //_player->setSequence(_downarray);
      break;
    case LEFT:
      //_player->setSequence(_leftarray);
      break;
    case RIGHT:
      //_player->setSequence(_rightarray);
      break;
   // case STAY:
    //  _player->setFrame(1);
     // break;
    default:
      break;
    }
    _player->show();     */
}