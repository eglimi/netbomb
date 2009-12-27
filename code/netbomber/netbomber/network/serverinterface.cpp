/***************************************************************************
                          serverinterface.cpp  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by R.Herrmann
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "serverinterface.h"
#include "../global.h"
#include <iostream>
#include "stringconverter.h"
#include "networkmanager.h"
// reichweite begrenzt auf 255
// position.x begrenzt auf 255
// position.y begrenzt auf 255
// PlayerID begrenzt auf 255

ServerInterface* ServerInterface::m_pServerInterface = 0;

ServerInterface*
ServerInterface::getServerInterface()
{
  if(m_pServerInterface == 0)
  {
    m_pServerInterface = new ServerInterface;
  }
  m_pServerInterface->m_rCount++;
  return m_pServerInterface;
}

ServerInterface::ServerInterface()
{
  m_pStringConverter = StringConverter::getStringConverter();
  m_pNetworkManager = NetworkManager::getNetworkManager();
  m_rCount = 0;
};

ServerInterface::~ServerInterface()
{
  m_pStringConverter->release();
  m_pNetworkManager->release();
};

void
ServerInterface::release()
{
  m_rCount--;
  if ( m_rCount == 0 )
  {
    m_pServerInterface = NULL;
    delete this;
  }
}

void
ServerInterface::setItem(Position _pos,int spielelement)
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( SET_ITEM );
  netMsg +=	m_pStringConverter->position2String(_pos);
	
	string s_elem=m_pStringConverter->int2hexString( spielelement );
  netMsg +=	m_pStringConverter->leftTrim(s_elem,2);
	m_pNetworkManager->addMessage( netMsg );
}


void
ServerInterface::setPlayer(int playerID,Position _pos)
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( SET_PLAYER );
  netMsg +=	m_pStringConverter->playerID2String( playerID );
  netMsg +=	m_pStringConverter->position2String( _pos );
	m_pNetworkManager->addMessage( netMsg );
}

void
ServerInterface::delPlayer(int playerID)
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( DEL_PLAYER );
  netMsg +=	m_pStringConverter->playerID2String( playerID );
	m_pNetworkManager->addMessage( netMsg );
}

void
ServerInterface::explode(Position _pos,int reichweite)
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( EXPLODE );
  netMsg +=	m_pStringConverter->position2String(_pos);

	string s_distance=m_pStringConverter->int2hexString( reichweite );
  netMsg +=	m_pStringConverter->leftTrim(s_distance,2);

	m_pNetworkManager->addMessage( netMsg );
}

void
ServerInterface::setPlayfield(vector<int> feldinfo,int zeilenbreite)
{
	string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( SET_PLAYFIELD );
  netMsg +=	m_pStringConverter->int2hexString( feldinfo.size() );
  netMsg +=	"/";
  netMsg +=	m_pStringConverter->int2hexString( zeilenbreite );
  netMsg +=	"/";
	vector<int>::iterator pos;
	for(pos=feldinfo.begin();pos<feldinfo.end();++pos)
	{
		netMsg +=	m_pStringConverter->int2hexString( *pos );
	  netMsg +=	"/";
	}
	m_pNetworkManager->addMessage( netMsg );
}

void
ServerInterface::sendAll()
{
	m_pNetworkManager->sendServerData();
}

void
ServerInterface::run()
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( RUN );
	m_pNetworkManager->addMessage( netMsg );
}

void
ServerInterface::endGame()
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( END_GAME );
	m_pNetworkManager->addMessage( netMsg );
}

void
ServerInterface::disconnect()
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( SERVER_DISCONNECT );
	m_pNetworkManager->addMessage( netMsg );
  m_pNetworkManager->disconnect();
}

void
ServerInterface::setPlayerName(int playerID,string _name)
{
	if (_name.size()>255) _name.resize(255);
	string netMsg;
	string size;
	netMsg=m_pStringConverter->int2hexString(SET_NAME);
  netMsg +=	m_pStringConverter->playerID2String( playerID );
	size=m_pStringConverter->int2hexString(_name.size());
	netMsg+=m_pStringConverter->leftTrim(size,2);
	netMsg+=_name;
	m_pNetworkManager->addMessage(netMsg);
}

void
ServerInterface::sendMsg(string msg)
{
	if (msg.size()>255) msg.resize(255);
	string netMsg;
	string size;
	netMsg=m_pStringConverter->int2hexString(SERVER_MSG);
	size=m_pStringConverter->int2hexString(msg.size());
	netMsg+=m_pStringConverter->leftTrim(size,2);
	netMsg+=msg;
	m_pNetworkManager->addMessage(netMsg);
}