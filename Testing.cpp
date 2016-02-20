// Testing.cpp: implementation of the Testing class.
//
//////////////////////////////////////////////////////////////////////

#include "Testing.h"

#include "engine\math\hquaternion.h"
#include <math.h>

#include <assert.h>


#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library


#include "Engine\HObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
/*
double pi = 3.1415926535;
   double x, y;

   x = pi / 2;
*/


Testing::Testing()
{

  {
	double cos_a , sin_a,angle;

 angle = M_PI/2;
 sin_a = sin( angle );
 cos_a = cos( angle );

 angle = M_PI/4;
 sin_a = sin( angle );
 cos_a = cos( angle );

 angle = M_PI/6;
 sin_a = sin( angle );
 cos_a = cos( angle );

 angle = M_PI/12;
 sin_a = sin( angle );
 cos_a = cos( angle );

  }

  {
  double angle = M_PI/2;
  HVector v(0,1,0);
  HQuaternion q(angle,v);

  double scos = cos(angle/2);
  double ssin = sin(angle/2);
  
  assert(IsZero(q[0]) && IsZero(q[1]-ssin) && IsZero(q[2]) && IsZero(q[3]-scos));
}
  {
  double angle = M_PI;
  HVector v(0,1,0);
  HQuaternion q(angle,v);

  double scos = cos(angle/2);
  double ssin = sin(angle/2);
  
  assert(IsZero(q[0]) && IsZero(q[1]-ssin) && IsZero(q[2]) && IsZero(q[3]-scos));
}
  {
  double angle = 3*M_PI/2;
  HVector v(0,1,0);
  HQuaternion q(angle,v);

  double scos = cos(angle/2);
  double ssin = sin(angle/2);
  
  assert(IsZero(q[0]) && IsZero(q[1]-ssin) && IsZero(q[2]) && IsZero(q[3]-scos));
}
  {
  double angle = 2*M_PI;
  HVector v(0,1,0);
  HQuaternion q(angle,v);

  double scos = cos(angle/2);
  double ssin = sin(angle/2);
  
  assert(IsZero(q[0]) && IsZero(q[1]-ssin) && IsZero(q[2]) && IsZero(q[3]-scos));
}
  {
//rotation angle = 0 around vector (0,1,0) => q(0,0,0,1)
  double angle = 0;
  HVector v(0,1,0);
  HQuaternion q(angle,v);

  double scos = cos(angle/2);
  double ssin = sin(angle/2);
  
  assert(q[0]== (ssin * 0) && q[1]== (ssin * 0) && q[2]== (ssin * 0) && q[3]== scos);
  }

  {
//rotation angle = Pi/2 around vector (0,1,0) => 
  double angle = M_PI/2;
  HVector v(0,1,0);
  HQuaternion q(angle,v);

  double scos = cos(angle/2);
  double ssin = sin(angle/2);
  
  assert(q[0]== (ssin * 0) && q[1]== (ssin * 1) && q[2]== (ssin * 0) && q[3]== scos);
  }

  {
//from a quaternion to matrix and  verify that the produced matrix is correct
  //q(0,1,0,) for rotation Pi/2 around vector (0,1,0) 
  double angle = M_PI/2;
  HVector v(0,1,0);
  HQuaternion q(angle,v);
  HMatrix mat;
  q.ToMatrix(mat);

  }

  {
//from a quaternion to matrix and  verify that the produced matrix is correct
  //q(0,1,0,) for rotation Pi/2 around vector (0,0,1) 
  double angle = M_PI/2;
  HVector v(0,0,1);
  HQuaternion q(angle,v);
  HMatrix mat;
  q.ToMatrix(mat);

  }


  {
//rotation angle = Pi/6 around vector (0,0,1) => 

	double angle = M_PI/6;
	HVector v(0,0,1);
	HQuaternion q(angle,v);
	HMatrix mat;
	q.ToMatrix(mat);

  }


  {
	HMatrix t,m(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
	m.Transpose(t);
	assert(t.GetElements()[2*4+0] == m.GetElements()[0*4+2] && t.GetElements()[3*4+1] == m.GetElements()[1*4+3]);
  }



  {
//shall i transpose ?
//get the opengl constructed matrix and compare it to mine

#define Rad2Deg(r) (r * 180.f / M_PI)

	GLdouble gl_mat[16];
  //q(0,1,0,) for rotation Pi/2 around vector (0,0,1) 

	//preserve the current mode
	GLint matrix_mode_2_restore_after_test;
	glGetIntegerv(GL_MATRIX_MODE,&matrix_mode_2_restore_after_test);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotated(Rad2Deg(M_PI/2),0.0f,0.0f,1.0f);
	glGetDoublev(GL_MODELVIEW_MATRIX, gl_mat);

	glMatrixMode(matrix_mode_2_restore_after_test);


  double angle = M_PI/2;
  HVector v(0,0,1);
  HQuaternion q(angle,v);
  HMatrix mat;
  q.ToMatrix(mat);

  }


  {
	  double PI_Over_4 = atan(1.);
	  double PI_Over_2 = PI_Over_4 * 2;
	  double PI = PI_Over_4 * 4;

	  double sin_PI = sin(PI);
	  double cos_PI = cos(PI);

		double tostopdebug=1;
  }

	{
		HVector v0(0,0,-15), v1(-15,0,0), v2(0,0,15), v3(15,0,0);

		double angle0 = GetAngle(v0, v1);
	  double angle1 = GetAngle(v1, v2);
	  double angle2 = GetAngle(v2, v3);
	  double angle3 = GetAngle(v3, v0);

	  double PI_Over_2 = 2 * atan(1.);


		assert(angle0 == PI_Over_2);
		assert(angle1 == PI_Over_2);
		assert(angle2 == PI_Over_2);
		assert(angle3 == PI_Over_2);

	}

	{//test 12/07/2011-13:19:56
		HVector v0(0,0,-15), v1(-15,0,0), v2(0,0,15), v3(15,0,0);

		double framediv = 0.5;
		
		HVector loc = Interpolate( v0, v1, framediv);
		
		GLdouble gl_mat[16];
		HVector c;
		HVector4 t4_0,t4_1; 
		{

			//preserve the current mode
			GLint matrix_mode_2_restore_after_test;
			glGetIntegerv(GL_MATRIX_MODE,&matrix_mode_2_restore_after_test);
			glMatrixMode(GL_MODELVIEW);

			glLoadIdentity();
			glRotated(45.f, 0.0f, 1.0f, 0.f);
			glGetDoublev(GL_MODELVIEW_MATRIX, gl_mat);

			glMatrixMode(matrix_mode_2_restore_after_test);
		}
		HMatrix r(gl_mat);
		t4_0=v0;
		t4_1=r*t4_0;
		c=t4_1;

		
		HVector f = loc-c; 		f.Validate();
		assert(f == HVector::Zero);

		c.Normalize();

  }

	{//test multiplication
		HQuaternion q1(M_PI/6,HVector(0,1,0));
		HQuaternion q2(M_PI/6,HVector(0,1,0));
		HQuaternion q3(M_PI/3,HVector(0,1,0));
		HQuaternion q=q2*q1;
		assert(q3==q);
	}
	{//test multiplication
		HQuaternion q1(M_PI/12,HVector(0,1,0));
		HQuaternion q2(M_PI/6,HVector(0,1,0));
		HQuaternion q3(M_PI/4,HVector(0,1,0));
		HQuaternion q=q2*q1;
		assert(q3==q);
	}


  {//combination of quaternions : a rotation by q2*q1 should yield a same rotation by q1 and then by q2

	HQuaternion q1(M_PI/4,HVector(0,1,0));
	HQuaternion q2(M_PI/4,HVector(0,1,0));
	HVector4 po(1,0,0,1); //a point
	GLdouble gl_mat[16];



//product of two quaternions, conversion to matrix, rotation. pnQ is the new point after rotation
	HQuaternion q=q2*q1;
	HMatrix mat;
	q.ToMatrix(mat);

	//Init context{
	GLint matrix_mode_2_restore_after_test;
	glGetIntegerv(GL_MATRIX_MODE,&matrix_mode_2_restore_after_test);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); 
	//}


	HVector4 pnQ;

	glLoadIdentity();
	glMultMatrixd(mat.GetElements());
	glGetDoublev(GL_MODELVIEW_MATRIX, gl_mat);
	HMatrix r(gl_mat);
	pnQ=r*po;


	//Deinit context {
	glPopMatrix();
	glMatrixMode(matrix_mode_2_restore_after_test);
	//}


//conversion of each quaternion to matrix, product of the two matrices, rotation. pnM is the new point after rotation
	HMatrix mat1;
	q1.ToMatrix(mat1);
	HMatrix mat2;
	q2.ToMatrix(mat2);


	//Init context{
	glGetIntegerv(GL_MATRIX_MODE,&matrix_mode_2_restore_after_test);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); 
	//}


	HVector4 pnM;

	glLoadIdentity();
	glMultMatrixd(mat1.GetElements());
	glMultMatrixd(mat2.GetElements());
	glGetDoublev(GL_MODELVIEW_MATRIX, gl_mat);
	HMatrix r1(gl_mat);
	pnM=r1*po;


	//Deinit context {
	glPopMatrix();
	glMatrixMode(matrix_mode_2_restore_after_test);
	//}


	assert(pnM==pnQ);

  }



}

Testing::~Testing()
{

}
