#if !defined(AFX_BORROWBOOK_H__91472BE5_07D5_4982_A024_5E4BEFD7EEE3__INCLUDED_)
#define AFX_BORROWBOOK_H__91472BE5_07D5_4982_A024_5E4BEFD7EEE3__INCLUDED_

#include "BookRS.h"	// Added by ClassView
#include "BorrowRS.h"	// Added by ClassView
#include "CardRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowBook dialog

class CBorrowBook : public CDialog
{
// Construction
public:
	CBorrowBook(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBorrowBook)
	enum { IDD = IDD_BOOK_BORROW };
	CListCtrl	m_ctrList;
	CString	m_strBookNum;
	CString	m_strCardNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBorrowBook)
	virtual void OnOK();
	afx_msg void OnQuery();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCardRS m_cardSet;
	CBorrowRS m_borrowSet;
	CBookRS m_bookSet;
	bool BorrowBook(const CString &cardNum, const CString &bookNum);
	bool AnyBookExpired(const CString &cardNum);
	bool IsValidCard(const CString &cardNum);
	bool Nobook(const CString &bookNum);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWBOOK_H__91472BE5_07D5_4982_A024_5E4BEFD7EEE3__INCLUDED_)
