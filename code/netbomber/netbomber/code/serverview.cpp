/***************************************************************************
                          serverview.cpp  -  description
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

#include "serverview.h"
#include "spielview.h"

/* 
 *  Constructs a ServerView which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
ServerView::ServerView( SpielView* spielview, QWidget* parent,  const char* name, WFlags fl )
    : gserverform( parent, name, fl ), _spielview(spielview)
{
}

/*  
 *  Destroys the object and frees any allocated resources
 */
ServerView::~ServerView()
{
    // no need to delete child widgets, Qt does it all for us
}

void ServerView::bStartenPressed()
{
  _spielview->startServer();
  hide();
}

void ServerView::bCancelPressed()
{
  hide();
}

