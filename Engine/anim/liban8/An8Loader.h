/*
* Copyright (c) 2002-2009, Grégory Smialek
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
*
*   * Redistributions of source code must retain the above copyright notice, 
*     this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation 
*     and/or other materials provided with the distribution.
*   * Neither the name of the Grégory Smialek nor the names of its contributors
*     may be used to endorse or promote products derived from this software 
*     without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* web site: http://texel3d.free.fr/projets/liban8/index.html
*/

//////HEADER/////////////An8Loader.h///////////////////////
///     .an8 file loading module (2002-2010)			///
///     Version 10.02.01       By Grégory Smialek       ///
///////////texel3d.free.fr//////texel_3d@yahoo.com/////////

#ifndef _Anim8or_H
#define _Anim8or_H



#ifndef AN8_WIN32
#define AN8_WIN32
#endif


#define LINERETURN 1

#ifdef AN8_WIN32
	#define _CRT_SECURE_NO_DEPRECATE
#endif


//hbf
#pragma warning(disable:4786)


#include<string>
#include <vector>

#include"AN8X.h"


#define AN8_INFINITELIGHT 1
#define AN8_LOCALLIGHT 2
#define AN8_SPOTLIGHT 3

#define AN8_UNDEFINED  0
#define AN8_FLOAT      1
#define AN8_INTEGER    2
#define AN8_POINT3     3
#define AN8_QUATERNION 4
#define AN8_STRING     5

#define AN8_COLOR      0
#define AN8_IMAGE      1
#define AN8_CUBEMAP    2
#define AN8_PANORAMA   3

#define AN8_PARENT      0
#define AN8_PATH        1
#define AN8_OTHER       2
#define AN8_FACINGOTHER 3

#define AN8_NORMAL 1

// Blending Mode
#define AN8_DECAL   0
#define AN8_DARKEN  1
#define AN8_LIGHTEN 2

// Alpha Mode
#define AN8_NONE  0
#define AN8_LAYER 1
#define AN8_FINAL 2

// CubeMap Index
#define AN8_RIGHT	0
#define AN8_LEFT	1
#define AN8_BOTTOM	2
#define AN8_TOP		3
#define AN8_FRONT	4
#define AN8_BACK	5


class An8ObjectElement;
class An8Scene;
class An8File;

class An8FloatKey
{
public:

	int FrameNumber;

	int NbrFloat;
	std::vector<float> vFloats;

	std::string KnotBehavior;

	An8FloatKey();
	~An8FloatKey();
	bool Load(AN8XPARSER*p_parser);
};



class An8QKey
{
public:

	int FrameNumber;
	AN8XQUATERNION Quaternion;
	std::string KnotBehavior;

	An8QKey();
	~An8QKey();
	bool Load(AN8XPARSER*p_parser);
};

class An8BooleanKey
{
public:

	int FrameNumber;
	bool Value;
	std::string KnotBehavior;

	An8BooleanKey();
	~An8BooleanKey();
	bool Load(AN8XPARSER*p_parser);
};

class An8PointKey
{
public:

	int FrameNumber;

	AN8XVECTOR3 Value;
	AN8XVECTOR3 Forward;
	AN8XVECTOR3 Reverse;

	std::string KnotBehavior;

	An8PointKey();
	~An8PointKey();
	bool Load(AN8XPARSER*p_parser);
};

class An8Track
{
public:

	int NbrFloatKey;
	std::vector<An8FloatKey> vFloatKeys;

	int NbrQKey;
	std::vector<An8QKey> vQKeys;

	int NbrPointKey;
	std::vector<An8PointKey> vPointKeys;

	int NbrBooleanKey;
	std::vector<An8BooleanKey> vBooleanKeys;

	An8Track();
//	An8Track(const An8Track &t);
	~An8Track();
	bool Load(AN8XPARSER*p_parser);
};


class An8Controller
{
public:
	std::string Name;

	bool IsUser;
	std::string Type;

	bool HasTrack;
	An8Track Track;

	An8Controller();
//	An8Controller(const An8Controller &s);
	~An8Controller();

	bool Load(AN8XPARSER*p_parser);

};


class An8Element
{
public:
	std::string Name;      // Name
  	bool EnableRoll;
	AN8XVECTOR3    Loc;         // Position (from .an8. Can by relative to something)
	AN8XQUATERNION Orientation; // quaternion rotation (from .an8. Can by relative to something)

	int NbrController;
	std::vector<An8Controller> vControllers;

	// Absolute poistion/orientation computed by ComputeAllMatrices()
	AN8XMATRIX  Matrix;      // Absolute Matrix (rotation, translation,scale)
	AN8XVECTOR3 LookAtLoc;   // Location
	AN8XVECTOR3 LookAtUp;    // Up vector
	AN8XVECTOR3 LookAtEye;   // Eye (in front of loc)

	float Scale;

	bool Locked;
private:

	AN8XMATRIX OrientationMatrix;   // Alpha
	AN8XMATRIX TranslationMatrix;  // Alpha
	AN8XMATRIX ScaleMatrix;   // Alpha

public:
	An8Element(void);
	~An8Element(void);


#if defined (dead_code)

public:

	int NbrObjectElement;
	std::vector<An8ObjectElement> vObjectElements;



	int NbrAttribute;
	std::vector<An8Attribute> vAttributes;

	int RelativeTo;
    std::string TargetName;

	// For RelativeTo: Parent ( it's like groups)
	int NbrCamera;
	std::vector<An8Camera> vCameras;
	int NbrFigureElement;
	std::vector<An8FigureElement> vFigureElements;
	int NbrNull;
	std::vector<An8Null> vNulls;
	int NbrLight;
	std::vector<An8Light> vLights;

