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
	virtual ~Queue() {
		//temp ref domain
		QueueNode<T> * p;
		//��ͷ����ʼɾ��
		while (front != NULL) {
			p = front;
			front = front->next;
			delete p;
		}
	}
	//���β����Ԫ��
	void EnQueue(const T & item) {
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
	 //ɾ�������ض���Ԫ��ֵ
	T DeQueue(void) {
		if (IsEmpty()) {
			cerr << "Deleting from an empty queue !" << endl;
			exit(1);
		}
		QueueNode<T> * p = front;
		T RetValue = p->data;
		delete p;
		return RetValue;
	}
	//��ȡ����Ԫ��
	T QFront(void) const {
		if (IsEmpty()) exit(1);
		return front->data;
	}
	//���ض�����Ԫ�ظ���
	int QLength(void) const {
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
	//�������Ƿ�Ϊ��
	int IsEmpty() const {
		return front == NULL;
	}
	//��ն���
	void QClear(void) {
		rear = front;
		count = 0;
	}
	//���ٶ���	
	void QDestroy(void) {
		QueueNode<T> * p; //temp ref domain	
		while (front != NULL) { //��ͷ����ʼɾ��
			p = front;
			front = front->next;
			delete p;
		}
	}
};//!_class Queue


