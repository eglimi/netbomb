/***************************************************************************
                          playerhandler.h  -  description
                             -------------------
    begin                : Tue Jun 18 2002
    copyright            : (C) 2002 by M.Egli
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
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
  void release();
	void registerPlayer(GameHandler* pGameHandler);
	void removePlayer(GameHandler* pGameHandler);
	int getActivePlayer(GameHandler* pGameHandler);
	ssize_t writeToClients(const char* str, size_t n);
	void killHandles();
	
private:
  PlayerHandler();
  static PlayerHandler* m_pInstance;
  map<int, GameHandler*> m_playerList;
	int m_rCount;
};

#endif
