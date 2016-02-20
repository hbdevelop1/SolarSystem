// HVector.cpp: implementation of the HVector class.
//
//////////////////////////////////////////////////////////////////////

#include "HVector.h"
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const HVector HVector::Zero=HVector(0,0,0);
/*
static HVector & HVector::NULL()
{
	m[0]=m[1]=m[2]=0;
}
*/

HVector::HVector(double a, double b, double c)
{
	m[0]=a;
	m[1]=b;
	m[2]=c;
}

HVector::HVector(const AN8XVECTOR3 & an8)
{
  m[0]=an8.x;
  m[1]=an8.y;
  m[2]=an8.z;

  Validate();
}

HVector & HVector::operator= (const HVector & v)
{
m[0]=v.m[0];
m[1]=v.m[1];
m[2]=v.m[2];

  Validate();

  return *this;
}

void HVector::Validate()
{
  for(int i =0; i<3; i++)
	if (IsZero(m[i]))
	  m[i] = 0;

}

void HVector::Normalize()
{

  Validate();

  double f = sqrt( m[0]*m[0] + m[1]*m[1] + m[2]*m[2]);

  m[0] /= f;
  m[1] /= f;
  m[2] /= f;

}

double HVector::GetLenght()
{

  Validate();

  return sqrt( m[0]*m[0] + m[1]*m[1] + m[2]*m[2]);

}


double GetAngle(HVector v1, HVector v2) //in radian, see acos help
{

  v1.Normalize();
  v2.Normalize();
   double cos_of_angle= v1.m[0]*v2.m[0] + v1.m[1]*v2.m[1] + v1.m[2]*v2.m[2] ;

	
	assert(-1 <= cos_of_angle && cos_of_angle<=1);

	return acos(cos_of_angle);
}


HVector Interpolate(HVector v1, HVector v2, double sub)
{
  HVector r;
  
    double angle = GetAngle(v1, v2);
  double sin_angle = sin(angle);

	 double ratioA = sin((1 - sub) * angle);
	  double ratioB = sin(sub * angle); 

	  r[0] = (v1[0] * ratioA + v2[0] * ratioB) / sin_angle;
	  r[1] = (v1[1] * ratioA + v2[1] * ratioB) / sin_angle;
	  r[2] = (v1[2] * ratioA + v2[2] * ratioB) / sin_angle;

  return r;
}