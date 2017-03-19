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
template <typename T>
class LinkList {
	#pragma region Member Field	
private:
	Node<T>* head; //头指针
	#pragma endregion !_Member Field
	//6个方法
public:
	#pragma region Member Function Definition
	//构造器
	LinkList(Node<T>* headptr = NULL) :head(headptr) {
		//Node<T>* nextptr = NULL 表示如果没有传参，默认值为NULL
		Node<T> * newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			//cerr：输出到标准错误的ostream对象，常用于程序错误信息；
			cerr << "Memory allocation failure !" << end;
			//由于返回0代表程序正常退出, 返回1等其他数字通常代表异常终止。
			exit(1);//错误号1
		}
		head = newNode
			return head;
	}
	//析构造器
	virtual ~LinkList() {}
	//创建结点，构造链表,CreateLinkList,Malloc
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
	//遍历链表
	void printList(Node<T>* head) {
		Node<T>* currptr = head;
		count = 0;
		while (currptr != NULL) {
			//输出数据
			cout << (currptr->data) << " ";
			if ((count++) % 5 == 0)
				//就是回车的意思~相当于C语言里面的printf("");
				cout << endl;
			currptr = currptr->NextNode();
		}
	}//!_printList()
	//头插法，构造链表//在头指针为head的链表中，插入一个data域为item的新结点作为该链表的表头结点
	void InsertFront(Node<T>* &head, T item) {
		head = GetNode(item, head);
	}
	//尾插法//表尾插入结点表尾
	void InsertRear(Node<T>* &head, const T &item) {
		Node<T>* currptr = head;
		//若表为空，调表头插入函数
		if (currptr == NULL) {
			InsertFront(head, item);
		} else {
			//找到表尾，找到最后一个结点
			while (currptr->NextNode() != NULL)
				currptr = currptr->NextNode();
			//尾插法
			Node<T>* newNode;
			newNode = GetNode(item);//Malloc()
			currptr->InsertAfter(newNode);
		}
	}//!_InsertRear()

	#pragma endregion !_Member Function Definition
};//class LinkList

