// Menu.cpp: implementation of the Menu class.
//
//////////////////////////////////////////////////////////////////////

#include "Menu.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library


#include "..\engine\hevent.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Menu::Menu()
{
	m_but[e_continue].Init("menu/earth_tex",HVector(2,0,0));
	m_but[e_quit].Init("menu/moon_tex",HVector(-2,0,0));

	Event::RegisterHandler(Event::event_click,this,&Menu::Click);
}

Menu::~Menu()
{
	Event::UnRegisterHandler(Event::event_click);

}

void Menu::Tick()
{
	/*
	listen to click messages and react approprietly
	*/
	m_but[e_continue].Tick(); //respond to possible event
	m_but[e_quit].Tick();
}


void Menu::Draw()
{

	Draw(true);


}

void Menu::Draw(bool render)
{
	glPushMatrix(); 

	glLoadIdentity();	
	glTranslatef(0.0f,0.0f,-7.0f);
//	glRasterPos2f(0, 0);

	if(render)
	{
	glEnable(GL_BLEND);      // Turn Blending On 
	glDisable(GL_DEPTH_TEST);   
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_QUADS);						
			glColor4f(1.0f,0.0f,0.0f,0.5);			
			glVertex3f( 3.0f, 3.0f,0.0f);		
			glVertex3f(-3.0f, 3.0f,0.0f);		
			glVertex3f(-3.0f, -3.0f, 0.0f);		
			glVertex3f( 3.0f, -3.0f, 0.0f);		
		glEnd();
	glDisable(GL_BLEND);      // Turn Blending On 
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
		
	}

	
	glLoadName(e_continue);		m_but[e_continue].Draw();
	glLoadName(e_quit);			m_but[e_quit].Draw();  

	glPopMatrix(); 
}



void Menu::Click(int x, int y)
{
	int mouse_x = x;
	int mouse_y=y;



	GLuint	buffer[512];										// Set Up A  Buffer
	GLint	hits;												// The Number Of Objects That We Selected

	
	// The Size Of The Viewport. [0] Is <x>, [1] Is <y>, [2] Is <length>, [3] Is <width>
	GLint	viewport[4];

	// This Sets The Array <viewport> To The Size And Location Of The Screen Relative To The Window
	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(512, buffer);								// Tell OpenGL To Use Our Array For 

	// Puts OpenGL In  Mode. Nothing Will Be Drawn.  Object ID's and Extents Are Stored In The Buffer.
	(void) glRenderMode(GL_SELECT);

	glInitNames();												// Initializes The Name Stack
	glPushName(0);												// Push 0 (At Least One Entry) Onto The Stack

	glMatrixMode(GL_PROJECTION);								// Selects The Projection Matrix
	glPushMatrix();												// Push The Projection Matrix
	glLoadIdentity();											// Resets The Matrix

	// This Creates A Matrix That Will Zoom Up To A Small Portion Of The Screen, Where The Mouse Is.
	gluPickMatrix((GLdouble) mouse_x, (GLdouble) (viewport[3]- mouse_y), 1.0f, 1.0f, viewport);

	// Apply The Perspective Matrix
	gluPerspective(45.0f, (GLfloat) (viewport[2]-viewport[0])/(GLfloat) (viewport[3]-viewport[1]), 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);									// Select The Modelview Matrix


	Draw(false);
	
	glMatrixMode(GL_PROJECTION);								// Select The Projection Matrix
	glPopMatrix();												// Pop The Projection Matrix

	glMatrixMode(GL_MODELVIEW);									// Select The Modelview Matrix
	
	hits=glRenderMode(GL_RENDER);								// Switch To Render Mode, Find Out How Many
																// Objects Were Drawn Where The Mouse Was
	int	choose =-6;
	if (hits > 0)												// If There Were More Than 0 Hits
	{
		if(buffer[3]==e_continue)
		{
			//remove menu and start ticking the scene;
			Event::Handle(Event::event_pause, false);
		}
		else //(buffer[e_quit])
		{
			//quit
			Event::Handle(Event::event_quit);
		}
    }
}



