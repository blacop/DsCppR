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
//�����
template <class T>
class Node {
	#pragma region Member Field	
private:
	Node<T> * next; //ref domain
public:
	T data; //data domain
	#pragma endregion !_Member Field

	#pragma region Member Attribute
	Node<T>* NextNode(void) const;//����ָ��ǰ���ĺ�̽���ָ��
	#pragma endregion !_Member Attribute

	#pragma region Member Function Interface
	Node(const T& item, Node<T> * ptrnext = NULL);//������
	virtual ~Node() {}	//������

	void InsertAfter(Node<T> *p);//�ڵ�ǰ���֮�����ָ��p��ָ���	
	Node<T> * DeleteAfter(void);//ɾ����ǰ���ĺ�̽��
	#pragma endregion !_Member Function Interface
};//!_class Node

#pragma region Member Attribute
//���ص�ǰ����next���ֵ
//��ֵ�Ƿ���ֵ Node<T>*
//��ֵ�ǿռ��ʶ�� Node<T>::
template<class T>
inline Node<T>* Node<T>::NextNode(void) const {
	return this.next;
}
#pragma endregion !_Member Attribute

#pragma region Member Function Definition

template<class T> //������ //��ð������൱�ڸ�ֵ
inline Node<T>::Node(const T& item, Node<T> * ptrnext)
	:data(item), next(ptrnext) {}

template<class T> //�ڵ�ǰ���֮�����ָ��p��ָ���
inline void Node<T>::InsertAfter(Node<T>* p) {
	//c++������ó�Ա�����Զ��� this.ָ��
	//thisָ�ĵ�ǰ������Node��
	//this.nextʡ����this
	p->next = this.next;
	this.next = p;
}

template<class T> //ɾ����ǰ���ĺ�̽��
inline Node<T>* Node<T>::DeleteAfter(void) {
	if (next == NULL)
		return NULL;
	Node<T>* tempptr = this.next;
	this.next = tempptr->next;
	return tempptr;
}

#pragma endregion !_Member Function Definition