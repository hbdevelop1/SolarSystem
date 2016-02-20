// HObjectList.h: interface for the HObjectList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOBJECTLIST_H__171818F8_6459_4F87_8BE1_DE089AD7943A__INCLUDED_)
#define AFX_HOBJECTLIST_H__171818F8_6459_4F87_8BE1_DE089AD7943A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HObject.h"
#include <list>


//typedef list<HObject> HObjectList; //list and not deque or vector, in order to insert at any location in the collection. for objects that depend on others.


class HObjectList : public std::list<HObject *>
{
public:
	HObjectList();
	virtual ~HObjectList();

    void Tick();

};

#endif // !defined(AFX_HOBJECTLIST_H__171818F8_6459_4F87_8BE1_DE089AD7943A__INCLUDED_)
