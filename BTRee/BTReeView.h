
// BTReeView.h : CBTReeView ��Ľӿ�
//

#pragma once


class CBTReeView : public CView
{
protected: // �������л�����
	CBTReeView();
	DECLARE_DYNCREATE(CBTReeView)

// ����
public:
	CBTReeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CBTReeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // BTReeView.cpp �еĵ��԰汾
inline CBTReeDoc* CBTReeView::GetDocument() const
   { return reinterpret_cast<CBTReeDoc*>(m_pDocument); }
#endif

