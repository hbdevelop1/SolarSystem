// HRendererState.cpp: implementation of the HRendererState class.
//
//////////////////////////////////////////////////////////////////////

#include "HRendererState.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////




HRendererState::HRendererState()
{
	m_viewport.width =640;
	m_viewport.height=480;

	glViewport(0,0,m_viewport.width,m_viewport.height );						// Reset The Current Viewport

}


HRendererState::~HRendererState()
{

}


void HRendererState::Init()
{
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)m_viewport.width/(GLfloat)m_viewport.height,0.1f,200.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix


	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.f, 0.f, 0.f, 0.f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void HRendererState::PreDraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();	
}

void HRendererState::Draw()
{
}

void HRendererState::SetLight(int l)
{
	if(l)
	{
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHTING);
	}
}

int HRendererState::GetLight() 
{
	GLboolean param;
	glGetBooleanv(GL_LIGHTING, &param);
	return param;
}
