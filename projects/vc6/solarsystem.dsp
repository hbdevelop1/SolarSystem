# Microsoft Developer Studio Project File - Name="solarsystem" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=solarsystem - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "solarsystem.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "solarsystem.mak" CFG="solarsystem - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "solarsystem - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "solarsystem - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "solarsystem - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "D:\hassan\resources\C++\boost_1_46_1_installed\boost\boost_1_46_1" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 opengl32.lib glu32.lib glaux.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "solarsystem - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\utilities" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D DataPath=\"..\\..\\data\" /D DataPath1=\"data\" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 expat.lib opengl32.lib glu32.lib glaux.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"..\..\utilities\GL" /libpath:"..\..\utilities\xml"
# SUBTRACT LINK32 /nodefaultlib

!ENDIF 

# Begin Target

# Name "solarsystem - Win32 Release"
# Name "solarsystem - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Engine"

# PROP Default_Filter ""
# Begin Group "math"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\..\..\Engine\math\HCommon.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\math\HMatrix.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\math\HMatrix.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\math\HQuaternion.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\math\HQuaternion.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\math\HVector.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\math\HVector.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\math\HVector4.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\math\HVector4.h
# End Source File
# End Group
# Begin Group "anim"

# PROP Default_Filter ""
# Begin Group "liban8"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8BooleanKey.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8Controller.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8Element.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8File.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8FloatKey.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8Loader.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8ObjectElement.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8PointKey.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8QKey.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8Scene.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\An8Track.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\AN8X.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\AN8X.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\AN8X_Math.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\liban8\AN8XMath_Quaternion.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\..\..\Engine\anim\HAnimation.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\anim\HAnimation.h
# End Source File
# End Group
# Begin Group "xml"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\..\..\Engine\xml\expat.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\xml\xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\xml\xml.h
# End Source File
# End Group
# Begin Group "2D"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\..\..\Engine\HButton.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HButton.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\Engine\Camera.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Camera.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\HEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\HEvent.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HGraphicObj.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HGraphicObj.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HObject.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HObject.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HObjectList.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HObjectList.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\HRendererState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\HRendererState.h
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HTexture.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Engine\HTexture.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Menu.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Menu.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Root.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Root.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Scene.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\Scene.h
# End Source File
# End Group
# Begin Group "Game"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Game\Sun.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Game\Sun.h
# End Source File
# End Group
# Begin Group "Globals"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\..\..\solarsystem.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Testing.cpp
# End Source File
# Begin Source File

SOURCE=.\..\..\Testing.h
# End Source File
# End Group
# End Group
# End Target
# End Project
