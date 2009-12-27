/***************************************************************************
                          reactor.h  -  description
                             -------------------
    begin                : Sat Apr 27 2002
    copyright            : (C) 2002 by 
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef REACTOR_H
#define REACTOR_H
#include "demuxtable.h"

class EventHandler;


class Reactor {
public: 
	~Reactor();
	void registerHandler(EventHandler* pEventHandler, EventType eventType);
	void removeHandler(EventHandler* pEventHandler, EventType eventType);
	int handleEvents();
	static Reactor* instance();
private:
	Reactor();
	static Reactor* m_pInstance;
	DemuxTable m_demuxTable;
	
};

#endif
