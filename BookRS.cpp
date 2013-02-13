// BookRS.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BookRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookRS

IMPLEMENT_DYNAMIC(CBookRS, CRecordset)

CBookRS::CBookRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBookRS)
	m_bno = _T("");
	m_category = _T("");
	m_title = _T("");
	m_press = _T("");
	m_year = 0;
	m_author = _T("");
	m_price = _T("");
	m_total = 0;
	m_stock = 0;
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBookRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=test");
}

CString CBookRS::GetDefaultSQL()
{
	return _T("[dbo].[book]");
}

void CBookRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBookRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[bno]"), m_bno);
	RFX_Text(pFX, _T("[category]"), m_category);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[press]"), m_press);
	RFX_Long(pFX, _T("[year]"), m_year);
	RFX_Text(pFX, _T("[author]"), m_author);
	RFX_Text(pFX, _T("[price]"), m_price);
	RFX_Long(pFX, _T("[total]"), m_total);
	RFX_Long(pFX, _T("[stock]"), m_stock);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBookRS diagnostics

#ifdef _DEBUG
void CBookRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBookRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
