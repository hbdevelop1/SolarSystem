// HMatrix.cpp: implementation of the HMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "HMatrix.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const HMatrix HMatrix::Identity=HMatrix (1,0,0,0,
								  0,1,0,0,
								  0,0,1,0,
								  0,0,0,1);

HMatrix::HMatrix(float a,float b,float c,float d,
		  float e,float f,float g,float h,
		  float i,float j,float k,float l,
		  float m,float n,float o,float p
		)
{
  t[0]=a;	t[1]=e;	  t[2]=i;	t[3]=m;
  t[4]=b;	t[5]=f;	  t[6]=j;	t[7]=n;
  t[8]=c;	t[9]=g;	  t[10]=k;	t[11]=o;
  t[12]=d;	t[13]=h;  t[14]=l;	t[15]=p;

}

HMatrix::HMatrix(double *a)
{
  for(int i =0; i<16; i++)
	  t[i] = a[i];

}


void HMatrix::SetColumn(int c,HVector v)
{

  t[c*4+0]=v[0];
  t[c*4+1]=v[1];
  t[c*4+2]=v[2];


}

void HMatrix::Validate()
{
  for(int i =0; i<16; i++)
	if (IsZero(t[i]))
	  t[i] = 0;
}

void HMatrix::Transpose(HMatrix & out)
{
  for(int i=0; i<4; i++)
	for(int j=0; j<4; j++)
	{
	  out.t[j*4+i] = t[i*4+j];
	}
}



HVector4 operator*(HMatrix m, HVector4 v)
{
	HVector4 r;

	r[0]=m.GetElements()[0*4+0] * v[0] + m.GetElements()[1*4+0] * v[1] + m.GetElements()[2*4+0] * v[2] + m.GetElements()[3*4+0] * v[3];
	r[1]=m.GetElements()[0*4+1] * v[0] + m.GetElements()[1*4+1] * v[1] + m.GetElements()[2*4+1] * v[2] + m.GetElements()[3*4+1] * v[3];
	r[2]=m.GetElements()[0*4+2] * v[0] + m.GetElements()[1*4+2] * v[1] + m.GetElements()[2*4+2] * v[2] + m.GetElements()[3*4+2] * v[3];
	r[3]=m.GetElements()[0*4+3] * v[0] + m.GetElements()[1*4+3] * v[1] + m.GetElements()[2*4+3] * v[2] + m.GetElements()[3*4+3] * v[3];
	

	return r;
}
