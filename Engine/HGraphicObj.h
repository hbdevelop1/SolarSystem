// HGraphicObj.h: interface for the HGraphicObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HGRAPHICOBJ_H__28C8A61B_3D49_44BA_ACC5_91F6D54972E3__INCLUDED_)
#define AFX_HGRAPHICOBJ_H__28C8A61B_3D49_44BA_ACC5_91F6D54972E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "math\HVector.h"

#include <list>

class HObject3D;


struct stVertex
{
  HVector	c;
  HVector	texcoord;
};

struct stQuad
{
  stVertex	v[4];
  HVector	normal;
  HVector	color;
};


typedef std::list<stQuad*> QuadsList;


class HAnimation;


/*
A graphic object has a list of quads, an animation.
*/
class HGraphicObj //: public HObject3D  
{
protected:
	QuadsList	m_quads;
	HAnimation	*m_anim;
	bool		m_dataloaded;

	struct 
	{
		int				present;	//does the HGraphicObject has a texture.
		unsigned int	id;			//the id of the texture. Obtained at loading time.
	}m_texture;


public:
	HGraphicObj(const char * filename);
	virtual ~HGraphicObj();

	void Tick();
	void Draw();

	void LoadAnimation(const char *, HObject3D *);
	void SetLight(HVector pos);

	friend HAnimation;
};

#endif // !defined(AFX_HGRAPHICOBJ_H__28C8A61B_3D49_44BA_ACC5_91F6D54972E3__INCLUDED_)
