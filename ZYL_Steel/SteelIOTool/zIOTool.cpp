#include "stdafx.h"
#include "zIOTool.h"
#include "LoadModelData.h"

#include <afxwin.h>        // MFC core and standard components
#include <afxext.h>        // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>        // MFC support for Internet Explorer 4 Common Controls

#include <afxcmn.h>

zIOTool::zIOTool()
{
}


zIOTool::~zIOTool()
{
}

void zIOTool::LoadData(ProjectServer *pPro, CString strFilePathName)
{
  LoadModelData loadData;
  loadData.mpPrj = pPro;
  std::string str = CT2CA(strFilePathName);
  loadData.setLoadPath(str);
  loadData.Load();
}

