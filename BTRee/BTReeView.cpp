
// BTReeView.cpp : CBTReeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CBTReeView 构造/析构

CBTReeView::CBTReeView()
{
	// TODO: 在此处添加构造代码

}

CBTReeView::~CBTReeView()
{
}

BOOL CBTReeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBTReeView 绘制

void CBTReeView::OnDraw(CDC* /*pDC*/)
{
	CBTReeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CBTReeView 诊断

#ifdef _DEBUG
void CBTReeView::AssertValid() const
{
	CView::AssertValid();
}

void CBTReeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBTReeDoc* CBTReeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBTReeDoc)));
	return (CBTReeDoc*)m_pDocument;
}
#endif //_DEBUG


// CBTReeView 消息处理程序
