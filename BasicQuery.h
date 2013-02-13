#if !defined(AFX_BASICQUERY_H__AB5E8211_6AC3_4409_B29A_A7507E535428__INCLUDED_)
#define AFX_BASICQUERY_H__AB5E8211_6AC3_4409_B29A_A7507E535428__INCLUDED_

#include "BookRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BasicQuery.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBasicQuery dialog

class CBasicQuery : public CDialog
{
// Construction
public:
	CBasicQuery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBasicQuery)
	enum { IDD = IDD_QUERY_BASIC };
	CListCtrl	m_ctrList;
	CString	m_strKeyWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasicQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBasicQuery)
	afx_msg void OnQuery();
	virtual BOOL OnInitDialog();
	afx_msg void OnColumnclickListctrl(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBookRS m_bookSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASICQUERY_H__AB5E8211_6AC3_4409_B29A_A7507E535428__INCLUDED_)
