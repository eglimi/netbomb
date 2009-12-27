/***************************************************************************
                          networkmanager.h  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by René Herrmann
 ***************************************************************************/

#ifndef _NETWORKMANAGER_H
#define _NETWORKMANAGER_H
#include <string>
#include <vector>
#include "stringconverter.h"

//#include "../pd/pdkontroller.h"

class Client;
class PDKontroller;
class PlayerHandler;



class NetworkManager {
public:

  ~NetworkManager();

  static NetworkManager* getNetworkManager();
  void sendData();
  void sendServerData();
  void addMessage(string _newData);
  void informPD(const char*,int playerID,int size);
  void connectToServer(const char* _serverIP);
  void disconnect();
  void disconnect(int _playerID);
  void disconnectServer();

private:
  NetworkManager();

  static NetworkManager* m_pNetworkManager;
  string m_tmpData;
  StringConverter* m_pStringConverter;
	Client* m_pClient;
  PlayerHandler*  m_pServer;
  vector<int> fieldVektor;
	PDKontroller* m_pKontroller;

};

#endif