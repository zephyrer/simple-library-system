// MainMenu.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "MainMenu.h"
#include "AdvancedQuery1.h"
#include "BasicQuery.h"
#include "CardNewDlg.h"
#include "CardLostDlg.h"
#include "SingleAddDlg.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "MultiplyAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainMenu dialog


CMainMenu::CMainMenu(CWnd* pParent /*=NULL*/)
	: CDialog(CMainMenu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainMenu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainMenu)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainMenu, CDialog)
	//{{AFX_MSG_MAP(CMainMenu)
	ON_COMMAND(ID_ADVANCED, OnAdvanced)
	ON_COMMAND(ID_BASIC_QUERY, OnBasicQuery)
	ON_COMMAND(ID_CARD_APPLY, OnCardApply)
	ON_COMMAND(ID_CARD_DESTROY, OnCardDestroy)
	ON_COMMAND(IDD_SINGLE_ADD, OnSingleAdd)
	ON_COMMAND(ID_BOOK_BORROW, OnBookBorrow)
	ON_COMMAND(ID_BOOK_RETURN, OnBookReturn)
	ON_COMMAND(ID_MULTIPLY_ADD, OnMultiplyAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainMenu message handlers

void CMainMenu::OnAdvanced() 
{
	CAdvancedQuery a;
	a.DoModal();
}

void CMainMenu::OnBasicQuery() 
{
	CBasicQuery a;
	a.DoModal();
}

void CMainMenu::OnCardApply() 
{
	CCardNewDlg a;
	a.DoModal();
}

void CMainMenu::OnCardDestroy() 
{
	CCardLostDlg a;
	a.DoModal();
}

void CMainMenu::OnSingleAdd() 
{
	CSingleAddDlg a;
	a.DoModal();
}

void CMainMenu::OnBookBorrow() 
{
	CBorrowBook a;
	a.DoModal();	
}

void CMainMenu::OnBookReturn() 
{
	CReturnBook a;
	a.DoModal();	
}

void CMainMenu::OnMultiplyAdd() 
{
	CMultiplyAdd a;
	a.DoModal();
}
