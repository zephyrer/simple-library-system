// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LoginDlg.h"
#include "BasicQuery.h"
#include "AdvancedQuery1.h"
#include"SingleAddDlg.h"
#include "CardNewDlg.h"
#include "CardLostDlg.h"
#include "MainMenu.h"
#include "LibraryDlg.h"
#include "currentID.h"
extern CString currentID;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_strAdminiID = _T("");
	m_strCode = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_CBString(pDX, IDC_ADMINI_ID, m_strAdminiID);
	DDX_Text(pDX, IDC_CODE, m_strCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_READER, OnReader)
//	ON_COMMAND(ID_ADVANCED, OnAdvanced)
//	ON_COMMAND(ID_BASIC_QUERY, OnBasicQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	CString str;
	CString strfilter;
    UpdateData(true);//将编辑框中的数据更新到成员变量m_strAdminiID和m_strCode中
	if(!m_adminiSet.IsOpen())
	{
		m_adminiSet.Open();
	}
	strfilter.Format("admini_ID='%s'",m_strAdminiID);
	m_adminiSet.m_strFilter=strfilter;
	m_adminiSet.Requery();
	//若ID不存在，弹出出错消息并返回
	if(m_adminiSet.IsEOF())
	{
		AfxMessageBox("ID不存在");
		return;
	}
	else
	{
		str.Format(" and code='%s'",m_strCode);
		strfilter+=str;
		m_adminiSet.m_strFilter=strfilter;
		m_adminiSet.Requery();
		//若密码不匹配，弹出出错消息并返回
		if(m_adminiSet.IsEOF())
		{
			AfxMessageBox("密码不匹配");
			return;
		}
		//若卡号信息正确，则更新当前登录的ID并打开主菜单对话框
		else 
		{
			currentID=m_strAdminiID;
			CMainMenu a;
			a.DoModal();
		}
	}
}
//选择读者登录则打开查询对话框
void CLoginDlg::OnReader() 
{
	CBasicQuery a;
	a.DoModal();
	CDialog::OnOK();
}
