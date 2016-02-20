// HVector4.h: interface for the HVector4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HVector4_H__57163BBF_0232_4F6C_8E98_9934B790E2B8__INCLUDED_)
#define AFX_HVector4_H__57163BBF_0232_4F6C_8E98_9934B790E2B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "HCommon.h"
#include "HVector.h"


class HVector4
{
  double m[4];
public:
	const static HVector4 Zero;

public:
	HVector4(double a=0, double b=0, double c=0, double d=0);
	HVector4(const HVector &);
	HVector4 & operator= (const HVector4 &);
	operator HVector () {	return HVector(m[0],m[1],m[2]);}

	void Validate();

	void Normalize();
	inline double & operator[] (int index);


  	friend double GetAngle(HVector4 v1, HVector4 v2);
	friend HVector4 Interpolate(HVector4 v1, HVector4 v2, double sub);

	friend bool operator==(const HVector4 v1, const HVector4 v2);

};


inline double & HVector4::operator[] (int index)
{
	//todo:control the value of index.
	return m[index];
}



#endif // !defined(AFX_HVector4_H__57163BBF_0232_4F6C_8E98_9934B790E2B8__INCLUDED_)
