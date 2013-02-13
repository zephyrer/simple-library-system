#if !defined(AFX_MULTIPLYADDDLG_H__E2FF9938_3370_444E_AA42_698505DFF401__INCLUDED_)
#define AFX_MULTIPLYADDDLG_H__E2FF9938_3370_444E_AA42_698505DFF401__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiplyAddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMultiplyAddDlg dialog

class CMultiplyAddDlg : public CDialog
{
// Construction
public:
	CMultiplyAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiplyAddDlg)
	enum { IDD = IDD_MULTIPLY_ADD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiplyAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMultiplyAddDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIPLYADDDLG_H__E2FF9938_3370_444E_AA42_698505DFF401__INCLUDED_)
