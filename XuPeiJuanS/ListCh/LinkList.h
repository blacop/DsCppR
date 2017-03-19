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
template <typename T>
class LinkList {
	#pragma region Member Field	
private:
	Node<T>* head; //ͷָ��
	#pragma endregion !_Member Field
	//6������
public:
	#pragma region Member Function Definition
	//������
	LinkList(Node<T>* headptr = NULL) :head(headptr) {
		//Node<T>* nextptr = NULL ��ʾ���û�д��Σ�Ĭ��ֵΪNULL
		Node<T> * newNode;
		newNode = new Node<T>(item, nextptr);
		if (newNode == NULL) {
			//cerr���������׼�����ostream���󣬳����ڳ��������Ϣ��
			cerr << "Memory allocation failure !" << end;
			//���ڷ���0������������˳�, ����1����������ͨ�������쳣��ֹ��
			exit(1);//�����1
		}
		head = newNode
			return head;
	}
	//��������
	virtual ~LinkList() {}
	//������㣬��������,CreateLinkList,Malloc
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
	//��������
	void printList(Node<T>* head) {
		Node<T>* currptr = head;
		count = 0;
		while (currptr != NULL) {
			//�������
			cout << (currptr->data) << " ";
			if ((count++) % 5 == 0)
				//���ǻس�����˼~�൱��C���������printf("");
				cout << endl;
			currptr = currptr->NextNode();
		}
	}//!_printList()
	//ͷ�巨����������//��ͷָ��Ϊhead�������У�����һ��data��Ϊitem���½����Ϊ������ı�ͷ���
	void InsertFront(Node<T>* &head, T item) {
		head = GetNode(item, head);
	}
	//β�巨//��β�������β
	void InsertRear(Node<T>* &head, const T &item) {
		Node<T>* currptr = head;
		//����Ϊ�գ�����ͷ���뺯��
		if (currptr == NULL) {
			InsertFront(head, item);
		} else {
			//�ҵ���β���ҵ����һ�����
			while (currptr->NextNode() != NULL)
				currptr = currptr->NextNode();
			//β�巨
			Node<T>* newNode;
			newNode = GetNode(item);//Malloc()
			currptr->InsertAfter(newNode);
		}
	}//!_InsertRear()

	#pragma endregion !_Member Function Definition
};//class LinkList

