#if !defined(AFX_BORROWRS_H__9A6783F3_F5E1_4093_AE9F_88703C8E73D7__INCLUDED_)
#define AFX_BORROWRS_H__9A6783F3_F5E1_4093_AE9F_88703C8E73D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowRS recordset

class CBorrowRS : public CRecordset
{
public:
	CBorrowRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBorrowRS)

// Field/Param Data
	//{{AFX_FIELD(CBorrowRS, CRecordset)
	CString	m_cno;
	CString	m_bno;
	CTime	m_borrow_date;
	CTime	m_return_date;
	CString	m_admini_ID;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowRS)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWRS_H__9A6783F3_F5E1_4093_AE9F_88703C8E73D7__INCLUDED_)
