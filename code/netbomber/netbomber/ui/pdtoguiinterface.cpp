/***************************************************************************
                          pdtoguiinterface.cpp  -  description
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

#include "pdtoguiinterface.h"
#include <qmessagebox.h>
#include <assert.h>
#include "../global.h"

PDToGUIInterface* PDToGUIInterface::_instance = NULL;

PDToGUIInterface::PDToGUIInterface()
{
  _spielfeld = NULL;
  _rCount = 0;
}
PDToGUIInterface::~PDToGUIInterface()
{
}

PDToGUIInterface* PDToGUIInterface::instance()
{
	if(_instance == NULL)
	{
		_instance = new PDToGUIInterface();
	}
	_instance->_rCount++;
	return _instance;
}

void PDToGUIInterface::release()
{
  _rCount--;
  if ( _rCount == 0 )
  {
    _instance = NULL;
    delete this;
  }
}

bool PDToGUIInterface::movePlayer(int id, int direction, int tox, int toy)
{
   assert(_spielfeld != NULL);
	 _spielfeld->moveXY(id, direction, tox, toy);
	 return true;
}

bool PDToGUIInterface::setItem(int type, int tox, int toy)
{
  assert(_spielfeld != NULL);
	_spielfeld->changeItem(type, tox, toy);
	return true;
}

void PDToGUIInterface::setSpielfeld(SpielFeldView* field)
{
//  assert(field != NULL);
	_spielfeld = field;
}

void PDToGUIInterface::newPlayer(int id, const char* name)
{
  assert(_spielfeld != NULL);
  _spielfeld->newPlayer(id, name);
}

void PDToGUIInterface::removePlayer(int id)
{
  assert(_spielfeld != NULL);
  _spielfeld->removePlayer(id);
}

void PDToGUIInterface::connConf()
{
  infoMsg(MSG_CONNECTED);
}

void PDToGUIInterface::beginGame()
{
  assert(_spielfeld != NULL);
  _spielfeld->showGame();
}

void PDToGUIInterface::endGame()
{
  //assert(_spielfeld != NULL);
  //_spielfeld->flushGame();
}

void PDToGUIInterface::infoMsg(const char* message)
{
  QMessageBox::information( 0, "netbomber",message);
}


