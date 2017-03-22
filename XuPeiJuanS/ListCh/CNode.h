#pragma once
#include "stdafx.h"

//循环链表结点
template <typename T>
class CNode {
private:
	CNode<T>* next; //ref domain
	//7个方法
public:
	T data; //data domain

	CNode(void) {} //构造器,无参，生成哨位结点，头结点
	CNode(const T &item):data(item), next(this) {}//构造器,有参
	virtual ~CNode() {} //析构造器

	//getNext()
	CNode<T>* CNode<T>::NextNode(void) const {
		return this.next;
	}

	//插入当前结点的后继结点
	void CNode<T>::InsertAfter(CNode<T>* p) {
		//c++对象调用成员函数自动加 this.指针
		//this指的当前对象是Node类
		//this.next省略了this
		p->next = this.next;
		this.next = p;
	}

	//删除当前结点的后继结点,返回删除的结点
	CNode<T>* CNode<T>::DeleteAfter(void) {
		//this CNode is the end of LinkList
		if (this.next == this) {
			return NULL;
		}
		//删除当前结点的后继结点
		CNode<T>* tempptr = this.next;
		this.next = tempptr->next;
		return tempptr;
	}

	//合并2个循环链表
	CNode<T>* CNode<T>::Merge(CNode<T> &A, CNode<T> &B) {
		//A，B 都是尾指针
		//因为循环链表的尾结点指向头结点 rear.next==head
		CNode<T>* p = A->next;
		//connect by pass B的头结点
		A->next = B->next->next;
		//删除B的头结点
		delete B->next;
		//connect A的头结点
		B->next = p;
		return B;
	}//!_Merge()

}; //!_class CNode
