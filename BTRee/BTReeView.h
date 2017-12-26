
// BTReeView.h : CBTReeView 类的接口
//

#pragma once


class CBTReeView : public CView
{
protected: // 仅从序列化创建
	CBTReeView();
	DECLARE_DYNCREATE(CBTReeView)

// 特性
public:
	CBTReeDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CBTReeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // BTReeView.cpp 中的调试版本
inline CBTReeDoc* CBTReeView::GetDocument() const
   { return reinterpret_cast<CBTReeDoc*>(m_pDocument); }
#endif

