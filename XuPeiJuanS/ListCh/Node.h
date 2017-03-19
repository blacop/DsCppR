#include "stdafx.h"
#pragma once
//结点类
template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
	//6个方法
public:
	//构造器 2参
	Node(T &elem, Node<T>* ptr = NULL) :data(elem), next(ptr) {}
	//构造器 1参
	Node(Node<T>* p = nullptr) :next(p) {}
	//析构器
	virtual ~Node() {}
	//在当前结点之后插入指针p所指结点	
	void InsertAfter(Node<T> *p) {
		//c++对象调用成员函数自动加 this.指针
		//this指的当前对象是Node类
		//this.next省略了this
		p->next = this.next;
		this.next = p;
	}
	//删除当前结点的后继结点
	Node<T> * DeleteAfter(void) {
		if (next == NULL)
			return NULL;
		Node<T>* tempptr = this.next;
		this.next = tempptr->next;
		return tempptr;
	}
	//GetNext()，返回指向当前结点的后继结点的指针
	Node<T>* NextNode(void) const {
		return this.next;
	}	
};//!_class Node
