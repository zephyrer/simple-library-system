#if !defined(AFX_SINGLEADDDLG_H__B2079621_E5BA_4F2C_BEFE_F6CF815CE06B__INCLUDED_)
#define AFX_SINGLEADDDLG_H__B2079621_E5BA_4F2C_BEFE_F6CF815CE06B__INCLUDED_

#include "BookRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SingleAddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSingleAddDlg dialog

class CSingleAddDlg : public CDialog
{
// Construction
public:
	CSingleAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSingleAddDlg)
	enum { IDD = IDD_SINGLE_ADD1 };
	CString	m_author;
	CString	m_bookNum;
	CString	m_category;
	CString	m_press;
	CString	m_title;
	long	m_number;
	CString	m_price;
	long	m_year;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSingleAddDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBookRS m_bookSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEADDDLG_H__B2079621_E5BA_4F2C_BEFE_F6CF815CE06B__INCLUDED_)
