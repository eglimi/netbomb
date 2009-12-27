/***************************************************************************
                          pdtoguiinterface.h  -  description
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

#ifndef PDTOGUIINTERFACE_H
#define PDTOGUIINTERFACE_H

#include "spielfeldview.h"

//SINGLETON.. our first pattern. special thanks to GoF. :)

class PDToGUIInterface
{
public: 
	~PDToGUIInterface();
	bool movePlayer(int id, int direction, int tox, int toy);
	bool setItem(int type, int tox, int toy);
	static PDToGUIInterface* instance();
	void setSpielfeld(SpielFeldView* field);
	void newPlayer(int id, const char* name);
	void removePlayer(int id);
	void connConf();
	void beginGame();
	void endGame();
  void infoMsg(const char* message);
	
private:
 	PDToGUIInterface();
	SpielFeldView* _spielfeld;
	static PDToGUIInterface* _instance;
};

#endif
