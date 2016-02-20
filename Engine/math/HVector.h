// HVector.h: interface for the HVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HVECTOR_H__57163BBF_0232_4F6C_8E98_9934B790E2B8__INCLUDED_)
#define AFX_HVECTOR_H__57163BBF_0232_4F6C_8E98_9934B790E2B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "HCommon.h"
#include "../anim/liban8/an8x.h"


class HVector
{
  double m[3];
public:
	const static HVector Zero;
	const static HVector Epsilon;

public:
	explicit HVector(double a=0, double b=0, double c=0);
	HVector(const AN8XVECTOR3 & an8);
	HVector & operator= (const HVector &);

	
	void Validate();

	void Normalize();
	inline double & operator[] (int index);
	double HVector::GetLenght();

	HVector operator* (const double s) 
	{ 
		return HVector(m[0]*s,m[1]*s,m[2]*s);
	}


  	friend double GetAngle(HVector v1, HVector v2);
	friend HVector Interpolate(HVector v1, HVector v2, double sub);
	friend bool operator== (const HVector & v0, const HVector & v1) 
	{ 
		return (v0.m[0]==v1.m[0] && v0.m[1]==v1.m[1] &&  v0.m[2]==v1.m[2] );
	}
	friend HVector operator- (const HVector & v0, const HVector & v1) 
	{ 
		return HVector(v0.m[0]-v1.m[0],v0.m[1]-v1.m[1],v0.m[2]-v1.m[2] );
	}


	friend double Dot(const HVector & v0, const HVector & v1) 
	{ 
		return (v0.m[0]*v1.m[0]+v0.m[1]*v1.m[1]+v0.m[2]*v1.m[2] );
	}
	friend HVector Cross (const HVector & v0, const HVector & v1) 
	{ 
		return HVector(	-v0.m[2]*v1.m[1]+v0.m[1]*v1.m[2],
						 v0.m[2]*v1.m[0]-v0.m[0]*v1.m[2],
						-v0.m[1]*v1.m[0]+v0.m[0]*v1.m[1]);
	}

	friend class HVector4;

};


inline double & HVector::operator[] (int index)
{
	//todo:control the value of index.
	return m[index];
}



#endif // !defined(AFX_HVECTOR_H__57163BBF_0232_4F6C_8E98_9934B790E2B8__INCLUDED_)
