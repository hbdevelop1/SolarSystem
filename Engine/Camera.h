// amera.h: interface for the Camera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMERA_H__AF63C3DF_C551_4CE7_A61A_CBB7B5D39D2E__INCLUDED_)
#define AFX_AMERA_H__AF63C3DF_C551_4CE7_A61A_CBB7B5D39D2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HObject3D.h"
#include "MATH\HVector.h"	// Added by ClassView

class Camera : public HObject3D
{
public:
	Camera();
	virtual ~Camera();

	void SetCameraInfo();
	//void SetLookAt(HVector at);
	//void SetPosition(HVector pos);
	void SetLookAt(HVector pos_cam,HVector pos_la);


private:
	HVector m_up;
	HVector m_lookAt;
	HVector m_pos; //todo:should have a position vector in HObject 
};

#endif // !defined(AFX_AMERA_H__AF63C3DF_C551_4CE7_A61A_CBB7B5D39D2E__INCLUDED_)
