#if !defined(AFX_RETURNBOOK_H__F6F00032_92C0_4098_A220_F4C22B6585DE__INCLUDED_)
#define AFX_RETURNBOOK_H__F6F00032_92C0_4098_A220_F4C22B6585DE__INCLUDED_

#include "BorrowRS.h"	// Added by ClassView
#include "CardRS.h"	// Added by ClassView
#include "BookRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReturnBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturnBook dialog

class CReturnBook : public CDialog
{
// Construction
public:
	CReturnBook(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReturnBook)
	enum { IDD = IDD_BOOK_RETURN };
	CListCtrl	m_ctrList;
	CString	m_strBookNum;
	CString	m_strCardNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturnBook)
	virtual void OnOK();
	afx_msg void OnQuery();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBookRS m_bookSet;
	CCardRS m_cardSet;
	CBorrowRS m_borrowSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNBOOK_H__F6F00032_92C0_4098_A220_F4C22B6585DE__INCLUDED_)
