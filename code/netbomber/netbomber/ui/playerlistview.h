/***************************************************************************
                          playerlistview.h  -  description
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


#ifndef PLAYERLISTVIEW_H
#define PLAYERLISTVIEW_H

#include <list>
#include <qwidget.h>
#include <qgroupbox.h>
#include "../global.h"

class QLabel;

class PlayerListView : public QWidget
{
public: 
	PlayerListView(QWidget* parent=0,  const char* name=0, WFlags fl=0);
	~PlayerListView();
  void addPlayer(const char* name, int id);
  void erasePlayer(int id);
private:
  list<int> playerIDs;
  QGroupBox* playerbox;
  QLabel*    players[MAX_PLAYERS];

};

#endif
