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
	//ref domain
	Node<T> * next;
public:
	//data domain
	T data;
	#pragma endregion !_Member Field
	//6������
	//GetNext()������ָ��ǰ���ĺ�̽���ָ��
	Node<T>* NextNode(void) const;
	//������
	Node(const T& item, Node<T> * ptrnext = NULL);
	//������
	virtual ~Node() {}
	//������㣬��������,CreateLinkList,Malloc
	template<class T>
	inline Node<T> * InitNode(const T& item, Node<T>* nextptr = NULL) {
		//Node<T>* nextptr = NULL ��ʾ���û�д��Σ�Ĭ��ֵΪNULL
		Node<T>* newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			//cerr���������׼�����ostream���󣬳����ڳ��������Ϣ��
			cerr << "Memory allocation failure !" << end;
			//���ڷ���0������������˳�, ����1����������ͨ�������쳣��ֹ��
			exit(1);//�����1
		}
		return newNode;
	}//!_GetNode()//!_���������������
	//�ڵ�ǰ���֮�����ָ��p��ָ���	
	void InsertAfter(Node<T> *p);
	//ɾ����ǰ���ĺ�̽��
	Node<T> * DeleteAfter(void);	
};//!_class Node

//GetNext(), ���ص�ǰ����next���ֵ
//��ֵ�Ƿ���ֵ Node<T>*
//��ֵ�ǿռ��ʶ�� Node<T>::
template<class T>
inline Node<T>* Node<T>::NextNode(void) const {
	return this.next;
}

//������ //��ð������൱�ڸ�ֵ
template<class T> 
inline Node<T>::Node(const T& item, Node<T> * ptrnext)
	:data(item), next(ptrnext) {}

//�ڵ�ǰ���֮�����ָ��p��ָ���
template<class T> 
inline void Node<T>::InsertAfter(Node<T>* p) {
	//c++������ó�Ա�����Զ��� this.ָ��
	//thisָ�ĵ�ǰ������Node��
	//this.nextʡ����this
	p->next = this.next;
	this.next = p;
}

//ɾ����ǰ���ĺ�̽��
template<class T> 
inline Node<T>* Node<T>::DeleteAfter(void) {
	if (next == NULL)
		return NULL;
	Node<T>* tempptr = this.next;
	this.next = tempptr->next;
	return tempptr;
}