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

//ѭ��������
template <class T>
class CNode {
private:
	CNode<T>* next; //ref domain
public:
	T data; //data domain

	template <class T>
	inline CNode<T>::CNode(void) {} //������,�޲Σ�������λ��㣬ͷ���
	inline CNode<T>::CNode(const T &item)
		:data(item), next(this) {}//������,�в�
	virtual ~CNode() {} //��������

	//getNext()
	template<class T>
	inline CNode<T>* CNode<T>::NextNode(void) const {
		return this.next;
	}

	//���뵱ǰ���ĺ�̽��
	template <class T>
	inline void CNode<T>::InsertAfter(CNode<T>* p) {
		//c++������ó�Ա�����Զ��� this.ָ��
		//thisָ�ĵ�ǰ������Node��
		//this.nextʡ����this
		p->next = this.next;
		this.next = p;
	}

	//ɾ����ǰ���ĺ�̽��,����ɾ���Ľ��
	template <class T>
	inline CNode<T>* CNode<T>::DeleteAfter(void) {
		//this CNode is the end of LinkList
		if (this.next == this) {
			return NULL;
		}
		//ɾ����ǰ���ĺ�̽��
		CNode<T>* tempptr = this.next;
		this.next = tempptr->next;
		return tempptr;
	}

	//�ϲ�2��ѭ������
	template <class T>
	inline CNode<T>* CNode<T>::Merge(CNode<T> &A, CNode<T> &B) {
		//A��B ����βָ��
		//��Ϊѭ�������β���ָ��ͷ��� rear.next==head
		CNode<T>* p = A->next;
		//connect by pass B��ͷ���
		A->next = B->next->next;
		//ɾ��B��ͷ���
		delete B->next;
		//connect A��ͷ���
		B->next = p;
		return B;
	}//!_Merge()

}; //!_class CNode
