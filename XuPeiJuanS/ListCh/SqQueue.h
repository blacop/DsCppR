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
#include "Queue.h"
const int MaxQSize = 50;
//顺序队列的类定义
template <typename T>
class SqQueue {
private:
	//存放队列元素的数组
	T QList[MaxQSize];
	//rear => last+1 , 尾指针指向last+1
	int front, rear, count;
public:
	//构造函数
	SqQueue(void);
	//析构造函数
	virtual ~SqQueue() {}
	//向队尾插入元素
	void QInsert(const T & item);
	//删除队首元素
	T QDelete(void);
	void ClearQueue(void);
	//读取队首元素
	T QFront(void) const;
	//返回队列中元素个数
	int QLength(void) const;
	//检测队列是否为空
	int QEmpty(void) const;
	//检测队列是否为满
	int QFull(void) const;

};//!_class Queue

  //Constructor
template <typename T>
inline SqQueue<T>::SqQueue(void)
	:front(0), rear(0), count(0) {}

//Insert()
template <typename T>
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
template <typename T>
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
template <typename T>
inline void Queue<T>::ClearQueue(void) {
	rear = front;
	count = 0;
}

//QFront(),读取队首元素
template <typename T>
inline T Queue<T>::QFront(void) const {
	return QList[front];
}

//QLength()
template <typename T>
inline int Queue<T>::QLength(void) const {
	QueueNode<T> * tempptr = this.front;
	int count=0;
	if (IsEmpty()) {
		return 0;
	}
	//按顺序找到最后一个结点
	while (tempptr!=NULL) {
		tempptr = tempptr->next;
		count++;
	}		
	return count+1;
}

//Destroy()
template <typename T>
inline void Queue<T>::QClear(void) {
	//temp ref domain
	QueueNode<T> * p;
	//从头部开始删除
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
}

//QEmpty()
template <typename T>
inline int Queue<T>::QEmpty(void) const {
	return count == 0;
}

//QFull()
template <typename T>
inline int Queue<T>::QFull(void) const {
	return return count == MaxQSize;
}


