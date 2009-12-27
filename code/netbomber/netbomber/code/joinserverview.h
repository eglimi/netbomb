/***************************************************************************
                          joinserverview.h  -  description
                             -------------------
    begin                : Fri May 27 2002
    copyright            : (C) 2002 by Stefan Kuenzle
    email                : skuenzle@hsr.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef JOINSERVERVIEW_H
#define JOINSERVERVIEW_H
#include "./generated/gjoinserverview.h"

class SpielView;

class JoinServerView : public gjoinserverform
{ 
    Q_OBJECT

public:
    JoinServerView( SpielView* spielview,
                    QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~JoinServerView();

public slots:
    void bCancelPressed();
    void bAnmeldenPressed();

private:
    SpielView* _spielview;

};

#endif // JOINSERVERVIEW_H
