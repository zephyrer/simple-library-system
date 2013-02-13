#if !defined(AFX_LOGINDLG_H__6BBDF871_8AA0_486C_87A5_97FF45EB534F__INCLUDED_)
#define AFX_LOGINDLG_H__6BBDF871_8AA0_486C_87A5_97FF45EB534F__INCLUDED_

#include "AdminRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_LOGIN };
	CString	m_strAdminiID;
	CString	m_strCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	virtual void OnOK();
	afx_msg void OnReader();
//	afx_msg void OnAdvanced();
//	afx_msg void OnBasicQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAdminRS m_adminiSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__6BBDF871_8AA0_486C_87A5_97FF45EB534F__INCLUDED_)
