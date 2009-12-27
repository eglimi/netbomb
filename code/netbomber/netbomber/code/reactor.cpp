/***************************************************************************
                          reactor.cpp  -  description
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


#include <assert.h>
#include <sys/select.h>
#include "reactor.h"
#include "eventhandler.h"

Reactor* Reactor::m_pInstance = 0;

Reactor*
Reactor::instance()
{
  if(m_pInstance == 0)
  {
    m_pInstance = new Reactor;
  }
  return m_pInstance;
}

Reactor::Reactor(){
}
Reactor::~Reactor(){
}

void
Reactor::registerHandler(EventHandler* pEventHandler, EventType eventType)
{
  m_demuxTable.addEventHandler(pEventHandler->getHandle(),  pEventHandler, eventType);
}

void
Reactor::removeHandler(EventHandler* pEventHandler, EventType eventType)
{
  m_demuxTable.removeEventHandler(pEventHandler->getHandle());
}

int
Reactor::handleEvents()
{
  struct timeval timeout = {0, 0};

  fd_set read_fds;
  fd_set except_fds;

  m_demuxTable.convert(read_fds, except_fds);

  int fdCount = select(m_demuxTable.getMaxFd() + 1,
                       &read_fds,
                       0,
                       &except_fds,
                       &timeout);

  if(fdCount > 0)
  {
    m_demuxTable.demultiplex(fdCount, read_fds, except_fds);
  }

  assert(fdCount != -1);
  return 1;
}

