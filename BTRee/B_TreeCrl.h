#pragma once
#include "afxcmn.h"



// CB_TreeCrl 窗体视图

class CB_TreeCrl : public CFormView
{
	DECLARE_DYNCREATE(CB_TreeCrl)

protected:
	CB_TreeCrl();           // 动态创建所使用的受保护的构造函数
	virtual ~CB_TreeCrl();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_B_TREE_CONTROL };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_B_TreeNodeOrder;
	CString m_B_TreeNodeData;
	CSpinButtonCtrl m_OrderNumSpin;
};


