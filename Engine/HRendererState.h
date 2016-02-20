// HRendererState.h: interface for the HRendererState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HRendererState_H__9407D0C2_E96B_4EB2_A66E_0E6D6B5FA96E__INCLUDED_)
#define AFX_HRendererState_H__9407D0C2_E96B_4EB2_A66E_0E6D6B5FA96E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library


class HRendererState
{
	HRendererState();
	HRendererState(const HRendererState&);
	HRendererState & operator=(const HRendererState&);

	

	struct
	{
		int width;
		int height;

	} m_viewport;


public:
	~HRendererState();

	static HRendererState & GetInstance()
	{
		static HRendererState instance;
		return instance;
	}

	void Init();
	void PreDraw();
	void Draw();
	
	void SetLight(int l);
	int GetLight() ;
};

#endif // !defined(AFX_HRendererState_H__9407D0C2_E96B_4EB2_A66E_0E6D6B5FA96E__INCLUDED_)
