#include "stdafx.h"
#pragma once
//�����
template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
	//6������
public:
	//������ 2��
	Node(T &elem, Node<T>* ptr = NULL) :data(elem), next(ptr) {}
	//������ 1��
	Node(Node<T>* p = nullptr) :next(p) {}
	//������
	virtual ~Node() {}
	//�ڵ�ǰ���֮�����ָ��p��ָ���	
	void InsertAfter(Node<T> *p) {
		//c++������ó�Ա�����Զ��� this.ָ��
		//thisָ�ĵ�ǰ������Node��
		//this.nextʡ����this
		p->next = this.next;
		this.next = p;
	}
	//ɾ����ǰ���ĺ�̽��
	Node<T> * DeleteAfter(void) {
		if (next == NULL)
			return NULL;
		Node<T>* tempptr = this.next;
		this.next = tempptr->next;
		return tempptr;
	}
	//GetNext()������ָ��ǰ���ĺ�̽���ָ��
	Node<T>* NextNode(void) const {
		return this.next;
	}	
};//!_class Node
