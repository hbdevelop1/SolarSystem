// HAnimation.h: interface for the HAnimation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HANIMATION_H__C95B0264_8450_4D46_90A8_68EF5A81B2B9__INCLUDED_)
#define AFX_HANIMATION_H__C95B0264_8450_4D46_90A8_68EF5A81B2B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "liban8\An8Loader.h"
#include <time.h>
#include "..\MATH\HQuaternion.h"	// Added by ClassView

class HObject3D;

class HAnimation  
{
private:
	HObject3D*	m_3dObj;	//the owner object of this animation. used to set it's orientation and position after animation playing
	An8Element  m_elt;	

//animation data structure.
	template <class KeyType> struct		stKeyFramesInfo
	{
		//loaded data
		std::vector<KeyType>						*keys; 

		//real time updated data
		int											IndexOfTheFrameToPlay; /*this covers all the frame indices from 0 to the index of the last keyframe */
		double										CurrentFrameTimeStep; /*the time when the current frame is playing. 
																		it goes from 1/N to N/N; where N is the number of frames between two successive keyframes.
																		it's needed to interpolate the current frame.
																		*/

		double										timeoflastintermediateframe;	//min=0, max<1s/24, to prevent unnecessary animation update.
		typename std::vector<KeyType>::iterator		currentkeyframe;
		typename std::vector<KeyType>::iterator		nextkeyframe;
		bool										stopAnim;

		void										init(std::vector<KeyType> *);

	};
//the last keyframe equals the first one, for smooth looping
	
	
	stKeyFramesInfo<An8QKey>				m_Rot;
	stKeyFramesInfo<An8PointKey>			m_Disp;

	static double							ms_TimeToPlayNewFrame;
	double									m_TimeOfLastFrame ; 
							/*m_TimeOfLastFrame registers the time when the last frame (be it rotation or displacement) has been played. 
							it's updated at each new frame played.
							when it gets later than (currenttime - HAnimation::ms_TimeToPlayNewFrame),  a new frame should be played.
							it interacts only with currenttime and HAnimation::ms_TimeToPlayNewFrame*/
  
	bool									m_loop;

public:
	HAnimation(HObject3D * go, An8Element & e);
	virtual ~HAnimation();

	void Update(void);
	void Update2(void);
};

#endif // !defined(AFX_HANIMATION_H__C95B0264_8450_4D46_90A8_68EF5A81B2B9__INCLUDED_)
