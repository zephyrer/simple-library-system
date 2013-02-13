// AdminRS.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "AdminRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdminRS

IMPLEMENT_DYNAMIC(CAdminRS, CRecordset)

CAdminRS::CAdminRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAdminRS)
	m_admini_ID = _T("");
	m_code = _T("");
	m_admin_name = _T("");
	m_contact = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAdminRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=test");
}

CString CAdminRS::GetDefaultSQL()
{
	return _T("[dbo].[admini]");
}

void CAdminRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAdminRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[admini_ID]"), m_admini_ID);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[admin_name]"), m_admin_name);
	RFX_Text(pFX, _T("[contact]"), m_contact);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAdminRS diagnostics

#ifdef _DEBUG
void CAdminRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAdminRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
