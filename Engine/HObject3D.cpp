// HObject.cpp: implementation of the HObject class.
//
//////////////////////////////////////////////////////////////////////

#include "HObject3D.h"
#include <windows.h>	
#include <gl\gl.h>
#include <boost/mem_fn.hpp>
#include <algorithm>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HObject3D::HObject3D():m_posmat(HMatrix::Identity),m_rotmat(HMatrix::Identity),m_rotation(0,0,0,1)
{

}

HObject3D::~HObject3D()
{

}

void HObject3D::SetPosition(const HVector & pos)
{
  m_posmat.SetColumn(3,pos);  //UpdateMatrix to update
}


/*
HObject::UpdateMatrix called at each time just before drawing the object.
since object is drawn using information in its matrix, this function ensures that the object's matrix is up to date in term of orientation and position.
*/
void HObject3D::UpdateMatrix()
{
  //SetPosition()
  //SetRotation

	m_rotation.ToMatrix(m_rotmat);

}

void HObject3D::SetOrientation(const HQuaternion & q)
{
	m_rotation=q;
//	q.ToMatrix(m_rotmat);
}

void HObject3D::AddOrientation(const HQuaternion & q)
{
	m_rotation=m_rotation*q;
//	q.ToMatrix(m_rotmat);
}
