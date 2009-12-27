/***************************************************************************
                          demuxtable.cpp  -  description
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


#include "demuxtable.h"
#include "sys/select.h"
#include "eventhandler.h"

DemuxTable::DemuxTable()
{
  m_maxFd = 0;

  for(int i = 0; i < FD_SETSIZE; i++)
  {
    m_table[i].eventType = 0;
    m_table[i].pEventHandler = 0;
  }
}
DemuxTable::~DemuxTable(){
}

void
DemuxTable::convert(fd_set& read_fds, fd_set& except_fds)
{
  EventType eventType = 0;

  FD_ZERO(&read_fds);
  FD_ZERO(&except_fds);

  for(int i = 0; i < FD_SETSIZE; i++)
  {
    if(m_table[i].pEventHandler == 0)
    {
      continue;
    }
    eventType = m_table[i].eventType;

    if(eventType & READ_EVENT)
    {
      FD_SET(i, &read_fds);
    }

    if(eventType & ACCEPT_EVENT)
    {
      FD_SET(i, &read_fds);
    }

    if(eventType & CLOSE_EVENT)
    {
      FD_SET(i, &except_fds);
    }
  }
}


void
DemuxTable::addEventHandler(int fd, EventHandler* pEventHandler, EventType eventType)
{
  m_table[fd].pEventHandler = pEventHandler;
  m_table[fd].eventType |= eventType;

  if(fd > m_maxFd)
  {
    m_maxFd = fd;
  }

}

int
DemuxTable::getMaxFd()
{
  return m_maxFd;
}

void
DemuxTable::removeEventHandler(int fd)
{
  m_table[fd].pEventHandler = 0;
  m_table[fd].eventType = 0;
}

void
DemuxTable::demultiplex(int fdCount, fd_set& read_fds, fd_set& except_fds)
{
  for(int i = 0; i < FD_SETSIZE && fdCount > 0; ++i)
  {
    if(m_table[i].pEventHandler == 0)
    {
      continue;
    }
    if(FD_ISSET(i, &read_fds) && (m_table[i].eventType & READ_EVENT))
    {
      m_table[i].pEventHandler->handleEvent(i, READ_EVENT);
      fdCount -= 1;
    }

    if(FD_ISSET(i, &except_fds) && (m_table[i].eventType & CLOSE_EVENT))
    {
      m_table[i].pEventHandler->handleEvent(i, CLOSE_EVENT);
      fdCount -= 1;
    }
  }
}


