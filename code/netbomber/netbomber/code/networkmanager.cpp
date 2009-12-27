/***************************************************************************
                          networkmanager.cpp  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by Ren� Herrmann
 ***************************************************************************/

#include "networkmanager.h"
#include "client.h"
#include "reactor/playerhandler.h"
#include "../pd/pdkontroller.h"

#include "../global.h"

NetworkManager* NetworkManager::m_pNetworkManager = 0;

NetworkManager*
NetworkManager::getNetworkManager()
{
  if(m_pNetworkManager == 0)
  {
    m_pNetworkManager = new NetworkManager();
  }
  return m_pNetworkManager;
}

NetworkManager::NetworkManager()
{
  m_pKontroller = PDKontroller::getKontroller();
	m_pStringConverter = StringConverter::getStringConverter();
	m_pClient=Client::instance();
  m_pServer=PlayerHandler::instance();
  m_tmpData = "";
};

NetworkManager::~NetworkManager()
{
}

void
NetworkManager::addMessage(string _newMsg)
{
  m_tmpData += _newMsg;
//  if (m_tmpData.size()>MAX_STRING_PAKET_SIZE) sendData();   sendet daten nur an Server!!!
}

void
NetworkManager::sendData()
{
  int writeStatus;
  writeStatus=m_pClient->writeString(m_tmpData.data(),m_tmpData.size());
  // informPD(m_tmpData.c_str(),1);
	m_tmpData.erase();
}


void
NetworkManager::sendServerData()
{
//  int writeStatus;
  m_pServer->writeToClients(m_tmpData.data(),m_tmpData.size());
  // informPD(m_tmpData.c_str(),1);
	m_tmpData.erase();
}

void
NetworkManager::informPD(const char* msg,int _playerID,int size)
{
  if ( m_pKontroller->pdMutex == NULL )
  {
    cout << "NetworkManager::informPD : Mutex not set!!" << endl;
    return;
  }
  m_pKontroller->pdMutex->lock();

  string::size_type index=0;
  string tmp_data=string(msg);

  string m_data=tmp_data.substr(0,size);

  cout << "informPD("<< m_data <<")"<<endl;
  cout << "size:"<<m_data.size()<<endl;

  string nextMsg;

  while(index<m_data.size()){
    nextMsg=m_data.substr(index,1);
    int msgCode=(m_pStringConverter->hexString2int(nextMsg));
    ++index;

		// Handle Incomming Client Messages
    if(msgCode == READY)
    {
			m_pKontroller->ready(_playerID);
    }
   	else if (msgCode == SET_DIRECTION)
    {
    	int value = m_pStringConverter->hexString2int(m_data.substr(index,1));
    	++index;
			m_pKontroller->setDirection(value,_playerID);
   	}
		else if(msgCode == SET_BOMB_KEY)
    {
			bool	toggle;
			toggle=m_pStringConverter->hexString2int(m_data.substr(index,1));
    	++index;
 			m_pKontroller->setBombPressed(toggle,_playerID);	
    }
  	else if(msgCode == SET_NAME)
    {
			int _ID=m_pStringConverter->hexString2int(m_data.substr(index,2));
			index+=2;
    	int name_length = m_pStringConverter->hexString2int(m_data.substr(index,2));
    	index+=2;
    	string m_name=m_data.substr(index,name_length);
    	index+=name_length;
      if (_ID==0)
      {
				m_pKontroller->newPlayer(_playerID,m_name);
			}
      else
      {
				m_pKontroller->setPlayerName(_ID,m_name);
			}
    }
  	else if(msgCode == CLIENT_DISCONNECT)
    {
			m_pKontroller->disconnect(_playerID);
    }
  	else if(msgCode == CLIENT_MSG)
    {
    	int msg_length = m_pStringConverter->hexString2int(m_data.substr(index,2));
    	index+=2;
    	string _msg=m_data.substr(index,msg_length);
    	index+=msg_length;
 			m_pKontroller->receiveMsg(_msg,_playerID);
    }

		// Handle Incomming Server Messages
		else if(msgCode == SET_ITEM)
		{
			Position _pos;
			_pos=m_pStringConverter->hexString2position(m_data.substr(index,4));
			index+=4;
			int _element=m_pStringConverter->hexString2int(m_data.substr(index,2));
			index+=2;
			m_pKontroller->setItem(_pos,_element);	
 		}
		else if(msgCode == SET_PLAYER)
		{
			int _ID=m_pStringConverter->hexString2int(m_data.substr(index,2));
			index+=2;
			Position _pos;
			_pos=m_pStringConverter->hexString2position(m_data.substr(index,4));
			index+=4;
			m_pKontroller->setPlayer(_ID,_pos);	
 		}
		else if(msgCode == DEL_PLAYER)
		{
			int _ID=m_pStringConverter->hexString2int(m_data.substr(index,2));
      index+=2;
			m_pKontroller->delPlayer(_ID);	
 		}
		else if(msgCode == EXPLODE)
		{
			Position _pos;
			_pos=m_pStringConverter->hexString2position(m_data.substr(index,4));
			index+=4;
			int reichweite=m_pStringConverter->hexString2int(m_data.substr(index,2));
			index+=2;
      m_pKontroller->explode(_pos,reichweite);	
 		}
    else if(msgCode == SET_PLAYFIELD)
    {
      int rowLength,elementCount;
      fieldVektor.clear();
      string::size_type delPos=0;
      delPos=m_data.find('/',index);


      elementCount=m_pStringConverter->hexString2int(m_data.substr(index,delPos-index));
      index=  delPos+1;

      delPos=m_data.find('/',index);
      rowLength=m_pStringConverter->hexString2int(m_data.substr(index,delPos-index));
      index= delPos+1;


      for (int i=elementCount;i>0;--i)
      {
        delPos=m_data.find('/',index);
        fieldVektor.push_back(m_pStringConverter->hexString2int(m_data.substr(index,delPos-index)));
        index= delPos+1;
      }
      m_pKontroller->setPlayfield(fieldVektor,rowLength);
    }
  	else if(msgCode == RUN)
    {
			m_pKontroller->run();
    }
  	else if(msgCode == END_GAME)
    {
			m_pKontroller->endGame();
    }
  	else if(msgCode == SERVER_DISCONNECT)
    {
			m_pKontroller->disconnect();
    }
  	else if(msgCode == SERVER_MSG)
    {
    	int msg_length = m_pStringConverter->hexString2int(m_data.substr(index,2));
    	index+=2;
    	string _msg=m_data.substr(index,msg_length);
    	index+=msg_length;
 			m_pKontroller->receiveMsg(_msg);
    }
		// Unknown Message Code Received
   	else
    {
    	cout << "unknown message received. Message Code = "<<msgCode<<endl;
    }
  }
  m_pKontroller->pdMutex->unlock();
}


void
NetworkManager::connectToServer(const char* _serverIP)
{
  int connection=m_pClient->makeConnection(_serverIP);
  cout << "Server Connection Status:"<<connection<<endl;

// Eventuell Fehler abfangen
}

void
NetworkManager::disconnect()
{
  m_pClient->close();
}

void
NetworkManager::disconnectServer()
{
//  m_pServer->close();
}

void
NetworkManager::disconnect(int _playerID)
{
  if ( m_pKontroller->pdMutex == NULL )
  {
    cout << "NetworkManager::informPD : Mutex not set!!" << endl;
    return;
  }
  m_pKontroller->pdMutex->lock();
  m_pKontroller->disconnect(_playerID);
  m_pKontroller->pdMutex->unlock();
}