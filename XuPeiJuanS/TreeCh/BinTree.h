#pragma once
#include "stdafx.h"
#include "BinTreeNode.h"
#include "Stack.h"
//��������BinTree������
template <typename T, typename TElemType>
class BinTree {
	//3����
private:
	//ָ������
	BinTreeNode<T>* root;
	//����stopʱ����ֹ��������
	T stop;
	//�ӽ��begin��ʼ���������ؽ��current�ĸ����
	BinTreeNode<T>* father(BinTreeNode<T>* begin, BinTreeNode<T>* current);

public:
	//Constructor()
	BinTree() :root(new BinTreeNode()) {}
	//Constructor(),���캯��--������һ�ö�����ʱ���г�ʼ��������һ�ÿ���
	BinTree() :root(NULL) {}
	//Constructor(),//����stopʱ����ֹ��������
	BinTree(T mark) :root(NULL), stop(mark) {}
	//DeConstructor(),��������--ɾ�����ö�����
	virtual ~BinTree() { DelSubtree root; }
	//�ڵ�ǰ����λ�ò���һ�����
	int Insert(BinTreeNode<T>*& current, const T& item);
	//�ӽ��current��ʼ����������ֵΪitem�Ľ�㣬���ر��
	int Find(BinTreeNode<T>*& current, const T& item) const;
	//ɾ�����current������������,�����㷨
	void DelSubtree(BinTreeNode<T>* current) {
		BinTreeNode<T>* t = current; //tempPtr
		if (t != NULL) {
			Postorder(t->left, out);	//enter left subtree		
			Postorder(t->right, out); //enter right subtree
			delete t;		//delete() root node
		}
	}
	//�ȸ�����������Խ��tΪ���������ݹ��㷨
	void Preorder(BinTreeNode<T>* t, ostrem & out)const {
		if (t != NULL) {
			cout << t->data;		//visit() root node
			Preorder(t->left, out);	//enter left subtree		
			Preorder(t->right, out); //enter right subtree
		}
	}
	//�и�����������Խ��tΪ��������const��ʾ����Ƿ��ʺ����������޸Ľ�㣬�ݹ��㷨
	void Inorder(BinTreeNode<T>* t, ostrem & out)const {
		if (t != NULL) {
			Inorder(t->left, out);	//enter left subtree
			cout << t->data;		//visit() root node
			Inorder(t->right, out); //enter right subtree
		}
	}
	//�������������Խ��tΪ���������ݹ��㷨
	void Postorder(BinTreeNode<T>* t, ostrem & out)const {
		if (t != NULL) {
			Postorder(t->left, out);	//enter left subtree		
			Postorder(t->right, out); //enter right subtree
			cout << t->data;		//visit() root node
		}
	}
	//�ж϶������Ƿ�Ϊ��
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}
	//���������,������������Ӧ��,
	void countleaf(BinTreeNode<T>* t, int& count) {
		if (t != NULL) {
			if ((t->left == NULL) && (t->right == NULL))
				count++;
			countleaf(t->left, count);
			countleaf(t->right, count);
		}
	}
	//������������ÿ����������Ů������Ů,����ɣ�����ɣ����򲻿�
	void exchange(BinTreeNode<T>* t) {
		BinTreeNode<T>* temp;
		if ((t->left != NULL) || (t->right != NULL)) {
			temp = t->left;
			t->left = t->right;
			t->right = temp;
			exchange(t->left);
			exchange(t->right);
		}
	}
	//ɾ�����current�������������������
	void DelSubtree(BinTreeNode<T>* current) {
		if (current != NULL) {
			DelSubtree(current->left);
			DelSubtree(current->right);
			delete current;
		}
	}
	//������˳����һ�ö�����
	void CreateBiTree(BiTree<T>& T);
	//��������������ĵݹ��㷨1
	bool PreOrderTraverseRec(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return true;
	}

	//�ȸ�����������Խ��tΪ������,�ǵݹ��㷨���Խ�ջ
	bool PreOrderTrverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BinTreeNode<T>* p = T; //��ʱָ��
		Stack<T> S = new Stack<T>(); //�ǵݹ��㷨���Խ�ջ,����ջ��������ʵ���ֶ��ݹ�		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) {
				Visit(p->data); //���ʸ����
				push(S, p);		//�������ջ
				p = p->left;	//����������
			} else {	 //������ջ������������
				pop(S, p);
				p = p->right;
			}//else
		}//while
		return true;
	}

	//�и�����������Խ��tΪ������,�ǵݹ��㷨���Խ�ջ
	bool InOrderTrverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BinTreeNode<T>* p = T; //��ʱָ��
		Stack<T> S = new Stack<T>(); //�ǵݹ��㷨���Խ�ջ,����ջ��������ʵ���ֶ��ݹ�		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) { //�������ջ������������
				push(S, p);
				p = p->left;
			} else {  //������ջ�����ʸ���㣬����������
				pop(S, p);
				Visit(p->data);
				p = p->right;
			}//else
		}//while
		return true;
	}
	//�������������Խ��tΪ������,�ǵݹ��㷨���Խ�ջ
	bool PostOrderTrverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BinTreeNode<T>* p = T; //��ʱָ��
		Stack<T> S = new Stack<T>(); //�ǵݹ��㷨���Խ�ջ,����ջ��������ʵ���ֶ��ݹ�		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) { //�������ջ������������
				push(S, p);
				p = p->left;
			} else {   //������ջ������������
				pop(S, p);
				p = p->right;
				Visit(p->data);//���ʸ����
			}//else
		}//while
		return true;
	}

	//��α��������� ���ȸ�����
	bool LevelOrderTraverse(BinTreeNode<T>* T, bool(*Visit)(TElemType)) {
		Queue<TElemType> Q = new Queue<TElemType>(); //�½�����
		BinTreeNode<TElemType>* p; //����Ԫ��
		if (T != nullptr)  Q.EnQueue(Q, T); //��� root
		while (!Q.IsEmpty()) {
			Q.DeQueue(Q, p); //���� root
			Visit(p->data); //visit() root
			if (p->left != nullptr) Q.EnQueue(Q, p->left);
			if (p->right != nullptr) Q.EnQueue(Q, p->right);
		}
	}
	//�ж��Ƿ�Ϊ��ȫ������,��α���
	bool IsFullTree(BinTreeNode<T>* T) {
		Queue<TElemType> Q = new Queue<TElemType>(); //�½�����
		BinTreeNode<TElemType>* p; //����Ԫ��
		int tag = 1;
		if (T != nullptr) Q.EnQueue(Q, T); //��� root
		while (!Q.IsEmpty() && tag != 0) {
			Q.DeQueue(Q, p); //���� root
			//Visit(p->data); //visit() root
			if (p->left != nullptr) {
				Q.EnQueue(Q, p->left);
				if (p->right != nullptr)
					Q.EnQueue(Q, p->right);
				else tag = 0; //���Ӵ��� //�Һ��Ӳ�����
			} else { //���Ӳ����� //�Һ��Ӵ���
				tag = 0;
				if (p->right)
					return false;
			}
		}//!_WHILE
		 //������Һ������Ӵ��ڣ����ź�ÿһ����㶼��Ӧ�ô��ں��ӽ�㣬�����Ȼ������ȫ������
		while (!!Q.IsEmpty()) {
			Q.DeQueue(Q, p);
			if ((p->left) || (p->right))
				return false;
		}
		return true;
	}
	//���ʽ��Func
	typedef bool(*VisitFunc)(TElemType) {
		PrintElement(e);
		return true;
	};
	//���ʽ��Ԫ��
	bool Visit(TElemType e) {
		if (!e) return false;
		PrintElement(T e); //cout << t->data;
		return true;
	}
	//������Ԫ��
	bool PrintElement(TElemType e) {
		if (!e) return false;
		cout << e;	   //printf(e);
		return true;
	}
	//����������������������Ľ���������
	bool PostMarkTaverse(BinTreeNode<T>* T) {

	}
};//!_class BinTree


