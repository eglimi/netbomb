/***************************************************************************
                          serverview.h  -  description
                             -------------------
    begin                : Fri May 27 2002
    copyright            : (C) 2002 by S.Kuenzle
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SERVERVIEW_H
#define SERVERVIEW_H
#include "./generated/gserverview.h"

class SpielView;

class ServerView : public gserverform
{ 
    Q_OBJECT

public:
    ServerView( SpielView* spielview, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ServerView();

public slots:
    virtual void bStartenPressed();
    virtual void bCancelPressed();

private:
    SpielView* _spielview;

};

#endif // SERVERVIEW_H
