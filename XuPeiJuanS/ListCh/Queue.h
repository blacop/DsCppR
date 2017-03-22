#pragma once
#include "stdafx.h"
#include "QueueNode.h"

const int MaxQSize = 50;
//链式队列的类定义
template <typename T>
class Queue {
private:
	//ref domain
	QueueNode<T> *front, *rear;
	//8个成员方法
public:
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
	int IsEmpty() const {
		return front == NULL;
	}
	//清空队列
	void QClear(void);	
};//!_class Queue

//DeConstructor()
template <typename T>
inline Queue<T>::~Queue() {
	//temp ref domain
	QueueNode<T> * p;
	//从头部开始删除
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
}

//Insert()
template <typename T>
inline void Queue<T>::QInsert(const T & item) {
	//空队列
	if (front == NULL)
		//new 是向系统要这个类那么大的空间！注意，空间大小算的只是数据成员的空间！！！因为成员函数不占有空间的！！
		front = rear = new QueueNode<T>(item, NULL);
	else
		//c++里所有类，实例化对象后的操作，都是指针操作.new 返回了一个匿名对象指针。
		//rear->next = new QueueNode<T>(item, NULL);
		//rear = rear->next;
		rear = rear->next = new QueueNode<T>(item, NULL);
	////有名对象指针写法。
	//QueueNode<T> * q;
	//q= new QueueNode<T>(item, NULL);
	//rear->next = q;
	//rear = q;
}//!_Insert()

//Delete(),删除并返回队首元素值
template <typename T>
inline T Queue<T>::QDelete(void) {
	if (IsEmpty()) {
		cerr << "Deleting from an empty queue !" << endl;
		exit(1);
	}
	QueueNode<T> * p = front;
	T RetValue = p->data;
	delete p;
	return RetValue;
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
	if (IsEmpty()) exit(1);
	return front->data;
}

//返回队列中元素个数
template<typename T>
inline int Queue<T>::QLength(void) const {
	Queue<T>* tempptr = this.front;
	int count = 0;
	if (front == NULL) { //Queue is empty
		return 0;
	}
	while (tempptr->next != NULL) { //find Queue's end node
		tempptr = tempptr->next;
		count++;
	}
	return count + 1;
}

//清空队列
template<typename T>
inline void Queue<T>::QClear(void) {
	QueueNode<T> * p; //temp ref domain	
	while (front != NULL) { //从头部开始删除
		p = front;
		front = front->next;
		delete p;
	}
}

