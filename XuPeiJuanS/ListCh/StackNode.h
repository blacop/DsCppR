#include "stdafx.h"
#include "Node.h"
#pragma once
//链式栈结点的类定义
template <typename T>
class StackNode {
	friend class Stack<T>;
private:
	T data;
	StackNode<T>* next;
	//2个方法
public:
	//Construct Function()
	StackNode(T d = 0, StackNode<T>* n = NULL) :data(d), next(n) {}
	//DeConstruct Function()
	virtual ~StackNode() {}
};//!_class StackNode


