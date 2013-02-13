// CardLostDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
//
#include "CardRS.h"
//
#include "CardLostDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardLostDlg dialog


CCardLostDlg::CCardLostDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCardLostDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCardLostDlg)
	m_cardNum = _T("");
	//}}AFX_DATA_INIT
}


void CCardLostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCardLostDlg)
	DDX_Text(pDX, IDC_CARD_NUM, m_cardNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCardLostDlg, CDialog)
	//{{AFX_MSG_MAP(CCardLostDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardLostDlg message handlers

void CCardLostDlg::OnOK() 
{
	if (!m_cardSet.IsOpen()){
		m_cardSet.Open();
	}
	UpdateData();
	m_cardSet.m_strFilter.Format("cno=%s",m_cardNum);
	m_cardSet.Requery();
	//如果找到，则删除该记录，并提示注销成功
	if(!m_cardSet.IsEOF())
	{
		m_cardSet.Delete();
		AfxMessageBox("注销成功");
	
	}
	//若找不到，则提示该卡不存在
	else
	{
		AfxMessageBox("该卡不存在");
	}
	CDialog::OnOK();
}
