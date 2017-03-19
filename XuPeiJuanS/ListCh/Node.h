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
//结点类
template <class T>
class Node {
	#pragma region Member Field	
private:
	Node<T> * next; //ref domain
public:
	T data; //data domain
	#pragma endregion !_Member Field

	#pragma region Member Attribute
	Node<T>* NextNode(void) const;//返回指向当前结点的后继结点的指针
	#pragma endregion !_Member Attribute

	#pragma region Member Function Interface
	Node(const T& item, Node<T> * ptrnext = NULL);//构造器
	virtual ~Node() {}	//析构器

	void InsertAfter(Node<T> *p);//在当前结点之后插入指针p所指结点	
	Node<T> * DeleteAfter(void);//删除当前结点的后继结点
	#pragma endregion !_Member Function Interface
};//!_class Node

#pragma region Member Attribute
//返回当前结点的next域的值
//左值是返回值 Node<T>*
//右值是空间标识符 Node<T>::
template<class T>
inline Node<T>* Node<T>::NextNode(void) const {
	return this.next;
}
#pragma endregion !_Member Attribute

#pragma region Member Function Definition

template<class T> //构造器 //：冒号语句相当于赋值
inline Node<T>::Node(const T& item, Node<T> * ptrnext)
	:data(item), next(ptrnext) {}

template<class T> //在当前结点之后插入指针p所指结点
inline void Node<T>::InsertAfter(Node<T>* p) {
	//c++对象调用成员函数自动加 this.指针
	//this指的当前对象是Node类
	//this.next省略了this
	p->next = this.next;
	this.next = p;
}

template<class T> //删除当前结点的后继结点
inline Node<T>* Node<T>::DeleteAfter(void) {
	if (next == NULL)
		return NULL;
	Node<T>* tempptr = this.next;
	this.next = tempptr->next;
	return tempptr;
}

#pragma endregion !_Member Function Definition