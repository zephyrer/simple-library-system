//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_ADVANCEDQUERY1_H__7860E94A_984D_4E5A_8D7D_C7A4E422B83A__INCLUDED_)
#define AFX_ADVANCEDQUERY1_H__7860E94A_984D_4E5A_8D7D_C7A4E422B83A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdvancedQuery1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdvancedQuery dialog

class CAdvancedQuery : public CDialog
{
// Construction
public:
	CAdvancedQuery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdvancedQuery)
	enum { IDD = IDD_QUERY_ADVANCED };
	CAdodc	m_adodc;
	CString	m_author;
	CString	m_category;
	CDataGrid	m_datagrid;
	CString	m_fromPrice;
	CString	m_fromYear;
	CString	m_press;
	CString	m_title;
	CString	m_toPrice;
	CString	m_toYear;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdvancedQuery)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDQUERY1_H__7860E94A_984D_4E5A_8D7D_C7A4E422B83A__INCLUDED_)
