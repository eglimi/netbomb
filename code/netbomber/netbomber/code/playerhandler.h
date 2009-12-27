/***************************************************************************
                          playerhandler.h  -  description
                             -------------------
    begin                : Tue Jun 18 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H
#include <map.h>
#include "eventhandler.h"

class GameHandler;

class PlayerHandler {
public: 
	~PlayerHandler();
	static PlayerHandler* instance();
	void registerPlayer(GameHandler* pGameHandler);
	void removePlayer(GameHandler* pGameHandler);
	int getActivePlayer(GameHandler* pGameHandler);
	ssize_t writeToClients(const char* str, size_t n);
		
private:
  PlayerHandler();
  static PlayerHandler* m_pInstance;
  map<int, GameHandler*> m_playerList;
	
};

#endif
