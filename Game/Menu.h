// Menu.h: interface for the Menu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENU_H__AADA2CED_D8A7_4611_9559_5E1E796D927D__INCLUDED_)
#define AFX_MENU_H__AADA2CED_D8A7_4611_9559_5E1E796D927D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ENGINE\HObject.h"
#include "..\ENGINE\HButton.h"

/*
menu is made up of two buttons (graphic objects)
when click is detected on a button, action is undertaken.
*/
class Menu : public HObject  
{
	enum
	{
		e_continue,
		e_quit,
		e_nbr_of_buttons
	};
	
	HButton m_but[e_nbr_of_buttons];
	

public:
	Menu();
	virtual ~Menu();

	void Draw();
	void Draw(bool render);
	void Tick();
	void Selection();
	void Click(int x, int y);
};

#endif // !defined(AFX_MENU_H__AADA2CED_D8A7_4611_9559_5E1E796D927D__INCLUDED_)
