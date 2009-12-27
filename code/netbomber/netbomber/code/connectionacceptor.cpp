/***************************************************************************
                          connectionacceptor.cpp  -  description
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

#include "connectionacceptor.h"
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include "playerhandler.h"

ConnectionAcceptor::ConnectionAcceptor()
{
  m_fd = 0;
  m_port = 12210;

  m_pReactor = Reactor::instance();

}
ConnectionAcceptor::~ConnectionAcceptor()
{
  m_pReactor->removeHandler(this, ACCEPT_EVENT);
  delete PlayerHandler::instance();
  delete m_pReactor;
}

//creates a listening socket
void
ConnectionAcceptor::listen()
{
  sockaddr_in serverAddr;
  bzero(&serverAddr, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddr.sin_port = htons(m_port);

  m_fd = socket(AF_INET, SOCK_STREAM, 0);

  bind(m_fd, (sockaddr*) &serverAddr, sizeof(serverAddr));

  ::listen(m_fd, m_port);

  m_pReactor->registerHandler(this, ACCEPT_EVENT);

}

//if connection request from a client arrives, accept connection
//and create a new GameHandler (one per connected player)
void
ConnectionAcceptor::handleEvent(int fd, EventType eventType)
{
  if(eventType == ACCEPT_EVENT)
  {
    sockaddr_in clientAddr;
    unsigned int addrLen = sizeof(clientAddr);
    int clientFd = accept(m_fd, (sockaddr*) &clientAddr, &addrLen);
    GameHandler* handler = new GameHandler(clientFd, clientAddr);
  }
}

int
ConnectionAcceptor::getHandle() const
{
  return m_fd;
}
