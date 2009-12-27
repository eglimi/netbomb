/***************************************************************************
                          serverthread.h  -  description
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


#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <qthread.h>



class ServerThread : public QThread  {
public: 
	ServerThread(QMutex* runServ, QMutex* pdMut);
	~ServerThread();

  virtual void run();

private:
  QMutex*  runServer;
  QMutex*  pdMutex;

};

#endif
