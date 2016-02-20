// Earth.cpp: implementation of the Earth class.
//
//////////////////////////////////////////////////////////////////////

#include "Earth.h"
#include "..\Engine\math\HQuaternion.h"
#include <math.h>
#include <windows.h>

#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Earth::Earth(char * filename):HGraphicObj(filename)
{
  m_q0.Set(0,HVector(0,1,0));		  m_q0.Print();
  m_q1.Set(M_PI/2,HVector(0,1,0));	  m_q1.Print();

  m_interpolation.step = 0;
  m_interpolation.time = 0;
}

Earth::~Earth()
{

}

void Earth::Tick()
{
  
  HGraphicObj::Tick();

#if 0
	  //m_rotation should start at m_q0 and evolve to be equal m_q1.

  /*
  evolve rotation;
  set it in the matrix;
  */

  float limit = 1.1f;
  if(m_interpolation.step <= limit)
  {

	m_interpolation.time++; 	
	
	if(m_interpolation.time>=20)
	{
	  m_interpolation.time = 0;

	  double angle = M_PI/2;
	  double ha = angle/2;
	  double sinha = sin(ha);

	  double ratioA = sin((1 - m_interpolation.step) * ha) / sinha;
	  double ratioB = sin(m_interpolation.step * ha) / sinha; 

	  m_rotation[0] = (m_q0[0] * ratioA + m_q1[0] * ratioB);
	  m_rotation[1] = (m_q0[1] * ratioA + m_q1[1] * ratioB);
	  m_rotation[2] = (m_q0[2] * ratioA + m_q1[2] * ratioB);
	  m_rotation[3] = (m_q0[3] * ratioA + m_q1[3] * ratioB);

	  m_rotation.Normalize();

//#define _debug_slerp_1_
#ifdef _debug_slerp_1_
	  char buf[100];
	  sprintf(buf,"%.3f : (%.3f, %.3f, %.3f, %.3f)\n", m_interpolation.step, m_rotation[0], m_rotation[1], m_rotation[2], m_rotation[3]);
	  OutputDebugString(buf);
#endif //_debug_slerp_1_
	  
	  m_interpolation.step+=1/10.f;


	}

  
  
  }
#endif

}

void Earth::Init()
{
  //SetPosition(HVector(0, 0, -15));

}

