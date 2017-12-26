#pragma once
#include"B_TreeNode.h"
class CB_Tree
{
public:
	CB_Tree();
	virtual ~CB_Tree();
	bool InsertB_TreeNode(CRect vWinRect,
		int vB_TNValue);//B������ؼ��ֺ���
	bool InsertB_TreeNode(CB_TreeNode *vPB_TreeCurNode,
		int& vB_TNValue, int &vMedian,
		CB_TreeNode *&vPB_TreeNodeRight);//����B-������ؼ��ֺ���
	void InsertB_TreeNodeIn(CB_TreeNode * vPB_TreeCureNode,
		int& vB_TNValue, CB_TreeNode *vPBNodeRight,
		int vPos);//���ؼ��ִ����ڽ����
	void DeleteB_TreeNode(CRect vWinRect,
		int vB_TNValue);//B-��ɾ���ؼ��ֺ���
	bool DeleteB_TreeNode(CB_TreeNode * vPB_TreeCurNode,
		int vB_TNValue);//����B-��ɾ���ؼ��ֺ���
	void B_TreeNodeSplit(CB_TreeNode * vPB_TreeCurNode,
		int & vB_TNValValExtra, CB_TreeNode *vPB_TreeNodeExtra,
		int vPos, CB_TreeNode * &vPB_TreeNodeRightHalf,
		int &vMedian);
	void B_TreeNodeTraverse(CB_TreeNode * vPB_Tree,
		int &vMedian); //B-�����ķ��Ѻ���
	void B_TreeNodeTraverse(CB_TreeNode * vPB_Tree,
		int &vNosonNodeNum, int &vLeafNoteNum); //B-���ı�������
	void FindSuccessor(CB_TreeNode * vPB_TreeCurNode,
		int vPos); //���ұ�ɾ���Ĺؼ��ֵ������㺯��
	void DeleteB_TreeNodeKey(CB_TreeNode * vPB_TreeCurNode,
		int vPos);//ɾ�����Ĺؼ��ֵĺ���
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
	void DrawB_Tree(CRect vWinRect, CDC *pDC);//����B-Tree����
	void DrawB_Tree(CB_TreeNode * & vPB_TressNode,
		CDC * pDC);//���»���B-Trees����
	void ClearB_Tree();//�����
	void ClearB_Tree(CB_TreeNode * &vPB_TreeNode);//������պ���
	void  SetB_TreeSearchKey(int vB_TNKey);//����B-������ؼ��ֺ���
	void DrawSearchB_TreeNode(CDC * pDC);
	bool B_TreeNodeSearch(CB_TreeNode * vPB_TreeCurNode,
		int vKey, int &vPos);
	void SearchB_TreeNode(CB_TreeNode * vPB_TreeNode,
		CB_TreeNode * & vPBTreeSearchNode,
		int &vIndex, int vB_TNValue);//�ؼ��ֵĲ���
private:
	CB_TreeNode * m_PB_TreeRoot; //B���ĸ��ڵ�
	int m_nKeyNum; //����
	CRect m_WinSize;//���ڴ�С
	int m_Edge;//B���Ŀ��
	int m_Height;//B���ĸ߶�
	int m_NoSonNodeNum;//B���ķ�Ҷ�ӽ�����Ŀ
	int m_LeafNoteNum;//B-����Ҷ�ӽ�����Ŀ
	int m_Margin;//��ͬ�߶ȵ�B����ʾ�ľ���
	int m_Order;//B���Ľ�
	int m_SearchValue;//�������ֵ
};

