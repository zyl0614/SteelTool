#include "stdafx.h"
#include "zTestLoadByVtk.h"
#include "zIOTool.h"
#include "ProjectServer.h"

#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <vtkConeSource.h>//Դ����
#include <vtkPointSource.h>//Դ����
#include <vtkLineSource.h>//Դ����
#include <vtkCubeSource.h>//������
#include <vtkPolyDataMapper.h>//����ӳ��
#include <vtkRenderer.h>//������
#include <vtkRenderWindow.h>//���ƴ���
#include <vtkCamera.h>//�����
#include <vtkRenderWindowInteractor.h>//���뽻��������


void drawline(std::vector<std::vector<double> > &pntsI, std::vector<std::vector<double> > &pntsJ)
{
  //���̨  ʵ������Ⱦ������renderer
  vtkRenderer* renderer = vtkRenderer::New();
  size_t n = pntsI.size();
  for (size_t i = 0; i < n; i++)
  {
    //ָ�봴��һ����
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
    lineMapper->SetInputConnection(vtkline->GetOutputPort());//Դ���������ӳ��������

    //����һ����Ա����lineActor
    vtkActor* lineActor = vtkActor::New();
    lineActor->SetMapper(lineMapper);//Ϊ��Աָ��mapper����ӳ��
    renderer->AddActor(lineActor);//����Ա���볡��
  }

  renderer->SetBackground(0.0, 0.0, 0.0);//���ó���������ɫΪ��ɫ(R,G,B)
  //�ڻ��ƴ���ָ���ӿڣ�Xmin,Ymin,Xmax,Ymax)(x,y��Χ��Ϊ0~1)
  //renderer->SetViewport(0.0, 0.0, 0.5, 0.5);//�ӿ�1

  //ʵ����һ�����ڶ���renWin
  vtkRenderWindow* renWin = vtkRenderWindow::New();
  renWin->SetSize(640, 480);//���ô��ڴ�С��*��
  renWin->AddRenderer(renderer);//������renderer����renWin������

  //ʵ����һ����������
  vtkRenderWindowInteractor* interactor = vtkRenderWindowInteractor::New();//�����������renWin������
  interactor->SetRenderWindow(renWin);

  renWin->Render();//������̨�ϵĶ���

  interactor->Initialize();//���������ʼ��
  interactor->Start();//��ʼ�����¼�

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
