// HObject.h: interface for the HObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SpaceObject_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_)
#define AFX_SpaceObject_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "..\Engine\HGraphicObj.h"
#include "..\Engine\HObject3D.h"


class SpaceObject : public HObject3D, public HGraphicObj
{
public:
	SpaceObject(const char * filename);
	virtual ~SpaceObject();

	void Draw();
	void TickSpecifics();

};

#endif // !defined(AFX_SpaceObject_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_)
