//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition
#include "stdafx.h"
#include "QueueNode.h"
#include "Node.h"
#pragma once
const int MaxQSize = 50;
//链式队列的类定义
template <class T>
class Queue {
private:
	//ref domain
	QueueNode<T> *front, *rear;
public:
	//8个方法
	//构造函数
	Queue() :rear(NULL), front(NULL) {}
	//析构造函数
	virtual ~Queue();
	//向队尾插入元素
	void QInsert(const T & item);
	//删除队首元素
	T QDelete(void);

	//读取队首元素
	T QFront(void) const;
	//返回队列中元素个数
	int QLength(void) const;
	//检测队列是否为空
	int QEmpty(void) const {
		return front == NULL;
	}
	//清空队列
	void QClear(void);

};//!_class Queue

//Insert()
template<class T>
inline void Queue<T>::QInsert(const T & item) {
	if (count == MaxQSize) {
		cerr << "Queue overflow !" << endl;
		exit(1);
	}
	count++;
	QList[rear] = item;
	rear = (rear + 1) % MaxQSize;
}//!_Insert()

//Delete()
template<class T>
inline T Queue<T>::QDelete(void) {
	if (count == 0) {
		cerr << "Deleting from an empty queue !" << endl;
		exit(1);
	}
	T temp;
	temp = QList[front];
	count--;
	front = (front + 1) % MaxQSize;
	return temp;
}

//ClearQueue()
template<class T>
inline void Queue<T>::ClearQueue(void) {
	rear = front;
	count = 0;
}

//QFront(),读取队首元素
template<class T>
inline T Queue<T>::QFront(void) const {
	return QList[front];
}

//QLength()
template<class T>
inline int Queue<T>::QLength(void) const {
	return count;
}

//QFull()
template<class T>
inline int Queue<T>::QFull(void) const {
	return return count == MaxQSize;
}

//DeConstructor()
template<class T>
inline Queue<T>::~Queue() {
	QueueNode<T> * p;
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
}
