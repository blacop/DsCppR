#pragma once
#include "stdafx.h"
//template <typename TElemType>
//typedef BiTNode<TElemType>* BiTree<TElemType>;

//Cpp语言
//二叉链表的定义
template <typename TElemType>
class BiTNode {
public:
	//data domain
	TElemType data;
	//ref domain
	BiTNode *lchild, *rchild;
	//无参构造器, 用函数指针实现 成员函数	
	BiTNode() {}
	//De构造器()
	virtual ~BiTNode() {}	
	
	////先根遍历并输出以结点t为根的树
	//void Preorder(BiTree<TElemType>* t, ostrem& out)const;
	////中根遍历并输出以结点t为根的树
	//void Inorder(BiTree<TElemType>* t, ostrem& out)const;
	////后根遍历并输出以结点t为根的树
	//void Postorder(BiTree<TElemType>* t, ostrem& out)const;

	//按先序顺序构造一棵二叉树
	void CreateBiTree(BiTree<TElemType>& T);
	//先根遍历并输出以结点t为根的树
	void PreOrderTrverse(BiTree T);
	//中根遍历并输出以结点t为根的树
	void InOrderTrverse(BiTree T);
	//后根遍历并输出以结点t为根的树
	void PostOrderTrverse(BiTree T);
	//层次遍历二叉树
	void LevelOrderTraverse(BiTNode* T);
};




