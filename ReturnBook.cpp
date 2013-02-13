// ReturnBook.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReturnBook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturnBook dialog


CReturnBook::CReturnBook(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnBook)
	m_strBookNum = _T("");
	m_strCardNum = _T("");
	//}}AFX_DATA_INIT
}


void CReturnBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnBook)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Text(pDX, IDC_BOOK_NUM, m_strBookNum);
	DDX_Text(pDX, IDC_CARD_NUM, m_strCardNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturnBook, CDialog)
	//{{AFX_MSG_MAP(CReturnBook)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_BN_CLICKED(IDQUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnBook message handlers

void CReturnBook::OnOK() 
{
	UpdateData(true);//将编辑框中的数据更新到成员变量m_strCardNum和m_strBookNum中

	if (!m_borrowSet.IsOpen()){
		m_borrowSet.Open();
	}
	//找出所还书籍的还书记录
	m_borrowSet.m_strFilter.Format("cno='%s' and bno='%s' and return_date is null",m_strCardNum,m_strBookNum);
	m_borrowSet.Requery();
	//当所还书籍不存在或者所有记录的还书时间都非空时
	if (m_borrowSet.IsEOF()){
		AfxMessageBox("此书不存在或已经还掉");
		CDialog::OnOK();
		return ;
	}
	CTime today=CTime::GetCurrentTime();//当前日期
	CTimeSpan diffDays=today-m_borrowSet.m_borrow_date;	//计算所还书籍所借的天数
	// 若借书时间超过30天则弹出借书过期的提示对话框并继续进行还书操作
	if (diffDays.GetDays()>30){
 		AfxMessageBox("该书过期了");
		CDialog::OnOK();
	}
	//将还书日期改成当前日期
	m_borrowSet.Edit();
	m_borrowSet.m_return_date=today;
	m_borrowSet.Update();

	//book表中该藏书的库存加1
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}
	m_bookSet.m_strFilter.Format("bno='%s'",m_strBookNum);
	m_bookSet.Requery();
	m_bookSet.Edit();
	m_bookSet.m_stock=m_bookSet.m_stock+1;
	m_bookSet.Update();	
	AfxMessageBox("还书成功");
	CDialog::OnOK();
}

void CReturnBook::OnQuery() 
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);
	UpdateData();
	if(!m_cardSet.IsOpen())
	{
		m_cardSet.Open();
	}
	if (!m_borrowSet.IsOpen()){
		m_borrowSet.Open();
	}
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}
	m_cardSet.m_strFilter.Format("cno=%s",m_strCardNum);
	m_cardSet.Requery();
	//若卡号信息不正确，则报错返回
	if(m_cardSet.IsEOF())
	{
		AfxMessageBox("卡号信息不正确");
		return;
	}
	m_borrowSet.m_strFilter.Format("cno='%s'",m_strCardNum);
	m_borrowSet.Requery();
	//若没有已借书籍，则报错返回
	if(m_borrowSet.IsEOF())
	{
		AfxMessageBox("没有已借书籍");
		return;
	}
	int i=0;
	CString str;//将非CString类型的成员变量转换为CString类型以便显示
	while(!m_borrowSet.IsEOF())
	{
		m_bookSet.m_strFilter.Format("bno='%s'",m_borrowSet.m_bno);
		m_bookSet.Requery();

		m_ctrList.InsertItem(i,m_bookSet.m_bno);
		m_ctrList.SetItemText(i,1,m_bookSet.m_category);
		m_ctrList.SetItemText(i,2,m_bookSet.m_title);
		m_ctrList.SetItemText(i,3,m_bookSet.m_press);
		str.Format("%d",m_bookSet.m_year);
		m_ctrList.SetItemText(i,4,str);
		m_ctrList.SetItemText(i,5,m_bookSet.m_author);
		str.Format("%f",m_bookSet.m_price);
		m_ctrList.SetItemText(i,6,str);
		str.Format("%d",m_bookSet.m_total);
		m_ctrList.SetItemText(i,7,str);
		str.Format("%d",m_bookSet.m_stock);
		m_ctrList.SetItemText(i,8,str);
		i++;
		m_borrowSet.MoveNext();
	}	
	m_borrowSet.Close();
	m_ctrList.SetRedraw(TRUE);	
}
BOOL CReturnBook::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"书号");
	m_ctrList.InsertColumn(1,"类别");
	m_ctrList.InsertColumn(2,"书名");
	m_ctrList.InsertColumn(3,"出版社");
	m_ctrList.InsertColumn(4,"年份");
	m_ctrList.InsertColumn(5,"作者");
	m_ctrList.InsertColumn(6,"价格");
	m_ctrList.InsertColumn(7,"总藏书量");
	m_ctrList.InsertColumn(8,"库存");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,120);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,80);
	m_ctrList.SetColumnWidth(8,80);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
