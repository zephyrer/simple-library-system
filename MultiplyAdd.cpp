// MultiplyAdd.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "MultiplyAdd.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdio.h>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiplyAdd dialog


CMultiplyAdd::CMultiplyAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiplyAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiplyAdd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMultiplyAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiplyAdd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMultiplyAdd, CDialog)
	//{{AFX_MSG_MAP(CMultiplyAdd)
//	ON_COMMAND(ID_MULTIPLY_ADD, OnMultiplyAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiplyAdd message handlers
//txt中一行信息：(书号,类别,书名,出版社,年份,作者,价格,数量) 
void CMultiplyAdd::OnOK() 
{
	CString filePath;//用户所选择的文件的路径
	CFileDialog filedlg(TRUE);//设置为TRUE读文件模式
	if(IDOK==filedlg.DoModal())//显示打开文件对话框
		filePath=filedlg.GetFileName();//得到CFileDialog的文件名
	UpdateData();//更新数据
	int length;
	char * FileName;//文件名
	//将CString类型的filePath转换为char *类型的FileName
	length=filePath.GetLength();//得到filePath长度
	FileName=new char[length];//分配内存空间
	//复制filePath内容到FileName
	for(int j=0;j<length;j++)
		*(FileName+j)=filePath.GetAt(j);
	*(FileName+length)='\0';

	FILE *file;
	file=fopen(FileName,"r");
	if(!file)  //判断是否打开成功
	{
		cout<<"文件打开失败"<<endl;
		exit(0);
	}
    char *attribute[10];//相应属性的字符串值
	char *line;//读到的一行字符串
	//分配内存空间
	line=(char *)malloc(1000);
	for(int i=0;i<10;i++){
		attribute[i]=(char *)malloc(1000);
	}
	//检查book表是否已经打开
	if (!m_bookSet.IsOpen()){
		m_bookSet.Open();
	}
	int num=0;//插入数据数量
	while(fgets(line,1000,file)!=NULL)//从文件读入一行字符串
	{
		line[strlen(line)-1]='\0';
		for(int i=0;i<strlen(line);i++)
		{
			//忽略")"字符
			if(line[i]==')')
			{
				line[i]='\0';
			}
		}
		//第一个是"("字符，忽略，并以","为分隔符将读到的字符串写入attribute数组元素中
		attribute[0]=strtok(line+1,",");
		for(int k=1;k<=7;k++){
			attribute[k]=strtok(NULL,",");
		}
		//根据attribute的字符串值插入数据，其中year和number要转换成int型
		CString m_bno,m_category,m_title,m_press,m_author,m_price;
		int m_year,m_number;
		m_bno.Format("%s",attribute[0]);
		m_category.Format("%s",attribute[1]);
		m_title.Format("%s",attribute[2]);
		m_press.Format("%s",attribute[3]);
		m_year=atoi(attribute[4]);
		m_author.Format("%s",attribute[5]);
		m_price.Format("%s",attribute[6]);
		m_number=atoi(attribute[7]);
		//查询该书是否存在
		m_bookSet.m_strFilter.Format("bno='%s'",m_bno);
		m_bookSet.Requery();
		//若该书不存在，则创建新项目
		if(m_bookSet.IsEOF())
		{
			m_bookSet.AddNew();
			m_bookSet.m_bno=m_bno;
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
		num++;//更新插入数据数量
	}
	CString str;
	str.Format("成功插入了%d条记录",num);
	MessageBox(str);
	fclose(file); 
	CDialog::OnOK();
}
