#if !defined(AFX_BOOKRS_H__EF739DFD_4D0B_40D2_A733_C1BBB8710404__INCLUDED_)
#define AFX_BOOKRS_H__EF739DFD_4D0B_40D2_A733_C1BBB8710404__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookRS recordset

class CBookRS : public CRecordset
{
public:
	CBookRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBookRS)

// Field/Param Data
	//{{AFX_FIELD(CBookRS, CRecordset)
	CString	m_bno;
	CString	m_category;
	CString	m_title;
	CString	m_press;
	long	m_year;
	CString	m_author;
	CString	m_price;
	long	m_total;
	long	m_stock;
	//}}AFX_FIELD
/*
	CString	m_category;
	CString	m_title;
	CString	m_press;
	long	m_year;
	CString	m_author;
	CString	m_price;
	long	m_total;
	long	m_stock;
	//}}AFX_FIELD
*/

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookRS)
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

#endif // !defined(AFX_BOOKRS_H__EF739DFD_4D0B_40D2_A733_C1BBB8710404__INCLUDED_)
