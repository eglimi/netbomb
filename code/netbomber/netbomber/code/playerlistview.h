/***************************************************************************
                          playerlistview.h  -  description
                             -------------------
    begin                : Mon Jul 1 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/


#ifndef PLAYERLISTVIEW_H
#define PLAYERLISTVIEW_H

#include <list>
#include <qwidget.h>
#include <qgroupbox.h>


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

};

#endif
