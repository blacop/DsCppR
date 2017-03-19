//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition
#include "stdafx.h"
#pragma once
const int MaxQSize = 50;
//˳����е��ඨ��
template <class T>
class Queue {
private:
	T QList[MaxQSize];//��Ŷ���Ԫ�ص�����
	//rear => last+1 , βָ��ָ��last+1
	int front, rear, count;
public:
	//���캯��
	Queue(void);
	//�����캯��
	virtual ~Queue() {}
	//���β����Ԫ��
	void QInsert(const T & item);
	//ɾ������Ԫ��
	T QDelete(void);
	void ClearQueue(void);
	//��ȡ����Ԫ��
	T QFront(void) const;
	//���ض�����Ԫ�ظ���
	int QLength(void) const;
	//�������Ƿ�Ϊ��
	int QEmpty(void) const;
	//�������Ƿ�Ϊ��
	int QFull(void) const;

};//!_class Queue

//Constructor
template<class T>
inline Queue<T>::Queue(void)
	:front(0), rear(0), count(0) {}

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

//QEmpty()
template<class T>
inline int Queue<T>::QEmpty(void) const {
	return count == 0;
}

//QFull()
template<class T>
inline int Queue<T>::QFull(void) const {
	return return count == MaxQSize;
}


