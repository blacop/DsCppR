//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition
#pragma once
#include "stdafx.h"
//循环双向链表结点
template <typename T>
class DNode {
private:
	DNode<T>* left; //ref domain
	DNode<T>* right; //ref domain
public:
	T data; //data domain
	DNode<T>* NextNodeLeft(void) const;
	DNode<T>* NextNodeRight(void) const;

	DNode(void); //构造方法
	DNode(const T &item); //构造方法
	virtual ~DNode() {} //析构造方法

	void InsertLeft(DNode<T>* p);
	void InsertRight(DNode<T>* p);
	DNode<T>* DeleteNode(void);

};//!_class DNode

//construct function
template <typename T>
inline DNode<T>::DNode(void) {}

//construct function
template <typename T>
inline DNode<T>::DNode(const T & item)
	:data(item), left(this), right(this) {}

//在当前结点(this)之后插入结点p
template <typename T>
inline void DNode<T>::InsertRight(DNode<T>* p) {
	//p is inserted node;
	//change ptr 4 times;
	this.right->left = p;
	p->right = this.right;
	p->left = this;
	this.right = p;
}

//Delete this DNode
template <typename T>
inline DNode<T>* DNode<T>::DeleteNode(void) {	
	DNode<T>* tempptr = this;
	//core 2 ptr move;
	this.left->right = this.right;
	this.right->left = this.left;
	return tempptr;
}//!_DeleteNode
