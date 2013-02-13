#if !defined(AFX_MAINMENU_H__40590D9C_60BD_482D_9B7F_846FAA6CF92E__INCLUDED_)
#define AFX_MAINMENU_H__40590D9C_60BD_482D_9B7F_846FAA6CF92E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainMenu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainMenu dialog

class CMainMenu : public CDialog
{
// Construction
public:
	CMainMenu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainMenu)
	enum { IDD = IDD_MENU };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainMenu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainMenu)
	afx_msg void OnAdvanced();
	afx_msg void OnBasicQuery();
	afx_msg void OnCardApply();
	afx_msg void OnCardDestroy();
	afx_msg void OnSingleAdd();
	afx_msg void OnBookBorrow();
	afx_msg void OnBookReturn();
	afx_msg void OnMultiplyAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINMENU_H__40590D9C_60BD_482D_9B7F_846FAA6CF92E__INCLUDED_)
