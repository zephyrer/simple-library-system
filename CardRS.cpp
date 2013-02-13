// CardRS.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "CardRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardRS

IMPLEMENT_DYNAMIC(CCardRS, CRecordset)

CCardRS::CCardRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCardRS)
	m_cno = _T("");
	m_name = _T("");
	m_department = _T("");
	m_type = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCardRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=test");
}

CString CCardRS::GetDefaultSQL()
{
	return _T("[dbo].[card]");
}

void CCardRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCardRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[cno]"), m_cno);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[department]"), m_department);
	RFX_Text(pFX, _T("[type]"), m_type);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCardRS diagnostics

#ifdef _DEBUG
void CCardRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCardRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
