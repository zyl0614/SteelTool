#pragma once

// LoadProjectDlg 对话框

class LoadProjectDlg : public CDialog
{
	DECLARE_DYNAMIC(LoadProjectDlg)

public:
	LoadProjectDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LoadProjectDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

public:
  CString FilePathName;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedButtonAddydb();
};
