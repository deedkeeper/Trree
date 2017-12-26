// B_TreeDraw.cpp : 实现文件
//

#include "stdafx.h"
#include "BTRee.h"
#include "B_TreeDraw.h"


// CB_TreeDraw

IMPLEMENT_DYNCREATE(CB_TreeDraw, CFormView)

CB_TreeDraw::CB_TreeDraw()
	: CFormView(IDD_B_TREE_DRAW)
{

}

CB_TreeDraw::~CB_TreeDraw()
{
}

void CB_TreeDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CB_TreeDraw, CFormView)
END_MESSAGE_MAP()


// CB_TreeDraw 诊断

#ifdef _DEBUG
void CB_TreeDraw::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CB_TreeDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CB_TreeDraw 消息处理程序
