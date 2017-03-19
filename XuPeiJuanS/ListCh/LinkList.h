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
#include "Node.h"

//������
template <class T>
class LinkList {
	#pragma region Member Field	
private:
	Node<T>* head; //ͷָ��
	#pragma endregion !_Member Field
public:
	#pragma region Member Function Definition
	LinkList() {}
	virtual ~LinkList() {}

	//������㣬��������
	template<class T>
	Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL) {
		//Node<T>* nextptr = NULL ��ʾ���û�д��Σ�Ĭ��ֵΪNULL
		Node<T> * newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			//cerr���������׼�����ostream���󣬳����ڳ��������Ϣ��
			cerr << "Memory allocation failure !" << end;
			//���ڷ���0������������˳�, ����1����������ͨ�������쳣��ֹ��
			exit(1);//�����1
		}
		return newNode;
	}//!_GetNode()//!_���������������

	//ͷ�巨����������
	//��ͷָ��Ϊhead�������У�����һ��data��Ϊitem���½����Ϊ������ı�ͷ���
	template<class T>
	void InsertFront(Node<T>* &head, T item) {
		head = GetNode(item, head);
	}
	#pragma endregion !_Member Function Definition
};//class LinkList

