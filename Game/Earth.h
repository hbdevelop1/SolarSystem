// Earth.h: interface for the Earth class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EARTH_H__2DB1EC2E_7090_4C35_B891_F82ED4A8AED5__INCLUDED_)
#define AFX_EARTH_H__2DB1EC2E_7090_4C35_B891_F82ED4A8AED5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpaceObject.h"
#include "..\ENGINE\MATH\HQuaternion.h"	// Added by ClassView

class Earth : public SpaceObject  
{
private:

	HQuaternion m_q0;
	HQuaternion m_q1;
	struct
	{
	  int	time;
	  float step;
	} m_interpolation;

public:
	Earth(char * filename);
	~Earth();
};

#endif // !defined(AFX_EARTH_H__2DB1EC2E_7090_4C35_B891_F82ED4A8AED5__INCLUDED_)
