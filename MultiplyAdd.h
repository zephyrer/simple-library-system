#if !defined(AFX_MULTIPLYADD_H__6E510D7B_EBD3_47CD_8963_598B8699E573__INCLUDED_)
#define AFX_MULTIPLYADD_H__6E510D7B_EBD3_47CD_8963_598B8699E573__INCLUDED_

#include "BookRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiplyAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMultiplyAdd dialog

class CMultiplyAdd : public CDialog
{
// Construction
public:
	CMultiplyAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiplyAdd)
	enum { IDD = IDD_MULTIPLY_ADD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiplyAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMultiplyAdd)
	virtual void OnOK();
//	afx_msg void OnMultiplyAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBookRS m_bookSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIPLYADD_H__6E510D7B_EBD3_47CD_8963_598B8699E573__INCLUDED_)
