#include "stdafx.h"
#include "B_TreeNode.h"

//构造函数
CB_TreeNode::CB_TreeNode(int vOrder)
{
	m_Order = vOrder;
	int tVal = 0;
	m_pParent = NULL;
	for (int i = 0; i < vOrder; i++)
	{
		m_B_TreeNodeKey.Add(tVal);
		m_B_TreeSonPointer.Add(NULL);

	}

}

CB_TreeNode::~CB_TreeNode()
{
}
//结点绘制函数
void CB_TreeNode::DrawB_TreeNode(CDC* pDC)
{
	CPoint tPoint;
	tPoint = m_Point;
	for (int i = 0; i<m_NumKeys; i++)
	{
		DrawB_TreeRectangle(tPoint, m_B_TreeNodeKey[i], i + 1, pDC);
		tPoint.x += m_Edge;
	}
}

//绘制指针
void CB_TreeNode::DrawB_TreeSon(CDC* pDC)
{
	CPoint tPoint;
	tPoint.x = m_Point.x;
	for (int i = 0; i < m_NumKeys; i++)
	{
		DrawB_TreeLine(tPoint, i, pDC);
		tPoint.x += m_Edge;
	}
}
//线段绘制函数
void CB_TreeNode::DrawB_TreeLine(CPoint vPoint, int vNum, CDC * pDC)
{
	CBrush tBrush;
	tBrush.CreateSolidBrush(RGB(0, 0, 0));
	CBrush *tPOldBrush = pDC->SelectObject(&tBrush);
	pDC->SelectObject(tPOldBrush);
	if (m_B_TreeSonPointer[0] = NULL)
	{
		pDC->MoveTo(vPoint.x, vPoint.y);
		pDC->LineTo(vPoint.x, vPoint.y);
		pDC->Rectangle(vPoint.x - 0.1*m_Edge, vPoint.y + m_Edge, vPoint.x + 0.1*m_Edge, vPoint.y + m_Edge + 0.2*m_Edge);
	}
	else
	{
		for (int i = 0; i <= m_NumKeys; i++)
		{
			if (i == vNum)
			{
				pDC->MoveTo(vPoint.x, vPoint.y);
				pDC->LineTo(
					m_B_TreeSonPointer[i]->m_Point.x
					+ m_B_TreeSonPointer[i]->m_NumKeys*m_Edge / 2,
					m_B_TreeSonPointer[i]->m_Point.y);
			}
		}
	}
}
//绘制矩形函数
void CB_TreeNode::DrawB_TreeRectangle(CPoint vPoint, int vB_TreeKey, int vNum, CDC* pDC)
{
	TEXTMETRIC tTxt;
	pDC->GetTextMetrics(&tTxt);
	CString tStr;
	tStr.Format(_T("%d"), vB_TreeKey);//修正  来源/*http://blog.sina.com.cn/s/blog_52e27e8a0100umki.html*/
	pDC->Rectangle(vPoint.x, vPoint.y, vPoint.x + m_Edge, vPoint.y + m_Edge);
	pDC->TextOut(vPoint.x - 10 + m_Edge / 2 - tTxt.tmAveCharWidth / 2,
		vPoint.y + m_Edge / 2 - tTxt.tmHeight / 2,
		tStr);
}
//显示位置设置函数
void CB_TreeNode::SetB_TreeNodePosition(CPoint vPoint, int vEdge)
{
	m_Point = vPoint;
	m_Edge = vEdge;
}
/*查询结果显示函数*/
void CB_TreeNode::DrawSearchB_TreeNode(int vIndex, int vB_TreeKey, CDC* pDC)
{
	CPen tPen;
	TEXTMETRIC tTxt;
	CString tStr;
	tPen.CreatePen(1, 2, RGB(255, 0, 0));
	CPen *ttPOldPen = pDC->SelectObject(&tPen);
	tStr.Format(_T("%d"), vB_TreeKey);
	int x = this->m_NumKeys;
	pDC->GetTextMetrics(&tTxt);
	pDC->Rectangle(m_Point.x + vIndex*m_Edge,
		m_Point.y, m_Point.x + (vIndex + 1)*m_Edge, m_Point.y + m_Edge);
	pDC->TextOut(m_Point.x
		+ vIndex* m_Edge - 10 + m_Edge / 2 - tTxt.tmAveCharWidth / 2,
		m_Point.y + m_Edge / 2 - tTxt.tmHeight / 2,
		tStr);
	pDC->SelectObject(ttPOldPen);
}
