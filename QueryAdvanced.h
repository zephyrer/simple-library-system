#if !defined(AFX_QUERYADVANCED_H__B46596EF_2547_4321_A13C_A90EEBC88D38__INCLUDED_)
#define AFX_QUERYADVANCED_H__B46596EF_2547_4321_A13C_A90EEBC88D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryAdvanced.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryAdvanced dialog

class CQueryAdvanced : public CDialog
{
// Construction
public:
	CQueryAdvanced(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryAdvanced)
	enum { IDD = IDD_ADVANCED_QUERY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryAdvanced)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryAdvanced)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYADVANCED_H__B46596EF_2547_4321_A13C_A90EEBC88D38__INCLUDED_)
