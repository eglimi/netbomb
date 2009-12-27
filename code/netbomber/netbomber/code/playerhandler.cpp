/***************************************************************************
                          playerhandler.cpp  -  description
                             -------------------
    begin                : Tue Jun 18 2002
    copyright            : (C) 2002 by Stefan Kuenzle
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
  return m_pInstance;
}

PlayerHandler::PlayerHandler()
{
}

PlayerHandler::~PlayerHandler()
{
  map<int,GameHandler*>::iterator pos;
  for(pos = m_playerList.begin(); pos != m_playerList.end(); ++pos)
  {
    (pos->second)->handleEvent((pos->second)->getHandle(), CLOSE_EVENT);
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
