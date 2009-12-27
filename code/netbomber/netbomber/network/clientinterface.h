/***************************************************************************
                          clientinterface.h  -  description
                             -------------------
    begin                : Wed May 1 2002
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


#ifndef 	_CLIENTINTERFACE_H
#define	_CLIENTINTERFACE_H

#include <string>
#include "../global.h"
#include "networkmanager.h"
#include "stringconverter.h"

class ClientInterface {

public:
 		~ClientInterface();
    void    ready();
    void    setDirection(int _direction);
    void    setBombPressed(bool key_pressed);
    void    connect(string player_name,const char* _serverIP);
    void    setName(string player_name);
    void    sendAll();
    static  ClientInterface* getClientInterface();
    void    release();
    void    disconnect();
    void    sendMsg(string msg);

private:
   	ClientInterface();
    static ClientInterface* m_pClientInterface;
    NetworkManager* m_pNetworkManager;
    StringConverter* m_pStringConverter;
    int m_rCount;
};
#endif