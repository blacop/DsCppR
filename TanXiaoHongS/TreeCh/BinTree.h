#pragma once
#include "stdafx.h"
#include "BinTreeNode.h"
//二叉树类BinTree的声明
template <typename TElemType>
class BinTree {
	//2个属性
private:
	//指向根结点
	BinTreeNode<TElemType>* root;
	//输入stop时，终止结点的输入
	TElemType stop;

	//从结点begin开始搜索，返回结点current的父结点
	BinTreeNode<TElemType>* father(BinTreeNode<TElemType>* begin, BinTreeNode<TElemType>* current);
	//11个方法
public:
	//Constructor(),构造函数--在声明一棵二叉树时进行初始化，生成一棵空树
	BinTree() :root(NULL) {}
	//Constructor(),//输入stop时，终止结点的输入
	BinTree(TElemType mark) :root(NULL), stop(mark) {}
	//DeConstructor(),析构函数--删除整棵二叉树
	virtual ~BinTree() { DelSubtree root; }
	//在当前结点的位置插入一个结点
	int Insert(BinTreeNode<TElemType>*& current, const T& item);
	//从结点current开始，搜索数据值为item的结点，返回编号
	int Find(BinTreeNode<TElemType>*& current, const T& item) const;
	//删除结点current及其左右子树
	void DelSubtree(BinTreeNode<TElemType>* current);

	////先根遍历并输出以结点t为根的树
	//void Preorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////中根遍历并输出以结点t为根的树
	//void Inorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////后根遍历并输出以结点t为根的树
	//void Postorder(BinTreeNode<TElemType>* t, ostrem& out)const;

	//判断二叉树是否为空
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}

	//按先序顺序构造一棵二叉树
	void CreateBiTree(BiTree<TElemType>& T);

	//先序遍历二叉树的递归算法1
	Status PreOrderTraverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return OK;
	}
	//先序遍历二叉树的递归算法2
	//这个算法有错，左子树没有，右子树就进不去了
	Status PreOrderTraverse2(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType)) {
		if (T != NULL) {
			if (Visit(T->data))
				//这个算法有错，左子树没有，右子树就进不去了
				if (PreOrderTraverse(T->left, Visit(T->data)))
					if (PreOrderTraverse(T->right, Visit(T->data))) return OK;
			return ERROR; //!_else if (!Visit(T->data))
		} else return OK;
	}

	//中根遍历并输出以结点t为根的树,非递归算法，自建栈
	Status InOrderTrverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType)) {}
	//后根遍历并输出以结点t为根的树
	Status PostOrderTrverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType));
	//层次遍历二叉树
	Status LevelOrderTraverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType));

	//访问结点
	Status Visit(TElemType e) {
		if (!e) {
			return FALSE;
		}
		//cout << t->data);
		PrintElement(TElemType e);
		return TRUE;
	}

	//输出结点
	Status PrintElement(TElemType e) {
		printf(e);
		return OK;
	}

};//!_class BinTree



