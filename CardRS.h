#if !defined(AFX_CARDRS_H__CDDD11A4_9FF5_4A38_9D31_3BA9866909ED__INCLUDED_)
#define AFX_CARDRS_H__CDDD11A4_9FF5_4A38_9D31_3BA9866909ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCardRS recordset

class CCardRS : public CRecordset
{
public:
	CCardRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCardRS)

// Field/Param Data
	//{{AFX_FIELD(CCardRS, CRecordset)
	CString	m_cno;
	CString	m_name;
	CString	m_department;
	CString	m_type;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardRS)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDRS_H__CDDD11A4_9FF5_4A38_9D31_3BA9866909ED__INCLUDED_)
