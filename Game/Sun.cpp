// Sun.cpp: implementation of the Sun class.
//
//////////////////////////////////////////////////////////////////////

#include "Sun.h"

#include <windows.h>	
#include <gl\gl.h>
#include <gl\glu.h>	
#include <gl\glaux.h>


#include <algorithm>
#include <boost/mem_fn.hpp>

#include "..\Engine\HRendererState.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Sun::Sun(const char * filename):HGraphicObj(filename)
//,m_light(NULL)
{

}

Sun::~Sun()
{
//	delete m_light;

}




/*
void Scene::SetLight(HVector pos)
{
	m_light = new stLight;

	m_light->pos = pos;

	m_light->ambient[0] = 0;
	m_light->ambient[1] = 0;
	m_light->ambient[2] = 0;
	m_light->ambient[3] = 1;

	m_light->diffuse[0] = 1;
	m_light->diffuse[1] = 1;
	m_light->diffuse[2] = 1;
	m_light->diffuse[3] = 1;
}
*/

void Sun::DrawSpecifics()
{

//	if(m_light) //the sun
	{
		GLfloat pos[] = { 0, 0, 0, 1/*positional*/ };
		GLfloat ambient[] = { 1, 1, 1, 1.0 };
		GLfloat diffuse[] = { 1, 1, 1, 1.0 };
		GLfloat specul[] = { 0, 0, 0, 1.0 };

		GLfloat model_ambient[] = { .5f, 0.5f, 0.5f, 1.0f };
		
		glLightfv(GL_LIGHT1, GL_POSITION,pos);//todo:use the position of the current obj (this)
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, specul);

		glEnable(GL_LIGHT1);
		glDisable(GL_LIGHT0);

//		light model ???
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient); 
		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);	//one sided effect
		
		//glEnable(GL_LIGHTING);
		HRendererState::GetInstance().SetLight(true);

	}

	if(m_texture.present)
	{
		glEnable(GL_TEXTURE_2D);							
		glBindTexture(GL_TEXTURE_2D, m_texture.id);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //sun is not subject to light. its texture is displayed with no color alteration
	}

	glBegin(GL_QUADS);									// Draw A Quad

	for(QuadsList::iterator it=m_quads.begin(); it!=m_quads.end(); it++)
	{
		stQuad * q = *it;

		if(m_texture.present)
		{
			glNormal3d(q->normal[0],q->normal[1],q->normal[2]);
			glTexCoord2d(q->v[0].texcoord[0], q->v[0].texcoord[1]);		glVertex3d(q->v[0].c[0], q->v[0].c[1], q->v[0].c[2]);
			glTexCoord2d(q->v[1].texcoord[0], q->v[1].texcoord[1]);		glVertex3d(q->v[1].c[0], q->v[1].c[1], q->v[1].c[2]);
			glTexCoord2d(q->v[2].texcoord[0], q->v[2].texcoord[1]);		glVertex3d(q->v[2].c[0], q->v[2].c[1], q->v[2].c[2]);
			glTexCoord2d(q->v[3].texcoord[0], q->v[3].texcoord[1]);		glVertex3d(q->v[3].c[0], q->v[3].c[1], q->v[3].c[2]);
		}
		else
		{
			glColor3d(q->color[0], q->color[1], q->color[2]);
			glVertex3d(q->v[0].c[0], q->v[0].c[1], q->v[0].c[2]);
			glVertex3d(q->v[1].c[0], q->v[1].c[1], q->v[1].c[2]);
			glVertex3d(q->v[2].c[0], q->v[2].c[1], q->v[2].c[2]);
			glVertex3d(q->v[3].c[0], q->v[3].c[1], q->v[3].c[2]);
		}
	}

	glEnd();											// Done Drawing The Quad

	if(m_texture.present)
	{
		glDisable(GL_TEXTURE_2D);							
	}

}