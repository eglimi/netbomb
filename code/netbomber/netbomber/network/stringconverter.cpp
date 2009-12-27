/***************************************************************************
                          stringconverter.cpp  -  description
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


#include "stringconverter.h"
#include "assert.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "math.h"


StringConverter* StringConverter::m_StringConverter = 0;

StringConverter*
StringConverter::getStringConverter()
{
  if(m_StringConverter == 0)
  {
    m_StringConverter = new StringConverter;
  }
  m_StringConverter->m_rCount++;
  return m_StringConverter;
}

StringConverter::StringConverter()
{
  m_rCount = 0;
};

StringConverter::~StringConverter()
{
};

void
StringConverter::release()
{
  m_rCount--;
  if ( m_rCount == 0 )
  {
     m_StringConverter = NULL;
     delete this;
  }
}


string
StringConverter::leftTrim(string _string,unsigned int stringSize)
{
	// stringSize is the desired string size after the function call
	
	// if the cutChars value is bigger then the size length
  // the return value will be an empty string

	if (stringSize>_string.size())
  {
    string fillString(stringSize-_string.size(),'0');
    return (fillString + _string);
  }
	_string.substr(_string.size()-stringSize,stringSize);
	return _string;
}

string
StringConverter::position2String(Position _position)
{
  string positionString;

	string x = int2hexString( _position.x );
  positionString += leftTrim(x,2);

	string y = int2hexString( _position.y );
  positionString +=	leftTrim(y,2);

	return positionString;
}

Position
StringConverter::hexString2position(string s_pos)
{
  Position _pos;
  _pos.x	=	hexString2int(s_pos.substr(0,2));
  _pos.y	=	hexString2int(s_pos.substr(2,2));
  return _pos;
}

string
StringConverter::playerID2String(int _ID)
{
	string id_string = int2hexString( _ID );
	return leftTrim(id_string,2);
}

string
StringConverter::int2hexString(unsigned int iValue)
{
  // This function converts an integer into hex format
	string hexString;

	ostringstream tmpStream;
	
	tmpStream << std::hex << iValue;
	hexString=tmpStream.str();
  return (hexString);

}

int
StringConverter::hexString2int(string s)
{
  int intValue=0;
	int totalValue=0;
	unsigned int	digit,digit_count;
	string hexChar;
	digit_count	=	s.size();

  for (digit=digit_count;digit>0;--digit)
	{
		hexChar=s.substr(digit_count-digit,1);
	  intValue=0;
		if (hexChar=="a"){intValue=10;}
		else if (hexChar=="b"){ intValue=11;}
		else if (hexChar=="c"){ intValue=12;}
		else if (hexChar=="d"){ intValue=13;}
		else if (hexChar=="e"){ intValue=14;}
		else if (hexChar=="f"){ intValue=15;}
		else {intValue=atoi(hexChar.c_str());}
    if ( digit == 1 )
      totalValue += intValue;
    else
		  totalValue+=(int)(pow(16,digit-1))*intValue;

		//cout <<"intValue:"<<intValue<<endl;
		//cout <<"hexChar:"<<hexChar<<endl;
	}
	return totalValue;
}
