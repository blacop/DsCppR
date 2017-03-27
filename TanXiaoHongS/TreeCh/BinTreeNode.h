#pragma once
#include "stdafx.h"
//二叉树结点类
template <typename T>
class BinTreeNode {
	//友元类, 本类的private member私有成员可被友元类操作
	friend class BinTree;
private:
	//ref domain 引用域
	BinTreeNode<T>* left;
	BinTreeNode<T>* right;	
	//6个方法
public:
	//data domain 数据域
	T data;

	//返回左孩子
	BinTreeNode<T>* GetLeft(void) const {
		return left;
	}
	//将左孩子更新为结点L
	void SetLeft(BinTreeNode<T>* L) {
		left = L;
	}

	//返回右孩子
	BinTreeNode<T>* GetRight(void) const {
		return right;
	}	
	//将右孩子更新为结点R
	void SetRight(BinTreeNode<T>* R) {
		right = R;
	}

	//构造函数,Constructor()
	BinTreeNode(const T& item, BinTreeNode<T>* lptr = NULL, BinTreeNode<T>* rptr = NULL)
		:data(item), left(lptr), right(rptr) {}

	//Deconstructor()
	virtual ~BinTreeNode() {}

};//!_class BinTreeNode

