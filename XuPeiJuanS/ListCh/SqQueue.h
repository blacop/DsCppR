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
	//8个 方法
public:
	//构造函数 //Constructor
	SqQueue(void) :front(0), rear(0), count(0) {}
	//析构造函数
	virtual ~SqQueue() {}
	//向队尾插入元素 //Insert()
	void QInsert(const T & item) {
		if (count == MaxQSize) {
			cerr << "Queue overflow !" << endl;
			exit(1);
		}
		count++;
		QList[rear] = item;
		rear = (rear + 1) % MaxQSize;
	}//!_Insert()
	//删除队首元素 //Delete()
	T QDelete(void) {
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
	void ClearQueue(void) {
		rear = front;
		count = 0;
	}
	//读取队首元素 //QFront()
	T QFront(void) const {
		return QList[front];
	}
	//返回队列中元素个数 //QLength()
	int QLength(void) const {
		QueueNode<T> * tempptr = this.front;
		int count = 0;
		if (IsEmpty()) {
			return 0;
		}
		//按顺序找到最后一个结点
		while (tempptr != NULL) {
			tempptr = tempptr->next;
			count++;
		}
		return count + 1;
	}//!_QLength()
	//检测队列是否为空 //Destroy() Clear
	void QClear(void) const {
		//temp ref domain
		QueueNode<T> * p;
		//从头部开始删除
		while (front != NULL) {
			p = front;
			front = front->next;
			delete p;
		}
	}//!_Destroy() Clear
	//IsEmpty()
	int IsEmpty(void) const {
		return count == 0;
	}//!_IsEmpty()
	//检测队列是否为满 //IsFull()
	int IsFull(void) const {
		return return count == MaxQSize;
	}//!_IsFull()
};//!_class Queue



