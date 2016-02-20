// HObject.cpp: implementation of the HObject class.
//
//////////////////////////////////////////////////////////////////////

#include "HObject.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HObject::HObject():m_posmat(HMatrix::Identity),m_rotmat(HMatrix::Identity),m_rotation(0,0,0,1)
{

}

HObject::~HObject()
{

}

void HObject::SetPosition(const HVector & pos)
{
  m_posmat.SetColumn(3,pos);  //UpdateMatrix to update
}


/*
HObject::UpdateMatrix called at each time just before drawing the object.
since object is drawn using information in its matrix, this function ensures that the object's matrix is up to date in term of orientation and position.
*/
void HObject::UpdateMatrix()
{
  //SetPosition()
  //SetRotation

	m_rotation.ToMatrix(m_rotmat);

}

void HObject::SetOrientation(const HQuaternion & q)
{
	m_rotation=q;
//	q.ToMatrix(m_rotmat);
}

void HObject::AddOrientation(const HQuaternion & q)
{
	m_rotation=m_rotation*q;
//	q.ToMatrix(m_rotmat);
}

void HObject::AddChild(HObject *c)
{
	//todo:a child might be unloaded/destroyed while game is still playing. parent must be informed.
	m_children.push_back(c);
}
