#if !defined(AFX_CARDLOSTDLG_H__658F5934_E6CA_43A5_BBC3_61C36A3BF388__INCLUDED_)
#define AFX_CARDLOSTDLG_H__658F5934_E6CA_43A5_BBC3_61C36A3BF388__INCLUDED_

#include "CardRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardLostDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCardLostDlg dialog

class CCardLostDlg : public CDialog
{
// Construction
public:
	CCardLostDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCardLostDlg)
	enum { IDD = IDD_CARD_END };
	CString	m_cardNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardLostDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCardLostDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCardRS m_cardSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDLOSTDLG_H__658F5934_E6CA_43A5_BBC3_61C36A3BF388__INCLUDED_)
