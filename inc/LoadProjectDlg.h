#pragma once

// LoadProjectDlg �Ի���

class LoadProjectDlg : public CDialog
{
	DECLARE_DYNAMIC(LoadProjectDlg)

public:
	LoadProjectDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LoadProjectDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

public:
  CString FilePathName;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedButtonAddydb();
};
