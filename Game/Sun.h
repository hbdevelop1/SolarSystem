// Sun.h: interface for the Sun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUN_H__C7E7490C_B3EC_4C4D_84E3_FF48820F2847__INCLUDED_)
#define AFX_SUN_H__C7E7490C_B3EC_4C4D_84E3_FF48820F2847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ENGINE\HGraphicObj.h"


/*
struct stLight
{
	HVector		pos;
	float		diffuse[4];
	float		ambient[4];
};
*/
class Sun : public HGraphicObj  
{
//	stLight			*m_light;

public:
	Sun(const char * filename);
	virtual ~Sun();


	void DrawSpecifics();

};

#endif // !defined(AFX_SUN_H__C7E7490C_B3EC_4C4D_84E3_FF48820F2847__INCLUDED_)
