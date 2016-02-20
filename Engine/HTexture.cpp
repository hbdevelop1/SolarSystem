
#include <windows.h>		
#include <gl\gl.h>		
#include <gl\glu.h>	
#include <gl\glaux.h>		
#include <stdio.h>

#include "htexture.h"



AUX_RGBImageRec *LoadBMP(const char *Filename)
{
	FILE *File=NULL;								

	if (!Filename)									
	{
		return NULL;								
	}

#if _MSC_VER<=1200
	File=fopen(Filename,"r");						
	if (File)										
#else
	if (!fopen_s(&File, Filename,"r"))
#endif
	

	{
		fclose(File);									
		return auxDIBImageLoad(Filename);		
	}

	return NULL;									
}

bool LoadGLTextures(const char * filename, unsigned int * ptextureid)						
{
	bool Status=false;								
	AUX_RGBImageRec *TextureImage[1];		

	memset(TextureImage,0,sizeof(void *)*1);           

	if (TextureImage[0]=LoadBMP(filename))
	{
		Status=true;								

		glGenTextures(1, ptextureid);				

		glBindTexture(GL_TEXTURE_2D, *ptextureid);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	}

	if (TextureImage[0])						
	{
		if (TextureImage[0]->data)			
		{
			free(TextureImage[0]->data);	
		}

		free(TextureImage[0]);				
	}

	return Status;								
}
