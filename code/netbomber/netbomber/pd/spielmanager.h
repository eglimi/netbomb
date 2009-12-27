/***************************************************************************
                          spielmanager.h  -  description
                             -------------------
    begin                : Mon May 27 2002
    copyright            : (C) 2002 by U.Heimann
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#ifndef SPIELMANAGER_H
#define SPIELMANAGER_H

#include <string>
#include "../global.h"

class GUIToPDInterface;
class PDToGUIInterface;
class PDKontroller;
class ClientInterface;
class ServerInterface;

class Spiel;
class ServerThread;
class Client;
class QMutex;

#include <qobject.h>

class SpielManager : public QObject{
  Q_OBJECT
public: 
	SpielManager();
	~SpielManager();

// Gamehandling functions
  void startServer(string playerName);            // creates new Game (server)
  void joinServer(string ipAdress, string playerName);  // creates new Game (client)
  void startGame();                               // starts the Game with the connected players (server)
  void endGame();                                 // ends the Game regularly
  void killGame();                                // ends the Game (at any time)
  void errorMsg(int msgNumber, string addInfo);   // an error occured in the Network layer

// Server functions
  void newPlayer(int playerID, string name);      // new player has connected
  void ready(int playerID);                       // player is ready to play (playfield is set up)
  void removePlayer(int playerID);                // player has disconnected
  void distributeMsg(string info);                // sends a message to all clients

// Client functions
  void connectConfirm();                          // connection to server is set up
  void disconnect();                              // server has disconnected
  void setPlayerName(int playerID, string name);  // sets the Name of a (connected) player
  void run();                                     // start Game
  void infoMsg(string info);                      // display an infomessage

// Test functions
//  void exAll();                                   // explode all bombes

private:
// Interfaces
  GUIToPDInterface* guiInputInterface;            // interface GUI->PD
  PDToGUIInterface* guiOutputInterface;           // interface PD ->GUI
  PDKontroller*     netInputInterface;            // interface NET->PD
  ClientInterface*  netOutClientInterface;        // interface PD ->NET(client)
  ServerInterface*  netOutServerInterface;        // interface PD ->NET(server)

// Game variables
  Spiel*            game;                         // instance of the game
  bool              serverGame;                   // true if is the server
  string            playerName[MAX_PLAYERS];      // the names of the connected players

// server variables
  bool              playerConnected[MAX_PLAYERS];  // shows which player-slot is connected
  int               playerReady[MAX_PLAYERS];      // shows which player is ready to start

// network listening thread for server
  ServerThread*     serverThread;

  void              createNetworkServer();
  void              killNetworkServer();
  void              createNetworkClient();
  void              killNetworkClient();

  QMutex*           pdMutex;                       // mutex to protect the PD
  QMutex*           serverMutex;                   // mutex to stop the server thread

  QTimer*           clientTimer;
  Client*           client;

public slots:
  void clientTimeout();

};



#endif
