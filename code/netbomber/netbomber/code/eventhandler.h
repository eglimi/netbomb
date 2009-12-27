/***************************************************************************
                          eventhandler.h  -  description
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

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "reactor.h"

class EventHandler {
public: 
	virtual void handleEvent(int fd, EventType eventType) = 0;
	virtual int getHandle() const = 0;
};

#endif
