// Root.h: interface for the Root class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOT_H__71A6A7B4_1F71_44B7_AA73_A2836EE90989__INCLUDED_)
#define AFX_ROOT_H__71A6A7B4_1F71_44B7_AA73_A2836EE90989__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HObject.h"

class Scene;
class Menu;


class Root
{
public:
	Root();
	virtual ~Root();

	void Tick();
	void Init();
	void UnInit();
	void Pause(bool);
	void Draw();

private:
	Menu		*m_pausemenu;//the pause menu
	Scene		*m_scene;	//the scene that contains the planets
	HObject		*m_active;	//which of the scene or menu is currently active.
};

#endif // !defined(AFX_ROOT_H__71A6A7B4_1F71_44B7_AA73_A2836EE90989__INCLUDED_)
