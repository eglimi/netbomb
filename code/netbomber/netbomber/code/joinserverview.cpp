/***************************************************************************
                          joinserverview.cpp  -  description
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

#include "joinserverview.h"
#include "spielview.h"
#include <qstring.h>
#include <qlineedit.h>

JoinServerView::JoinServerView( SpielView* spielview, QWidget* parent,  const char* name, WFlags fl )
    : gjoinserverform( parent, name, fl ), _spielview(spielview)
{
}


JoinServerView::~JoinServerView()
{
    // no need to delete child widgets, Qt does it all for us
}


void JoinServerView::bCancelPressed()
{
    hide();
}

void JoinServerView::bAnmeldenPressed()
{
  QString ipadress = IPAdressField->text();
  _spielview->joinServer(ipadress.latin1());
  hide();
}

