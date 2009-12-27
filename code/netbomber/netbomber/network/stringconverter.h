/***************************************************************************
                          stringconverter.h  -  description
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

#ifndef _STRINGCONVERTER_H
#define _STRINGCONVERTER_H
#include <string>
#include "../global.h"


class StringConverter {

public:
	~StringConverter();
	static StringConverter* getStringConverter();
  void release();

	string int2hexString(unsigned int iValue);
 	int hexString2int(string s);
	string position2String(Position _position);
	Position hexString2position(string s_pos);
	string leftTrim(string,unsigned int stringSize);
	string playerID2String(int _ID);

private:
 	StringConverter();
  static StringConverter* m_StringConverter;
  int m_rCount;
};
#endif
