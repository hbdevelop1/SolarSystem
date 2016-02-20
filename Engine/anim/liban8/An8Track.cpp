// This file in a part of LibAn8, Copyright (c) 2002-2007, Gr�gory Smialek
// It's licence can be found in an8loader.h included in this package
// WebSite: texel3d.free.fr
#include "An8Loader.h"
#include <iterator>
using namespace std;

An8Track::An8Track(void)
{
	NbrFloatKey   = 0;
	NbrQKey       = 0;
	NbrPointKey   = 0;
	NbrBooleanKey = 0;
}

/*
An8Track::An8Track(const An8Track &t):
  NbrFloatKey(t.NbrFloatKey),
  NbrQKey(t.NbrQKey),
  NbrPointKey(t.NbrPointKey),
  NbrBooleanKey(t.NbrBooleanKey)
{
	std::copy(t.vFloatKeys.begin(),	  t.vFloatKeys.end(),	std::back_inserter(vFloatKeys));
	std::copy(t.vQKeys.begin(),		  t.vQKeys.end(),		std::back_inserter(vQKeys));
	std::copy(t.vPointKeys.begin(),	  t.vPointKeys.end(),	std::back_inserter(vPointKeys));
	std::copy(t.vBooleanKeys.begin(), t.vBooleanKeys.end(), std::back_inserter(vBooleanKeys));
}
*/

An8Track::~An8Track(void)
{

}


bool An8Track::Load(AN8XPARSER*p_parser)
{

	int trackStart =p_parser->IndexOf(1,"track {");
	if(trackStart<0) return false;
	int trackEnd =p_parser->IndexOf(1,"}");

	while(p_parser->Length()!=1+LINERETURN && trackStart != trackEnd) 
	{
		if(p_parser->FindWord("floatkey {"))
		{
			++NbrFloatKey;
			An8FloatKey newFloatKey; 
			newFloatKey.Load(p_parser);
			vFloatKeys.push_back(newFloatKey);
		}
		if(p_parser->FindWord("qkey {"))
		{
			++NbrQKey;
			An8QKey newQKey; 
			newQKey.Load(p_parser);
			vQKeys.push_back(newQKey);
		}
		if(p_parser->FindWord("pointkey {"))
		{
			++NbrPointKey;
			An8PointKey newPointKey; 
			newPointKey.Load(p_parser);
			vPointKeys.push_back(newPointKey);
		}
		if(p_parser->FindWord("booleankey {"))
		{
			++NbrBooleanKey;
			An8PointKey newPointKey; 
			newPointKey.Load(p_parser);
			vPointKeys.push_back(newPointKey);
		}
		p_parser->ReadLine();
	    trackEnd = p_parser->IndexOf(1,"}");
	}

	return true;
}

