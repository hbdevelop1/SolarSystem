// Scene.h: interface for the Scene class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENE_H__059DFD62_9041_4F1C_9D58_16E8FC4E9DC2__INCLUDED_)
#define AFX_SCENE_H__059DFD62_9041_4F1C_9D58_16E8FC4E9DC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\engine\HObject.h"
#include "..\engine\HGraphicObj.h"
#include <list>
#include "..\engine\Camera.h"	// Added by ClassView


class Scene : public HObject  
{
private:
	Camera			m_camera;

	static HObject* ms_lightobj; //the object emiting light (the sun)

public:

	Scene();
	~Scene();

	void Draw();

	static bool IsLit() {return (ms_lightobj!=NULL);}

};

#endif // !defined(AFX_SCENE_H__059DFD62_9041_4F1C_9D58_16E8FC4E9DC2__INCLUDED_)
