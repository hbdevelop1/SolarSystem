// HAnimation.cpp: implementation of the HAnimation class.
//
//////////////////////////////////////////////////////////////////////



#include "HAnimation.h"
#include <iterator>
#include "../HGraphicObj.h"
#include <windows.h>
#include <assert.h>




//#define _debug_animation_

#if defined (_debug_animation_)

#define clock hclock

clock_t hclock()
{
  static clock_t g_hbtime=0;
  g_hbtime += 10;
  if(g_hbtime >= 0xFFFFFFFF)
	assert(0);
  return g_hbtime;
}
#endif //defined (_debug_animation_)





//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template <class KeyType> void HAnimation::stKeyFramesInfo<KeyType>::init(std::vector<KeyType> * p)
{
	IndexOfTheFrameToPlay = 0;
	CurrentFrameTimeStep = 0;



	keys = p;

	currentkeyframe = keys->begin();
	nextkeyframe = currentkeyframe+1;
  
	if(nextkeyframe == keys->end())
		stopAnim = true;
	else
		stopAnim=false;


}

/*
animation is updated each ms_TimeToPlayNewFrame
*/
double HAnimation::ms_TimeToPlayNewFrame=CLOCKS_PER_SEC/100.0;

/*
At animation creation, load information about its keyframe positions and keyframe orientations.
*/
HAnimation::HAnimation(HGraphicObj * go, An8Element & e):m_go(go),m_loop(true)
{

	m_elt.Loc=e.Loc;         
	m_elt.Orientation=e.Orientation; 

	std::copy(e.vControllers.begin(),e.vControllers.end(), std::back_inserter(m_elt.vControllers));
	


	m_go->SetPosition(m_elt.Loc);
	m_go->SetOrientation(m_elt.Orientation);


	An8Track *Track;
	std::vector<An8Controller>::iterator it = m_elt.vControllers.begin(); 
	for( ;it != m_elt.vControllers.end(); it++)
	{
		Track= & ((*it).Track);
		
		if(Track->NbrQKey)
			m_Rot.init(& Track->vQKeys);
		else if(Track->NbrPointKey)
			m_Disp.init(& Track->vPointKeys);
	}

	m_TimeOfLastFrame=static_cast<double>(clock());

}

HAnimation::~HAnimation()
{

}


/*

 |---currentkeyframe(FrameNumber=0)
 |
 .....................................................
		^								^
		|								|
		|								|
		|--IndexOfTheFrameToPlay=7		|--nextkeyframe(FrameNumber=40)
*/
void HAnimation::Update()
{
	double currenttime = static_cast<double>(clock());

//	0-if it's not yet time to play anim, go away;
	if(currenttime - m_TimeOfLastFrame < HAnimation::ms_TimeToPlayNewFrame) 
		return;

	m_TimeOfLastFrame = currenttime;


	if(m_Rot.stopAnim == false)
	{
	//	1-increment the frame Number; (the initial position of the object is considered the first keyframe; no problem in animation id the initial position equals the actual first keyframe. otherwise, trouble . );
		m_Rot.IndexOfTheFrameToPlay++; //take on the values 0 to 11, 23, 24, 27, .... can loop back to 0 if the anim is looping.


		m_Rot.CurrentFrameTimeStep = ((double)m_Rot.IndexOfTheFrameToPlay - m_Rot.currentkeyframe->FrameNumber) / (m_Rot.nextkeyframe->FrameNumber - m_Rot.currentkeyframe->FrameNumber);

		//quaternions give absolute orientations (relative to the first most initial orientation of the object)
		//but interpolation is done only between two successive keyframes, which don't exceed PI/2
		HQuaternion orientation = Interpolate( (*m_Rot.currentkeyframe).Quaternion,
										  (*m_Rot.nextkeyframe).Quaternion,
										  m_Rot.CurrentFrameTimeStep);
		m_go->SetOrientation(orientation);
#if 0
		{
		char buf[100];
		//	  sprintf(buf,"(%.3f, %d\n", durationinseconds,current_frame_to_display);
		sprintf(buf,"m_Rot.CurrentFrameTimeStep = %e\n", m_Rot.CurrentFrameTimeStep);
		OutputDebugString(buf);
	}
#endif
		if(m_Rot.CurrentFrameTimeStep == 1) //at new key frame
		{
			m_Rot.currentkeyframe++;
			m_Rot.nextkeyframe = m_Rot.currentkeyframe+1;
			if(m_Rot.nextkeyframe == m_Rot.keys->end())
			{
				if(m_loop)
				{
					m_Rot.IndexOfTheFrameToPlay=0;
					m_Rot.currentkeyframe = m_Rot.keys->begin();
					m_Rot.nextkeyframe = m_Rot.currentkeyframe+1;
				}
				else
					m_Rot.stopAnim=true;
			}
		}
	}	



	if(m_Disp.stopAnim == false)
	{
	//	1-increment the frame Number; (the initial position is considered the first keyframe;);
		m_Disp.IndexOfTheFrameToPlay++;

		m_Disp.CurrentFrameTimeStep = ((double)m_Disp.IndexOfTheFrameToPlay - m_Disp.currentkeyframe->FrameNumber) / (m_Disp.nextkeyframe->FrameNumber - m_Disp.currentkeyframe->FrameNumber);

		HVector loc = Interpolate( (*m_Disp.currentkeyframe).Value,
										  (*m_Disp.nextkeyframe).Value,
								m_Disp.CurrentFrameTimeStep);
		m_go->SetPosition(loc);



		if(m_Disp.CurrentFrameTimeStep == 1) //at new key frame
		{
			m_Disp.currentkeyframe++;
			m_Disp.nextkeyframe = m_Disp.currentkeyframe+1;
			if(m_Disp.nextkeyframe == m_Disp.keys->end())
			{
				if(m_loop)
				{
					m_Disp.IndexOfTheFrameToPlay=0;
					m_Disp.currentkeyframe = m_Disp.keys->begin();
					m_Disp.nextkeyframe = m_Disp.currentkeyframe+1;
				}
				else
					m_Disp.stopAnim=true;
			}
		}
	}	

}


