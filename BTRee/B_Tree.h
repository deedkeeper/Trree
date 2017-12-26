#pragma once
#include"B_TreeNode.h"
class CB_Tree
{
public:
	CB_Tree();
	virtual ~CB_Tree();
	bool InsertB_TreeNode(CRect vWinRect,
		int vB_TNValue);//B树插入关键字函数
	bool InsertB_TreeNode(CB_TreeNode *vPB_TreeCurNode,
		int& vB_TNValue, int &vMedian,
		CB_TreeNode *&vPB_TreeNodeRight);//重载B-树插入关键字函数
	void InsertB_TreeNodeIn(CB_TreeNode * vPB_TreeCureNode,
		int& vB_TNValue, CB_TreeNode *vPBNodeRight,
		int vPos);//将关键字储存在结点中
	void DeleteB_TreeNode(CRect vWinRect,
		int vB_TNValue);//B-树删除关键字函数
	bool DeleteB_TreeNode(CB_TreeNode * vPB_TreeCurNode,
		int vB_TNValue);//重载B-树删除关键字函数
	void B_TreeNodeSplit(CB_TreeNode * vPB_TreeCurNode,
		int & vB_TNValValExtra, CB_TreeNode *vPB_TreeNodeExtra,
		int vPos, CB_TreeNode * &vPB_TreeNodeRightHalf,
		int &vMedian);
	void B_TreeNodeTraverse(CB_TreeNode * vPB_Tree,
		int &vMedian); //B-树结点的分裂函数
	void B_TreeNodeTraverse(CB_TreeNode * vPB_Tree,
		int &vNosonNodeNum, int &vLeafNoteNum); //B-树的遍历函数
	void FindSuccessor(CB_TreeNode * vPB_TreeCurNode,
		int vPos); //查找被删除的关键字的替代结点函数
	void DeleteB_TreeNodeKey(CB_TreeNode * vPB_TreeCurNode,
		int vPos);//删除结点的关键字的函数
	void B_TreeAdjustment(CB_TreeNode *vPB_TreeCurNode,
		int vPos);
	void B_TreeNodeMoveLeft(CB_TreeNode *vPB_TreeCurNode,
		int vPos);
	void B_TreeNodeMoveRight(CB_TreeNode *vPB_TreeCurNode,
		int vPos);
	void B_TreeNodeCombine(CB_TreeNode *vPB_TreeCurNode,
		int vPos);
	void SetB_TreeNodePositions();
	void SetB_TreeLeafNodePosition(CB_TreeNode * vPB_TreeRoot,
		int &vX, int vEdge);
	void SetB_TreeNonLeafNodePosition(CB_TreeNode * vPB_TreeNode,
		int vEdge, int vHeight);
	void SetB_TreeOrder(int vB_TreeOrder);
	void DrawB_Tree(CRect vWinRect, CDC *pDC);//绘制B-Tree函数
	void DrawB_Tree(CB_TreeNode * & vPB_TressNode,
		CDC * pDC);//重新绘制B-Trees函数
	void ClearB_Tree();//清空树
	void ClearB_Tree(CB_TreeNode * &vPB_TreeNode);//重载清空函数
	void  SetB_TreeSearchKey(int vB_TNKey);//设置B-树待查关键字函数
	void DrawSearchB_TreeNode(CDC * pDC);
	bool B_TreeNodeSearch(CB_TreeNode * vPB_TreeCurNode,
		int vKey, int &vPos);
	void SearchB_TreeNode(CB_TreeNode * vPB_TreeNode,
		CB_TreeNode * & vPBTreeSearchNode,
		int &vIndex, int vB_TNValue);//关键字的查找
private:
	CB_TreeNode * m_PB_TreeRoot; //B树的根节点
	int m_nKeyNum; //阶数
	CRect m_WinSize;//窗口大小
	int m_Edge;//B树的宽度
	int m_Height;//B树的高度
	int m_NoSonNodeNum;//B树的非叶子结点的数目
	int m_LeafNoteNum;//B-树的叶子结点的数目
	int m_Margin;//相同高度的B树显示的距离
	int m_Order;//B树的阶
	int m_SearchValue;//待查的数值
};

