// B_TreeCrl.cpp : 实现文件
//

#include "stdafx.h"
#include "BTRee.h"
#include "B_TreeCrl.h"


// CB_TreeCrl

IMPLEMENT_DYNCREATE(CB_TreeCrl, CFormView)

CB_TreeCrl::CB_TreeCrl()
	: CFormView(IDD_B_TREE_CONTROL)
	, m_B_TreeNodeOrder(0)
	, m_B_TreeNodeData(_T(""))
{

}

CB_TreeCrl::~CB_TreeCrl()
{
}

void CB_TreeCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_B_TREE_ORDER, m_B_TreeNodeOrder);
	DDX_Text(pDX, IDC_EDIT_B_TREE_DATA, m_B_TreeNodeData);
	DDX_Control(pDX, IDC_SPIN_B_TREE, m_OrderNumSpin);
}

BEGIN_MESSAGE_MAP(CB_TreeCrl, CFormView)
END_MESSAGE_MAP()


// CB_TreeCrl 诊断

#ifdef _DEBUG
void CB_TreeCrl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CB_TreeCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CB_TreeCrl 消息处理程序
