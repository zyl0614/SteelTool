// LoadProjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ZSteel.h"
#include "LoadProjectDlg.h"
#include "afxdialogex.h"
#include "zTestLoadByVtk.h"




// LoadProjectDlg 对话框

IMPLEMENT_DYNAMIC(LoadProjectDlg, CDialog)

LoadProjectDlg::LoadProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LoadProjectDlg::IDD, pParent)
{

}

LoadProjectDlg::~LoadProjectDlg()
{
}

void LoadProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LoadProjectDlg, CDialog)
  ON_BN_CLICKED(IDOK, &LoadProjectDlg::OnBnClickedOk)
  ON_BN_CLICKED(IDC_BUTTON_AddYdb, &LoadProjectDlg::OnBnClickedButtonAddydb)
END_MESSAGE_MAP()


// LoadProjectDlg 消息处理程序


void LoadProjectDlg::OnBnClickedOk()
{
  zTestLoadByVtk::test(FilePathName);

  CDialog::OnOK();
}


void LoadProjectDlg::OnBnClickedButtonAddydb()
{
  CFileDialog filedlg(true); //显示打开对话框
  filedlg.m_ofn.lpstrTitle = L"打开"; 
  filedlg.m_ofn.lpstrFilter = L"*.ydb";//

  if (IDOK == filedlg.DoModal())
  {

    FilePathName = filedlg.GetPathName();
    UpdateData(FALSE);
  }

  SetDlgItemText(IDC_EDIT_AddYDB, FilePathName);
}
