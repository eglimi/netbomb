
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
    void    disconnect();
    void    sendMsg(string msg);

private:
   	ClientInterface();
    static ClientInterface* m_pClientInterface;
    NetworkManager* m_pNetworkManager;
    StringConverter* m_pStringConverter;
};
#endif