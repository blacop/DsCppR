#pragma once
#include "stdafx.h"
#include "BiThrNode.h"
#include "Stack.h"
//������������BiThrTree������
template <typename T, typename TElemType>
class BiThrTree {
private:
	//ָ������
	BiThrTreeNode<T>* root;
	//����stopʱ����ֹ��������
	T stop;
	//�ӽ��begin��ʼ���������ؽ��current�ĸ����
	BiThrTreeNode<T>* father(BiThrTreeNode<T>* begin, BiThrTreeNode<T>* current);
	//10������
public:
	//Constructor(),���캯��--������һ�ö�����ʱ���г�ʼ��������һ�ÿ���
	BiThrTree() :root(NULL) {}
	//Constructor(),//����stopʱ����ֹ��������
	BiThrTree(T mark) :root(NULL), stop(mark) {}
	//DeConstructor(),��������--ɾ�����ö�����
	virtual ~BiThrTree() { DelSubtree root; }
	//�ڵ�ǰ����λ�ò���һ�����
	int Insert(BiThrTreeNode<T>*& current, const T& item);
	//�ӽ��current��ʼ����������ֵΪitem�Ľ�㣬���ر��
	int Find(BiThrTreeNode<T>*& current, const T& item) const;
	//ɾ�����current������������
	void DelSubtree(BiThrTreeNode<T>* current);
	//�ȸ�����������Խ��tΪ������
	void Preorder(BiThrTreeNode<T>* t, ostrem& out)const;
	//�и�����������Խ��tΪ������
	void Inorder(BiThrTreeNode<T>* t, ostrem& out)const;
	//�������������Խ��tΪ������
	void Postorder(BiThrTreeNode<T>* t, ostrem& out)const;
	//�ж϶������Ƿ�Ϊ��
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}
	//���������,������������Ӧ��,
	void countleaf(BiThrTreeNode<T>* t, int& count) {
		if (t != NULL) {
			if ((t->left == NULL) && (t->right == NULL))
				count++;
			countleaf(t->left, count);
			countleaf(t->right, count);
		}
	}
	//������������ÿ����������Ů������Ů,����ɣ�����ɣ����򲻿�
	void exchange(BiThrTreeNode<T>* t) {
		BiThrTreeNode<T>* temp;
		if ((t->left != NULL) || (t->right != NULL)) {
			temp = t->left;
			t->left = t->right;
			t->right = temp;
			exchange(t->left);
			exchange(t->right);
		}
	}
	//ɾ�����current�������������������
	void DelSubtree(BiThrTreeNode<T>* current) {
		if (current != NULL) {
			DelSubtree(current->left);
			DelSubtree(current->right);
			delete current;
		}
	}
	//������˳����һ�ö�����
	void CreateBiTree(BiTree<T>& T);

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

	//��������������ĵݹ��㷨1
	bool PreOrderTraverseRec(BiThrTreeNode<T>* T, bool(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return true;
	}
	//�ȸ�����������Խ��tΪ������,�ǵݹ��㷨���Խ�ջ
	bool PreOrderTrverse(BiThrTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BiThrTreeNode<T>* p = T; //��ʱָ��
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
	bool InOrderTrverse(BiThrTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BiThrTreeNode<T>* p = T; //��ʱָ��
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
	bool PostOrderTrverse(BiThrTreeNode<T>* T, bool(*Visit)(TElemType)) {
		BiThrTreeNode<T>* p = T; //��ʱָ��
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
	//��α���������
	bool LevelOrderTraverse(BiThrTreeNode<T>* T, bool(*Visit)(TElemType));

	//˫��ѭ����������Ķ�������������㷨, ������ͷ��������������,T��ͷ��㣬*Visit�Ǻ���ָ��
	bool InOrderTraverse_Thr(BiThrNode<T>* T, bool(*Visit)(TElemType)) {
		BiThrNode<T>* p = T->left; //��ͷ��������������,�ҵ����ڵ�
		while (p != T) { //p=T ��ʾ����ĩβ�����µ���ͷ���
			while (p->LTag == Link)  //Link��ʾһֱ�����ң��ҵ������ĵ�һ���ڵ�
				p = p->left;
			//else if (p->Link && p->right == Thread) //��ʾ�����������Ѿ���Ҷ�ӽڵ�
			Visit(p->data); //�������Ҷ�ӽڵ㣬���������ĵ�һ���ڵ㣬���ڵ㣬��̽ڵ�
			while (p->right == Thread && p->right != T) { //Thread��ʾ�������������Һ�̽ڵ�
				p = p->right; //������һ����̽ڵ�
				Visit(p->data); //����˺�̽ڵ㣬������ڵ�
			}
			//else if(p->right == Link) //��ʾ��������
			p = p->right; //�������������
		}
		return OK;
	}

};//!_class BiThrTree

  //�ȸ�����������Խ��tΪ���������ݹ��㷨
template<typename T>
inline void BiThrTree<T>::Preorder(BiThrTreeNode<T>* t, ostrem & out) const {
	if (t != NULL) {
		cout << t->data;		//bool(*visit)(TElemType) root node
		Preorder(t->left, out);	//enter left subtree		
		Preorder(t->right, out); //enter right subtree
	}
}

//�и�����������Խ��tΪ��������const��ʾ����Ƿ��ʺ����������޸Ľ�㣬�ݹ��㷨
template<typename T>
inline void BiThrTree<T>::Inorder(BiThrTreeNode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Inorder(t->left, out);	//enter left subtree
		cout << t->data;		//bool(*visit)(TElemType) root node
		Inorder(t->right, out); //enter right subtree
	}
}

//�������������Խ��tΪ���������ݹ��㷨
template<typename T>
inline void BiThrTree<T>::Postorder(BiThrTreeNode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Postorder(t->left, out);	//enter left subtree		
		Postorder(t->right, out); //enter right subtree
		cout << t->data;		//bool(*visit)(TElemType) root node
	}
}

