#pragma once
#include "stdafx.h"
#include "QueueNode.h"

const int MaxQSize = 50;
//��ʽ���е��ඨ��
template <typename T>
class Queue {
private:
	//ref domain
	QueueNode<T> *front, *rear;
	//8����Ա����
public:
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
	int IsEmpty() const {
		return front == NULL;
	}
	//��ն���
	void QClear(void);	
};//!_class Queue

//DeConstructor()
template <typename T>
inline Queue<T>::~Queue() {
	//temp ref domain
	QueueNode<T> * p;
	//��ͷ����ʼɾ��
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
}

//Insert()
template <typename T>
inline void Queue<T>::QInsert(const T & item) {
	//�ն���
	if (front == NULL)
		//new ����ϵͳҪ�������ô��Ŀռ䣡ע�⣬�ռ��С���ֻ�����ݳ�Ա�Ŀռ䣡������Ϊ��Ա������ռ�пռ�ģ���
		front = rear = new QueueNode<T>(item, NULL);
	else
		//c++�������࣬ʵ���������Ĳ���������ָ�����.new ������һ����������ָ�롣
		//rear->next = new QueueNode<T>(item, NULL);
		//rear = rear->next;
		rear = rear->next = new QueueNode<T>(item, NULL);
	////��������ָ��д����
	//QueueNode<T> * q;
	//q= new QueueNode<T>(item, NULL);
	//rear->next = q;
	//rear = q;
}//!_Insert()

//Delete(),ɾ�������ض���Ԫ��ֵ
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

//QFront(),��ȡ����Ԫ��
template <typename T>
inline T Queue<T>::QFront(void) const {
	if (IsEmpty()) exit(1);
	return front->data;
}

//���ض�����Ԫ�ظ���
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

//��ն���
template<typename T>
inline void Queue<T>::QClear(void) {
	QueueNode<T> * p; //temp ref domain	
	while (front != NULL) { //��ͷ����ʼɾ��
		p = front;
		front = front->next;
		delete p;
	}
}

