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
#include "StackNode.h"
#include "Node.h"

//LinkStack
template <class T>
class Stack {
private:
	StackNode<T>* top; //cur ptr
public:
	//Construct Function()
	template<class T>
	inline Stack<T>::Stack(void)
		:top(NULL) {}
	//DeConstruct Function()
	template<class T>
	virtual inline Stack<T>:: ~Stack() {
		StackNode<T>* p; //temp ref domain		 
		while (top != NULL) { //free()
			p = top;
			top = top->next;
			delete p;
		}
	}//!_DeConstruct Function()

	void Push(const T &item);
	T Pop();
	T GetTop(void) const;
	void MakeEmpty(void);
	int IsEmpty(void) const;

};//!_class //!_LinkStack

//Push() 从栈顶压入一个元素
template<class T>
inline void Stack<T>::Push(const T & item) {
	StackNode<T>* p = &(new StackNode<T>);
	p->data = item; //赋值
	p->next = top; //connect cur ptr
	top = p; //cur ptr move ++
}//!_Push() 从栈顶压入一个元素

//Pop() 从栈顶弹出一个元素
template<class T>
inline T Stack<T>::Pop() {
	if (IsEmpty()) { //empty stack
		cerr << "Attempt to pop an empty stack!" << endl;
		exit(1);
	}
	StackNode<T>* p = top; //temp ref domain	
	T RetValue = p->data; //temp data domain
	top = top->next; //top-- move
	delete p; //free() p, else will crash memory
	return RetValue;
}//!_Pop()

 //peek(),GetTop()
template<class T>
inline T Stack<T>::GetTop(void) const {
	if (IsEmpty()) { //empty stack
		cerr << "Attempt to pop an empty stack!" << endl;
		exit(1);
	}
	return top->data;
}//!_peek(),GetTop()


//MakeEmpty()
template<class T>
inline void Stack<T>::MakeEmpty(void) {
	this.top = NULL;
}//!_MakeEmpty()


//IsEmpty()
template<class T>
inline int Stack<T>::IsEmpty(void) const {
	return top == NULL;
}//!_IsEmpty()





