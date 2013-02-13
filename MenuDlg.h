#if !defined(AFX_MENUDLG_H__3C8DBBD6_8C24_4627_9F6A_7D901240EE4C__INCLUDED_)
#define AFX_MENUDLG_H__3C8DBBD6_8C24_4627_9F6A_7D901240EE4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MenuDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMenuDlg dialog

class CMenuDlg : public CDialog
{
// Construction
public:
	CMenuDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMenuDlg)
	enum { IDD = IDD_MENU };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMenuDlg)
	afx_msg void OnSingleAdd();
	afx_msg void OnBasicQuery();
	afx_msg void OnAdvanced();
	afx_msg void OnBookBorrow();
	afx_msg void OnBookReturn();
	afx_msg void OnCardApply();
	afx_msg void OnCardDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUDLG_H__3C8DBBD6_8C24_4627_9F6A_7D901240EE4C__INCLUDED_)
