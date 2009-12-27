/***************************************************************************
                          client.cpp  -  description
                             -------------------
    begin                : Wed May 1 2002
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


#include "client.h"
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "networkmanager.h"
#include <signal.h>

static void connectAlarm(int signo);

Client* Client::m_pInstance = 0;

Client*
Client::instance()
{
  if(m_pInstance == 0)
  {
    m_pInstance = new Client;
  }
  m_pInstance->m_rCount++;
  return m_pInstance;
}


Client::Client()
{
  m_fd = 0;
  m_port = 12210;
  m_rCount = 0;
}

Client::~Client()
{
}

void
Client::release()
{
  m_rCount--;
  if ( m_rCount == 0 )
  {
     m_pInstance = NULL;
     delete this;
  }
}

//opens a tcp connection to a server with ip = strPtr
int
Client::makeConnection(const char* strPtr)
{
  const int CONN_TIMEOUT = 10;
  sockaddr_in serverAddr;
  int n = 0;

  m_fd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&serverAddr, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(m_port);
  inet_pton(AF_INET, strPtr, &serverAddr.sin_addr);

  //make connection and if host is not reachable, return error after
  //10 seconds by calling connectAlarm() and close connection.
  Sigfunc* sigfunc;
  sigfunc = signal(SIGALRM, connectAlarm);
  if(alarm(CONN_TIMEOUT) != 0)
  {
    return -1;
  }
  if ((n = connect(m_fd, (sockaddr*) &serverAddr, sizeof(serverAddr))) < 0)
  {
    close();
    if(errno == EINTR)
    {
      errno = ETIMEDOUT;
    }
  }
  alarm(0);                //turn off alarm
  signal(SIGALRM,sigfunc); //restore previous signal handler

  return n;
}

//writes any string to connected server
ssize_t
Client::writeString(const char* str, size_t n)
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

//reads strings from server and passes string to pd
ssize_t
Client::readString()
{
  const int MAXLINE = 10000;

  static char buffer[10000];
  ssize_t nread;

  struct timeval timeout = {0, 0};

  fd_set read_fds;
  FD_ZERO(&read_fds);
  FD_SET(m_fd, &read_fds);

  int fdCount = select(m_fd + 1,
                       &read_fds,
                       0,
                       0,
                       &timeout);
  if(fdCount > 0)
  {
    nread = read(m_fd, buffer, MAXLINE);
    if(nread > 0)
    {
      NetworkManager* netMan = NetworkManager::getNetworkManager();
      netMan->informPD((char*)&buffer, 42, nread);
      netMan->release();
    }
  }

  return nread;
}

//closes tcp connection
void
Client::close()
{
//  cout << "Close client Socket: " << m_fd << endl;
  ::close(m_fd);
}

//if connection can't be established, exit the connection attempt
//and close fd.
static void
connectAlarm(int signo)
{
  Client* myClient = Client::instance();
  myClient->close();
  myClient->release();
  return;
}

