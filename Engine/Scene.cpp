// Scene.cpp: implementation of the Scene class.
//
//////////////////////////////////////////////////////////////////////

#include "Scene.h"
#include <algorithm>
#include <boost/mem_fn.hpp>
#include "..\game\Sun.h" //todo : to correct : engine files should be independent from the game files.
#include "xml\xml.h"
#include <map>
#include <assert.h>

#include <windows.h>		// Header File For Windows

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//#define DataPath	"..\\..\\data"
HGraphicObj * Scene::ms_lightobj = NULL;

/*
at scene creation, data is loaded/set.
data = {actors, cameras, any other future data}
actors = {sun, planets, ...}
*/
Scene::Scene()
{

	XmlParser xmlParser;
	XmlNodeRef rootNode= xmlParser.parse( DataPath"\\map.xml" );

	
	if (!rootNode) 
	{
		//todo : endprocess(); roll back allocation and end game
		MessageBox(NULL,"Problème de données.\nRépertoire \"data\" ou fichier \"map.xml\" introuvable.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		assert(0);
	}


	typedef std::map<String,HGraphicObj*> MapOfObjectsType;

	MapOfObjectsType mapofobjects;
	int i;
	HGraphicObj *o ;
	for (i = 0; i < rootNode->getChildCount(); i++) 
	{
		XmlNodeRef child = rootNode->getChild(i);
		if (child->isTag("actor")) 
		{
			String name = child->getAttribute("name");
			String type = child->getAttribute("type");
			String data = child->getAttribute("datafile");
			String animation = child->getAttribute("animationfile");

			String position = child->getAttribute("position");


/*
todo:set position and orientation for objects without anim
			String orientation = child->getAttribute("orientation");
*/
			//todo : use factory method 
			if(type == "Sun")
			{
				o= new Sun(data.c_str());
				ms_lightobj=o;
			}
			else
				o= new HGraphicObj(data.c_str());

			
			if(!animation.empty())
				o->LoadAnimation(animation.c_str());

			HVector pos;
#if _MSC_VER<=1200
			sscanf(position.c_str(),"%f %f %f",&pos[0],&pos[1],&pos[2]);
#else
			sscanf_s(position.c_str(),"%f %f %f",&pos[0],&pos[1],&pos[2]);
#endif
			o->SetPosition(pos);




			MapOfObjectsType::value_type p(name,o);
			mapofobjects.insert(p);




			String parent = child->getAttribute("parent");
			
			if (!parent .empty()) 
			{
				MapOfObjectsType::iterator it = mapofobjects.find(parent);
				if (it == mapofobjects.end())
				{
					//todo:problem : parent doesn't exist; or not yet loaded
				}
				else
					(*it).second->AddChild(o);
			}
			else
			{
				//scene will be the parent
				this->AddChild(o);
			}
		}
	}

//todo:make sure all objects have their wanted parents.

	MapOfObjectsType::iterator it;
	for(it=mapofobjects.begin(); it!=mapofobjects.end(); it++)
	{
		m_objects.push_back((*it).second);
	}

	
/*
	HVector la(0, 0, 0),pos(20, 50, 50);//bug : Z can't be 0 !!!
	m_camera.SetPosition(pos);
	m_camera.SetLookAt(la);
	*/

	HVector pos_la(0, 0, 0),pos_cam(20, 50, 50);
	m_camera.SetLookAt(pos_cam,pos_la);
}


/*
free all resources
*/
Scene::~Scene()
{
  for(GraphicsList::iterator it=m_objects.begin(); it!=m_objects.end(); it++)
  {
	HGraphicObj * object = *it;
	delete object;
  }
  m_objects.clear();


	ms_lightobj = NULL;
}

/*
1-set camera
2-draw each actor in the list
*/
void Scene::Draw()
{
	m_camera.SetCameraInfo();

	std::for_each(m_children.begin(), m_children.end(), boost::mem_fn(&HObject::Draw));
	//std::mem_fun can only be used with non void returning member functions. so must use boost::mem_fn


}

/*
-call the init function of each actor
*/
void Scene::Init()
{
  std::for_each(m_objects.begin(), m_objects.end(), boost::mem_fn(&HObject::Init));

}

/*
-update each actor
*/
void Scene::Tick()
{
  std::for_each(m_objects.begin(), m_objects.end(), boost::mem_fn(&HObject::Tick));

}
