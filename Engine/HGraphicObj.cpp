// HGraphicObj.cpp: implementation of the HGraphicObj class.
//
//////////////////////////////////////////////////////////////////////

#include "HGraphicObj.h"

#include <windows.h>	
#include <gl\gl.h>
#include <gl\glu.h>	
#include <gl\glaux.h>

#if _MSC_VER<=1200
#include <fstream.h>
#else
#include <iosfwd>
#endif

#include "anim\liban8\An8Loader.h"
#include <assert.h>
#include <crtdbg.h>
#include "anim\HAnimation.h"
#include <algorithm>
#include <boost/mem_fn.hpp>
#include "htexture.h"
#include "Scene.h"
#include "HRendererState.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/*
at the creation of the graphic object, load its corresponding data.
data = {goemetry,texture, animation, ...}
*/
HGraphicObj::HGraphicObj(const char * filename):m_anim(NULL)
{
  /*
  create a file reader object;
  fill in the m_quads;
  */
	std::string s=DataPath;
	s+="\\";
	s+=filename;

	std::ifstream file(s.c_str());

	int nbrOfQuads;
	file >> nbrOfQuads;
	file >> m_texture.present;

	if(m_texture.present)
	{
		std::string bmpfile;
		do
		{
			std::getline( file,bmpfile , '\n' );
		}
		while(bmpfile.empty());

		s=DataPath;
		s+="\\";	
		s+=bmpfile;

		assert(LoadGLTextures(s.c_str(),&m_texture.id)==true);
	}


	stQuad *q;

	for(int i=0; i<nbrOfQuads; i++)
	{
		q = new stQuad;

		if(m_texture.present)
		{
			file >> q->normal[0] >> q->normal[1] >> q->normal[2] ;
			file >> q->v[0].texcoord[0] >> q->v[0].texcoord[1] >> q->v[0].c[0] >> q->v[0].c[1] >> q->v[0].c[2];
			file >> q->v[1].texcoord[0] >> q->v[1].texcoord[1] >> q->v[1].c[0] >> q->v[1].c[1] >> q->v[1].c[2];
			file >> q->v[2].texcoord[0] >> q->v[2].texcoord[1] >> q->v[2].c[0] >> q->v[2].c[1] >> q->v[2].c[2];
			file >> q->v[3].texcoord[0] >> q->v[3].texcoord[1] >> q->v[3].c[0] >> q->v[3].c[1] >> q->v[3].c[2];
		}
		else
		{
			file >> q->color[0] >> q->color[1] >> q->color[2];
			file >> q->v[0].c[0] >> q->v[0].c[1] >> q->v[0].c[2];
			file >> q->v[1].c[0] >> q->v[1].c[1] >> q->v[1].c[2];
			file >> q->v[2].c[0] >> q->v[2].c[1] >> q->v[2].c[2];
			file >> q->v[3].c[0] >> q->v[3].c[1] >> q->v[3].c[2];
		}


		m_quads.push_back(q);
	}

	file.close();



}

/*
destruct and free resources
*/
HGraphicObj::~HGraphicObj()
{

  	for(QuadsList::iterator it=m_quads.begin(); it!=m_quads.end(); it++)
	{
	  stQuad * q = *it;
	  delete q;
	}

	m_quads.clear();


	delete m_anim;
}


/*
HGraphicObj::Draw
to draw an object, its position and orientation are first set in the global matrix
to draw its children, care is taken to pass parent position information to them
care is taken also to not pass orientation information.

1-set position information in the global matrix
2-push matrix
3-set rotation in the global matrix
4-draw object
5-pop matrix to erase rotation information
6-draw children
7-pop matrix

*/
void HGraphicObj::Draw()
{
	UpdateMatrix();

	glPushMatrix(); //i will alter the toppest matrix. so save it first. to be able to dispaly non children object.

	glMultMatrixd(m_posmat.GetElements());

	glPushMatrix(); //save the position for children to draw relative to it.

	glMultMatrixd(m_rotmat.GetElements());


	if(m_texture.present)
	{
		glEnable(GL_TEXTURE_2D);							
		glBindTexture(GL_TEXTURE_2D, m_texture.id);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

		//if(Scene::IsLit())
		if(HRendererState::GetInstance().GetLight())
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //light is on
		else
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}

	glBegin(GL_QUADS);	// Draw A Quad

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

	glEnd();	// Done Drawing The Quad

	if(m_texture.present)
	{
		glDisable(GL_TEXTURE_2D);							
	}



	glPopMatrix(); //get the position saved previously, and erase rotation by the same occasion, before starting drawing children

	std::for_each(m_children.begin(), m_children.end(), boost::mem_fn(&HObject::Draw));
	//std::mem_fun can only be used with non void returning member functions. so must use boost::mem_fn


	glPopMatrix();
}


/*
Load animation function.
called at the creation time of the object
*/
void HGraphicObj::LoadAnimation(const char *filename)
{
	An8File an8File;

	std::string s=DataPath;
	s+="\\";
	s+=filename;

	if( an8File.LoadFile(s) == false)
	{
		//assert(false);
	  return;
	}

	An8Scene &sc = *an8File.vScenes.begin();
	An8ObjectElement &oe = *sc.vObjectElements.begin();

	m_anim = new HAnimation(this, oe);
}

/*
HGraphicObj::Tick function to update the animation of the object each frame.
called from Scene::Tick
*/
void HGraphicObj::Tick()
{

  if(!m_anim)
	return;

  m_anim->Update();

}

