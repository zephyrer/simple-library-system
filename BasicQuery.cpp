// BasicQuery.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BasicQuery.h"
#include "BookRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBasicQuery dialog


CBasicQuery::CBasicQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CBasicQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBasicQuery)
	m_strKeyWord = _T("");
	//}}AFX_DATA_INIT
}


void CBasicQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBasicQuery)
	DDX_Control(pDX, IDC_LISTCTRL, m_ctrList);
	DDX_Text(pDX, IDC_KEY_WORD, m_strKeyWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBasicQuery, CDialog)
	//{{AFX_MSG_MAP(CBasicQuery)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LISTCTRL, OnColumnclickListctrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBasicQuery message handlers

void CBasicQuery::OnQuery() 
{
	m_ctrList.DeleteAllItems();//进行查询时，清空ListControl原有的内容
	m_ctrList.SetRedraw(FALSE);// ListControl内容进行大数据量更新时，避免闪烁
	UpdateData();//将编辑框内容更新到与此绑定的成员变量m_strKeyWord中
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}
	//设置查询条件，根据书名关键字进行模糊查询
	m_bookSet.m_strFilter="title like '%"+m_strKeyWord+"%'";
	m_bookSet.Requery();
	
	//若找不到该书，则弹出提示并返回
	if (m_bookSet.IsEOF()){
		AfxMessageBox("查无此书");
		return;
	}
	//将全部的结果显示在ListControl中
	int i=0;
	CString str;//将非CString类型的成员变量转换为CString类型以便显示
	while (!m_bookSet.IsEOF()){		
		m_ctrList.InsertItem(i,m_bookSet.m_bno);//插入bno属性的值作为索引
		//添加其他内容
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
		m_bookSet.MoveNext();
	}
	m_bookSet.Close();
	m_ctrList.SetRedraw(TRUE);
}
BOOL CBasicQuery::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//添加表头	
	m_ctrList.InsertColumn(0,"书号");
	m_ctrList.InsertColumn(1,"类别");
	m_ctrList.InsertColumn(2,"书名");
	m_ctrList.InsertColumn(3,"出版社");
	m_ctrList.InsertColumn(4,"年份");
	m_ctrList.InsertColumn(5,"作者");
	m_ctrList.InsertColumn(6,"价格");
	m_ctrList.InsertColumn(7,"总藏书量");
	m_ctrList.InsertColumn(8,"库存");
	//设置列宽
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
	//LVS_EX_FULLROWSELECT为选中某行使整行高亮功能，为"报告"显示方式所特有
	//LVS_EX_GRIDLINES为网格线功能，为"报告"显示方式所特有
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBasicQuery::OnColumnclickListctrl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	static int sortstyl=1;//排序方式
	int selectcol = pNMListView->iSubItem;//获得当前所选列
	int listcount;//总行数
	listcount = m_ctrList.GetItemCount();
	CString temp0,temp1,temp2;
	if(sortstyl==1)
	{
		//冒泡排序
		 for(int j = 1;j<=listcount;j++)
		 {
			for(int i=0;i<listcount-j;i++)
			{
				temp1 = m_ctrList.GetItemText(i,selectcol);
				temp2 = m_ctrList.GetItemText(i+1,selectcol);
				if(temp1 > temp2)
				{
					for(int n=0;n<9;n++)
					{
						temp1 = m_ctrList.GetItemText(i,n);
						temp2 = m_ctrList.GetItemText(i+1,n);
						m_ctrList.SetItemText(i,n,temp2);
						m_ctrList.SetItemText(i+1,n,temp1);
					}
				}
			}  
		}
	 }
	//点击第二次时将换一种方式排
	else if(sortstyl==-1)
	{ 
		for(int j = 1;j<=listcount;j++)
		{
			for(int i=0;i<listcount-j;i++)
			{
				temp1 = m_ctrList.GetItemText(i,selectcol);
				temp2 = m_ctrList.GetItemText(i+1,selectcol);
				if(temp2 > temp1)
				{
					for(int n=0;n<9;n++)
					{
						temp1 = m_ctrList.GetItemText(i,n);
						temp2 = m_ctrList.GetItemText(i+1,n);
						m_ctrList.SetItemText(i,n,temp2);
						m_ctrList.SetItemText(i+1,n,temp1);
					}
				}
			}  
		}
	}
	sortstyl = sortstyl*(-1);//每点击一次sortstyl乘以负1，这样下次点击就换成另一种方式排序	
	*pResult = 0;
}
