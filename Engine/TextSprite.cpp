// TextSprite.cpp: implementation of the TextSprite class.
//
//////////////////////////////////////////////////////////////////////

#include "TextSprite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

extern HDC			g_hDC;

TextSprite TextSprite::s_inst;
GLuint	TextSprite::ms_dlbase=H_Invalid_DL;



void TextSprite::Draw(std::string  txt, int x, int y)			
{
	glPushMatrix();
	glTranslatef(x,0.0f,0.0f);						// Move One Unit Into The Screen
	glColor3f(1.0f,1.0f,1.0f);
	// Position The Text On The Screen
	glRasterPos2f(0, 0);


	glPushAttrib(GL_LIST_BIT);						
	glListBase(TextSprite::ms_dlbase - 32);
	glCallLists(txt.size() , GL_UNSIGNED_BYTE, txt.c_str());
	glPopAttrib();	
	
	glPopMatrix();
}



TextSprite::TextSprite()
{
}

void TextSprite::Init()
{
	HFONT	font;										// Windows Font ID
	HFONT	oldfont;									// Used For Good House Keeping

	TextSprite::ms_dlbase = glGenLists(96);								// Storage For 96 Characters

	font = CreateFont(	-24,							// Height Of Font
						0,								// Width Of Font
						0,								// Angle Of Escapement
						0,								// Orientation Angle
						FW_BOLD,						// Font Weight
						FALSE,							// Italic
						FALSE,							// Underline
						FALSE,							// Strikeout
						ANSI_CHARSET,					// Character Set Identifier
						OUT_TT_PRECIS,					// Output Precision
						CLIP_DEFAULT_PRECIS,			// Clipping Precision
						ANTIALIASED_QUALITY,			// Output Quality
						FF_DONTCARE|DEFAULT_PITCH,		// Family And Pitch
						"Courier New");					// Font Name

	oldfont = (HFONT)SelectObject(g_hDC, font);           // Selects The Font We Want
	wglUseFontBitmaps(g_hDC, 32, 96, TextSprite::ms_dlbase);				// Builds 96 Characters Starting At Character 32
	SelectObject(g_hDC, oldfont);							// Selects The Font We Want
	DeleteObject(font);									// Delete The Font
}

TextSprite::~TextSprite()
{
	if(TextSprite::ms_dlbase!=H_Invalid_DL)
	glDeleteLists(TextSprite::ms_dlbase, 96);							// Delete All 96 Characters
}
