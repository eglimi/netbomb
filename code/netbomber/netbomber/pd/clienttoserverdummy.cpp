/***************************************************************************
                          clienttoserverdummy.cpp  -  description
                             -------------------
    begin                : Mon Apr 29 2002
    copyright            : (C) 2002 by U.Heimann
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "clienttoserverdummy.h"
#include "spielfigur.h"

#include "../global.h"

ClientToServerDummy::ClientToServerDummy(Spielfigur* fig) : figur(fig) {
}

ClientToServerDummy::~ClientToServerDummy(){
}

void ClientToServerDummy::setDirection(int dir){
  //cout << "C2SDummy: setDirection(" << dir << ");" << endl;
  figur->setDirection(dir);
}

void ClientToServerDummy::setBombPressed(bool bomb){
  //cout << "C2SDummy: setBombPressed(" << bomb << ");" << endl;
  figur->setBombPressed(bomb);
}
