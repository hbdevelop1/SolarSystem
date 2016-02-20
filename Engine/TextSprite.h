// TextSprite.h: interface for the TextSprite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTSPRITE_H__49D8FD07_8576_431E_8800_FCB1729CB227__INCLUDED_)
#define AFX_TEXTSPRITE_H__49D8FD07_8576_431E_8800_FCB1729CB227__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <string>

#define H_Invalid_DL	(-5)

class TextSprite  
{
	static GLuint	ms_dlbase;

	static TextSprite s_inst;

	TextSprite();
	TextSprite(const TextSprite &);
	TextSprite & operator=(const TextSprite &);

public:
	static TextSprite & getInstance() 
	{
		if(TextSprite::ms_dlbase ==H_Invalid_DL)	Init();
		return s_inst;
	}

	virtual ~TextSprite();

	static void Init();

	static void Draw(std::string  txt, int x, int y);

};

#endif // !defined(AFX_TEXTSPRITE_H__49D8FD07_8576_431E_8800_FCB1729CB227__INCLUDED_)
