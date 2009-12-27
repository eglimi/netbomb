/***************************************************************************
                          playerlistview.cpp  -  description
                             -------------------
    begin                : Mon Jul 1 2002
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


#include "playerlistview.h"
#include <qlabel.h>
#include <qpalette.h>

PlayerListView::PlayerListView(QWidget* parent,  const char* name, WFlags fl )
: QWidget(parent, name, fl)
{
  playerbox = new QGroupBox( this, "playerbox" );
  playerbox->setGeometry( QRect( 10, 0, 220, 300 ) );
  playerbox->setTitle( tr( "Player List" ) );
  for ( int i=0; i < MAX_PLAYERS; i++)
  {
    players[i] = new QLabel(playerbox);
    players[i]->hide();
  }
}

PlayerListView::~PlayerListView()
{
  delete playerbox;
}

void PlayerListView::addPlayer(const char* name, int id)
{
//    QLabel* newplayer = new QLabel(playerbox);
    QLabel* newplayer = players[id-1];
    if (id==1)
    {
       newplayer->setGeometry( QRect( 20, 30, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(255,255,255));
    }
    else if (id==2)
    {
       newplayer->setGeometry( QRect( 20, 60, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(0,200,255));
    }
    else if (id==3)
    {
       newplayer->setGeometry( QRect( 20, 90, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(60,255,0));
    }
    else if (id==4)
    {
       newplayer->setGeometry( QRect( 20, 120, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(255,60,255));
    }
    QFont newplayer_font(  newplayer->font() );
    newplayer_font.setPointSize( 17 );
    newplayer->setFont( newplayer_font );
    newplayer->setText( tr( name));
    newplayer->show();
}

void PlayerListView::erasePlayer(int id)
{
  players[id-1]->hide();
}


