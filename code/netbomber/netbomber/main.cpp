/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Wed Apr 24 2002
    copyright            : (C) 2002 by NetbomberGroup
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "ui/spielview.h"
#include "pd/spielmanager.h"
#include "global.h"


int main(int argc, char* argv[])
{
  SpielManager manager;

  QApplication netBombAppli(argc, argv);

  SpielView* _spielview = new SpielView();
  _spielview->setGeometry(50,50,800,600);

  netBombAppli.setMainWidget(_spielview);
  _spielview->show();

  int ret = netBombAppli.exec();

  delete _spielview;
  return ret;

}

