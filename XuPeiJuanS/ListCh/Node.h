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
	//ref domain
	Node<T> * next;
public:
	//data domain
	T data;
	#pragma endregion !_Member Field
	//6个方法
	//GetNext()，返回指向当前结点的后继结点的指针
	Node<T>* NextNode(void) const;
	//构造器
	Node(const T& item, Node<T> * ptrnext = NULL);
	//析构器
	virtual ~Node() {}
	//创建结点，构造链表,CreateLinkList,Malloc
	template<class T>
	inline Node<T> * InitNode(const T& item, Node<T>* nextptr = NULL) {
		//Node<T>* nextptr = NULL 表示如果没有传参，默认值为NULL
		Node<T>* newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			//cerr：输出到标准错误的ostream对象，常用于程序错误信息；
			cerr << "Memory allocation failure !" << end;
			//由于返回0代表程序正常退出, 返回1等其他数字通常代表异常终止。
			exit(1);//错误号1
		}
		return newNode;
	}//!_GetNode()//!_构造链表，创建结点
	//在当前结点之后插入指针p所指结点	
	void InsertAfter(Node<T> *p);
	//删除当前结点的后继结点
	Node<T> * DeleteAfter(void);	
};//!_class Node

//GetNext(), 返回当前结点的next域的值
//左值是返回值 Node<T>*
//右值是空间标识符 Node<T>::
template<class T>
inline Node<T>* Node<T>::NextNode(void) const {
	return this.next;
}

//构造器 //：冒号语句相当于赋值
template<class T> 
inline Node<T>::Node(const T& item, Node<T> * ptrnext)
	:data(item), next(ptrnext) {}

//在当前结点之后插入指针p所指结点
template<class T> 
inline void Node<T>::InsertAfter(Node<T>* p) {
	//c++对象调用成员函数自动加 this.指针
	//this指的当前对象是Node类
	//this.next省略了this
	p->next = this.next;
	this.next = p;
}

//删除当前结点的后继结点
template<class T> 
inline Node<T>* Node<T>::DeleteAfter(void) {
	if (next == NULL)
		return NULL;
	Node<T>* tempptr = this.next;
	this.next = tempptr->next;
	return tempptr;
}