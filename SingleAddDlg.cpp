// SingleAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "SingleAddDlg.h"
//
#include "BookRS.h"
//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleAddDlg dialog


CSingleAddDlg::CSingleAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSingleAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSingleAddDlg)
	m_author = _T("");
	m_bookNum = _T("");
	m_category = _T("");
	m_press = _T("");
	m_title = _T("");
	m_number = 0;
	m_price = _T("");
	m_year = 0;
	//}}AFX_DATA_INIT
}


void CSingleAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSingleAddDlg)
	DDX_Text(pDX, IDC_AUTHOR, m_author);
	DDX_Text(pDX, IDC_BOOK_NUM, m_bookNum);
	DDX_Text(pDX, IDC_CATEGORY, m_category);
	DDX_Text(pDX, IDC_PRESS, m_press);
	DDX_Text(pDX, IDC_TITLE, m_title);
	DDX_Text(pDX, IDC_NUMBER, m_number);
	DDX_Text(pDX, IDC_PRICE, m_price);
	DDX_Text(pDX, IDC_YEAR, m_year);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSingleAddDlg, CDialog)
	//{{AFX_MSG_MAP(CSingleAddDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleAddDlg message handlers

void CSingleAddDlg::OnOK() 
{
	UpdateData();//更新数据
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}

	m_bookSet.m_strFilter.Format("bno='%s'",m_bookNum);
	m_bookSet.Requery();
	//若该书不存在，则创建新项目
	if(m_bookSet.IsEOF())
	{
		m_bookSet.AddNew();
		m_bookSet.m_bno=m_bookNum;
		m_bookSet.m_category=m_category;
		m_bookSet.m_title=m_title;
		m_bookSet.m_press=m_press;
		m_bookSet.m_year=m_year;
		m_bookSet.m_author=m_author;
	    m_bookSet.m_price=m_price;
		m_bookSet.m_total=m_number;
		m_bookSet.m_stock=m_number;
		m_bookSet.Update();
	}
	//若该书已存在，则更新其总藏书量和库存
	else
	{
		m_bookSet.Edit();
		m_bookSet.m_total+=m_number;
		m_bookSet.m_stock+=m_number;
		m_bookSet.Update();
	}
	AfxMessageBox("申请成功！");
	CDialog::OnOK();
}
