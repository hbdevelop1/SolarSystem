// Scene.cpp: implementation of the Scene class.
//
//////////////////////////////////////////////////////////////////////

#include "Scene.h"
#include <algorithm>
#include <boost/mem_fn.hpp>
#include "Sun.h"
#include "Sun.h"
#include "..\Engine\xml\xml.h"
#include <map>
#include <assert.h>

#include <windows.h>		// Header File For Windows

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//#define DataPath	"..\\..\\data"
HObject * Scene::ms_lightobj = NULL;

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
		MessageBox(NULL,"Probl�me de donn�es.\nR�pertoire \"data\" ou fichier \"map.xml\" introuvable.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		assert(0);
	}


	typedef std::map<String,SpaceObject*> MapOfObjectsType;

	MapOfObjectsType mapofobjects;
	int i;
	SpaceObject *o ;
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
			{
				//o= new HGraphicObj(data.c_str());
				o= new SpaceObject(data.c_str());
			}
			
			if(!animation.empty())
				o->LoadAnimation(animation.c_str(), o);

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

	ms_lightobj = NULL;
}




/*
1-set camera
2-draw each actor in the list
*/

void Scene::Draw()
{
	m_camera.SetCameraInfo();

	HObject::Draw();
}
