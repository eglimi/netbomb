/***************************************************************************
                          clientthread.cpp  -  description
                             -------------------
    begin                : Mon Jun 17 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "clientthread.h"
#include "../network/client.h"


ClientThread::ClientThread(QMutex* runCli, QMutex* pdMut)
  : runClient(runCli), pdMutex(pdMut)
{
}

ClientThread::~ClientThread()
{
}

void ClientThread::run()
{
  cout << "starting...";
  Client* client = Client::instance();
  while( runClient->locked() == true)
  {
    pdMutex->lock();
    client->readString();
    pdMutex->unlock();
    msleep(10);
  }
  client->release();
  cout << "exiting...";
}