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

const int MaxStackSize = 50;

//SqStack
template <class T>
class Stack {
private:
	T StackList[MaxStackSize]; //data domain Array
	int top; //cur ptr
public:
	Stack(void);
	virtual ~Stack() {}

	void Push(const T &item);
	T Pop(void);
	void ClearStack(void);
	T Peek(void) const;
	int StackEmpty(void) const;
	int StackFull(void) const;

};//!_class Stack

//Construct Function()
template<class T>
inline Stack<T>::Stack(void)
	:top(-1) {}

//Push() 从栈顶压入一个元素
template<class T>
inline void Stack<T>::Push(const T & item) {
	//full stack
	if (top == MaxStackSize - 1) {
		cerr << "Stack overflow !" << endl;
		exit(1);
	}
	top++; //cur ptr ++
	StackList[top] = item; //赋值
}

//Pop() 从栈顶弹出一个元素
template<class T>
inline T Stack<T>::Pop(void) {
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
template<class T>
inline void Stack<T>::ClearStack(void) {
	this.top = -1;
}//!_ClearStack()


//peek()
template<class T>
inline T Stack<T>::Peek(void) const {
	if (top = -1) { //empty stack
		cerr << "Attempt to pop an empty stack!" << endl;
		exit(1);
	}
	return StackList[top];
}//!_peek()

//StackEmpty()
template<class T>
inline int Stack<T>::StackEmpty(void) const {
	return top == -1;
}//!_StackEmpty()

//StackFull()
template<class T>
inline int Stack<T>::StackFull(void) const {
	return top == MaxStackSize - 1;
}//!_StackFull()



