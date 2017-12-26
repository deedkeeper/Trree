#include "stdafx.h"
#include "B_Tree.h"



//对其初值进行设置
CB_Tree::CB_Tree()
{
	m_PB_TreeRoot = NULL;
	m_nKeyNum = 3;
	m_Height = 0;
	m_NoSonNodeNum = 0;
	m_LeafNoteNum = 0;
	m_Order = 3;
}


CB_Tree::~CB_Tree()
{
}

bool CB_Tree::InsertB_TreeNode(CRect vWinRect, int vB_TNValue)
{
	m_WinSize = vWinRect;
	int tCurNodeval;
	bool tStatus;
	CB_TreeNode * tPB_TreeNodeRight, *tNewB_TreeNodeRoot;
	tStatus = InsertB_TreeNode(m_PB_TreeRoot, vB_TNValue,
		tCurNodeval, tPB_TreeNodeRight);
	if (tStatus == false)
	{
		tNewB_TreeNodeRoot = new CB_TreeNode(m_Order);
		tNewB_TreeNodeRoot->m_NumKeys = 1;
		tNewB_TreeNodeRoot->m_B_TreeNodeKey[0] = tCurNodeval;
		tNewB_TreeNodeRoot->m_B_TreeSonPointer[0] = m_PB_TreeRoot;
		tNewB_TreeNodeRoot->m_B_TreeSonPointer[1] = tPB_TreeNodeRight;
		tStatus = true;
	}
	return tStatus;
}

bool CB_Tree::InsertB_TreeNode(CB_TreeNode * vPB_TreeCurNode, int & vB_TNValue, int & vMedian, CB_TreeNode *& vPB_TreeNodeRight)
{
	bool tStatus;
	int tPos;
	if (vPB_TreeCurNode == NULL)
	{
		vMedian = vB_TNValue;
		vPB_TreeNodeRight = NULL;
		tStatus = false;
	}
	else
	{
		if (B_TreeNodeSearch(vPB_TreeCurNode, vB_TNValue, tPos) == true)
			tStatus = true;
		else
		{
			int tCurNodeValExtra;
			CB_TreeNode *tPB_TreeCurNodeExtra;
			tStatus = InsertB_TreeNode(
				vPB_TreeCurNode->m_B_TreeSonPointer[tPos],
				vB_TNValue,
				tCurNodeValExtra,
				tPB_TreeCurNodeExtra
			);
			if (tStatus == false)
			{
				if (vPB_TreeCurNode->m_NumKeys < m_Order - 1)
				{
					tStatus = true;
					InsertB_TreeNodeIn(
						vPB_TreeCurNode,
						tCurNodeValExtra,
						tPB_TreeCurNodeExtra,
						tPos
					);
				}
				else
					B_TreeNodeSplit(
						vPB_TreeCurNode,
						tCurNodeValExtra,
						tPB_TreeCurNodeExtra,
						tPos, vPB_TreeNodeRight,
						vMedian
					);
			}
		}

	}
	return tStatus;
}

void CB_Tree::InsertB_TreeNodeIn(CB_TreeNode * vPB_TreeCureNode, int & vB_TNValue, CB_TreeNode * vPBNodeRight, int vPos)
{
	for (int i = vPB_TreeCureNode->m_NumKeys; i > vPos; i--)
	{
		vPB_TreeCureNode->m_B_TreeNodeKey[i] =
			vPB_TreeCureNode->m_B_TreeNodeKey[i - 1];
		vPB_TreeCureNode->m_B_TreeSonPointer[i + 1] =
			vPB_TreeCureNode->m_B_TreeSonPointer[i];
	}
	vPB_TreeCureNode->m_B_TreeNodeKey[vPos] = vB_TNValue;
	vPB_TreeCureNode->m_B_TreeSonPointer[vPos + 1] = vPBNodeRight;
	vPB_TreeCureNode->m_NumKeys++;
}



