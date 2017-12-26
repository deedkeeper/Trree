#pragma once
#include"stdafx.h"
class CB_TreeNode :
	public CObject
{
public:
	CB_TreeNode(int vOrder);
	virtual ~CB_TreeNode();
	void SetB_TreeNodePosition(CPoint vPoint, int vEdge);//设置结点显示的位置
	void DrawB_TreeLine(CPoint vPoint, int vNum, CDC* pDC);//绘制线段
	void DrawB_TreeSon(CDC* pDC);//绘制孩子结点
	void DrawB_TreeRectangle(CPoint vPoint, int vB_TreeKey, int vNum, CDC* pDC);//绘制矩形
	void DrawB_TreeNode(CDC* pDC);
	void DrawSearchB_TreeNode(int vIndec, int vB_TreeKey, CDC* pDC);
public:
	CPoint m_Point;
	COLORREF M_Color;
	CArray<int, int&> m_B_TreeNodeKey;
	CTypedPtrArray<CObArray, CB_TreeNode*> m_B_TreeSonPointer; //B-Tree 结点字树指针序列
	CB_TreeNode * m_pParent;
	int m_NumKeys;
	int m_Width;
	int m_Edge;
	int m_Order;
};

