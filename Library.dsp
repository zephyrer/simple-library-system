# Microsoft Developer Studio Project File - Name="Library" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Library - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Library.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Library.mak" CFG="Library - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Library - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Library - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Library - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Library - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 SkinPlusPlusDLL.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Library - Win32 Release"
# Name "Library - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\_recordset.cpp
# End Source File
# Begin Source File

SOURCE=.\AdminRS.cpp
# End Source File
# Begin Source File

SOURCE=.\adodc.cpp
# End Source File
# Begin Source File

SOURCE=.\AdvancedQuery1.cpp
# End Source File
# Begin Source File

SOURCE=.\BasicQuery.cpp
# End Source File
# Begin Source File

SOURCE=.\BookRS.cpp
# End Source File
# Begin Source File

SOURCE=.\BorrowBook.cpp
# End Source File
# Begin Source File

SOURCE=.\BorrowRS.cpp
# End Source File
# Begin Source File

SOURCE=.\CardLostDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CardNewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CardRS.cpp
# End Source File
# Begin Source File

SOURCE=.\column.cpp
# End Source File
# Begin Source File

SOURCE=.\columns.cpp
# End Source File
# Begin Source File

SOURCE=.\dataformatdisp.cpp
# End Source File
# Begin Source File

SOURCE=.\datagrid.cpp
# End Source File
# Begin Source File

SOURCE=.\field.cpp
# End Source File
# Begin Source File

SOURCE=.\fields.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\Library.cpp
# End Source File
# Begin Source File

SOURCE=.\Library.rc
# End Source File
# Begin Source File

SOURCE=.\LibraryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MultiplyAdd.cpp
# End Source File
# Begin Source File

SOURCE=.\MultiplyAddDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\properties.cpp
# End Source File
# Begin Source File

SOURCE=.\property.cpp
# End Source File
# Begin Source File

SOURCE=.\QueryAdvanced.cpp
# End Source File
# Begin Source File

SOURCE=.\ReturnBook.cpp
# End Source File
# Begin Source File

SOURCE=.\selbookmarks.cpp
# End Source File
# Begin Source File

SOURCE=.\SingleAddDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\split.cpp
# End Source File
# Begin Source File

SOURCE=.\splits.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\stddataformatsdisp.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\_recordset.h
# End Source File
# Begin Source File

SOURCE=.\AdminRS.h
# End Source File
# Begin Source File

SOURCE=.\adodc.h
# End Source File
# Begin Source File

SOURCE=.\AdvancedQuery1.h
# End Source File
# Begin Source File

SOURCE=.\BasicQuery.h
# End Source File
# Begin Source File

SOURCE=.\BookRS.h
# End Source File
# Begin Source File

SOURCE=.\BorrowBook.h
# End Source File
# Begin Source File

SOURCE=.\BorrowRS.h
# End Source File
# Begin Source File

SOURCE=.\CardLostDlg.h
# End Source File
# Begin Source File

SOURCE=.\CardNewDlg.h
# End Source File
# Begin Source File

SOURCE=.\CardRS.h
# End Source File
# Begin Source File

SOURCE=.\column.h
# End Source File
# Begin Source File

SOURCE=.\columns.h
# End Source File
# Begin Source File

SOURCE=.\currentID.h
# End Source File
# Begin Source File

SOURCE=.\dataformatdisp.h
# End Source File
# Begin Source File

SOURCE=.\datagrid.h
# End Source File
# Begin Source File

SOURCE=.\field.h
# End Source File
# Begin Source File

SOURCE=.\fields.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\Library.h
# End Source File
# Begin Source File

SOURCE=.\LibraryDlg.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainMenu.h
# End Source File
# Begin Source File

SOURCE=.\MultiplyAdd.h
# End Source File
# Begin Source File

SOURCE=.\MultiplyAddDlg.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\properties.h
# End Source File
# Begin Source File

SOURCE=.\property.h
# End Source File
# Begin Source File

SOURCE=.\QueryAdvanced.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ReturnBook.h
# End Source File
# Begin Source File

SOURCE=.\selbookmarks.h
# End Source File
# Begin Source File

SOURCE=.\SingleAddDlg.h
# End Source File
# Begin Source File

SOURCE=.\SkinPlusPlus.h
# End Source File
# Begin Source File

