// Root.cpp: implementation of the Root class.
//
//////////////////////////////////////////////////////////////////////

#include "Root.h"
#include "Scene.h"
#include "Menu.h"
#include "hevent.h"
#include "HRendererState.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Root::Root()
{
	m_scene = new Scene;
	m_pausemenu = new Menu;

	Event::RegisterHandler(Event::event_pause,this,&Root::Pause);

}

Root::~Root()
{
	Event::UnRegisterHandler(Event::event_pause);
	delete m_scene;
	delete m_pausemenu;

}

void Root::Init()
{
	HRendererState::GetInstance().Init();

	m_active = m_scene;
	m_active->Init();
  
}




void Root::UnInit()
{
}

void Root::Tick()
{
	m_active->Tick();
}

void Root::Draw()
{
	HRendererState::GetInstance().PreDraw();

	m_scene->Draw();
  
	int l = HRendererState::GetInstance().GetLight() ;
	HRendererState::GetInstance().SetLight(false);

	if(m_active == m_pausemenu)
		m_pausemenu->Draw();

	HRendererState::GetInstance().SetLight(l);
}

void Root::Pause(bool b)
{
	if(b)
		m_active = m_pausemenu;
	else
		m_active = m_scene;
}
