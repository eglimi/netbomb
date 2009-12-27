/***************************************************************************
                          connectionacceptor.h  -  description
                             -------------------
    begin                : Sat Apr 27 2002
    copyright            : (C) 2002 by M.Egli
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#ifndef CONNECTIONACCEPTOR_H
#define CONNECTIONACCEPTOR_H

#include "eventhandler.h"
#include "gamehandler.h"

class ConnectionAcceptor : public EventHandler  {
public: 
	ConnectionAcceptor();
	virtual ~ConnectionAcceptor();
	virtual void handleEvent(int fd, EventType eventType);
	virtual int getHandle() const;
	void listen();

private:
  int m_fd;
  int m_port;
  Reactor* m_pReactor;
};

#endif
