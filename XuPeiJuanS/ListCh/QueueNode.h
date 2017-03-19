//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition
#include "stdafx.h"
#include "Node.h"
#pragma once
//链式队列结点的类定义
template <class T>
class QueueNode : public Node {
	//如果在本类以外的其它地方定义了一个函数（这个函数可以是不属于任何类的非成员函数，也可以是其它类的成员函数），在类体中用friend对该函数进行声明，此函数就称为本类的友元函数。一个类的友元函数可以访问这个类中的private成员。
	//mean can operated by class Stack<T>
	friend class Queue<T>;
private:
	T data; //data domain
	QueueNode<T>* next; //ref domain
public:
	//2个方法
	//Construct Function()	
	QueueNode(T d = 0, QueueNode<T>* n = NULL)
		:data(d), next(n) {}
	//DeConstruct Function()
	virtual ~QueueNode() {}
};
