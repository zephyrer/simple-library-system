// MenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
//#include"QueryBasicDlg.h"
//#include"SingleAddDlg.h"
//#include"BookBorrowDlg.h"
//#include"BookReturnDlg.h"
#include"CardNewDlg.h"
#include"CardLostDlg.h"
//#include"QueryBasicDlg1.h"
#include"AdvancedQuery1.h"
#include"MenuDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuDlg dialog


CMenuDlg::CMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CMenuDlg)
	ON_COMMAND(ID_SINGLE_ADD, OnSingleAdd)
	ON_COMMAND(ID_BASIC_QUERY, OnBasicQuery)
	ON_COMMAND(ID_ADVANCED, OnAdvanced)
	ON_COMMAND(ID_BOOK_BORROW, OnBookBorrow)
	ON_COMMAND(ID_BOOK_RETURN, OnBookReturn)
	ON_COMMAND(ID_CARD_APPLY, OnCardApply)
	ON_COMMAND(ID_CARD_DESTROY, OnCardDestroy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuDlg message handlers

void CMenuDlg::OnSingleAdd() 
{
     	CSingleAddDlg a;
		a.DoModal();
}

void CMenuDlg::OnBasicQuery() 
{
		CQueryBasicDlg e;
		e.DoModal();
	
}

void CMenuDlg::OnAdvanced() 
{
	CAdvancedQueryDlg f;
	f.DoModal();
      	
}

void CMenuDlg::OnBookBorrow() 
{
	CBookBorrowDlg b;
	b.DoModal();
}

void CMenuDlg::OnBookReturn() 
{
	CBookReturnDlg a;
	a.DoModal();
}

void CMenuDlg::OnCardApply() 
{
	CCardNewDlg c;
	c.DoModal();
}

void CMenuDlg::OnCardDestroy() 
{
	CCardLostDlg d;
	d.DoModal();
}
