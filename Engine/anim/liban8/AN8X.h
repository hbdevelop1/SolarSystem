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
/*
	Some part of AN8X*.hand AN8X*.cpp use some modified source code of GLGX:
	http://texel3d.free.fr/projets/glgx/index.html
*/



#ifndef _AN8X_H
#define _AN8X_H

//hbf
#pragma warning(disable:4786)



#include <iostream>
#include <fstream>
#include<string>
#include<vector>



class AN8XPARSER{
protected:
  std::ifstream	_file;
  std::string _FileName; // The file name
  std::string Line;

public:
  int LineNbr;  // num of the current line
  char Msg[1024]; // Error message

  bool IsOpen; // == true if the source is open (file, ftp, ressource,...)

public:
	
	virtual bool Open( std::string filename );
	virtual void Close( void );
	virtual int  ReadLine( void );


public:
	// Get the current line
	const char* GetLine(void);

	// Find if a string is in the current line
	int FindWord(std::string theWord); 

	int IndexOf(int occuenceNbr, std::string str);

	std::string SubStr(std::string strStart, std::string strEnd);

	bool SubLine(int start, int end);

	void CutLine(std::string strStart, int offset);

	std::string* CutStr(std::string* io_pStrStart,std::string strStart, int offset);
	std::string SubStr(std::string* i_pStrStart,std::string strStart, std::string strEnd);

	// return the nbr of instance of a string in the line
	int CountChar(std::string theString);

	// get the firt nbr on this->Line, return its position
	int CaptureNumber(std::string* outString); 

	// get the firt nbr on i_String, return its position
	int StrCaptureNumber(std::string* o_String,std::string* i_String );

	// Set a string in Line
	void SetLine(std::string inString);

	// Return the length of the current line
	int Length(void);

	// Get a string between "" in the current line
	void GetName(std::string* stringName);

	// Get 2 string between "" in the current line
	void Get2Names(std::string* stringName,std::string* stringName2);

public:
  AN8XPARSER();
  virtual ~AN8XPARSER();
};

class AN8XSTRINGPARSER : public AN8XPARSER
{
protected:
	char* _FileString;
	int _CurrPos;
public:
	virtual void SetString( char* i_FileString );
	virtual int  ReadLine( void );

	AN8XSTRINGPARSER();
	virtual ~AN8XSTRINGPARSER();
};




class AN8XQUATERNION{
public:
		float x;
		float y;
		float z;
		float w;

	AN8XQUATERNION(){x=0.0f;y=0.0f;z=0.0f;w=1.0f;};
	AN8XQUATERNION( float x , float y , float z, float w ){ this->x = x; this->y = y; this->z = z;this->w = w;}
	~AN8XQUATERNION(){};
};

class AN8XVECTOR4{
public:
	/*union {
		struct {
			float x,y,z,w;
		};
		struct
		{
			float s,t,r,q;
		};
	};
	*/
	float x,y,z,w;

	explicit AN8XVECTOR4()
	{
		x=0.0f;y=0.0f;z=0.0f;w=0.0f;
	};
	explicit AN8XVECTOR4( float x , float y , float z, float w )
	{
		this->x = x; this->y = y; this->z = z;this->w = w;
	}

	AN8XVECTOR4 operator= (const AN8XVECTOR4 &B)
	{
		if (this == &B) return B;
		this->x = B.x;
		this->y = B.y;
		this->z = B.z;
		this->w = B.w;
		return B;
	}

	~AN8XVECTOR4(){};



	AN8XVECTOR4 operator+ (const AN8XVECTOR4 &B);
	AN8XVECTOR4 operator- (const AN8XVECTOR4 &B);
	float	    operator* (const AN8XVECTOR4 &B);
	AN8XVECTOR4 operator* (float factor);
	AN8XVECTOR4 operator/ (float factor);
};


class AN8XVECTOR3{
public:
	/*union {
		struct {
			float x,y,z;
		};
		struct
		{
			float s,t,r;
		};
	};*/
	float x,y,z;

	explicit AN8XVECTOR3()
	{
		x = 0.0f; y = 0.0f; z = 0.0f;
	};
	explicit AN8XVECTOR3( float x , float y , float z)
	{
		this->x = x; this->y = y; this->z = z;
	}

	AN8XVECTOR3 operator= (const AN8XVECTOR3 &B)
	{
		if (this == &B) return B;
		this->x = B.x;
		this->y = B.y;
		this->z = B.z;
		return B;
	}

