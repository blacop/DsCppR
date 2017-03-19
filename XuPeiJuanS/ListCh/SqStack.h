#pragma once
#include "stdafx.h"
#include "Stack.h"
const int MaxStackSize = 50;
//SqStack,˳��ջ
template <typename T>
class SqStack {
private:
	T StackList[MaxStackSize]; //data domain Array
	int top; //cur ptr
	//8 func
public:
	//Construct Function()
	SqStack() :top(-1) {}
	//DeConstructor()
	virtual ~SqStack() {}
	//Push() ��ջ��ѹ��һ��Ԫ��
	void Push(const T &item) {
		//full stack
		if (top == MaxStackSize - 1) {
			cerr << "Stack overflow !" << endl;
			exit(1);
		}
		top++; //cur ptr ++
		StackList[top] = item; //��ֵ
	}
	//Pop() ��ջ������һ��Ԫ��
	T Pop(void) {
		T temp; //temp data  domain	
		if (top = -1) { //empty stack
			cerr << "Attempt to pop an empty stack!" << endl;
			exit(1);
		}
		temp = StackList[top];
		top--;
		return temp;
	}//!_Pop()
	 //ClearStack()
	void ClearStack(void) {
		this.top = -1;
	}//!_ClearStack()
	 //peek()
	T Peek(void) const {
		if (top = -1) { //empty stack
			cerr << "Attempt to pop an empty stack!" << endl;
			exit(1);
		}
		return StackList[top];
	}//!_peek()
	 //StackEmpty()
	int StackEmpty(void) const {
		return top == -1;
	}//!_StackEmpty()
	 //StackFull()
	int StackFull(void) const {
		return top == MaxStackSize - 1;
	}//!_StackFull()
};//!_class Stack





