#if !defined(AFX_CARDNEWDLG_H__84634645_FD30_4454_A24F_FF34C905A1E2__INCLUDED_)
#define AFX_CARDNEWDLG_H__84634645_FD30_4454_A24F_FF34C905A1E2__INCLUDED_

#include "CardRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardNewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCardNewDlg dialog

class CCardNewDlg : public CDialog
{
// Construction
public:
	CCardNewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCardNewDlg)
	enum { IDD = IDD_CARD_APPLY };
	CString	m_cardNum;
	CString	m_department;
	CString	m_name;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardNewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCardNewDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCardRS m_cardSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDNEWDLG_H__84634645_FD30_4454_A24F_FF34C905A1E2__INCLUDED_)
