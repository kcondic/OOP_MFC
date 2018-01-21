// TxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Seminarski.h"
#include "TxtDlg.h"
#include "afxdialogex.h"
// CTxtDlg dialog

IMPLEMENT_DYNAMIC(CTxtDlg, CDialogEx)

CTxtDlg::CTxtDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
}

CTxtDlg::~CTxtDlg()
{
}

void CTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_txtedit);
	DDX_Control(pDX, IDC_COMBO1, m_izborfontaedit);
	DDX_Control(pDX, IDC_COMBO2, m_izborvelicinefontaedit);
	m_izborfontaedit.SetCurSel(1);
	m_izborvelicinefontaedit.SetCurSel(4);
}


BEGIN_MESSAGE_MAP(CTxtDlg, CDialogEx)
END_MESSAGE_MAP()


// CTxtDlg message handlers


void CTxtDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	CString privremena;

	m_txtedit.GetWindowText(m_text);
	m_izborfontaedit.GetWindowText(m_izborfonta);
	m_izborvelicinefontaedit.GetWindowText(privremena);
	m_izborvelicinefonta = _ttoi(privremena);

	CDialogEx::OnOK();
}
