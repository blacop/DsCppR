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
	if (count==MaxQSize) {
		cerr << "Queue overflow !" << endl;
		exit(1);
	}
	count++;
	QList[rear] = item;
	rear = (rear + 1) % MaxQSize;
}//!_Insert()
