
// BTReeView.cpp : CBTReeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "BTRee.h"
#endif

#include "BTReeDoc.h"
#include "BTReeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBTReeView

IMPLEMENT_DYNCREATE(CBTReeView, CView)

BEGIN_MESSAGE_MAP(CBTReeView, CView)
END_MESSAGE_MAP()

// CBTReeView ����/����

CBTReeView::CBTReeView()
{
	// TODO: �ڴ˴���ӹ������

}

CBTReeView::~CBTReeView()
{
}

BOOL CBTReeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CBTReeView ����

void CBTReeView::OnDraw(CDC* /*pDC*/)
{
	CBTReeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CBTReeView ���

#ifdef _DEBUG
void CBTReeView::AssertValid() const
{
	CView::AssertValid();
}

void CBTReeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBTReeDoc* CBTReeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBTReeDoc)));
	return (CBTReeDoc*)m_pDocument;
}
#endif //_DEBUG


// CBTReeView ��Ϣ�������
