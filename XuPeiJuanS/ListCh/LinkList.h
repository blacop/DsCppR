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

//������
template <class T>
class LinkList {
public:

	LinkList() {}
	virtual ~LinkList() {}

	//���������������
	Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL) {
		Node<T> * newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			cerr << "Memory allocation failure !" << end; //�����쳣
			exit(1);
		}
		return newNode;
	}
};

