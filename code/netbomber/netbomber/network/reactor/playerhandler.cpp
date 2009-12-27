/***************************************************************************
                          playerhandler.cpp  -  description
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


#include "playerhandler.h"
#include <map.h>
#include "gamehandler.h"


PlayerHandler* PlayerHandler::m_pInstance = 0;

PlayerHandler*
PlayerHandler::instance()
{
  if(m_pInstance == 0)
  {
    m_pInstance = new PlayerHandler;
  }
  m_pInstance->m_rCount++;
  return m_pInstance;
}

PlayerHandler::PlayerHandler()
{
  m_rCount = 0;
}

PlayerHandler::~PlayerHandler()
{
}

void
PlayerHandler::killHandles()
{
  map<int,GameHandler*>::iterator pos;
  for(pos = m_playerList.begin(); pos != m_playerList.end(); ++pos)
  {
    (pos->second)->handleEvent((pos->second)->getHandle(), CLOSE_EVENT);
  }
}

void
PlayerHandler::release()
{
  m_rCount--;
  if ( m_rCount == 0 )
  {
    m_pInstance = NULL;
    delete this;
  }
}

void
PlayerHandler::registerPlayer(GameHandler* pGameHandler)
{
  int sizeOfMap;
  sizeOfMap = m_playerList.size();
  map<int, GameHandler*>::iterator pos;
  pos = m_playerList.begin();
  for(int i = 0; i <= m_playerList.size(); ++i)
  {
    if(pos->first != i+1)
    {
      m_playerList[i+1] = pGameHandler;
      break;
    }
    ++pos;
  }
}

void
PlayerHandler::removePlayer(GameHandler* pGameHandler)
{
  map<int, GameHandler*>::iterator pos;
  for(pos = m_playerList.begin(); pos != m_playerList.end(); ++pos)
  {
    if(pos->second == pGameHandler)
    {
      m_playerList.erase(pos);
    }
  }
}

int
PlayerHandler::getActivePlayer(GameHandler* pGameHandler)
{
  map<int, GameHandler*>::iterator pos;
  for(pos = m_playerList.begin(); pos != m_playerList.end(); ++pos)
  {
    if(pos->second == pGameHandler)
    {
      return pos->first;
    }
  }
  return -1;
}

ssize_t
PlayerHandler::writeToClients(const char* str, size_t n)
{
 map<int, GameHandler*>::iterator pos;
 for(pos = m_playerList.begin(); pos != m_playerList.end(); ++pos)
 {
    int nwritten = (pos->second)->writeToClient(str, n);
 }
  return n;
}
