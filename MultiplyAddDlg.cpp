// MultiplyAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "MultiplyAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiplyAddDlg dialog


CMultiplyAddDlg::CMultiplyAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiplyAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiplyAddDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMultiplyAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiplyAddDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMultiplyAddDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiplyAddDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiplyAddDlg message handlers
