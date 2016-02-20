// HMatrix.h: interface for the HMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HMATRIX_H__696E727B_D133_4371_9E63_C166DF65E020__INCLUDED_)
#define AFX_HMATRIX_H__696E727B_D133_4371_9E63_C166DF65E020__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "HCommon.h"


#include "HVector.h"
#include "HVector4.h"

class HMatrix  
{
private:
  double t[16];

public:
	void Transpose(HMatrix &);
	void Validate();
  
  static const HMatrix Identity;

  HMatrix(float a=0,float b=0,float c=0,float d=0,
		float e=0,float f=0,float g=0,float h=0,
		float i=0,float j=0,float k=0,float l=0,
		float m=0,float n=0,float o=0,float p=0
		  );

HMatrix(double *a);

  double*  GetElements(){return t;}
  void	  SetColumn(int c, HVector v);


  	friend HVector4 operator*(HMatrix , HVector4);


};

#endif // !defined(AFX_HMATRIX_H__696E727B_D133_4371_9E63_C166DF65E020__INCLUDED_)
