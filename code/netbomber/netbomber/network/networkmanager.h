/***************************************************************************
                          networkmanager.h  -  description
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


#ifndef _NETWORKMANAGER_H
#define _NETWORKMANAGER_H
#include <string>
#include <vector>
#include "stringconverter.h"


class Client;
class PDKontroller;
class PlayerHandler;


class NetworkManager {
public:

  ~NetworkManager();

  static NetworkManager* getNetworkManager();
  void release();
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

  int m_rCount;

};

#endif