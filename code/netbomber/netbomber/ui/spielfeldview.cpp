/***************************************************************************
                          spielfeldview.cpp  -  description
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
  }
  for(i=0; i<= FELD_WIDTH-1; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,i,FELD_HEIGHT-1);  // bottom walls
  }
  for(i=1; i<= FELD_HEIGHT-2; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,0,i); // left walls
  }
  for(i=1; i<= FELD_HEIGHT-2; i++)
  {
  	MauerView* amauer = new MauerView(_canvas,FELD_WIDTH-1,i); // right walls
  }
  for(i=0; i<= NR_VERT_MAUERN-1; i++)
  {
    for(j=0; j<=NR_HORI_MAUERN-1; j++)
    {
  		MauerView* amauer = new MauerView(_canvas,2+2*i,2+2*j);
   	}
  }

  //get the interface instances
  _guitopdif = GUIToPDInterface::getInterface();

  _timer = new QTimer();



}

SpielFeldView::~SpielFeldView()
{
  _guitopdif->release();
  delete _timer;
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

  setDirection(id, direction);
  list<SpielfigurView*>::iterator iter;
  for(iter=_players.begin(); iter!=_players.end(); ++iter)
  {
    if( ((*iter)->getID()) == id)
    {
      if ( ax == 0 )
      {
        (*iter)->hide();
      }
      else
      {
        (*iter)->moveXY(ax, ay);
      }
    }
  }	
  _canvas->setAllChanged();
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
//  cout << "SpielFeldView::drawWand(" << x << "," << y << ");" << endl;
}

void SpielFeldView::removeItem(int atx, int aty)
{
//  cout << "removeItem(" << atx << "," << aty << ");" << endl;
  QCanvasItemList list = canvas()->allItems();
  QCanvasItemList::Iterator it = list.begin();
  for(; it != list.end(); ++it)
  {
     if( ((*it)->x() == atx*FIELD_WIDTH) && ((*it)->y() == aty*FIELD_WIDTH)
         && ((*it)->rtti() != RTTI_FIGUR) && ((*it)->rtti() != RTTI_FLAMME))
    {
      delete (*it);
    }
  }
}

void SpielFeldView::addBomb(int atx, int aty)
{
  BombenView* bombe = new BombenView(_canvas, atx, aty);
  bombe->show();
  _canvas->setAllChanged();
  _canvas->update();
}

void SpielFeldView::drawFlamme(int atx, int aty)
{
  FlammenView* flamme = new FlammenView(_canvas, atx, aty);
  flamme->show();
  _canvas->update();
  QObject::connect( _timer, SIGNAL(timeout()), this, SLOT(timerDone()) );
  _timer->start( 150, TRUE );
}

void SpielFeldView::timerDone()
{
  QCanvasItemList list = canvas()->allItems();
  QCanvasItemList::Iterator it = list.begin();
  for(; it != list.end(); ++it)
  {
    if((*it)->rtti() == RTTI_FLAMME)
    {
      (*it)->hide();
      _canvas->update();
      delete (*it);
    }
  }
}

void SpielFeldView::newPlayer(int id, const char* name)
{
  _plview->addPlayer(name, id);
  int ax, ay;
  switch(id)
  {
  case 1:
    ax=1;
    ay=1;
    break;
  case 2:
    ax=FELD_WIDTH-1;
    ay=FELD_HEIGHT-1;
    break;
  case 3:
    ax=1;
    ay=FELD_HEIGHT-1;
    break;
  case 4:
    ax=FELD_WIDTH-1;
    ay=1;
     break;
  }

  SpielfigurView* figur = new SpielfigurView(_canvas, ax, ay, id, name);
  _players.push_back(figur);
}

void SpielFeldView::removePlayer(int id)
{
  _plview->erasePlayer(id);
/*  list<SpielfigurView*>::iterator iter;
  for(iter=_players.begin(); iter!=_players.end(); ++iter)
  {
    if( ((*iter)->getID()) == id)
    {
      delete (*iter);
      _players.erase(iter);
    }
  }
*/
}

void SpielFeldView::showGame()
{
  QCanvasItemList list = canvas()->allItems();
  QCanvasItemList::Iterator it = list.begin();
  for(; it != list.end(); ++it)
  {
    (*it)->show();
  }

  _canvas->setAllChanged();
  _canvas->update();
}

void SpielFeldView::flushGame()
{
}

void SpielFeldView::setDirection(int id, int direction)
{
    list<SpielfigurView*>::iterator it;
    for(it=_players.begin(); it!=_players.end(); ++it)
    {
      if((*it)->getID() == id)
        _player = (*it);
    }
    _player->setDirection(direction);
}