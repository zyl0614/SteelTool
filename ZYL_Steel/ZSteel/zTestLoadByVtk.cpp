#include "stdafx.h"
#include "zTestLoadByVtk.h"
#include "zIOTool.h"
#include "ProjectServer.h"

#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <vtkConeSource.h>//源数据
#include <vtkPointSource.h>//源数据
#include <vtkLineSource.h>//源数据
#include <vtkCubeSource.h>//立方体
#include <vtkPolyDataMapper.h>//数据映射
#include <vtkRenderer.h>//绘制器
#include <vtkRenderWindow.h>//绘制窗口
#include <vtkCamera.h>//照相机
#include <vtkRenderWindowInteractor.h>//加入交互机制类


void drawline(std::vector<std::vector<double> > &pntsI, std::vector<std::vector<double> > &pntsJ)
{
  //搭建舞台  实例化渲染器对象renderer
  vtkRenderer* renderer = vtkRenderer::New();
  size_t n = pntsI.size();
  for (size_t i = 0; i < n; i++)
  {
    //指针创建一个点
    vtkLineSource* vtkline = vtkLineSource::New();
    float pntS[3];
    float pntE[3];
    pntS[0] = pntsI[i][0];
    pntS[1] = pntsI[i][1];
    pntS[2] = pntsI[i][2];
    pntE[0] = pntsJ[i][0];
    pntE[1] = pntsJ[i][1];
    pntE[2] = pntsJ[i][2];

    vtkline->SetPoint1(pntS);
    vtkline->SetPoint2(pntE);

    vtkPolyDataMapper* lineMapper = vtkPolyDataMapper::New();
    lineMapper->SetInputConnection(vtkline->GetOutputPort());//源数据输出给映射器输入

    //创建一个演员对象lineActor
    vtkActor* lineActor = vtkActor::New();
    lineActor->SetMapper(lineMapper);//为演员指定mapper进行映射
    renderer->AddActor(lineActor);//将演员加入场景
  }

  renderer->SetBackground(0.0, 0.0, 0.0);//设置场景背景颜色为红色(R,G,B)
  //在绘制窗口指定视口（Xmin,Ymin,Xmax,Ymax)(x,y范围都为0~1)
  //renderer->SetViewport(0.0, 0.0, 0.5, 0.5);//视口1

  //实例化一个窗口对象renWin
  vtkRenderWindow* renWin = vtkRenderWindow::New();
  renWin->SetSize(640, 480);//设置窗口大小宽*高
  renWin->AddRenderer(renderer);//将场景renderer加入renWin窗口中

  //实例化一个交互对象
  vtkRenderWindowInteractor* interactor = vtkRenderWindowInteractor::New();//交互对象加入renWin窗口中
  interactor->SetRenderWindow(renWin);

  renWin->Render();//绘制舞台上的东西

  interactor->Initialize();//交互对象初始化
  interactor->Start();//开始交互事件

  renderer->Delete();
  renWin->Delete();
  interactor->Delete();
}

zTestLoadByVtk::zTestLoadByVtk()
{
}


zTestLoadByVtk::~zTestLoadByVtk()
{
}

void zTestLoadByVtk::test(CString filePathName)
{
  ProjectServer *pPro = ProjectServer::getInctance();
  zIOTool::LoadData(pPro, filePathName);

  std::vector<std::vector<double> > pntsI;
  std::vector<std::vector<double> > pntsJ;
  
  for (auto i : pPro->beamSegs)
  {
    pntsI.push_back({ i.jointI.mPnt.mdX, i.jointI.mPnt.mdY, i.jointI.mPnt.mdZ });
    pntsJ.push_back({ i.jointJ.mPnt.mdX, i.jointJ.mPnt.mdY, i.jointJ.mPnt.mdZ });
  }
  for (auto i : pPro->colSegs)
  {
    pntsI.push_back({ i.jointI.mPnt.mdX, i.jointI.mPnt.mdY, i.jointI.mPnt.mdZ });
    pntsJ.push_back({ i.jointJ.mPnt.mdX, i.jointJ.mPnt.mdY, i.jointJ.mPnt.mdZ });
  }
  drawline(pntsI, pntsJ);

}