	~AN8XVECTOR3(){};

	AN8XVECTOR3 operator+ (const AN8XVECTOR3 &B);
	AN8XVECTOR3 operator- (const AN8XVECTOR3 &B);
	float	  operator* (const AN8XVECTOR3 &B);
	AN8XVECTOR3 operator* (float factor);
	AN8XVECTOR3 operator/ (float factor);
};

class AN8XVECTOR2{
public:
	/*union {
		float _13;
		struct {
			float x,y;
		};
		struct
		{
			float u,v;
		};
		struct
		{
			float s,t;
		};
	};*/
	float x,y;

	explicit AN8XVECTOR2()
	{
		x=0.0f;y=0.0f;
	};
	explicit AN8XVECTOR2( float x , float y)
	{
		this->x = x; this->y = y;
	}

	AN8XVECTOR2 operator= (const AN8XVECTOR2 &B)
	{
		if (this == &B) return B;
		this->x = B.x;
		this->y = B.y;
		return B;
	}

	~AN8XVECTOR2(){};

	AN8XVECTOR2 operator+ (const AN8XVECTOR2 &B);
	AN8XVECTOR2 operator- (const AN8XVECTOR2 &B);
	float	  operator* (const AN8XVECTOR2 &B);
	AN8XVECTOR2 operator* (float factor);
	AN8XVECTOR2 operator/ (float factor);
};



class AN8XMATRIX{
public:
	/*union{
		struct {
			float _11,_12,_13,_14,_21,_22,_23,_24,_31,_32,_33,_34,_41,_42,_43,_44;
		};
		struct {
			float Array[16];
		};
	};*/
	float _11,_12,_13,_14,_21,_22,_23,_24,_31,_32,_33,_34,_41,_42,_43,_44;

	explicit AN8XMATRIX()
	{
		_12 = _13 = _14 = _21 = _23 = _24 = _31 = _32 = _34 = _41 = _42 = _43 = 0.0f;
		_11 = _22 = _33 = _44 = 1.0f;

	};
	inline operator float*()
	{
		//return Array;
		return &_11;
	}

	AN8XMATRIX operator= (const AN8XMATRIX &B)
	{
		if (this == &B) return B;
		this->_11 = B._11;this->_12 = B._12;this->_13 = B._13;this->_14 = B._14;
		this->_21 = B._21;this->_22 = B._22;this->_23 = B._23;this->_24 = B._24;
		this->_31 = B._31;this->_32 = B._32;this->_33 = B._33;this->_34 = B._34;
		this->_41 = B._41;this->_42 = B._42;this->_43 = B._43;this->_44 = B._44;
		return B;
	}

	~AN8XMATRIX(){};

};


// Matrix ///////////////////////////////////////////////////

void  AN8XMatrixMultiply( AN8XMATRIX* Result, AN8XMATRIX* A, AN8XMATRIX* B );
void  AN8XMatrixIdentity(AN8XMATRIX* matrix);
void  AN8XMatrixMultVect( AN8XVECTOR3* result, AN8XMATRIX* matrix, AN8XVECTOR3* vector );
void  AN8XMatrixTranspose( AN8XMATRIX* Result, AN8XMATRIX* matrix);

AN8XMATRIX * AN8XMatrixMultiplyTranspose(AN8XMATRIX *o_Matrix,AN8XMATRIX *i_Matrix1,AN8XMATRIX *i_Matrix2);

void  AN8XMatrixCopy( AN8XMATRIX* Result, AN8XMATRIX* matrix);
void  AN8XMatrixScaling(AN8XMATRIX* dest,float x,float y,float z);
void  AN8XMatrixScaling(AN8XMATRIX* dest,AN8XVECTOR3* vector);
void  AN8XMatrixTranslation(AN8XMATRIX* dest,float x, float y,float z);
void  AN8XMatrixTranslation(AN8XMATRIX* dest,AN8XVECTOR3* vector);
float AN8XMatrixDeterminant( AN8XMATRIX* i_matrix);
AN8XMATRIX* AN8XMatrixInverse(AN8XMATRIX * o_Matrix,float* o_Determinant,AN8XMATRIX * i_Matrix);
AN8XMATRIX* AN8XMatrixLookAt( AN8XMATRIX* pResult,AN8XVECTOR3 *pPosition,AN8XVECTOR3 *pTarget,AN8XVECTOR3 *pUp);

