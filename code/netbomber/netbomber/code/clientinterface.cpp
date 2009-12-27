#include "clientinterface.h"
#include "assert.h"
#include <iostream>
#include <sstream>
#include <iomanip>
//#include "../global.h"

//Direction < 16
//NetMsg < 16
//Name > 255 werden auf 255 gekürzt
//Message > 255 "    "   255  "

ClientInterface* ClientInterface::m_pClientInterface = 0;

ClientInterface*
ClientInterface::getClientInterface()
{
  if(m_pClientInterface == 0)
  {
    m_pClientInterface = new ClientInterface;
  }
  return m_pClientInterface;
}

ClientInterface::ClientInterface()
{
  m_pNetworkManager = NetworkManager::getNetworkManager() ;
  m_pStringConverter = StringConverter::getStringConverter();
};

ClientInterface::~ClientInterface()
{};


void
ClientInterface::ready()
{
	string netMsg;
	netMsg = m_pStringConverter->int2hexString( READY );
	m_pNetworkManager->addMessage( netMsg );
}


void
ClientInterface::setDirection(int _dir)
{
  string netMsg;
  netMsg = 	m_pStringConverter->int2hexString( SET_DIRECTION );
  netMsg +=	m_pStringConverter->int2hexString( _dir );
	m_pNetworkManager->addMessage( netMsg );
}

void
ClientInterface::setBombPressed(bool _keypressed)
{
	string netMsg;
	netMsg=m_pStringConverter->int2hexString(SET_BOMB_KEY);
	netMsg+=m_pStringConverter->int2hexString(_keypressed);
	m_pNetworkManager->addMessage(netMsg);
}

void
ClientInterface::connect(string _name,const char* _serverIP)
{
	m_pNetworkManager->connectToServer(_serverIP);
	setName(_name);
}

void
ClientInterface::setName(string _name)
{
	if (_name.size()>255) _name.resize(255);
	string netMsg;
	string size;
	netMsg=m_pStringConverter->int2hexString(SET_NAME);
  netMsg+="00";
	size=m_pStringConverter->int2hexString(_name.size());
	netMsg+=m_pStringConverter->leftTrim(size,2);
	netMsg+=_name;
	m_pNetworkManager->addMessage(netMsg);
}

void
ClientInterface::sendAll()
{
	 m_pNetworkManager->sendData();
}

void
ClientInterface::disconnect()
{
	string netMsg;
	netMsg = m_pStringConverter->int2hexString( CLIENT_DISCONNECT );
	m_pNetworkManager->addMessage( netMsg );
  m_pNetworkManager->disconnect();
}

void
ClientInterface::sendMsg(string msg)
{
	if (msg.size()>255) msg.resize(255);
	string netMsg;
	string size;
	netMsg=m_pStringConverter->int2hexString(CLIENT_MSG);
	size=m_pStringConverter->int2hexString(msg.size());
	netMsg+=m_pStringConverter->leftTrim(size,2);
	netMsg+=msg;
	m_pNetworkManager->addMessage(netMsg);

}
