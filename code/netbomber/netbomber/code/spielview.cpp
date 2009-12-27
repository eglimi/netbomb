/***************************************************************************
                          spielview.cpp  -  description
                             -------------------
    begin                : Wed Apr 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#include "spielview.h"
#include "spielfeldview.h"
#include "joinserverview.h"
#include "serverview.h"
#include "spieloptview.h"
#include "pdtoguiinterface.h"
#include "playerlistview.h"
#include "../pd/guitopdinterface.h"
#include "../global.h"

SpielView::SpielView(QWidget *parent, const char *name )
: QWidget(parent,name), _player(NULL)
{
	_gamemenu = new QPopupMenu;
	_settingsmenu = new QPopupMenu;
	_networkmenu = new QPopupMenu;
	_gamemenu->insertItem(MENU_FILE_NEW, this, SLOT(slotGame()));
	_gamemenu->insertSeparator();
	_gamemenu->insertItem(MENU_FILE_QUIT, qApp, SLOT(quit()));
	_settingsmenu->insertItem(MENU_OPTIONS_KEYBOARD, this, SLOT(slotTastatur()));
	_networkmenu->insertItem(MENU_NETWORK_CREATE, this, SLOT(slotStartServer()));
	_networkmenu->insertItem(MENU_NETWORK_JOIN, this, SLOT(slotJoinServer()));
	_menubar = new QMenuBar(this);
	_menubar->insertItem(MENU_FILE, _gamemenu);
	_menubar->insertItem(MENU_NETWORK, _networkmenu);
	_menubar->insertItem(MENU_OPTIONS, _settingsmenu);
	
  _joinserverview = new JoinServerView(this);
  _serverview = new ServerView(this);
  _spieloptview = new SpielOpiView(this);

	_pdinterface = GUIToPDInterface::getInterface();

  _playerview = new PlayerListView(this);
  _playerview->setGeometry(QRect(530, 23, 240, 300 ));
  _playerview->show();

  _gamecanvas = new QCanvas(FIELD_WIDTH*FELD_WIDTH,FIELD_WIDTH*FELD_HEIGHT);
  //_gamecanvas->setAdvancePeriod(ADV_PERIOD);
  _gamecanvas->setBackgroundColor(QColor(Qt::yellow));
	_spielfeld = new SpielFeldView(_playerview, _gamecanvas, this);
	_spielfeld->setFixedSize(FIELD_WIDTH*FELD_WIDTH+5,FIELD_WIDTH*FELD_HEIGHT+5);
	_spielfeld->move(10,30);  //due to menu
  _spielfeld->show();

  PDToGUIInterface* pdinterface = PDToGUIInterface::instance();
  pdinterface->setSpielfeld(_spielfeld);
	
}
SpielView::~SpielView()
{
}

void SpielView::slotGame()
{
  _pdinterface->startGame();
}

SpielFeldView* SpielView::getSpielfeld() const
{
	return _spielfeld;
}

void SpielView::keyPressEvent(QKeyEvent* e)
{
  e->accept();
	
	switch(e->key())
	{
		case Key_Left:
		  _spielfeld->keyPressed(KEY_LEFT);
		  break;
		case Key_Right:
		  _spielfeld->keyPressed(KEY_RIGHT);
		  break;
		case Key_Down:
		  _spielfeld->keyPressed(KEY_DOWN);
		  break;
		case Key_Up:
		  _spielfeld->keyPressed(KEY_UP);
		  break;
		case Key_Space:
		  _spielfeld->keyPressed(KEY_BOMB);
		  break;
		default: e->ignore();
	}
}

void SpielView::keyReleaseEvent(QKeyEvent* e)
{
  e->accept();
	
	switch(e->key())
	{
	case Key_Left:
	  _spielfeld->keyReleased(KEY_LEFT);
	  break;
	case Key_Right:
	  _spielfeld->keyReleased(KEY_RIGHT);
	  break;
	case Key_Down:
	  _spielfeld->keyReleased(KEY_DOWN);
	  break;
	case Key_Up:
	  _spielfeld->keyReleased(KEY_UP);
	  break;
	case Key_Space:
		_spielfeld->keyReleased(KEY_BOMB);
		break;
	default: e->ignore();
	}
}

void SpielView::slotStartServer()
{
  _serverview->show();
}

void SpielView::slotJoinServer()
{
  _joinserverview->show();
}

void SpielView::slotTastatur()
{
  _spieloptview->show();
}

void SpielView::startServer()
{
  if(_player != NULL)
    _pdinterface->startServer(_player);
  else
    _pdinterface->startServer("anonymous");
}

void SpielView::joinServer(const char* ip)
{
  if(_player != NULL)
    _pdinterface->joinServer(ip, _player);
  else
    _pdinterface->joinServer(ip,"anonymous");
}

void SpielView::setPlayername(const char* name)
{
  _player = name;
}
