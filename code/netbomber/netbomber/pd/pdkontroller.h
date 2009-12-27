/***************************************************************************
                          pdkontroller.h  -  description
                             -------------------
    begin                : Tue May 21 2002
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



#ifndef PDKONTROLLER_H
#define PDKONTROLLER_H

#include "../global.h"
#include <string>
#include <vector>
#include <qthread.h>

class SpielManager;
class Spielfigur;
class SpielfeldClient;


class PDKontroller {
public:
  static PDKontroller* getKontroller();
  void release();
	~PDKontroller();

  void setManager(SpielManager* manager);                    // registers the Manager   (both)
  void setSpielfigur(int playerID, Spielfigur* figur);       // registers the Players   (server)
  void setClientFeld(SpielfeldClient* feld);                 // registers the Playfield (client)

// Messages to SpielManager (server / client)
  void newPlayer(int playerID, string playerName);           // new player connected           (server)
  void disconnect(int playerID);                             // client has disconnected        (server)
  void ready(int playerID);                                  // player is ready to play        (server)
  void run();                                                // starts the game                (client)
  void endGame();                                            // ends the game                  (client)
  void connectConfirm();                                     // connection to server is ready  (client)
  void disconnect();                                         // server has disconnected        (client
  void setPlayerName(int playerID, string playerName);       // sets Name of a player          (client)
  void errorMsg(int msgNumber, string addInfo);              // Errormessage from the Network  (both)
  void receiveMsg(string msg);                               // Infomessage from Server        (client)
  void receiveMsg(string msg, int playerID);                 // Infomessage from Client to broadcast (server)

// Messages to Server
  void setDirection(int direction, int playerID);            // sets the moving direction of a player
  void setBombPressed(bool keypressed, int playerID);        // sets the bomb flag of a player

// Messages to Client
  void setPlayfield(vector<int> feldinfo, int zeilenbreite); // sets the entire playfield
  void setItem(Position position, int item);                 // sets an object on the playfield
  void setPlayer(int playerID, Position position);           // sets a player to a new position
  void delPlayer(int playerID);                              // removes a player from the playfield
  void explode(Position position, int reichweite);           // starts an explosion


private:
	PDKontroller();                                            // private constructor (singleton)
  static PDKontroller* m_pdkontroller;
  int rCount;

  SpielManager*     spielManager;                            // pointer to the manager   (both)
  Spielfigur*       serverFigur[MAX_PLAYERS];                // pointers to the players  (server)
  SpielfeldClient*  clientFeld;                              // pointer to the playfield (client)
};

#endif
