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
	//�������ͷ���ĵ�����head�ĳ���
	int Length()const {
		Node<T>* p = head->next;
		int count = 1;
		while (p->next != NULL) {
			p = p->next; count++;
		}
		return count;
	}
	//��һ������head��ת��Ҫ�е�ѭ�������˼ά
	void Inverse(Node<T>*& head) {
		if (head == NULL) return;
		Node<T>  *q = head, *p = head->next, *r = NULL; //1,2,end
		while (p != NULL) {
			q->next = r;	//��ת 1->end , head �� end
			r = q;			//ָ��++�� end=1 ,end ��1
			q = p;			//ָ��++�� 1=2,  1 ��2
			p = p->next;	//ָ��++�� 2=3 , 2 ��3
		}
		q->next = r; // head �� end
		head = q; //head = q
	}
	//����p��ָ��������̽���������е�λ��
	int Reverse(Node<T>* head��Node<T>* p) {
		if (p->next == NULL) return 0;
		Node<T>* q = head;
		Node<T>* r;
		while (q->next != p)
			q = q->next; //p��ǰ��
		r = p->next; //p�ĺ��
		q->next = r; //1->3
		p->next = r->next;  //2->4
		r->next = p; //3->2
		return 1;
	}

	#pragma endregion !_Member Function Definition
};//class LinkList