void CB_Tree::DeleteB_TreeNode(CRect vWinRect, int vB_TNValue)
{
	m_WinSize = vWinRect;
	DeleteB_TreeNode(m_PB_TreeRoot, vB_TNValue);
	if (m_PB_TreeRoot != NULL&&m_PB_TreeRoot->m_NumKeys == 0)
	{
		CB_TreeNode * tPoldB_TreeNode = m_PB_TreeRoot;
		m_PB_TreeRoot = m_PB_TreeRoot->m_B_TreeSonPointer[0];
		delete tPoldB_TreeNode;

	}

}
bool CB_Tree::DeleteB_TreeNode(CB_TreeNode * vPB_TreeCurNode, int vB_TNValue)
{
	bool tStatus;
	int tPos;
	if (vPB_TreeCurNode == NULL) tStatus = false;
	else
	{
		if (B_TreeNodeSearch(vPB_TreeCurNode,
			vB_TNValue, tPos) == true)
		{
			tStatus = true;
			if (vPB_TreeCurNode->m_B_TreeSonPointer[tPos] != NULL)
			{
				FindSuccessor(vPB_TreeCurNode->
					m_B_TreeSonPointer[tPos],
					vPB_TreeCurNode->m_B_TreeNodeKey[tPos]);
			}
			else DeleteB_TreeNodeKey(vPB_TreeCurNode, tPos);

		}
		else  tStatus = DeleteB_TreeNode(
			vPB_TreeCurNode->m_B_TreeSonPointer[tPos], vB_TNValue);
		if (vPB_TreeCurNode->m_B_TreeSonPointer[tPos] != NULL)
			if (vPB_TreeCurNode->
				m_B_TreeSonPointer[tPos]->m_NumKeys < (m_Order - 1) / 2)
				B_TreeAdjustment(vPB_TreeCurNode, tPos);
	}
	return tStatus;
}

void CB_Tree::B_TreeNodeSplit(CB_TreeNode * vPB_TreeCurNode, int & vB_TNValValExtra, CB_TreeNode * vPB_TreeNodeExtra, int vPos, CB_TreeNode *& vPB_TreeNodeRightHalf, int & vMedian)
{
	vPB_TreeNodeRightHalf = new CB_TreeNode(m_Order);
	int tMiddle = this->m_Order / 2;
	if (vPos <= tMiddle)
	{
		for (int i = tMiddle; i<m_Order - 1; i++)
		{
			vPB_TreeNodeRightHalf->m_B_TreeNodeKey[i - tMiddle] =
				vPB_TreeCurNode->m_B_TreeNodeKey[i];
			vPB_TreeNodeRightHalf->m_B_TreeSonPointer[i + 1 - tMiddle] =
				vPB_TreeCurNode->m_B_TreeSonPointer[i + 1];
		}
		vPB_TreeCurNode->m_NumKeys = tMiddle;
		vPB_TreeNodeRightHalf->m_NumKeys = m_Order - 1 - tMiddle;
		InsertB_TreeNodeIn(vPB_TreeCurNode,
			vB_TNValValExtra, vPB_TreeNodeExtra, vPos);
	}
	else
	{
		tMiddle++;
		for (int i = 0; i<m_Order - 1; i++)
		{
			vPB_TreeNodeRightHalf->m_B_TreeNodeKey[i - tMiddle] =
				vPB_TreeCurNode->m_B_TreeNodeKey[i];
			vPB_TreeNodeRightHalf->m_B_TreeSonPointer[i + 1 - tMiddle] =
				vPB_TreeCurNode->m_B_TreeSonPointer[i + 1];
		}
		vPB_TreeCurNode->m_NumKeys = tMiddle;
		vPB_TreeNodeRightHalf->m_NumKeys = m_Order - 1 - tMiddle;

		InsertB_TreeNodeIn(vPB_TreeNodeRightHalf,
			vB_TNValValExtra, vPB_TreeNodeExtra, vPos - tMiddle);
	}
	vMedian = vPB_TreeCurNode->
		m_B_TreeNodeKey[vPB_TreeCurNode->m_NumKeys - 1];
	vPB_TreeNodeRightHalf->m_B_TreeSonPointer[0] =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPB_TreeCurNode->
		m_NumKeys];
	vPB_TreeCurNode->m_NumKeys--;
}
//B树节点遍历函数
void CB_Tree::B_TreeNodeTraverse(CB_TreeNode * vPB_Tree, int &vNoSonNodeNum,
	int &vLeafNoteNum)
{
	if (vPB_Tree == NULL)
	{
		vNoSonNodeNum++;
		return;
	}
	else if (vPB_Tree->m_B_TreeSonPointer[0] == NULL)
		vLeafNoteNum++;
	for (int i = 0; i <= vPB_Tree->m_NumKeys; i++)
		B_TreeNodeTraverse(vPB_Tree->m_B_TreeSonPointer[i],
			vNoSonNodeNum, vLeafNoteNum);
}
//寻找被删除的节点的替代节点的功能
void CB_Tree::FindSuccessor(CB_TreeNode * vPB_TreeCurNode, int vPos)
{
	CB_TreeNode * tPB_TreeLeafNode =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos];
	while (tPB_TreeLeafNode->
		m_B_TreeSonPointer[tPB_TreeLeafNode->m_NumKeys] != NULL)
		tPB_TreeLeafNode =
		tPB_TreeLeafNode->
		m_B_TreeSonPointer[tPB_TreeLeafNode->m_NumKeys];
	vPB_TreeCurNode->m_B_TreeNodeKey[vPos] =
		tPB_TreeLeafNode->
		m_B_TreeNodeKey[tPB_TreeLeafNode->m_NumKeys - 1];
}



