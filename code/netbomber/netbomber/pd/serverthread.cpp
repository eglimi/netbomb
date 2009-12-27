/***************************************************************************
                          serverthread.cpp  -  description
                             -------------------
    begin                : Mon Jun 17 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/



#include "serverthread.h"
#include "../network/reactor/connectionacceptor.h"
#include "../network/reactor/reactor.h"
#include "../global.h"


ServerThread::ServerThread(QMutex* runServ, QMutex* pdMut)
  : runServer(runServ), pdMutex(pdMut)
{
}

ServerThread::~ServerThread()
{
}

void ServerThread::run()
{
  {
    ConnectionAcceptor myCA;
    myCA.listen();
    Reactor* reactor = Reactor::instance();
    while(runServer->locked() == true)
    {
      pdMutex->lock();
      reactor->handleEvents();
      pdMutex->unlock();
      msleep(SERVER_WAIT_TIME);
    }
    reactor->release();
  }
}