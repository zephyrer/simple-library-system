// CardNewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
//
#include "CardRS.h"
//
#include "CardNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardNewDlg dialog


CCardNewDlg::CCardNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCardNewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCardNewDlg)
	m_cardNum = _T("");
	m_department = _T("");
	m_name = _T("");
	m_type = _T("");
	//}}AFX_DATA_INIT
}


void CCardNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCardNewDlg)
	DDX_Text(pDX, IDC_CARD_NUM, m_cardNum);
	DDX_Text(pDX, IDC_DEPARTMENT, m_department);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_TYPE, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCardNewDlg, CDialog)
	//{{AFX_MSG_MAP(CCardNewDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardNewDlg message handlers

void CCardNewDlg::OnOK() 
{
	UpdateData();//将编辑框中的数据更新到成员变量m_CardNum中
	if (!m_cardSet.IsOpen()){
		m_cardSet.Open();
	}
	//查找借书证，检查是否已经存在
	m_cardSet.m_strFilter.Format("cno='%s'",m_cardNum);
	m_cardSet.Requery();
	//若该卡不存在，则在card表中增加一条新的记录
	if(m_cardSet.IsEOF())
	{
		m_cardSet.AddNew();
		m_cardSet.m_cno=m_cardNum;
		m_cardSet.m_name=m_name;
		m_cardSet.m_department=m_department;
		m_cardSet.m_type=m_type;
		m_cardSet.Update();

		AfxMessageBox("申请成功！");
	}
	//若该卡已存在，则弹出相应提示
	else
	{
		AfxMessageBox("该卡已存在");
	}
	CDialog::OnOK();
}