void CB_Tree::DeleteB_TreeNodeKey(CB_TreeNode * vPB_TreeCurNode, int vPos)
{
	for (int i = vPos; i <vPB_TreeCurNode->m_NumKeys - 1; i++)
	{
		vPB_TreeCurNode->m_B_TreeNodeKey[i] =
			vPB_TreeCurNode->m_B_TreeNodeKey[i + 1];
		vPB_TreeCurNode->m_NumKeys--;
	}
}
//删除节点中的关键字 再进行调整
void CB_Tree::B_TreeAdjustment(CB_TreeNode * vPB_TreeCurNode, int vPos)
{
	if (vPos == vPB_TreeCurNode->m_NumKeys)
		if (vPB_TreeCurNode->m_B_TreeSonPointer[vPos - 1]->
			m_NumKeys > (m_Order) / 2)
			B_TreeNodeMoveRight(vPB_TreeCurNode, vPos - 1);
		else
			B_TreeNodeCombine(vPB_TreeCurNode, vPos);
	else if (vPos == 0)
		if (vPB_TreeCurNode->m_B_TreeSonPointer[1]->
			m_NumKeys > (m_Order - 1) / 2)
			B_TreeNodeMoveLeft(vPB_TreeCurNode, 1);
		else
			B_TreeNodeCombine(vPB_TreeCurNode, 1);
	else if (vPB_TreeCurNode->m_B_TreeSonPointer[vPos - 1]->
		m_NumKeys > (m_Order) / 2)
		B_TreeNodeMoveRight(vPB_TreeCurNode, vPos - 1);
	else if (vPB_TreeCurNode->m_B_TreeSonPointer[vPos + 1]->m_NumKeys > (m_Order) / 2)
		B_TreeNodeMoveLeft(vPB_TreeCurNode, vPos);
	else B_TreeNodeCombine(vPB_TreeCurNode, vPos);
}
//将关键字调整到做下兄弟中
void CB_Tree::B_TreeNodeMoveLeft(CB_TreeNode * vPB_TreeCurNode, int vPos)
{
	CB_TreeNode *tPB_TreeCurKeyLeftBranch =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos - 1],
		*tPB_TreeCurKeyRightBranch =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos];
	tPB_TreeCurKeyLeftBranch->
		m_B_TreeNodeKey[tPB_TreeCurKeyLeftBranch->m_NumKeys] =
		vPB_TreeCurNode->m_B_TreeNodeKey[vPos - 1];
	tPB_TreeCurKeyLeftBranch->
		m_B_TreeSonPointer[++tPB_TreeCurKeyLeftBranch->m_NumKeys] =
		tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[0];
	vPB_TreeCurNode->m_B_TreeNodeKey[vPos - 1] =
		tPB_TreeCurKeyRightBranch->m_B_TreeNodeKey[0];
	tPB_TreeCurKeyRightBranch->m_NumKeys--;
	for (int i = 0; i < tPB_TreeCurKeyRightBranch->m_NumKeys; i++) {
		tPB_TreeCurKeyRightBranch->m_B_TreeNodeKey[i] =
			tPB_TreeCurKeyRightBranch->m_B_TreeNodeKey[i + 1];
		tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[i] =
			tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[i + 1];
	}
	tPB_TreeCurKeyRightBranch->
		m_B_TreeSonPointer[tPB_TreeCurKeyRightBranch->m_NumKeys] =
		tPB_TreeCurKeyRightBranch->
		m_B_TreeSonPointer[tPB_TreeCurKeyRightBranch->m_NumKeys + 1];
}
//关键字调整到右兄弟
void CB_Tree::B_TreeNodeMoveRight(CB_TreeNode * vPB_TreeCurNode, int vPos)
{
	CB_TreeNode *tPB_TreeCurKeyLeftBranch =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos],
		*tPB_TreeCurKeyRightBranch =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos + 1];
	tPB_TreeCurKeyRightBranch->
		m_B_TreeSonPointer[tPB_TreeCurKeyRightBranch->m_NumKeys + 1] =
		tPB_TreeCurKeyRightBranch->
		m_B_TreeSonPointer[tPB_TreeCurKeyRightBranch->m_NumKeys];
	for (int i = tPB_TreeCurKeyLeftBranch->m_NumKeys; i > 0; i--) {
		tPB_TreeCurKeyRightBranch->m_B_TreeNodeKey[i] =
			tPB_TreeCurKeyRightBranch->m_B_TreeNodeKey[i - 1];
		tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[i] =
			tPB_TreeCurKeyLeftBranch->m_B_TreeSonPointer[i - 1];
	}
	tPB_TreeCurKeyRightBranch->m_NumKeys++;
	tPB_TreeCurKeyRightBranch->m_B_TreeNodeKey[0] =
		vPB_TreeCurNode->m_B_TreeNodeKey[vPos];
	tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[0] =
		tPB_TreeCurKeyLeftBranch->
		m_B_TreeSonPointer[tPB_TreeCurKeyLeftBranch->m_NumKeys--];
	vPB_TreeCurNode->m_B_TreeNodeKey[vPos] =
		tPB_TreeCurKeyLeftBranch->
		m_B_TreeNodeKey[tPB_TreeCurKeyLeftBranch->m_NumKeys];
}

