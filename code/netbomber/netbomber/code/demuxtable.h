/***************************************************************************
                          demuxtable.h  -  description
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

#ifndef DEMUXTABLE_H
#define DEMUXTABLE_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

class EventHandler;

typedef unsigned int EventType;
enum{
  READ_EVENT = 01,
	ACCEPT_EVENT = 01,
	CLOSE_EVENT = 020
};


class DemuxTable {
public: 
	DemuxTable();
	~DemuxTable();
	
  void convert(fd_set& read_fds, fd_set& except_fds);
  void addEventHandler(int fd, EventHandler* pEventHandler, EventType eventType);
  void removeEventHandler(int fd);
  int getMaxFd();
  void demultiplex(int fdCount, fd_set& read_fds, fd_set& except_fds);

private:

	struct Tuple{
  	EventHandler* pEventHandler;
	 EventType eventType;
	};

	Tuple m_table[FD_SETSIZE];
	
	int m_maxFd;
};

#endif
