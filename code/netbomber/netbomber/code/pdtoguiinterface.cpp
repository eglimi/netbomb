/***************************************************************************
                          pdtoguiinterface.cpp  -  description
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

#include "pdtoguiinterface.h"
#include <qmessagebox.h>
#include <assert.h>

PDToGUIInterface* PDToGUIInterface::_instance = NULL;

PDToGUIInterface::PDToGUIInterface()
{
  _spielfeld = NULL;
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
	
	return _instance;
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
  assert(field != NULL);
	_spielfeld = field;
}

void PDToGUIInterface::newPlayer(int id, const char* name)
{
  _spielfeld->newPlayer(id, name);
}

void PDToGUIInterface::removePlayer(int id)
{
  _spielfeld->removePlayer(id);
}

void PDToGUIInterface::connConf()
{
  infoMsg("Erfolgreich an Server angemeldet!");
}

void PDToGUIInterface::beginGame()
{
  _spielfeld->showGame();
}

void PDToGUIInterface::endGame()
{
  //_spielfeld->flushGame();
}

void PDToGUIInterface::infoMsg(const char* message)
{
  QMessageBox::information( 0, "netbomber",message);
}


