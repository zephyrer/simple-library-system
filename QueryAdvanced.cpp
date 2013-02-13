// QueryAdvanced.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "QueryAdvanced.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryAdvanced dialog


CQueryAdvanced::CQueryAdvanced(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryAdvanced::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryAdvanced)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CQueryAdvanced::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryAdvanced)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryAdvanced, CDialog)
	//{{AFX_MSG_MAP(CQueryAdvanced)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryAdvanced message handlers
