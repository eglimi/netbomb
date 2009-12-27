/***************************************************************************
                          serverinterface.h  -  description
                             -------------------
    begin                : Fri May 24 2002
    copyright            : (C) 2002 by 
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
};
#endif