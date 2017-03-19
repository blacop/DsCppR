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
#include "Node.h"

//链表类
template <class T>
class LinkList {
public:

	LinkList() {}
	virtual ~LinkList() {}

	//构造链表，创建结点
	Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL) {
		Node<T> * newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			cerr << "Memory allocation failure !" << end; //捕获异常
			exit(1);
		}
		return newNode;
	}
};

