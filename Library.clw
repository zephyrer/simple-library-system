; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdvancedQuery
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Library.h"

ClassCount=18
Class1=CLibraryApp
Class2=CLibraryDlg
Class3=CAboutDlg

ResourceCount=15
Resource1=IDD_MENU
Resource2=IDR_MAINFRAME
Resource3=IDD_CARD_APPLY
Resource4=IDD_ABOUTBOX
Resource5=IDD_ADVANCED_QUERY
Class5=CCardNewDlg
Resource6=IDD_CARD_END
Resource7=IDD_LOGIN
Class6=CCardLostDlg
Class7=CLoginDlg
Resource8=IDD_MULTIPLY_ADD
Class8=CBasicQuery
Resource9=IDD_LIBRARY_DIALOG
Class9=CAdvancedQuery
Resource10=IDD_QUERY_BASIC
Class10=CBookRS
Class11=CBorrowRS
Class12=CCardRS
Class13=CAdminRS
Class4=CSingleAddDlg
Class14=CMainMenu
Resource11=IDD_SINGLE_ADD1
Class15=CQueryAdvanced
Resource12=IDD_QUERY_ADVANCED
Resource13=IDD_BOOK_RETURN
Class16=CBorrowBook
Class17=CReturnBook
Resource14=IDD_BOOK_BORROW
Class18=CMultiplyAdd
Resource15=IDR_MENU1

[CLS:CLibraryApp]
Type=0
HeaderFile=Library.h
ImplementationFile=Library.cpp
Filter=N

[CLS:CLibraryDlg]
Type=0
HeaderFile=LibraryDlg.h
ImplementationFile=LibraryDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=LibraryDlg.h
ImplementationFile=LibraryDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIBRARY_DIALOG]
Type=1
Class=CLibraryDlg
ControlCount=1
Control1=IDC_STATIC,static,1342308864

[DLG:IDD_MENU]
Type=1
Class=CMainMenu
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDD_SINGLE_ADD
Command2=ID_MULTIPLY_ADD
Command3=ID_BASIC_QUERY
Command4=ID_ADVANCED
Command5=ID_BOOK_BORROW
Command6=ID_BOOK_RETURN
Command7=ID_CARD_APPLY
Command8=ID_CARD_DESTROY
CommandCount=8

[DLG:IDD_SINGLE_ADD1]
Type=1
Class=CSingleAddDlg
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_BOOK_NUM,edit,1350631552
Control12=IDC_CATEGORY,edit,1350631552
Control13=IDC_PRESS,edit,1350631552
Control14=IDC_TITLE,edit,1350631552
Control15=IDC_YEAR,edit,1350631552
Control16=IDC_AUTHOR,edit,1350631552
Control17=IDC_PRICE,edit,1350631552
Control18=IDC_NUMBER,edit,1350631552

[CLS:CSingleAddDlg]
Type=0
HeaderFile=SingleAddDlg.h
ImplementationFile=SingleAddDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_MULTIPLY_ADD

[DLG:IDD_CARD_APPLY]
Type=1
Class=CCardNewDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CARD_NUM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_NAME,edit,1350631552
Control9=IDC_DEPARTMENT,edit,1350631552
Control10=IDC_TYPE,edit,1350631552

[CLS:CCardNewDlg]
Type=0
HeaderFile=CardNewDlg.h
ImplementationFile=CardNewDlg.cpp
BaseClass=CDialog

[DLG:IDD_CARD_END]
Type=1
Class=CCardLostDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CARD_NUM,edit,1350631552

[CLS:CCardLostDlg]
Type=0
HeaderFile=CardLostDlg.h
ImplementationFile=CardLostDlg.cpp
BaseClass=CDialog

