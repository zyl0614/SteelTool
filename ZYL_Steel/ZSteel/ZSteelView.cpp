// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// ZSteelView.cpp : CZSteelView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZSteel.h"
#endif

#include "ZSteelDoc.h"
#include "ZSteelView.h"
#include "LoadProjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZSteelView

IMPLEMENT_DYNCREATE(CZSteelView, CView)

BEGIN_MESSAGE_MAP(CZSteelView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
  ON_COMMAND(ID_BUTTON_LOADPROJECT, &CZSteelView::OnButtonLoadproject)
END_MESSAGE_MAP()

// CZSteelView ����/����

CZSteelView::CZSteelView()
{
	// TODO:  �ڴ˴���ӹ������

}

CZSteelView::~CZSteelView()
{
}

BOOL CZSteelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZSteelView ����

void CZSteelView::OnDraw(CDC* /*pDC*/)
{
	CZSteelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CZSteelView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CZSteelView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CZSteelView ���

#ifdef _DEBUG
void CZSteelView::AssertValid() const
{
	CView::AssertValid();
}

void CZSteelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZSteelDoc* CZSteelView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZSteelDoc)));
	return (CZSteelDoc*)m_pDocument;
}
#endif //_DEBUG


// CZSteelView ��Ϣ�������


void CZSteelView::OnButtonLoadproject()
{
  // TODO:  �ڴ���������������

  LoadProjectDlg dlg;
  dlg.DoModal();

}
