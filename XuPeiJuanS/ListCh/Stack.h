#include "stdafx.h"
#include "StackNode.h"
#pragma once
//LinkStack,链式栈的类定义
template <typename T>
class Stack {
private:
	StackNode<T>* top; //cur ptr
public:
	//Construct Function()
	Stack() :top(NULL) {}
	//DeConstruct Function()
	~Stack() {
		StackNode<T>* p; //temp ref domain		 
		while (top != NULL) { //free()
			p = top;
			top = top->next;
			delete p;
		}
	}
	//Push() 从栈顶压入一个元素
	void Push(const T & item) {
		StackNode<T> * p = new StackNode<T>;
		p->data = item; //赋值
		p->next = top; //connect cur ptr
		top = p; //cur ptr move ++
	}
	//Pop() 从栈顶弹出一个元素
	T Pop() {
		if (IsEmpty()) { //empty stack
			cerr << "Attempt to pop an empty stack!" << endl;
			exit(1);
		}
		StackNode<T>* p = top; //temp ref domain	
		T RetValue = p->data; //temp data domain
		top = top->next; //top-- move
		delete p; //free() p, else will crash memory
		return RetValue;
	}
	//peek(),GetTop()
	T GetTop(void) const {
		if (IsEmpty()) { //empty stack
			cerr << "Attempt to pop an empty stack!" << endl;
			exit(1);
		}
		return top->data;
	}
	//MakeEmpty()
	void MakeEmpty(void) {
		this.top = NULL;
	}//!_MakeEmpty()
	 //IsEmpty()
	int IsEmpty(void) const {
		return top == NULL;
	}//!_IsEmpty()
};//!_class Stack






