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
//��ʽ���е��ඨ��
template <class T>
class Queue {
private:
	//ref domain
	QueueNode<T> *front, *rear;
public:
	//8������
	//���캯��
	Queue() :rear(NULL), front(NULL) {}
	//�����캯��
	virtual ~Queue();
	//���β����Ԫ��
	void QInsert(const T & item);
	//ɾ������Ԫ��
	T QDelete(void);

	//��ȡ����Ԫ��
	T QFront(void) const;
	//���ض�����Ԫ�ظ���
	int QLength(void) const;
	//�������Ƿ�Ϊ��
	int QEmpty(void) const {
		return front == NULL;
	}
	//��ն���
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

//QFront(),��ȡ����Ԫ��
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
