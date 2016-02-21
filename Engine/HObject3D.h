// HObject.h: interface for the HObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOBJECT3D_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_)
#define AFX_HOBJECT3D_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define __STL_USE_NEW_IOSTREAMS
//otherwise problem due to "istream" not known stl\stl_iterator.h


#include "math\HMatrix.h"
#include "math\HVector.h"
#include "MATH\HQuaternion.h"	// Added by ClassView
#include "HObject.h"


class HObject3D : public HObject  
{
protected:
	HQuaternion m_rotation;
	HMatrix m_rotmat;
	HMatrix m_posmat;//todo:vector instead of a matrix and multiply it to the global matrix in Draw

public:
	HObject3D();
	virtual ~HObject3D();

	void UpdateMatrix();

	void SetPosition(const HVector & pos);

	void SetOrientation(const HQuaternion & q);
	void AddOrientation(const HQuaternion & q);
	
};

#endif // !defined(AFX_HOBJECT3D_H__5BA56B29_9B49_4DAE_92F1_D646A0592DBD__INCLUDED_)
