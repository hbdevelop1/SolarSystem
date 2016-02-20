// HButton.cpp: implementation of the HButton class.
//
//////////////////////////////////////////////////////////////////////

#include "HButton.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void HButton::Init(char * filename,HVector pos)
{
	m_graphic = new HGraphicObj(filename);
	m_graphic->SetPosition(pos);
}

HButton::~HButton()
{
	delete m_graphic;

}

void HButton::Tick()
{

}

void HButton::Draw()
{

	m_graphic->Draw();
}

