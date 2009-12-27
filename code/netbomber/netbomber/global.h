/***************************************************************************
                          global.h  -  description
                             -------------------
    begin                : Thu Apr 18 2002
    copyright            : (C) 2002 by NetbomberGroup
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <qstring.h>

// Datentyp für positionsangaben
struct Position{ int x; int y; };

// Spielfelddefinitionen
const int FELD_WIDTH = 17;
const int FELD_HEIGHT = 17;

// SpielElemente
const int FREI           = 0;
const int MAUER          = 1;
const int WAND           = 2;
const int BOMBE          = 3;
const int POWERUP_BOMBE  = 4;
const int POWERUP_FLAMME = 5;
const int EXPLOSION      = 6;

// Richtungsangaben
const int STAY  = 0;
const int UP    = 1;
const int DOWN  = 2;
const int RIGHT = 3;
const int LEFT  = 4;

// Maximale anzahl spieler
const int MAX_PLAYERS = 4;

// Minimale anzahl spieler (bei weniger wird das Spiel beendet)
const int MIN_PLAYERS = 2;

// Starteinstellungen der Spielfigur
const Position START_POSITION[MAX_PLAYERS] = {{1,1},{FELD_WIDTH-2, FELD_HEIGHT-2},{1,FELD_HEIGHT-2},{FELD_WIDTH-2,1}};
const int START_REICHWEITE = 3;
const int START_BOMBS      = 3;


// Tasten
const char KEY_UP    = '8';
const char KEY_DOWN  = '2';
const char KEY_LEFT  = '4';
const char KEY_RIGHT = '6';
const char KEY_BOMB  = '1';

// IP für localhost
const char LOCALHOST[] = "127.0.0.1";

// Zeitverzögerung zwischen 2 bewegungen
const int MOVE_DELAY = 300;//220;  // ms

// Zeitverzögerung bis zum explodieren der Bombe
const int BOMB_DELAY = 3000;

const int SERVER_WAIT_TIME = 2;
const int CLIENT_WAIT_TIME = 4;

// Meldungen
const char MSG_GAME_FINISHED[] = "Game finished!! ";
const char MSG_WINNER[]        = "The Winner is: ";
const char MSG_NO_WINNER[]     = "No winner.";
const char MSG_EXCLEMATION[]   = "!!!";
const char MSG_CONNECTED[]     = "Erfolgreich an Server angemeldet!";
const char MSG_CONNECT_FAIL[]  = "Anmeldung an Server fehlgeschlagen!";
const char MSG_DISCONNECT[]    = " has disconnected.";


//////////////////////////////////
// KONSTANTEN FÜR USERINTERFACE // added by STEK
//////////////////////////////////

// needed for animation
const double VELOCITY = 1;
const int ADV_PERIOD = 1;

//single field width
const int FIELD_WIDTH = 30;

// RTTI's (Run Time Type Information, needed by CanvasItems for
// identification

const int RTTI_FIGUR  = 1234;
const int RTTI_WAND   = 1235;
const int RTTI_MAUER  = 1236;
const int RTTI_BOMBE  = 1237;
const int RTTI_FLAMME = 1238;


//anzahl innere mauern
const int NR_VERT_MAUERN = 7;
const int NR_HORI_MAUERN = 7;

//Menu Eintraege

const QString MENU_FILE_NEW = "&Neues Spiel..";
const QString MENU_FILE_QUIT = "&Quit NetBomb";

const QString MENU_NETWORK_JOIN = "Spielserver &anmelden..";
const QString MENU_NETWORK_CREATE = "Spielserver &starten..";

const QString MENU_OPTIONS_KEYBOARD = "&Tastaturbelegung..";

const QString MENU_FILE = "&Spiel";
const QString MENU_NETWORK = "&Netzwerk";
const QString MENU_OPTIONS = "&Optionen";

// Pfäde der grafiken
const char SPRITE_WAND[]      = "wand0000.gif";
const char SPRITE_MAUER[]     = "mauer0000.png";
const char SPRITE_BOMBE[]     = "bombe.png";
const char SPRITE_FLAMME[]    = "flame.png";

const char SPRITE_UP_P1[]     = "up_1_0000.png";
const char SPRITE_DOWN_P1[]   = "down_1_0000.png";
const char SPRITE_LEFT_P1[]   = "left_1_0000.png";
const char SPRITE_RIGHT_P1[]  = "right_1_0000.png";

const char SPRITE_UP_P2[]     = "up_2_0000.png";
const char SPRITE_DOWN_P2[]   = "down_2_0000.png";
const char SPRITE_LEFT_P2[]   = "left_2_0000.png";
const char SPRITE_RIGHT_P2[]  = "right_2_0000.png";

const char SPRITE_UP_P3[]     = "up_3_0000.png";
const char SPRITE_DOWN_P3[]   = "down_3_0000.png";
const char SPRITE_LEFT_P3[]   = "left_3_0000.png";
const char SPRITE_RIGHT_P3[]  = "right_3_0000.png";

const char SPRITE_UP_P4[]     = "up_4_0000.png";
const char SPRITE_DOWN_P4[]   = "down_4_0000.png";
const char SPRITE_LEFT_P4[]   = "left_4_0000.png";
const char SPRITE_RIGHT_P4[]  = "right_4_0000.png";


// Netzwerk Protokoll Messages

typedef unsigned int NetMsg;
enum
{
  SET_ITEM          = 0,
  SET_PLAYER        = 1,
  DEL_PLAYER        = 2,
  EXPLODE           = 3,
  SET_PLAYFIELD     = 4,
  REGISTER_PLAYER   = 5,
  READY             = 6,
  SET_DIRECTION     = 7,
  SET_BOMB_KEY      = 8,
  SET_NAME          = 9,
  END_GAME          = 10,
  RUN               = 11,
  CLIENT_MSG        = 12,
  SERVER_MSG        = 13,
  SERVER_DISCONNECT = 14,
  CLIENT_DISCONNECT = 15
};

// Hat der zu übermittelnde String diese Grösse wird er abgeschickt
const unsigned int MAX_STRING_PAKET_SIZE = 100;

//for signal handlers
typedef void Sigfunc(int);

#endif
