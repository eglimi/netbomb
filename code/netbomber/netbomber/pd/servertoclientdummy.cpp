/***************************************************************************
                          servertoclientdummy.cpp  -  description
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

#include "servertoclientdummy.h"
#include "spielfeldclient.h"

#include "../global.h"

ServerToClientDummy::ServerToClientDummy(SpielfeldClient* feld) : clientFeld(feld){
}

ServerToClientDummy::~ServerToClientDummy(){
}

void ServerToClientDummy::setItem(Position pos, int item){
  //cout << "S2CDummy: setField(" << pos.x << ", " << pos.y << ", " << item << ");" << endl;
  clientFeld->setField(pos, item);

}

void ServerToClientDummy::setPlayer(Position pos){
  //cout << "S2CDummy: setPlayer(" << pos.x << ", " << pos.y << ");" << endl;
  clientFeld->setPlayer(0, pos);

}

void ServerToClientDummy::explode(Position pos, int reichweite)
{
  //cout << "ServerToClient::explode( pos, " << reichweite << ")" << endl;
  clientFeld->explode(pos, reichweite);
}

void ServerToClientDummy::sendAll()
{
//  clientFeld->printToConsole();
//  clientFeld->clearFire();
}