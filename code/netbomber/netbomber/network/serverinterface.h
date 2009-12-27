/***************************************************************************
                          serverinterface.h  -  description
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


#ifndef _SERVERINTERFACE_H
#define _SERVERINTERFACE_H   	
#include <string>
#include <vector>
#include "../global.h"

class StringConverter;
class NetworkManager;
class ServerInterface {

public:

	  ~ServerInterface();
    void    release();
    void    setItem(Position _pos,int spielelement);
    void    setPlayer(int playerID,Position _pos);
    void    delPlayer(int playerID);
    void    explode(Position _pos,int reichweite);
    void    setPlayfield(vector<int> feldinfo,int zeilenbreite);
    void    sendAll();
    static  ServerInterface* getServerInterface();
    void    run();
    void    endGame();
    void    disconnect();
    void    setPlayerName(int playerID,string playerName);
    void    sendMsg(string msg);

	
private:
  ServerInterface();
  static ServerInterface* m_pServerInterface;
	StringConverter* m_pStringConverter;
  NetworkManager* m_pNetworkManager;
  int m_rCount;
};
#endif