AN8XMATRIX* AN8XMatrixRotationAxis( AN8XMATRIX o_Matrix,AN8XVECTOR3* i_Vector, float i_Angle);
AN8XMATRIX* AN8XMatrixRotationX( AN8XMATRIX o_Matrix, float i_Angle);
AN8XMATRIX* AN8XMatrixRotationY( AN8XMATRIX o_Matrix, float i_Angle);
AN8XMATRIX* AN8XMatrixRotationZ( AN8XMATRIX o_Matrix, float i_Angle);

void AN8XYawPitchRollRotationMatrix(double* o_Yaw, double* o_Pitch, double* o_Roll, AN8XMATRIX* i_Matrix);
void AN8XYawPitchRollQuaternion(double* o_Yaw, double* o_Pitch, double* o_Roll, AN8XQUATERNION* i_Quat );

void AN8XMatrixDecompose( 
		AN8XVECTOR3 *o_Scale,AN8XQUATERNION *o_Rotation,AN8XVECTOR3 *o_Translation,
		AN8XMATRIX *i_Matrix);

// Quaternion ///////////////////////////////////////////////
void			AN8XQuaternionMatrixRotation( AN8XQUATERNION* o_quat, AN8XMATRIX* i_matrix );
void            AN8XMatrixRotationQuaternion( AN8XMATRIX* matrix, AN8XQUATERNION* quat );
void            AN8XQuaternionMultiply(AN8XQUATERNION* dest,AN8XQUATERNION* srcA,AN8XQUATERNION* srcB);
AN8XQUATERNION* AN8XQuaternionIdentity(AN8XQUATERNION *pOut);
AN8XQUATERNION* AN8XQuaternionRotationYawPitchRoll(AN8XQUATERNION * out,float yaw,float pitch,float roll);
AN8XQUATERNION* AN8XQuaternionRotationAxis(AN8XQUATERNION * out,AN8XVECTOR3 * axis,float angle);

void            AN8XQuaternionToAxisAngle(AN8XQUATERNION* quat,AN8XVECTOR3* axis,float* angle);

AN8XQUATERNION* AN8XQuaternionConjugate(AN8XQUATERNION * out,AN8XQUATERNION * in);
AN8XQUATERNION* AN8XQuaternionInverse(AN8XQUATERNION * out,AN8XQUATERNION * in);

AN8XQUATERNION* AN8XQuaternionNormalize(AN8XQUATERNION * out,AN8XQUATERNION * in);
float           AN8XQuaternionLength(AN8XQUATERNION *quat);
AN8XQUATERNION* AN8XQuaternionSlerp(AN8XQUATERNION* out, AN8XQUATERNION* i_quatA, AN8XQUATERNION* i_quatB, float t);
AN8XQUATERNION * AN8XQuaternionSquad(AN8XQUATERNION *o_Result,AN8XQUATERNION *i_quatA,AN8XQUATERNION *i_quatB,AN8XQUATERNION *i_quatC,AN8XQUATERNION *i_quatD,float i_t);
AN8XQUATERNION * AN8XQuaternionBaryCentric(AN8XQUATERNION *o_Result,AN8XQUATERNION *i_quatA,AN8XQUATERNION *i_quatB,AN8XQUATERNION *i_quatC,float i_f,float i_g);


// Vector3 //////////////////////////////////////////////////
AN8XVECTOR3* AN8XVec3Cross(AN8XVECTOR3* result,AN8XVECTOR3* A,AN8XVECTOR3* B);
AN8XVECTOR3* AN8XVec3Normalize(AN8XVECTOR3 *pOut,const AN8XVECTOR3 *pV);
AN8XVECTOR4* AN8XVec3Transform(AN8XVECTOR4 * dest,const AN8XVECTOR3 * src,const AN8XMATRIX * matrix);
AN8XVECTOR3* AN8XVec3TransformNormal(AN8XVECTOR3 * dest,const AN8XVECTOR3 * src,const AN8XMATRIX * matrix);

AN8XVECTOR3* AN8XVec3TransformCoord(AN8XVECTOR3 * dest,const AN8XVECTOR3 * src,const AN8XMATRIX * matrix);

float        AN8XVec3Dot(const AN8XVECTOR3 *srcA,const AN8XVECTOR3 *srcB);
float        AN8XVec3Length(const AN8XVECTOR3 *pV);
void         AN8XVec3Lerp(AN8XVECTOR3 *dest,AN8XVECTOR3 *v1,AN8XVECTOR3 *v2,float l);

