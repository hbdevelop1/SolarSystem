// HObject.cpp: implementation of the HObject class.
//
//////////////////////////////////////////////////////////////////////

#include "SpaceObject.h"
#include <windows.h>	
#include <gl\gl.h>
#include <boost/mem_fn.hpp>
#include <algorithm>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SpaceObject::SpaceObject(const char * filename):HGraphicObj(filename)
{

}

SpaceObject::~SpaceObject()
{

}


void SpaceObject::Draw()
{

  UpdateMatrix();

  glPushMatrix(); //i will alter the toppest matrix. so save it first. to be able to dispaly non children object.

  /*
  //set position in the global matrix
  position is always in a vector;
  multiply the global matrix with vector;

  //push matrix


  //set rotation in the global matrix
  //draw object
  //pop matrix
  //draw children
  //pop matrix
*/
	glMultMatrixd(m_posmat.GetElements());

	glPushMatrix(); //save the position for children

	glMultMatrixd(m_rotmat.GetElements());
	
	//DrawSpecifics();
	HGraphicObj::Draw();

	glPopMatrix(); //to start drawing children

	HObject3D::Draw();


	glPopMatrix();


}


void SpaceObject::TickSpecifics()
{
	HGraphicObj::Tick();
}