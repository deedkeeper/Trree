#pragma once
#include"stdafx.h"
class CB_TreeNode :
	public CObject
{
public:
	CB_TreeNode(int vOrder);
	virtual ~CB_TreeNode();
	void SetB_TreeNodePosition(CPoint vPoint, int vEdge);//���ý����ʾ��λ��
	void DrawB_TreeLine(CPoint vPoint, int vNum, CDC* pDC);//�����߶�
	void DrawB_TreeSon(CDC* pDC);//���ƺ��ӽ��
	void DrawB_TreeRectangle(CPoint vPoint, int vB_TreeKey, int vNum, CDC* pDC);//���ƾ���
	void DrawB_TreeNode(CDC* pDC);
	void DrawSearchB_TreeNode(int vIndec, int vB_TreeKey, CDC* pDC);
public:
	CPoint m_Point;
	COLORREF M_Color;
	CArray<int, int&> m_B_TreeNodeKey;
	CTypedPtrArray<CObArray, CB_TreeNode*> m_B_TreeSonPointer; //B-Tree �������ָ������
	CB_TreeNode * m_pParent;
	int m_NumKeys;
	int m_Width;
	int m_Edge;
	int m_Order;
};

