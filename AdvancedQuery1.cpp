// AdvancedQuery1.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "AdvancedQuery1.h"
#include "column.h"
#include "columns.h"
#include "COMDEF.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdvancedQuery dialog


CAdvancedQuery::CAdvancedQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CAdvancedQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdvancedQuery)
	m_author = _T("");
	m_category = _T("");
	m_fromPrice = _T("");
	m_fromYear = _T("");
	m_press = _T("");
	m_title = _T("");
	m_toPrice = _T("");
	m_toYear = _T("");
	//}}AFX_DATA_INIT
}


void CAdvancedQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdvancedQuery)
	DDX_Control(pDX, IDC_ADODC1, m_adodc);
	DDX_Text(pDX, IDC_AUTHOR, m_author);
	DDX_Text(pDX, IDC_CATEGORY, m_category);
	DDX_Control(pDX, IDC_DATAGRID1, m_datagrid);
	DDX_Text(pDX, IDC_FROM_PRICE, m_fromPrice);
	DDX_Text(pDX, IDC_FROM_YEAR, m_fromYear);
	DDX_Text(pDX, IDC_PRESS, m_press);
	DDX_Text(pDX, IDC_TITLE, m_title);
	DDX_Text(pDX, IDC_TO_PRICE, m_toPrice);
	DDX_Text(pDX, IDC_TO_YEAR, m_toYear);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdvancedQuery, CDialog)
	//{{AFX_MSG_MAP(CAdvancedQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvancedQuery message handlers

void CAdvancedQuery::OnOK() 
{
	UpdateData(TRUE);//将编辑框内容更新到与此绑定的各个成员变量中
	int i,j;
	int count=0;
	CString str;
	CString strFilter;//查询条件
	CString astrKeyWord[8];//指向CString的指针数组，记录用户输入的关键字
	astrKeyWord[0]=m_category;
	astrKeyWord[1]=m_title;
	astrKeyWord[2]=m_press;
	astrKeyWord[3]=m_author;
	//m_fromYear、m_toYear、m_fromPrice、m_toPrice这四个绑定的成员变量设为CString类型，以便检查输入是否为空
	astrKeyWord[4]=m_fromYear;
	astrKeyWord[5]=m_toYear;
	astrKeyWord[6]=m_fromPrice;	
	astrKeyWord[7]=m_toPrice;
	for(i=0;i<8;i++)
	{
		if(!astrKeyWord[i].IsEmpty())
		{
			//若当前关键字非空，检查前面的关键字是否为空已决定是否要插入" and "
			for(j=0;j<i;j++)
			{
				if(!astrKeyWord[j].IsEmpty())
					count++;	//count求出前面非空的关键字的个数
			}
			//若前面非空的关键字的个数，则需要在当前的查询语句中插入" and "
			if(count>0)
			{
				strFilter+=" and ";
			}
			//以下是针对各个关键字，插入相应的查询语句
			//注意：年份和价格为不严格的大于小于关系，这样当上下限相等时就可以查询精确值
			if(i==0)
			{
				str=" category like'%"+m_category+"%' ";
				strFilter+=str;
			}
			if(i==1)
			{
				str=" title like'%"+m_title+"%' ";
				strFilter+=str;
			}
			if(i==2)
			{
				str=" press like'%"+m_press+"%' ";
				strFilter+=str;
			}
			if(i==3)
			{
				str=" author like'%"+m_author+"%' ";
				strFilter+=str;
			}
			if(i==4)
			{
				str.Format(" year>=%s ",m_fromYear);
				strFilter+=str;
			}
			if(i==5)
			{
				str.Format(" year<=%s ",m_toYear);
				strFilter+=str;
			}
			if(i==6)
			{
				str.Format(" price>=%s ",m_fromPrice);
				strFilter+=str;
			}
			if(i==7)
			{
				str.Format(" price<=%s ",m_toPrice);
				strFilter+=str;
			}
		}
	}
	CString cSource;//ADO查询语句
	cSource="SELECT bno AS 书号,category AS 类别,title AS 书名,press AS 出版社,year AS 年份,author AS 作者,price AS 价格,total AS 总藏书量,stock AS 库存 FROM book";
	//根据输入是否非空来决定显示的内容
	count=0;
	for(i=0;i<8;i++)
	{
		if(!astrKeyWord[i].IsEmpty())
			count++;	//count求出所有非空的关键字的个数
	}
	//如果输入非空，则显示查询结果；如果输入为空，则显示所有图书的信息
	if(count!=0)
	{
		cSource+=" WHERE ";
		cSource+=strFilter;
	}
	m_adodc.SetRecordSource(cSource);
	m_adodc.Refresh();
/*	
	_variant_t vIndex;
	vIndex=long(0);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(1);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(2);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(3);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(4);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(5);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(6);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(7);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
*/	
//	CDialog::OnOK();
}

BOOL CAdvancedQuery::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString cSource;//ADO查询语句
	cSource="SELECT bno AS 书号,category AS 类别,title AS 书名,press AS 出版社,year AS 年份,author AS 作者,price AS 价格,total AS 总藏书量,stock AS 库存 FROM book";
	
	m_adodc.SetRecordSource(cSource);
	m_adodc.Refresh();
	
	_variant_t vIndex;
	vIndex=long(0);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(1);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(2);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(3);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(4);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(5);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(6);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	vIndex=long(7);
	m_datagrid.GetColumns().GetItem(vIndex).SetWidth(100);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