//结点合并

void CB_Tree::B_TreeNodeCombine(CB_TreeNode * vPB_TreeCurNode, int vPos)
{
	int i;
	CB_TreeNode * tPB_TreeCurKeyLeftBranch =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos - 1],
		*tPB_TreeCurKeyRightBranch =
		vPB_TreeCurNode->m_B_TreeSonPointer[vPos];
	tPB_TreeCurKeyLeftBranch->
		m_B_TreeNodeKey[tPB_TreeCurKeyLeftBranch->m_NumKeys] =
		vPB_TreeCurNode->m_B_TreeNodeKey[vPos - 1];
	tPB_TreeCurKeyLeftBranch->
		m_B_TreeSonPointer[++tPB_TreeCurKeyLeftBranch->m_NumKeys] =
		tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[0];
	for (i = 0; i < tPB_TreeCurKeyRightBranch->m_NumKeys; i++) {
		tPB_TreeCurKeyLeftBranch->
			m_B_TreeNodeKey[tPB_TreeCurKeyLeftBranch->m_NumKeys] =
			tPB_TreeCurKeyLeftBranch->m_B_TreeNodeKey[i];
		tPB_TreeCurKeyLeftBranch->
			m_B_TreeSonPointer[++tPB_TreeCurKeyLeftBranch->
			m_NumKeys] =
			tPB_TreeCurKeyRightBranch->m_B_TreeSonPointer[i + 1];
	}
	vPB_TreeCurNode->m_NumKeys--;
	for (i = vPos - 1; i < vPB_TreeCurNode->m_NumKeys; i++) {
		vPB_TreeCurNode->m_B_TreeNodeKey[i] =
			vPB_TreeCurNode->m_B_TreeNodeKey[i + 1];
		vPB_TreeCurNode->m_B_TreeSonPointer[i + 1] =
			vPB_TreeCurNode->m_B_TreeSonPointer[i + 2];
	}
	delete tPB_TreeCurKeyRightBranch;
}
//设置B树结点显示的位置
void CB_Tree::SetB_TreeNodePositions()
{
	CB_TreeNode * tPCurB_TreeNode = m_PB_TreeRoot;
	for (; tPCurB_TreeNode != NULL; m_Height++)
		tPCurB_TreeNode = tPCurB_TreeNode->
		m_B_TreeSonPointer[0];
	B_TreeNodeTraverse(m_PB_TreeRoot,
		m_NoSonNodeNum, m_LeafNoteNum);
	m_Margin = m_Edge = m_WinSize.Width()
		/ (m_LeafNoteNum + m_NoSonNodeNum + 1);
	if (m_Edge > 50)
	{
		m_Edge = 50;
		m_Margin = (m_WinSize.Width()
			- (m_NoSonNodeNum + m_LeafNoteNum - 1)*m_Edge) / 2;
	}
	int tX = m_Margin + m_Edge / 2;
	SetB_TreeLeafNodePosition(m_PB_TreeRoot, tX, m_Edge);
	for (int tHeight = m_Height - 1; tHeight != 0; tHeight--)
		SetB_TreeLeafNodePosition(m_PB_TreeRoot, m_Edge, tHeight);
	m_Height = 0;
	m_LeafNoteNum = 0;
	m_NoSonNodeNum = 0;
}
//设置叶子结点的显示位置
void CB_Tree::SetB_TreeLeafNodePosition(CB_TreeNode * vPB_TreeRoot, int & vX, int vEdge)
{
	CPoint tPoint;
	if (vPB_TreeRoot == NULL)
		return;
	else if (vPB_TreeRoot->m_B_TreeSonPointer[0] == NULL)
	{
		tPoint.x = vX;
		tPoint.y = 10 + (m_Height - 1) * 3 * m_Edge;
		vPB_TreeRoot->SetB_TreeNodePosition(tPoint, vEdge);
		vX - (vPB_TreeRoot->m_NumKeys + 2)*m_Edge;
	}
	for (int i = 0; i <= vPB_TreeRoot->m_NumKeys; i++)
		SetB_TreeLeafNodePosition(vPB_TreeRoot->
			m_B_TreeSonPointer[i], vX, vEdge);
}
//设置非叶子结点的显示位置
void CB_Tree::SetB_TreeNonLeafNodePosition(CB_TreeNode * vPB_TreeNode, int vEdge, int vHeight)
{
	CB_TreeNode * tPCureB_TreeNode =
		vPB_TreeNode->m_B_TreeSonPointer[0];
	for (int i = 0; i < m_Height - vHeight; i++)
		tPCureB_TreeNode = tPCureB_TreeNode->m_B_TreeSonPointer[0];
	if (tPCureB_TreeNode == NULL)
	{
		CPoint tPoint;
		tPoint.x = (vPB_TreeNode->m_B_TreeSonPointer[0]->m_Point.x
			+ vPB_TreeNode->
			m_B_TreeSonPointer[vPB_TreeNode->m_NumKeys]->
			m_NumKeys * m_Edge) / 2
			- vPB_TreeNode->m_NumKeys*m_Edge / 2;
		tPoint.y = 50 + 3 * (vHeight - 1)*m_Edge;
		vPB_TreeNode->SetB_TreeNodePosition(tPoint, vEdge);
		return;
	}
	for (int i = 0; i<vPB_TreeNode->m_NumKeys; i++)
		SetB_TreeLeafNodePosition(vPB_TreeNode->m_B_TreeSonPointer[i], vEdge, vHeight);

}
//设置B树的阶
void CB_Tree::SetB_TreeOrder(int vB_TreeOrder)
{
	if (m_PB_TreeRoot != NULL)
	{
		if (m_Order != vB_TreeOrder) {
			ClearB_Tree(m_PB_TreeRoot);
		}
	}
	CB_TreeNode * vPB_Tree = m_PB_TreeRoot;
	m_Order = vB_TreeOrder;
}
//设置B树待查关键字
void CB_Tree::SetB_TreeSearchKey(int vB_TNKey)
{
	m_SearchValue = vB_TNKey;
}
//实现B树结点内的关键字查找功能
bool CB_Tree::B_TreeNodeSearch(CB_TreeNode * vPB_TreeCurNode, int vKey, int & vPos)
{
	vPos = 0;
	while (vPos<vPB_TreeCurNode->m_NumKeys
		&&vKey>vPB_TreeCurNode->m_B_TreeNodeKey[vPos])
		vPos++;
	if (vPos < vPB_TreeCurNode->m_NumKeys
		&& vKey == vPB_TreeCurNode->m_B_TreeNodeKey[vPos])
		return true;
	else
		return false;
}
//实现B树的关键字的查找功能
void CB_Tree::SearchB_TreeNode(CB_TreeNode * vPB_TreeNode, CB_TreeNode *& vPBTreeSearchNode, int & vIndex, int vB_TNValue)
{
	if (vPBTreeSearchNode == NULL)
		return;
	int y = vPBTreeSearchNode->m_NumKeys;
	for (int i = 0; i < vPBTreeSearchNode->m_NumKeys; i++)
	{
		int x = vPBTreeSearchNode->m_B_TreeNodeKey[i];
		if (vB_TNValue == vPBTreeSearchNode->m_B_TreeNodeKey[i])
		{
			vPBTreeSearchNode == vPB_TreeNode;
			vIndex = i;
			return;
		}
		SearchB_TreeNode(vPB_TreeNode->m_B_TreeSonPointer[i],
			vPBTreeSearchNode, vIndex, vB_TNValue);
	}

}
//清空B树
void CB_Tree::ClearB_Tree()
{
	ClearB_Tree(m_PB_TreeRoot);
}
//重载B树清空函数
void CB_Tree::ClearB_Tree(CB_TreeNode *& vPB_TreeNode)
{
	if (vPB_TreeNode != NULL)
	{
		for (int i = 0; i <= vPB_TreeNode->m_NumKeys; i++)
		{
			ClearB_Tree(vPB_TreeNode->
				m_B_TreeSonPointer[i]);
		}
		delete vPB_TreeNode;
		vPB_TreeNode = NULL;
	}
}

