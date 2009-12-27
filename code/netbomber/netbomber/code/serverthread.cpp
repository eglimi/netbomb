/***************************************************************************
                          serverthread.cpp  -  description
                             -------------------
    begin                : Mon Jun 17 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "serverthread.h"
#include "../network/reactor/connectionacceptor.h"
#include "../network/reactor/reactor.h"
#include "../global.h"


ServerThread::ServerThread(QMutex* runServ)
{
  runServer = runServ;
}

ServerThread::~ServerThread()
{
}

void ServerThread::run()
{
  cout << "starting...";
  {
    ConnectionAcceptor myCA;
    myCA.listen();
    Reactor* reactor = Reactor::instance();
    while(runServer->locked() == true)
    {
      reactor->handleEvents();
    }
  }
  cout << "exiting...";
}