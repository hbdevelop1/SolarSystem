// Scene.h: interface for the Scene class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENE_H__059DFD62_9041_4F1C_9D58_16E8FC4E9DC2__INCLUDED_)
#define AFX_SCENE_H__059DFD62_9041_4F1C_9D58_16E8FC4E9DC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HObject.h"
#include "HGraphicObj.h"
#include <list>
#include "Camera.h"	// Added by ClassView

typedef std::list<HGraphicObj*> GraphicsList;


class Scene : public HObject  
{
private:
	Camera			m_camera;
	GraphicsList	m_objects;
  //list and not deque or vector, in order to insert at any location in the collection. for objects that depend on others.


	static HGraphicObj* ms_lightobj; //the object emiting light (the sun)

public:

	Scene();
	virtual ~Scene();

	void Tick();
	void Init();
	void Draw();

	static bool IsLit() {return (ms_lightobj!=NULL);}

};

#endif // !defined(AFX_SCENE_H__059DFD62_9041_4F1C_9D58_16E8FC4E9DC2__INCLUDED_)