AN8XVECTOR3* AN8XVec3Scale(AN8XVECTOR3 *out,AN8XVECTOR3 *vector,float s) ;
AN8XVECTOR3* AN8XVec3BaryCentric(AN8XVECTOR3 *o_Result,AN8XVECTOR3 *i_src1,AN8XVECTOR3 *i_src2,AN8XVECTOR3 *i_src3,float i_f,float i_g);
AN8XVECTOR3 * AN8XVec3CatmullRom(AN8XVECTOR3 *o_Result,AN8XVECTOR3 *i_Src0,AN8XVECTOR3 *i_Src1,AN8XVECTOR3 *i_Src2,AN8XVECTOR3 *i_Src3,float i_t);
AN8XVECTOR3* AN8XVec3Hermite(AN8XVECTOR3 *o_Result, AN8XVECTOR3 *i_Pos0, AN8XVECTOR3 *i_Tan0, AN8XVECTOR3 *i_Pos1, AN8XVECTOR3 *i_Tan1, float i_t);

AN8XVECTOR3* AN8XVec3BezierDeg2(AN8XVECTOR3 *o_Result, AN8XVECTOR3 *i_P0, AN8XVECTOR3 *i_P1, AN8XVECTOR3 *i_P2, float i_t);
AN8XVECTOR3* AN8XVec3BezierDeg3(AN8XVECTOR3 *o_Result, AN8XVECTOR3 *i_P0, AN8XVECTOR3 *i_P1, AN8XVECTOR3 *i_P2, AN8XVECTOR3 *i_P3, float i_t);

float        AN8XAngleBetweenVec3(AN8XVECTOR3 *srcA,AN8XVECTOR3 *srcB);

// Vector4 //////////////////////////////////////////////////
AN8XVECTOR4 * AN8XVec4Normalize(AN8XVECTOR4 *pOut,const AN8XVECTOR4 *pV);

// Vector2 //////////////////////////////////////////////////
AN8XVECTOR2* AN8XVec2Normalize(AN8XVECTOR2 *pOut,const AN8XVECTOR2 *pV);
float        AN8XVec2Length(const AN8XVECTOR2 *vector);
AN8XVECTOR4* AN8XVec2Transform(AN8XVECTOR4 * dest,const AN8XVECTOR2 * src,const AN8XMATRIX * matrix);
AN8XVECTOR2 * AN8XVec2TransformNormal(AN8XVECTOR2 * dest,const AN8XVECTOR2 * src,const AN8XMATRIX * matrix);

std::string* AN8XFileNameFromPath( std::string* o_Result, std::string* i_String);

#define AN8X_PI 3.14159265f
#define AN8XToDegree(i_radianAngle) ((i_radianAngle) * (180.0f / AN8X_PI))
#define AN8XToRadian(i_DegreeAngle) ((i_DegreeAngle) * (AN8X_PI / 180.0f))

// Utility


void AN8XBaseConcatenate(AN8XVECTOR3* o_Origin, AN8XQUATERNION* o_Orientation,
					AN8XVECTOR3* i_OriginParent, AN8XQUATERNION* i_OrientationParent,
					AN8XVECTOR3* i_OriginChild, AN8XQUATERNION* i_OrientationChild);


class An8Mesh;
class An8Cube;
class An8Sphere;
class An8Cylinder;

// Create a mesh from a cube with default UV coords.
// if(i_Option == AN8_NORMAL) => Create mesh with normals
An8Mesh* AN8XMeshFromCube( An8Mesh* i_Mesh, An8Cube* i_Cube, int i_Option = 0 );

// Create a mesh from a sphere with default UV coords
An8Mesh* AN8XMeshFromSphere( An8Mesh* i_Mesh, An8Sphere* i_Sphere, int i_Option = 0 );

// Create a mesh from a cylinder with default UV coords
An8Mesh* AN8XMeshFromCylinder( An8Mesh* i_Mesh, An8Cylinder* i_Cylinder, int i_Option = 0 );


struct AN8XFloatKey
{
	int KeyFrame;
	std::vector<float> RotationX;
	std::vector<float> RotationY;
	std::vector<float> RotationZ;

	AN8XQUATERNION Orientation; // RotationXYZ converted to quaternion

	AN8XFloatKey(void){KeyFrame=0;};
	~AN8XFloatKey()
	{
	}
};



//hbf
#if defined (dead_code)


//hbf
#endif //defined (dead_code)



#endif	// _AN8X_H

