/***************************************************************************
                          client.h  -  description
                             -------------------
    begin                : Wed May 1 2002
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

#ifndef CLIENT_H
#define CLIENT_H
#include <sys/socket.h>
#include "../global.h"

class Client {
public: 
	~Client();
	int makeConnection(const char* strPtr);
	ssize_t writeString(const char* str, size_t n);
	ssize_t readString();
	static Client* instance();
	void close();

private:
  Client();
  int m_fd;
  int m_port;
  static Client* m_pInstance;
};

#endif
