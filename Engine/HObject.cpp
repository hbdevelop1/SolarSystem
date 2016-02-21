// HObject.cpp: implementation of the HObject class.
//
//////////////////////////////////////////////////////////////////////

#include "HObject.h"
#include <boost/mem_fn.hpp>
#include <algorithm>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HObject::HObject()
{

}

HObject::~HObject()
{

}


void HObject::AddChild(HObject *c)
{
	m_children.push_back(c);
}



void HObject::Init()
{
	std::for_each(m_children.begin(), m_children.end(), boost::mem_fn(&HObject::Init));
}

void HObject::UnInit()
{
	std::for_each(m_children.begin(), m_children.end(), boost::mem_fn(&HObject::UnInit));
}

void HObject::Tick()
{
	TickSpecifics();
	std::for_each(m_children.begin(), m_children.end(), boost::mem_fn(&HObject::Tick));
}

void HObject::Draw()
{
	std::for_each(m_children.begin(), m_children.end(), boost::mem_fn(&HObject::Draw));
	//std::mem_fun can only be used with non void returning member functions. so must use boost::mem_fn

}
