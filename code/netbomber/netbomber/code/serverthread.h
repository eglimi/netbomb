/***************************************************************************
                          serverthread.h  -  description
                             -------------------
    begin                : Mon Jun 17 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <qthread.h>



class ServerThread : public QThread  {
public: 
	ServerThread(QMutex* runServ);
	~ServerThread();

  virtual void run();

private:
  QMutex*  runServer;
};

#endif
