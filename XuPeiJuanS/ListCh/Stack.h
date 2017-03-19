#include "stdafx.h"
#include "StackNode.h"
#pragma once
//LinkStack,��ʽջ���ඨ��
template <typename T>
class Stack {
private:
	StackNode<T>* top; //cur ptr
	// 7������
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
	//Push() ��ջ��ѹ��һ��Ԫ��
	void Push(const T & item) {
		StackNode<T> * p = new StackNode<T>;
		p->data = item; //��ֵ
		p->next = top; //connect cur ptr
		top = p; //cur ptr move ++
	}
	//Pop() ��ջ������һ��Ԫ��
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
	//Peek(),GetTop()
	T Peek() const {
		if (IsEmpty()) { //empty stack
			cerr << "Attempt to pop an empty stack!" << endl;
			exit(1);
		}
		return top->data;
	}//!_Peek
	//Clear()
	void Clear(void) {		
		//��free()���ڴ�й©
		StackNode<T>* p; //temp ref domain		 
		while (top != NULL) { //free()
			p = top;
			top = top->next;
			delete p;
		}
		this.top = NULL; 
	}//!_Clear()
	 //IsEmpty()
	int IsEmpty(void) const {
		return top == NULL;
	}//!_IsEmpty()
};//!_class Stack






