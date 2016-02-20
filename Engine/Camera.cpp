// amera.cpp: implementation of the Camera class.
//
//////////////////////////////////////////////////////////////////////

#include "Camera.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library

#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



Camera::Camera():m_lookAt(HVector::Zero), m_pos(HVector::Zero),m_up(0,1,0)
{

}

Camera::~Camera()
{

}

void Camera::SetCameraInfo()
{
	/*
gluLookAt (
	 0, 40, 10,
	 0, 0, -10, 
	 0.0, 0.0, -1.0);
*/

	gluLookAt (	m_pos[0],m_pos[1],m_pos[2],
				m_lookAt[0], m_lookAt[1], m_lookAt[2],
				m_up[0], m_up[1], m_up[2]);

}

void Camera::SetLookAt(HVector pos_cam,HVector pos_la)
{
	m_pos=pos_cam;

	HVector v_lat(pos_la-pos_cam);
	v_lat.Normalize();
	
//	v_lat=HVector (0,.99,0);

	HVector vw(0,1,0);
	
	double d = Dot(vw,v_lat);

	HVector temp=v_lat * d;

	HVector v_up=vw-temp;

	double l = v_up.GetLenght();

	HVector v_up2=vw-v_lat;
	double l2 = v_up2.GetLenght();

	if(IsZero(l))
	{
		vw=HVector(0,1,0);
	}

	//HVector right = 

/*
		t(0,1,0);
	m_lookAt=at;
	*/
}
void SetPosition(HVector pos)
{
	assert(0);

}



