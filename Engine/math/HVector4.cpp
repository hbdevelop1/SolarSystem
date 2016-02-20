// HVector4.cpp: implementation of the HVector4 class.
//
//////////////////////////////////////////////////////////////////////

#include "HVector4.h"
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const HVector4 HVector4::Zero=HVector4(0,0,0,1);
/*
static HVector4 & HVector4::NULL()
{
	m[0]=m[1]=m[2]=0;
}
*/

HVector4::HVector4(double a, double b, double c, double d)
{
	m[0]=a;
	m[1]=b;
	m[2]=c;
	m[3]=d;
}

HVector4::HVector4(const HVector &v)
{
m[0]=v.m[0];
m[1]=v.m[1];
m[2]=v.m[2];
m[3]=0;

}
/*
HVector4::operator HVector (const HVector4 & v)
{
}
*/
HVector4 & HVector4::operator= (const HVector4 & v)
{
m[0]=v.m[0];
m[1]=v.m[1];
m[2]=v.m[2];
m[3]=v.m[3];

  Validate();

  return *this;
}

void HVector4::Validate()
{
  for(int i =0; i<4; i++)
	if (IsZero(m[i]))
	  m[i] = 0;

}

void HVector4::Normalize()
{
	assert(0);

  Validate();

  double f = sqrt( m[0]*m[0] + m[1]*m[1] + m[2]*m[2]+ m[3]*m[3]);

  m[0] /= f;
  m[1] /= f;
  m[2] /= f;
  m[3] /= f;

}



double GetAngle(HVector4 v1, HVector4 v2)
{
	assert(0);
  double angle ;

	double cos_of_angle = v1.m[0]*v2.m[0] + v1.m[1]*v2.m[1] + v1.m[2]*v2.m[2] ;

	assert(-1 <= cos_of_angle && cos_of_angle<=1);

	angle = acos(cos_of_angle);


	return angle ;
}


HVector4 Interpolate(HVector4 v1, HVector4 v2, double sub)
{
	assert(0);
  HVector4 r;
  
  HVector4 v1tmp(v1);
  HVector4 v2tmp(v2);

  v1tmp.Normalize();
  v2tmp.Normalize();

  double angle = GetAngle(v1tmp, v2tmp);
  double ha = angle/2;
  double sinha = sin(ha);

	 double ratioA = sin((1 - sub) * ha) / sinha;
	  double ratioB = sin(sub * ha) / sinha; 

	  r[0] = (v1[0] * ratioA + v2[0] * ratioB);
	  r[1] = (v1[1] * ratioA + v2[1] * ratioB);
	  r[2] = (v1[2] * ratioA + v2[2] * ratioB);

  return r;
}

bool operator==(HVector4 v1, HVector4 v2)
{

	return (IsZero(v1[0]-v2[0]) && IsZero(v1[1]-v2[1]) && IsZero(v1[2]-v2[2]) && IsZero(v1[3]-v2[3]) );
}