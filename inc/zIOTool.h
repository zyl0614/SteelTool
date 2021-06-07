#pragma once
#include "Micro.h"
#include "ProjectServer.h"

#include <afxwin.h>          // MFC core and standard components
#include <afxext.h>          // MFC extensions
#include <afxdisp.h>         // MFC Automation classes
#include <afxdtctl.h>        // MFC support for Internet Explorer 4 Common Controls

#include <afxcmn.h>

class SteelIOTool_API zIOTool
{
public:
  zIOTool();
  virtual ~zIOTool();

  static void LoadData(ProjectServer *pPro, CString strFilePathName);

};

