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

//C语言
//二叉链表的定义
template <typename TElemType>
typedef struct BiTNode {
	//data domain
	TElemType data;
	//ref domain
	BiTNode *lchild, *rchild;
	//无参构造器, 用函数指针实现 成员函数	
	BiTNode() {}
	//有参构造器,建立链表
	void(*CreatePloyn)(PList p, int length);
	//De构造器()
	virtual ~BiTNode() {}		
	//按先序顺序构造一棵二叉树
	void CreateBiTree(BiTree& T);

	////先根遍历并输出以结点t为根的树
	//void Preorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////中根遍历并输出以结点t为根的树
	//void Inorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////后根遍历并输出以结点t为根的树
	//void Postorder(BinTreeNode<TElemType>* t, ostrem& out)const;

	//先根遍历并输出以结点t为根的树
	void Preorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	//中根遍历并输出以结点t为根的树
	void Inorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	//后根遍历并输出以结点t为根的树
	void Postorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	//层次遍历二叉树
	void LevelOrderTraverse(BiTNode* T);
};




