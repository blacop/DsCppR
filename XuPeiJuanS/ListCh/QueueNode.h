#include "stdafx.h"
#include "Node.h"
#pragma once
//链式队列结点的类定义
template <typename T>
class QueueNode : public Node {	
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
};//!_class QueueNode
