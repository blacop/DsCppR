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
	#pragma region Member Field	
private:
	Node<T>* head; //头指针
	#pragma endregion !_Member Field
public:
	#pragma region Member Function Definition
	LinkList() {}
	virtual ~LinkList() {}

	//创建结点，构造链表
	template<class T>
	Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL) {
		//Node<T>* nextptr = NULL 表示如果没有传参，默认值为NULL
		Node<T> * newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			//cerr：输出到标准错误的ostream对象，常用于程序错误信息；
			cerr << "Memory allocation failure !" << end;
			//由于返回0代表程序正常退出, 返回1等其他数字通常代表异常终止。
			exit(1);//错误号1
		}
		return newNode;
	}//!_GetNode()//!_构造链表，创建结点

	//头插法，构造链表
	//在头指针为head的链表中，插入一个data域为item的新结点作为该链表的表头结点
	template<class T>
	void InsertFront(Node<T>* &head, T item) {
		head = GetNode(item, head);
	}
	#pragma endregion !_Member Function Definition
};//class LinkList

