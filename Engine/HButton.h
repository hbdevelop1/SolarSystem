// HButton.h: interface for the HButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HBUTTON_H__D7676C71_0469_42C8_A755_5D0372DF8BA5__INCLUDED_)
#define AFX_HBUTTON_H__D7676C71_0469_42C8_A755_5D0372DF8BA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <string>
#include "HGraphicObj.h"


class HButton
{

	HGraphicObj *m_graphic;

public:
	HButton():m_graphic(NULL) {}
	virtual ~HButton();

	void Init(char * filename,HVector pos); //to initialize array of HButton

	void Draw();
	void Tick();
};

#endif // !defined(AFX_HBUTTON_H__D7676C71_0469_42C8_A755_5D0372DF8BA5__INCLUDED_)
