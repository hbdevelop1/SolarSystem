// HObject.h: interface for the HObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOBJECT_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_)
#define AFX_HOBJECT_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define __STL_USE_NEW_IOSTREAMS
//otherwise problem due to "istream" not known stl\stl_iterator.h


#include <list>

class HObject
{
protected:
	std::list<HObject  *> m_children;

public:
	HObject();
	virtual ~HObject();

	void Tick();
	virtual void Init();
	virtual void Draw();
	virtual void UnInit();

	virtual void TickSpecifics(){};


	void AddChild(HObject *c);
};

#endif // !defined(AFX_HOBJECT_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_)