//实现B树的绘制功能
void CB_Tree::DrawB_Tree(CRect vWinRect, CDC * pDC)
{
	m_WinSize = vWinRect;
	if (m_PB_TreeRoot) {
		SetB_TreeNodePositions();
		DrawB_Tree(m_PB_TreeRoot, pDC);
	}
}

void CB_Tree::DrawB_Tree(CB_TreeNode *& vPB_TreeNode, CDC * pDC)
{
	if (vPB_TreeNode)
	{
		vPB_TreeNode->DrawB_TreeNode(pDC);
		vPB_TreeNode->DrawB_TreeNode(pDC);
		for (int i = 0; i <= vPB_TreeNode->m_NumKeys; i++)
			DrawB_Tree(vPB_TreeNode->m_B_TreeSonPointer[i], pDC);
	}
}



//绘制B树的查找结点功能
void CB_Tree::DrawSearchB_TreeNode(CDC * pDC)
{
	int tIndex = 0;
	CString tStr;
	TEXTMETRIC tTxt;
	pDC->GetTextMetrics(&tTxt);
	tStr.Format(_T("%d"), m_SearchValue);//修正 
	CB_TreeNode * tPB_TreeCurNode;
	SearchB_TreeNode(m_PB_TreeRoot,
		tPB_TreeCurNode, tIndex, m_SearchValue);
	if (tPB_TreeCurNode != NULL)
	{
		tPB_TreeCurNode->
			DrawSearchB_TreeNode(tIndex, m_SearchValue, pDC);
	}
}


