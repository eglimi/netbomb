/***************************************************************************
                          spielerclient.h  -  description
                             -------------------
    begin                : Mon Apr 29 2002
    copyright            : (C) 2002 by U.Heimann
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SPIELERCLIENT_H
#define SPIELERCLIENT_H


class GUIToPDInterface;
class ClientInterface;


class SpielerClient {
public: 
	SpielerClient();
	~SpielerClient();

  void keyPressed(char key);
  void keyReleased(char key);


private:
  void computeDirection();

private:
  GUIToPDInterface* guiInterface;      // input interface from GUI
  ClientInterface* netInterface;       // output interface to Network

  bool keylist[5];                     // state of the moving keys, true = pressed
  int oldDirection;                    // moving direction before the key event
};

#endif