	An8Element* ptrParent; // Pointer to the parent (if relative to parent)
	An8Element* ptrTarget; // Pointer to the target (facing other...)

	// Compute all absolute matrices (element and children)
	void ComputeAllMatrices( void );

	// Get Pointer of a target (facing other...)
	An8Element* GetTargetPointer(An8Element* o_ptr, std::string i_TargetName);

	// Fill ptrParent and ptrTarget (to use if you add/remove elements)
	void SetElementsPointer(An8Scene* i_Scene,An8Element* i_ptrParent);

	// You should not use this function
	void ComputeMatrices( void );

	std::vector<An8ObjectElement*> GetObjectElements(void);
	std::vector<An8FigureElement*> GetFigureElements(void);
	std::vector<An8Camera*> GetCameras(void);
	std::vector<An8Light*>  GetLights(void);
	std::vector<An8Null*>   GetNulls(void);

private:

	void ComputeLookAt(AN8XVECTOR4* i_targetPosition); // Alpha
	void ComputeSimpleMatrix( void ); // Alpha
#endif //defined (dead_code)


};



class An8ObjectElement : public An8Element
{
public:

	std::string SourceName;

	int ObjectID; ///< Id number of the object in vObjects

    bool CastShadow;
    bool ReceiveShadow;

	bool Load(AN8XPARSER*p_parser);

public:
	An8ObjectElement(void);
	~An8ObjectElement(void);
};


////An8Scene////////////
class An8Scene{
public:
	std::string Name;     // Name of the scene

	int  BackGround[3]; // Background color
	int	 BackGroundType; // AN8_COLOR, AN8_IMAGE or AN8_CUBEMAP, AN8_PANORAMA
	std::string BackGroundImage;

	bool   GroundGrid;   // = true if the groundgrid is activated

	bool   HasFog;        // = 0 if no, = 1 if yes
	int   FogColor[3];    // RGB
	float FogStart;
	float FogEnd;
	int   FogPercent;

	float Znear;  // Z-Near clip plane
	float Zfar;   // Z-Far clip plane

	bool HasLighting; // By default Lighting is not present in the file

	int NbrCamera;

	int NbrObjectElement;

	int NbrFigureElement;

	int NbrNull;

	int NbrLight;

	std::vector<An8ObjectElement> vObjectElements;


public:
	bool Load(AN8XPARSER*p_parser);
	void FindObjectID(An8File *aniFile);


//hbf
#if defined (dead_code)
	An8Panorama BackGroundPanorama;


	An8Lighting	Lighting; // Lighting in the scene
	std::vector<An8Camera> vCameras;
	std::vector<An8FigureElement> vFigureElements;
	std::vector<An8Null> vNulls;
	std::vector<An8Light> vLights;

	std::vector<An8ObjectElement*> GetObjectElements(void);
	std::vector<An8FigureElement*> GetFigureElements(void);
	std::vector<An8Light*> GetLights(void);
	std::vector<An8Camera*> GetCameras(void);
	std::vector<An8Null*> GetNulls(void);

	void SetElementsPointer( void );
	An8Element* GetTargetPointer(An8Element* o_ptr, std::string i_TargetName);

	void ComputeAllMatrices( void );

//hbf
#endif //defined (dead_code)



	An8Scene();
	~An8Scene();

};



class An8File
{
private:
	AN8XPARSER* p_parser;
	bool _IsExternalParser;

public:



	std::string FileName;
	int NbrTexture;                // Number of texture in the file
	int NbrObject;                // Number of objects in the file
	int NbrFigure;                // Number of Figures in the file
	int NbrSequence;                // Number of Figures in the file
	int NbrScene;                 // Number of scenes in the file
	bool HasDescription;

//hbf
#if defined (dead_code)

	An8Header Header;

	An8Description Description;

	An8Environment Environment;

//hbf
#endif //defined (dead_code)


   // bool IsEmpty;        // = true if the An8Scene class is empty
	bool HasNormal(void);

//hbf
#if defined (dead_code)

	// Textures
	std::vector<An8Texture>	vTextures; // List of textures

	// Objects
	std::vector<An8Object>	vObjects; // List of objects in the file

	// Figures
	std::vector<An8Figure>	vFigures; // List of Figures in the file

	// Figures
	std::vector<An8Sequence> vSequences; // List of Figures in the file

//hbf
#endif //defined (dead_code)

	// Scenes
	std::vector<An8Scene>	vScenes;  // List of scenes in the file



public:


//hbf
#if defined (dead_code)

	void ConvertAllToMesh( void );

	void Ungroup( void ); //
	void Triangulize( void );
	void ComputeFaceNormal(void);

	void ComputeAllPositions(void);
	void ComputeAllMatrices( void );
	//void ComputeTangentsBinormals(void);
	void ComputeTextureIDForMaterial(void);

	void SetElementsPointer( void );

	AN8XPARSER* GetParser();
	void SetParser(AN8XPARSER* i_pParser);


	// utility function
	int GetNbrMesh(void);
	int GetFigureID(std::string name);
	int GetObjectID(std::string name);
	int GetSequenceID(std::string name);

	// Load a .an8 file using an external parser
	bool Load( void );

//hbf
#endif //defined (dead_code)


	An8File(void);
	~An8File(void);

	// Load a .an8 file
	bool LoadFile(std::string file_name);

};


//hbf
#if defined (dead_code)
//hbf
#endif //defined (dead_code)








#endif	// _Anim8or_H
