/***************************************************************************
                          clientthread.cpp  -  description
                             -------------------
    begin                : Mon Jun 17 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#include "clientthread.h"
#include "../network/client.h"


ClientThread::ClientThread(QMutex* runCli)
{
  runClient = runCli;
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
    client->readString();
  }
  cout << "exiting...";
}