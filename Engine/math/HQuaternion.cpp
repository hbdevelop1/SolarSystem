// HQuaternion.cpp: implementation of the HQuaternion class.
//
//////////////////////////////////////////////////////////////////////

#include "HQuaternion.h"
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HQuaternion::HQuaternion(double x, double y, double z, double d)
{
  m[0]=x;
  m[1]=y;
  m[2]=z;
  m[3]=d;


  Validate();
}

HQuaternion::HQuaternion(const AN8XQUATERNION & an8)
{
  m[0]=an8.x;
  m[1]=an8.y;
  m[2]=an8.z;
  m[3]=an8.w;


  Validate();
}

HQuaternion::~HQuaternion()
{

}

void HQuaternion::Set(double angle, HVector around)
{
//q = cos(a/2) + i ( x * sin(a/2)) + j (y * sin(a/2)) + k ( z * sin(a/2))

  double angleOver2 =angle / 2;
  double sin_a = sin( angleOver2 );
  double cos_a = cos( angleOver2 );

  m[0] = around[0] * sin_a;
  m[1] = around[1] * sin_a;
  m[2] = around[2] * sin_a;
  m[3] = cos_a;

  Normalize();


  Validate();


/*
    quaternion_normalise( q );
*/


}

void HQuaternion::Normalize()
{
/*
  Norm = Qr/|Qr|;

  where

			          ------------
	               /          --
|Qr| =  \/     Qr.Qr

*/

  Validate();

  double f = sqrt( m[0]*m[0] + m[1]*m[1] + m[2]*m[2] + m[3]*m[3]);

  m[0] /= f;
  m[1] /= f;
  m[2] /= f;
  m[3] /= f;

}


void HQuaternion::Print()
{
	  char buf[100];
#if _MSC_VER<=1200
	  sprintf(buf,"(%.3f, %.3f, %.3f, %.3f)\n", m[0], m[1], m[2], m[3]);
#else
	  assert(0);
	  sprintf_s(buf,sizeof(buf),"(%.3f, %.3f, %.3f, %.3f)\n", m[0], m[1], m[2], m[3]);
#endif
	  OutputDebugString(buf);

}

void HQuaternion::ToMatrix(HMatrix &mat) const
{
  Validate();

  double x2 = m[0]*m[0];
  double y2 = m[1]*m[1];
  double z2 = m[2]*m[2];
  double w2 = m[3]*m[3];

  mat.GetElements()[0*4+0] = ( x2 - y2 - z2 + w2);
  mat.GetElements()[1*4+1] = (-x2 + y2 - z2 + w2);
  mat.GetElements()[2*4+2] = (-x2 - y2 + z2 + w2);


  double tmp1 = m[0]*m[1];
  double tmp2 = m[2]*m[3];
  mat.GetElements()[0*4+1] = 2.0 * (tmp1 - tmp2);
  mat.GetElements()[1*4+0] = 2.0 * (tmp1 + tmp2);

  tmp1 = m[0]*m[2];
  tmp2 = m[1]*m[3];
  mat.GetElements()[2*4+0] = 2.0 * (tmp1 - tmp2);
  mat.GetElements()[0*4+2] = 2.0 * (tmp1 + tmp2);

  tmp1 = m[1]*m[2];
  tmp2 = m[0]*m[3];
  mat.GetElements()[1*4+2] = 2.0 * (tmp1 - tmp2);
  mat.GetElements()[2*4+1] = 2.0 * (tmp1 + tmp2);

  mat.Validate();
}

void HQuaternion::Validate() const
{
  for(int i =0; i<4; i++)
	if (IsZero(m[i]))
	  m[i] = 0;
}


double GetAngle(HQuaternion q1, HQuaternion q2)
{
  double angle ;

  q1.Normalize();
  q2.Normalize();
	double cos_of_angle = q1.m[0]*q2.m[0] + q1.m[1]*q2.m[1] + q1.m[2]*q2.m[2] + q1.m[3]*q2.m[3];

	assert(-1 <= cos_of_angle && cos_of_angle<=1);

	angle = acos(cos_of_angle);


	return angle ;
}


HQuaternion Interpolate(HQuaternion key1, HQuaternion key2, double sub)
{
  HQuaternion r;
  
  double angle = GetAngle(key1, key2);
  double sin_angle  = sin(angle );

	 double ratioA = sin((1 - sub) * angle );
	  double ratioB = sin(sub * angle );

	  r[0] = (key1[0] * ratioA + key2[0] * ratioB)/sin_angle;
	  r[1] = (key1[1] * ratioA + key2[1] * ratioB)/sin_angle;
	  r[2] = (key1[2] * ratioA + key2[2] * ratioB)/sin_angle;
	  r[3] = (key1[3] * ratioA + key2[3] * ratioB)/sin_angle;

	  r.Normalize();
	  
  return r;
}


HQuaternion operator*(const HQuaternion q1, const HQuaternion q2)
{
	HQuaternion q(
		q1.m[3]*q2.m[0] + q1.m[0]*q2.m[3] + q1.m[1]*q2.m[2] - q1.m[2]*q2.m[1] ,
		q1.m[3]*q2.m[1] - q1.m[0]*q2.m[2] + q1.m[1]*q2.m[3] + q1.m[2]*q2.m[0] ,
		q1.m[3]*q2.m[2] + q1.m[0]*q2.m[1] - q1.m[1]*q2.m[0] + q1.m[2]*q2.m[3] ,
		q1.m[3]*q2.m[3] - q1.m[0]*q2.m[0] - q1.m[1]*q2.m[1] - q1.m[2]*q2.m[2]
		);
	return q;
	
}

bool operator==(const HQuaternion q1, const HQuaternion q2)
{
	return ( IsZero(q1.m[0]-q2.m[0]) && IsZero(q1.m[1]-q2.m[1]) && IsZero(q1.m[2]-q2.m[2]) && IsZero(q1.m[3]-q2.m[3]));
}