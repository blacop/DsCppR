#pragma once
#include "stdafx.h"
#include "BinTreeNode.h"
#include "Stack.h"
//二叉树类BinTree的声明
template <typename T, typename TElemType>
class BinTree {
private:
	//指向根结点
	BinTreeNode<T>* root;
	//输入stop时，终止结点的输入
	T stop;
	//从结点begin开始搜索，返回结点current的父结点
	BinTreeNode<T>* father(BinTreeNode<T>* begin, BinTreeNode<T>* current);
	//10个方法
public:
	//Constructor(),构造函数--在声明一棵二叉树时进行初始化，生成一棵空树
	BinTree() :root(NULL) {}
	//Constructor(),//输入stop时，终止结点的输入
	BinTree(T mark) :root(NULL), stop(mark) {}
	//DeConstructor(),析构函数--删除整棵二叉树
	virtual ~BinTree() { DelSubtree root; }
	//在当前结点的位置插入一个结点
	int Insert(BinTreeNode<T>*& current, const T& item);
	//从结点current开始，搜索数据值为item的结点，返回编号
	int Find(BinTreeNode<T>*& current, const T& item) const;
	//删除结点current及其左右子树
	void DelSubtree(BinTreeNode<T>* current);
	//先根遍历并输出以结点t为根的树
	void Preorder(BinTreeNode<T>* t, ostrem& out)const;
	//中根遍历并输出以结点t为根的树
	void Inorder(BinTreeNode<T>* t, ostrem& out)const;
	//后根遍历并输出以结点t为根的树
	void Postorder(BinTreeNode<T>* t, ostrem& out)const;
	//判断二叉树是否为空
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}
	//计算结点个数,二叉树遍历的应用,
	void countleaf(BinTreeNode<T>* t, int& count) {
		if (t != NULL) {
			if ((t->left == NULL) && (t->right == NULL))
				count++;
			countleaf(t->left, count);
			countleaf(t->right, count);
		}
	}
	//交换二叉树中每个结点的左子女和右子女,先序可，后序可，中序不可
	void exchange(BinTreeNode<T>* t) {
		BinTreeNode<T>* temp;
		if ((t->left != NULL) || (t->right != NULL)) {
			temp = t->left;
			t->left = t->right;
			t->right = temp;
			exchange(t->left);
			exchange(t->right);
		}
	}
	//删除结点current极其左右子树，后序可
	void DelSubtree(BinTreeNode<T>* current) {
		if (current != NULL) {
			DelSubtree(current->left);
			DelSubtree(current->right);
			delete current;
		}
	}
	//按先序顺序构造一棵二叉树
	void CreateBiTree(BiTree<T>& T);
	//先序遍历二叉树的递归算法1
	bool PreOrderTraverseRec(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return true;
	}
	//先根遍历并输出以结点t为根的树,非递归算法，自建栈
	bool PreOrderTrverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BinTreeNode<T>* p = T; //临时指针
		Stack<T> S = new Stack<T>(); //非递归算法，自建栈,利用栈的特性来实现手动递归		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) {
				Visit(p->data); //访问根结点
				push(S, p);		//根结点入栈
				p = p->left;	//遍历左子树
			} else {	 //根结点出栈，遍历右子树
				pop(S, p);
				p = p->right;
			}//else
		}//while
		return true;
	}

	//中根遍历并输出以结点t为根的树,非递归算法，自建栈
	bool InOrderTrverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BinTreeNode<T>* p = T; //临时指针
		Stack<T> S = new Stack<T>(); //非递归算法，自建栈,利用栈的特性来实现手动递归		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) { //根结点入栈，遍历左子树
				push(S, p);
				p = p->left;
			} else {  //根结点出栈，访问根结点，遍历右子树
				pop(S, p);
				Visit(p->data);
				p = p->right;
			}//else
		}//while
		return true;
	}
	//后根遍历并输出以结点t为根的树,非递归算法，自建栈
	bool PostOrderTrverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BinTreeNode<T>* p = T; //临时指针
		Stack<T> S = new Stack<T>(); //非递归算法，自建栈,利用栈的特性来实现手动递归		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) { //根结点入栈，遍历左子树
				push(S, p);
				p = p->left;
			} else {   //根结点出栈，遍历右子树
				pop(S, p);
				p = p->right;
				Visit(p->data);//访问根结点
			}//else
		}//while
		return true;
	}
	//层次遍历二叉树
	bool LevelOrderTraverse(BinTreeNode<T>* T, bool(*Visit)(TElemType));

	//访问结点Func
	typedef bool(*VisitFunc)(TElemType) {
		PrintElement(e);
		return true;
	};
	//访问结点元素
	bool Visit(TElemType e) {
		if (!e) return false;
		PrintElement(T e); //cout << t->data;
		return true;
	}
	//输出结点元素
	bool PrintElement(TElemType e) {
		if (!e) return false;
		cout << e;	   //printf(e);
		return true;
	}
};//!_class BinTree

  //先根遍历并输出以结点t为根的树，递归算法
template<typename T>
inline void BinTree<T>::Preorder(BinTreeNode<T>* t, ostrem & out) const {
	if (t != NULL) {
		cout << t->data;		//visit() root node
		Preorder(t->left, out);	//enter left subtree		
		Preorder(t->right, out); //enter right subtree
	}
}

//中根遍历并输出以结点t为根的树，const表示这个是访问函数，不能修改结点，递归算法
template<typename T>
inline void BinTree<T>::Inorder(BinTreeNode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Inorder(t->left, out);	//enter left subtree
		cout << t->data;		//visit() root node
		Inorder(t->right, out); //enter right subtree
	}
}

//后根遍历并输出以结点t为根的树，递归算法
template<typename T>
inline void BinTree<T>::Postorder(BinTreeNode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Postorder(t->left, out);	//enter left subtree		
		Postorder(t->right, out); //enter right subtree
		cout << t->data;		//visit() root node
	}
}
