// BorrowRS.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BorrowRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowRS

IMPLEMENT_DYNAMIC(CBorrowRS, CRecordset)

CBorrowRS::CBorrowRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBorrowRS)
	m_cno = _T("");
	m_bno = _T("");
	m_admini_ID = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBorrowRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=test");
}

CString CBorrowRS::GetDefaultSQL()
{
	return _T("[dbo].[borrow]");
}

void CBorrowRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBorrowRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[cno]"), m_cno);
	RFX_Text(pFX, _T("[bno]"), m_bno);
	RFX_Date(pFX, _T("[borrow_date]"), m_borrow_date);
	RFX_Date(pFX, _T("[return_date]"), m_return_date);
	RFX_Text(pFX, _T("[admini_ID]"), m_admini_ID);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBorrowRS diagnostics

#ifdef _DEBUG
void CBorrowRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBorrowRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
