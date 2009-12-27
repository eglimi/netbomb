/***************************************************************************
                          clientthread.h  -  description
                             -------------------
    begin                : Mon Jun 17 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <qthread.h>


class ClientThread : public QThread  {
public: 
	ClientThread(QMutex* runCli, QMutex* pdMut);
	~ClientThread();

  virtual void run();

private:
  QMutex*  runClient;
  QMutex*  pdMutex;

};

#endif
