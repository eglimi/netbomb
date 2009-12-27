/***************************************************************************
                          gamehandler.cpp  -  description
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


#include "gamehandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "../networkmanager.h"
#include "playerhandler.h"

GameHandler::GameHandler(int fd, sockaddr_in& clientAddr)
{
  m_fd = fd;
  m_clientAddr = clientAddr;

  memcpy(&m_clientAddr, &clientAddr, sizeof(clientAddr));
  m_pReactor = Reactor::instance();
  m_pPlayerHandler = PlayerHandler::instance();
  m_pReactor->registerHandler(this, READ_EVENT);
  m_pPlayerHandler->registerPlayer(this);
  m_playerNumber = m_pPlayerHandler->getActivePlayer(this);
  m_pNetworkManager = NetworkManager::getNetworkManager();
}

GameHandler::~GameHandler()
{
  m_pReactor->release();
  m_pPlayerHandler->release();
  m_pNetworkManager->release();
}

int
GameHandler::getHandle() const
{
  return m_fd;
}

void
GameHandler::handleEvent(int fd, EventType eventType)
{
  if(eventType == READ_EVENT)
  {
    const int MAXLINE = 10000;

    static char buffer[10000];
    ssize_t nread;

    nread = read(fd, buffer, MAXLINE);
    if(nread == 0)
    {
      handleEvent(m_fd, CLOSE_EVENT);
    } else
    {
      m_pNetworkManager->informPD((char*)&buffer, m_playerNumber, nread);
    }
  }

  if(eventType == CLOSE_EVENT)
  {
    int state = close(m_fd);
    if(state == 0)
    {
      m_pReactor->removeHandler(this,READ_EVENT);
      m_pPlayerHandler->removePlayer(this);
      m_pNetworkManager->disconnect(m_playerNumber);
      delete this;
    }
  }
}

ssize_t
GameHandler::writeToClient(const char* str, size_t n)
{
  size_t nleft = n;
  ssize_t nwritten;
  const char* stringToWrite = 0;
  stringToWrite = str;
  while(nleft > 0)
  {
    if((nwritten = write(m_fd, stringToWrite, nleft)) <=0)
    {
      if(errno == EINTR)
      {
        nwritten = 0;
      } else
      {
        return -1;
      }
    }
    nleft -= nwritten;
    stringToWrite += nwritten;
  }
  return n;
}


