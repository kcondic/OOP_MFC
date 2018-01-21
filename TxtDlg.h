#pragma once
#include "afxwin.h"


// CTxtDlg dialog

class CTxtDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTxtDlg)

public:
	CTxtDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTxtDlg();
	CString m_text;
	CString m_izborfonta;
	int m_izborvelicinefonta;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_txtedit;
	CComboBox m_izborfontaedit;
	CComboBox m_izborvelicinefontaedit;
	virtual void OnOK();
};
