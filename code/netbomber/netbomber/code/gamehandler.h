/***************************************************************************
                          gamehandler.h  -  description
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

#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "eventhandler.h"

class Reactor;
class PlayerHandler;

class GameHandler : public EventHandler  {
public: 
	GameHandler(int fd, sockaddr_in& clientAddr);
	virtual ~GameHandler();
	virtual int getHandle() const;
	virtual void handleEvent(int fd, EventType eventType);
	ssize_t writeToClient(const char* str, size_t n);

private:
  int m_fd;
  int m_playerNumber;
  sockaddr_in m_clientAddr;
  Reactor* m_pReactor;
  PlayerHandler* m_pPlayerHandler;
};

#endif
