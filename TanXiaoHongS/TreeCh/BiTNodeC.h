//#pragma once
//class BiTNodeC {
//public:
//
//	BiTNodeC() {}
//
//	virtual ~BiTNodeC() {}
//};

//template <typename TElemType>
//typedef BiTNode<TElemType>* BiTree<TElemType>;

#pragma once
#include "stdafx.h"

//C����
//��������Ķ���
template <typename TElemType>
typedef struct BiTNode {
	//data domain
	TElemType data;
	//ref domain
	BiTNode *lchild, *rchild;
	//�޲ι�����, �ú���ָ��ʵ�� ��Ա����	
	BiTNode() {}
	//�вι�����,��������
	void(*CreatePloyn)(PList p, int length);
	//De������()
	virtual ~BiTNode() {}		
	//������˳����һ�ö�����
	void CreateBiTree(BiTree& T);

	////�ȸ�����������Խ��tΪ������
	//void Preorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////�и�����������Խ��tΪ������
	//void Inorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////�������������Խ��tΪ������
	//void Postorder(BinTreeNode<TElemType>* t, ostrem& out)const;

	//�ȸ�����������Խ��tΪ������
	void Preorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	//�и�����������Խ��tΪ������
	void Inorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	//�������������Խ��tΪ������
	void Postorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	//��α���������
	void LevelOrderTraverse(BiTNode* T);
};




