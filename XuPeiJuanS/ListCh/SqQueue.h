#pragma once
#include "stdafx.h"
#include "Queue.h"

const int MaxQSize = 50;
//˳����е��ඨ��
template <typename T>
class SqQueue {
private:
	//��Ŷ���Ԫ�ص�����
	T QList[MaxQSize];
	//rear => last+1 , βָ��ָ��last+1
	int front, rear, count;
	//8�� ����
public:
	//���캯�� //Constructor
	SqQueue(void) :front(0), rear(0), count(0) {}
	//�����캯��
	virtual ~SqQueue() {}
	//���β����Ԫ�� //Insert()
	void QInsert(const T & item) {
		if (count == MaxQSize) {
			cerr << "Queue overflow !" << endl;
			exit(1);
		}
		count++;
		QList[rear] = item;
		rear = (rear + 1) % MaxQSize;
	}//!_Insert()
	//ɾ������Ԫ�� //Delete()
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
	//��ȡ����Ԫ�� //QFront()
	T QFront(void) const {
		return QList[front];
	}
	//���ض�����Ԫ�ظ��� //QLength()
	int QLength(void) const {
		QueueNode<T> * tempptr = this.front;
		int count = 0;
		if (IsEmpty()) {
			return 0;
		}
		//��˳���ҵ����һ�����
		while (tempptr != NULL) {
			tempptr = tempptr->next;
			count++;
		}
		return count + 1;
	}//!_QLength()
	//�������Ƿ�Ϊ�� //Destroy() Clear
	void QClear(void) const {
		//temp ref domain
		QueueNode<T> * p;
		//��ͷ����ʼɾ��
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
	//�������Ƿ�Ϊ�� //IsFull()
	int IsFull(void) const {
		return return count == MaxQSize;
	}//!_IsFull()
};//!_class Queue



