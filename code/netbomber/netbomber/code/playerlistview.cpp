/***************************************************************************
                          playerlistview.cpp  -  description
                             -------------------
    begin                : Mon Jul 1 2002
    copyright            : (C) 2002 by U.Heimann
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
}

PlayerListView::~PlayerListView()
{
}

void PlayerListView::addPlayer(const char* name, int id)
{
    QLabel* newplayer = new QLabel(playerbox);
    if (id==1)
    {
       newplayer->setGeometry( QRect( 20, 30, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(123,123,23));
    }
    else if (id==2)
    {
       newplayer->setGeometry( QRect( 20, 60, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(123,23,23));
    }
    else if (id==3)
    {
       newplayer->setGeometry( QRect( 20, 90, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(123,123,232));
    }
    else if (id==4)
    {
       newplayer->setGeometry( QRect( 20, 120, 180, 20 ) );
       newplayer->setBackgroundColor(QColor(12,223,23));
    }
    QFont newplayer_font(  newplayer->font() );
    newplayer_font.setPointSize( 17 );
    newplayer->setFont( newplayer_font );
    newplayer->setText( tr( name));
    newplayer->show();
}

void PlayerListView::erasePlayer(int id)
{
}


