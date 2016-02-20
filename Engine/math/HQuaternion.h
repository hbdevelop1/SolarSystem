// HQuaternion.h: interface for the HQuaternion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HQUATERNION_H__49042A9C_E076_4276_94A2_BAE8A7DB4642__INCLUDED_)
#define AFX_HQUATERNION_H__49042A9C_E076_4276_94A2_BAE8A7DB4642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "HCommon.h"


#include "HVector.h"
#include "HMatrix.h"
#include "../anim/liban8/an8x.h"


class HQuaternion  
{
private:
  mutable double m[4];

public:
	HQuaternion(double=0,double=0,double=0,double=1);
	HQuaternion(const AN8XQUATERNION & an8);
	HQuaternion(double angle, HVector around) 
	{
	  Set(angle, around);
	}

	virtual ~HQuaternion();

	void Normalize();
	void Set(double angle, HVector around);
	double & operator[](int index)
	{
	  return m[index];
	}

	void ToMatrix(HMatrix &m) const; 
	void Print();
	void Validate() const;

	friend double GetAngle(HQuaternion q1, HQuaternion q2);
	friend HQuaternion Interpolate(HQuaternion q1, HQuaternion q2, double sub);
	friend HQuaternion operator*(const HQuaternion q1, const HQuaternion q2);
	friend bool operator==(const HQuaternion q1, const HQuaternion q2);
};

#endif // !defined(AFX_HQUATERNION_H__49042A9C_E076_4276_94A2_BAE8A7DB4642__INCLUDED_)
