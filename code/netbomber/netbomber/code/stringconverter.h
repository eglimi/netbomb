
//***************************************************************************
//  Dateiname        :stringconverter.h
//  Erstellungsdatum :Mon May 27 2002
//  Author           :René Herrmann(rherrman@hsr.ch)
//  Zweck            :
// ***************************************************************************

#ifndef _STRINGCONVERTER_H
#define _STRINGCONVERTER_H
#include <string>
#include "../global.h"


class StringConverter {

public:
	~StringConverter();
	static StringConverter* getStringConverter();

	string int2hexString(unsigned int iValue);
 	int hexString2int(string s);
	string position2String(Position _position);
	Position hexString2position(string s_pos);
	string leftTrim(string,unsigned int stringSize);
	string playerID2String(int _ID);

private:
   	StringConverter();
    static StringConverter* m_StringConverter;
};
#endif