SOURCE=.\split.h
# End Source File
# Begin Source File

SOURCE=.\splits.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\stddataformatsdisp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Library.ico
# End Source File
# Begin Source File

SOURCE=.\res\Library.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Library : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section Library : {A3CC339C-7BBA-434D-B4FB-D8FF8421234D}
# 	1:14:IDD_CARD_APPLY:105
# 	2:16:Resource Include:resource.h
# 	2:18:CLASS: CCardNewDlg:CCardNewDlg
# 	2:10:ENUM: enum:enum
# 	2:12:CardNewDlg.h:CardNewDlg.h
# 	2:14:CardNewDlg.cpp:CardNewDlg.cpp
# 	2:19:Application Include:Library.h
# 	2:14:IDD_CARD_APPLY:IDD_CARD_APPLY
# End Section
# Section Library : {00000569-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CField
# 	2:10:HeaderFile:field.h
# 	2:8:ImplFile:field.cpp
# End Section
# Section Library : {00000504-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CProperties
# 	2:10:HeaderFile:properties.h
# 	2:8:ImplFile:properties.cpp
# End Section
# Section Library : {CDE57A52-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CSelBookmarks
# 	2:10:HeaderFile:selbookmarks.h
# 	2:8:ImplFile:selbookmarks.cpp
# End Section
# Section Library : {20B8FA93-DF35-4726-B647-E6643C4D05CB}
# 	1:15:IDD_BOOK_BORROW:110
# 	2:16:Resource Include:resource.h
# 	2:15:IDD_BOOK_BORROW:IDD_BOOK_BORROW
# 	2:12:BorrowBook.h:BorrowBook.h
# 	2:10:ENUM: enum:enum
# 	2:18:CLASS: CBorrowBook:CBorrowBook
# 	2:14:BorrowBook.cpp:BorrowBook.cpp
# 	2:19:Application Include:Library.h
# End Section
# Section Library : {00000564-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CFields
# 	2:10:HeaderFile:fields.h
# 	2:8:ImplFile:fields.cpp
# End Section
# Section Library : {C9019037-4C9D-4785-A58B-87B71EA7F993}
# 	1:15:IDD_SINGLE_ADD1:104
# 	2:16:Resource Include:resource.h
# 	2:16:SingleAddDlg.cpp:SingleAddDlg.cpp
# 	2:14:SingleAddDlg.h:SingleAddDlg.h
# 	2:10:ENUM: enum:enum
# 	2:14:IDD_SINGLE_ADD:IDD_SINGLE_ADD1
# 	2:20:CLASS: CSingleAddDlg:CSingleAddDlg
# 	2:19:Application Include:Library.h
# End Section
# Section Library : {67397AA3-7FB1-11D0-B148-00A0C922E820}
# 	2:21:DefaultSinkHeaderFile:adodc.h
# 	2:16:DefaultSinkClass:CAdodc
# End Section
# Section Library : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section Library : {00000503-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CProperty
# 	2:10:HeaderFile:property.h
# 	2:8:ImplFile:property.cpp
# End Section
# Section Library : {CDE57A41-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CDataGrid
# 	2:10:HeaderFile:datagrid.h
# 	2:8:ImplFile:datagrid.cpp
# End Section
# Section Library : {E5CEE1CA-445D-412F-9CB0-5C31BB08295B}
# 	1:12:IDD_CARD_END:106
# 	2:16:Resource Include:resource.h
# 	2:15:CardLostDlg.cpp:CardLostDlg.cpp
# 	2:13:CardLostDlg.h:CardLostDlg.h
# 	2:10:ENUM: enum:enum
# 	2:19:CLASS: CCardLostDlg:CCardLostDlg
# 	2:19:Application Include:Library.h
# 	2:12:IDD_CARD_END:IDD_CARD_END
# End Section
# Section Library : {A0B2AE51-8D3D-4FD8-92ED-0ABF2A7762B6}
# 	1:15:IDD_QUERY_BASIC:108
# 	2:16:Resource Include:resource.h
# 	2:18:CLASS: CBasicQuery:CBasicQuery
# 	2:12:BasicQuery.h:BasicQuery.h
# 	2:15:IDD_QUERY_BASIC:IDD_QUERY_BASIC
# 	2:10:ENUM: enum:enum
# 	2:19:Application Include:Library.h
# 	2:14:BasicQuery.cpp:BasicQuery.cpp
# End Section
# Section Library : {CDE57A50-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CColumns
# 	2:10:HeaderFile:columns.h
# 	2:8:ImplFile:columns.cpp
# End Section
# Section Library : {00000556-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:C_Recordset
# 	2:10:HeaderFile:_recordset.h
# 	2:8:ImplFile:_recordset.cpp
# End Section
# Section Library : {A86249C7-80A3-4723-9B89-3D04423028DA}
# 	1:18:IDD_QUERY_ADVANCED:109
# 	2:16:Resource Include:resource.h
# 	2:16:AdvancedQuery1.h:AdvancedQuery1.h
# 	2:21:CLASS: CAdvancedQuery:CAdvancedQuery
# 	2:18:IDD_QUERY_ADVANCED:IDD_QUERY_ADVANCED
# 	2:10:ENUM: enum:enum
# 	2:19:Application Include:Library.h
# 	2:18:AdvancedQuery1.cpp:AdvancedQuery1.cpp
# End Section
# Section Library : {E675F3F0-91B5-11D0-9484-00A0C91110ED}
# 	2:5:Class:CDataFormatDisp
# 	2:10:HeaderFile:dataformatdisp.h
# 	2:8:ImplFile:dataformatdisp.cpp
# End Section
# Section Library : {CDE57A54-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CSplit
# 	2:10:HeaderFile:split.h
# 	2:8:ImplFile:split.cpp
# End Section
# Section Library : {D79CC95F-F0B1-4F4A-8835-D9858FD34210}
# 	1:9:IDD_LOGIN:107
# 	2:16:Resource Include:resource.h
# 	2:16:CLASS: CLoginDlg:CLoginDlg
# 	2:12:LoginDlg.cpp:LoginDlg.cpp
# 	2:10:ENUM: enum:enum
# 	2:10:LoginDlg.h:LoginDlg.h
# 	2:19:Application Include:Library.h
# 	2:9:IDD_LOGIN:IDD_LOGIN
# End Section
# Section Library : {99FF4676-FFC3-11D0-BD02-00C04FC2FB86}
# 	2:5:Class:CStdDataFormatsDisp
# 	2:10:HeaderFile:stddataformatsdisp.h
# 	2:8:ImplFile:stddataformatsdisp.cpp
# End Section
# Section Library : {FF52CE9F-FC4D-46C4-90E9-3B0162FCDA2A}
# 	1:15:IDD_BOOK_RETURN:111
# 	2:16:Resource Include:resource.h
# 	2:15:IDD_BOOK_RETURN:IDD_BOOK_RETURN
# 	2:14:ReturnBook.cpp:ReturnBook.cpp
# 	2:10:ENUM: enum:enum
# 	2:18:CLASS: CReturnBook:CReturnBook
# 	2:12:ReturnBook.h:ReturnBook.h
# 	2:19:Application Include:Library.h
# End Section
# Section Library : {986C478C-68C0-4E9F-AC6A-B4B5B7DC814F}
# 	1:8:IDD_MENU:103
# 	2:16:Resource Include:resource.h
# 	2:9:MenuDlg.h:MenuDlg.h
# 	2:8:IDD_MENU:IDD_MENU
# 	2:10:ENUM: enum:enum
# 	2:15:CLASS: CMenuDlg:CMenuDlg
# 	2:11:MenuDlg.cpp:MenuDlg.cpp
# 	2:19:Application Include:Library.h
# End Section
# Section Library : {CDE57A4F-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CColumn
# 	2:10:HeaderFile:column.h
# 	2:8:ImplFile:column.cpp
# End Section
# Section Library : {47A738F1-7FAF-11D0-B148-00A0C922E820}
# 	2:5:Class:CAdodc
# 	2:10:HeaderFile:adodc.h
# 	2:8:ImplFile:adodc.cpp
# End Section
# Section Library : {CDE57A53-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CSplits
# 	2:10:HeaderFile:splits.h
# 	2:8:ImplFile:splits.cpp
# End Section
# Section Library : {CDE57A43-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:21:DefaultSinkHeaderFile:datagrid.h
# 	2:16:DefaultSinkClass:CDataGrid
# End Section