[DLG:IDD_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_READER,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CODE,edit,1350631584
Control7=IDC_ADMINI_ID,combobox,1344340226

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[DLG:IDD_QUERY_BASIC]
Type=1
Class=CBasicQuery
ControlCount=5
Control1=IDC_QUERY,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_KEY_WORD,edit,1350631552
Control5=IDC_LISTCTRL,SysListView32,1350631425

[CLS:CBasicQuery]
Type=0
HeaderFile=BasicQuery.h
ImplementationFile=BasicQuery.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBasicQuery

[DLG:IDD_QUERY_ADVANCED]
Type=1
Class=CAdvancedQuery
ControlCount=22
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CATEGORY,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TITLE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PRESS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_AUTHOR,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_FROM_YEAR,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_TO_YEAR,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_FROM_PRICE,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_TO_PRICE,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDOK,button,1342242816
Control20=IDCANCEL,button,1342242816
Control21=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1073741824
Control22=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816

[CLS:CAdvancedQuery]
Type=0
HeaderFile=AdvancedQuery1.h
ImplementationFile=AdvancedQuery1.cpp
BaseClass=CDialog
LastObject=CAdvancedQuery
Filter=D
VirtualFilter=dWC

[CLS:CBookRS]
Type=0
HeaderFile=BookRS.h
ImplementationFile=BookRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CBookRS]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[bno], 1, 8
Column2=[category], 1, 10
Column3=[title], 12, 40
Column4=[press], 12, 30
Column5=[year], 4, 4
Column6=[author], 12, 20
Column7=[price], 3, 9
Column8=[total], 4, 4
Column9=[stock], 4, 4

[CLS:CBorrowRS]
Type=0
HeaderFile=BorrowRS.h
ImplementationFile=BorrowRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CBorrowRS]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[cno], 1, 7
Column2=[bno], 1, 8
Column3=[borrow_date], 11, 16
Column4=[return_date], 11, 16
Column5=[admini_ID], 1, 10

[CLS:CCardRS]
Type=0
HeaderFile=CardRS.h
ImplementationFile=CardRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CCardRS]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[cno], 1, 7
Column2=[name], 12, 10
Column3=[department], 12, 40
Column4=[type], 1, 1

[CLS:CAdminRS]
Type=0
HeaderFile=AdminRS.h
ImplementationFile=AdminRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CAdminRS

[DB:CAdminRS]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[admini_ID], 1, 10
Column2=[code], 1, 10
Column3=[admin_name], 1, 10
Column4=[contact], 12, 40

[CLS:CMainMenu]
Type=0
HeaderFile=MainMenu.h
ImplementationFile=MainMenu.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MULTIPLY_ADD
VirtualFilter=dWC

[DLG:IDD_ADVANCED_QUERY]
Type=1
Class=CQueryAdvanced
ControlCount=22
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=1001,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=1002,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=1003,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=1004,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_FROM_YEAR,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_TO_YEAR,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_FROM_PRICE,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_TO_PRICE,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1073741824
Control22=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816

[CLS:CQueryAdvanced]
Type=0
HeaderFile=QueryAdvanced.h
ImplementationFile=QueryAdvanced.cpp
BaseClass=CDialog
Filter=D
LastObject=1001

[DLG:IDD_BOOK_BORROW]
Type=1
Class=CBorrowBook
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CARD_NUM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BOOK_NUM,edit,1350631552
Control7=IDC_LIST1,SysListView32,1350631425
Control8=IDQUERY,button,1342242816

[CLS:CBorrowBook]
Type=0
HeaderFile=BorrowBook.h
ImplementationFile=BorrowBook.cpp
BaseClass=CDialog
LastObject=IDQUERY
Filter=D
VirtualFilter=dWC

[DLG:IDD_BOOK_RETURN]
Type=1
Class=CReturnBook
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CARD_NUM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BOOK_NUM,edit,1350631552
Control7=IDC_LIST1,SysListView32,1350631425
Control8=IDQUERY,button,1342242816

[CLS:CReturnBook]
Type=0
HeaderFile=ReturnBook.h
ImplementationFile=ReturnBook.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BOOK_NUM

[DLG:IDD_MULTIPLY_ADD]
Type=1
Class=CMultiplyAdd
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CMultiplyAdd]
Type=0
HeaderFile=MultiplyAdd.h
ImplementationFile=MultiplyAdd.cpp
BaseClass=CDialog
Filter=D
LastObject=CMultiplyAdd
VirtualFilter=dWC

