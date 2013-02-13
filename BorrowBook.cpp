// BorrowBook.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BorrowBook.h"
#include "currentID.h"
extern CString currentID;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowBook dialog


CBorrowBook::CBorrowBook(CWnd* pParent /*=NULL*/)
	: CDialog(CBorrowBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBorrowBook)
	m_strBookNum = _T("");
	m_strCardNum = _T("");
	//}}AFX_DATA_INIT
}


void CBorrowBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBorrowBook)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Text(pDX, IDC_BOOK_NUM, m_strBookNum);
	DDX_Text(pDX, IDC_CARD_NUM, m_strCardNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBorrowBook, CDialog)
	//{{AFX_MSG_MAP(CBorrowBook)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_BN_CLICKED(IDQUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBorrowBook message handlers

void CBorrowBook::OnOK() 
{
	UpdateData();//将编辑框中的数据更新到成员变量m_strCardNum和m_strBookNum中
	
	//如果卡号不存在则返回，拒绝借书
	if (!IsValidCard(m_strCardNum)){
		CDialog::OnOK();
		return;
	}
	//如果借书超过借书期限和借书限额，则返回拒绝借书
	if (AnyBookExpired(m_strCardNum)){
		CDialog::OnOK();
		return;
	}
	//如果所借图书不存在或没有库存，则返回拒绝借书
	if(Nobook(m_strBookNum)){
		CDialog::OnOK();
		return;
	}
	//只有以上情况都没有问题时，才允许外借图书
	if (BorrowBook(m_strCardNum,m_strBookNum))
	{
		AfxMessageBox("借书成功");
	}
	else
	{
		AfxMessageBox("借书失败");
	}
	CDialog::OnOK();
}

bool CBorrowBook::IsValidCard(const CString &cardNum)
{
	if (!m_cardSet.IsOpen()){
		m_cardSet.Open();
	}
	m_cardSet.m_strFilter.Format("cno='%s'",cardNum);
	m_cardSet.Requery();
	//若卡号不存在，弹出出错消息并返回
	if (m_cardSet.IsEOF()){
		AfxMessageBox("该卡号不存在");
		return false;
	}
	return true;
}

bool CBorrowBook::AnyBookExpired(const CString &cardNum)
{
	int total=0;//借书总数
	if (!m_borrowSet.IsOpen()){
		m_borrowSet.Open();
	}
	m_borrowSet.m_strFilter.Format("cno='%s' and return_date is null",cardNum);
	m_borrowSet.Requery();
	CTime  today=CTime::GetCurrentTime();//当前时间
	CTimeSpan diffDays;
	while (!m_borrowSet.IsEOF()){		
		total++;		
		diffDays=today-m_borrowSet.m_borrow_date;//计算当前时间与借书时间的间隔
		//超过30天借书期限，则报错返回
		if (diffDays.GetDays()>30){
			AfxMessageBox("您有书过期了");
			return true;
		}
		m_borrowSet.MoveNext();	
	}
	//借书总数不能超过12本借书限额
	if (total>12){
		AfxMessageBox("您借书总数超额了");
		return true;
	}	
	return false;
}
bool CBorrowBook::Nobook(const CString &bookNum)
{
	CTimeSpan span(30,0,0,0);//30天的时间间隔
	CTime nearest;//最近归还的时间
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}
	//指定查询条件bno为书号
	m_bookSet.m_strFilter.Format("bno='%s'",bookNum);
	m_bookSet.Requery();
	//若该书不存在，则报错返回
	if(m_bookSet.IsEOF())
	{
		AfxMessageBox("该书不存在");
		return true;
	}
	//若库存为0，则弹出没有库存的提示并提示使用者该书最近的还书时间以方便其再次借书
	if(m_bookSet.m_stock==0)
	{
		AfxMessageBox("该书已经没有库存");
		if (!m_borrowSet.IsOpen())
		{
			m_borrowSet.Open();
		}
		m_borrowSet.m_strFilter.Format("bno='%s' and return_date is NULL",bookNum);
		m_borrowSet.m_strSort="borrow_date ASC";//按借书时间升序排序
		nearest=m_borrowSet.m_borrow_date+span;//30天后的日期
		CString strTime="最近的还书时间是:";  
		strTime+=nearest.Format("%Y-%m-%d   %H:%M:%S");
		MessageBox(strTime);
		return true;
	}	
	return false;
}


bool CBorrowBook::BorrowBook(const CString &cardNum, const CString &bookNum)
{
	CTimeSpan span(30,0,0,0);//30天的时间间隔
	CTime nextMonth=CTime::GetCurrentTime()+span;//30天后的日期
	//将book表中的库存减1
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}	
	m_bookSet.m_strFilter.Format("bno='%s'",bookNum);
	m_bookSet.Requery();	
	m_bookSet.Edit();
	m_bookSet.m_stock=m_bookSet.m_stock-1;
	m_bookSet.Update();

	//在borrow表中增加一条借书记录
	if (!m_borrowSet.IsOpen()){
		m_borrowSet.Open();
	}	
	m_borrowSet.AddNew();
	m_borrowSet.m_bno=bookNum;
	m_borrowSet.m_cno=cardNum;
	m_borrowSet.m_borrow_date=CTime::GetCurrentTime();
	m_borrowSet.m_admini_ID=currentID;//经手人设为当前登录的管理员ID
	m_borrowSet.Update();
	m_borrowSet.Requery();
	return true;
}

void CBorrowBook::OnQuery() 
{	
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);
	UpdateData();

	if(!m_cardSet.IsOpen())
	{
		m_cardSet.Open();
	}
	if(!m_borrowSet.IsOpen()){
		m_borrowSet.Open();
	}
	if(!m_bookSet.IsOpen()){
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

	m_borrowSet.m_strFilter.Format("cno=%s",m_strCardNum);
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
BOOL CBorrowBook::OnInitDialog() 
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
