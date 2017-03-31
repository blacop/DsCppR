#pragma once
#include "stdafx.h"
#include "bithrnode.h"
#include "Stack.h"
#include "Queue.h"
//������������bithrtree������
template <typename T, typename TElemType>
class bithrtree {
private:
	//ָ������	
	bithrnode<T>* root;
	//����stopʱ����ֹ��������
	T stop;
	//�ӽ��begin��ʼ���������ؽ��current�ĸ����
	bithrnode<T>* father(bithrnode<T>* begin, bithrnode<T>* current);
	//10������
public:
	//Constructor()
	bithrtree() :root(new bithrnode()) {}
	//Constructor(),���캯��--������һ�ö�����ʱ���г�ʼ��������һ�ÿ���
	bithrtree() :root(NULL) {}
	//Constructor(),//����stopʱ����ֹ��������
	bithrtree(T mark) :root(NULL), stop(mark) {}
	//DeConstructor(),��������--ɾ�����ö�����
	virtual ~bithrtree() { DelSubtree root; }
	//�ڵ�ǰ����λ�ò���һ�����
	int Insert(bithrnode<T>*& current, const T& item);
	//�ӽ��current��ʼ����������ֵΪitem�Ľ�㣬���ر��
	int Find(bithrnode<T>*& current, const T& item) const;
	//ɾ�����current������������
	void DelSubtree(bithrnode<T>* current);
	//�ȸ�����������Խ��tΪ������
	void Preorder(bithrnode<T>* t, ostrem& out)const;
	//�и�����������Խ��tΪ������
	void Inorder(bithrnode<T>* t, ostrem& out)const;
	//�������������Խ��tΪ������
	void Postorder(bithrnode<T>* t, ostrem& out)const;
	//�ж϶������Ƿ�Ϊ��
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}
	//���������,������������Ӧ��,
	void countleaf(bithrnode<T>* t, int& count) {
		if (t != NULL) {
			if ((t->left == NULL) && (t->right == NULL))
				count++;
			countleaf(t->left, count);
			countleaf(t->right, count);
		}
	}
	//������������ÿ����������Ů������Ů,����ɣ�����ɣ����򲻿�
	void exchange(bithrnode<T>* t) {
		bithrnode<T>* temp;
		if ((t->left != NULL) || (t->right != NULL)) {
			temp = t->left;
			t->left = t->right;
			t->right = temp;
			exchange(t->left);
			exchange(t->right);
		}
	}
	//ɾ�����current�������������������
	void DelSubtree(bithrnode<T>* current) {
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
	bool PreOrderTraverseRec(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return true;
	}
	//�ȸ�����������Խ��tΪ������,�ǵݹ��㷨���Խ�ջ
	bool PreOrderTrverse(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T; //��ʱָ��
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
	bool InOrderTrverse(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T; //��ʱָ��
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
	bool PostOrderTrverse(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T; //��ʱָ��
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

	//˫��ѭ����������Ķ�������������㷨, ������ͷ��������������,T��ͷ��㣬*Visit�Ǻ���ָ��
	bool InOrderTraverse_Thr(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T->left; //��ͷ��������������,�ҵ����ڵ�
		while (p != T) { //p=T ��ʾ����ĩβ�����µ���ͷ���
			while (p->LTag == link)  //link��ʾһֱ�����ң��ҵ������ĵ�һ���ڵ�
				p = p->left;
			//else if (p->link && p->right == thread) //��ʾ�����������Ѿ���Ҷ�ӽڵ�
			Visit(p->data); //�������Ҷ�ӽڵ㣬���������ĵ�һ���ڵ㣬���ڵ㣬��̽ڵ�
			while (p->right == thread && p->right != T) { //thread��ʾ�������������Һ�̽ڵ�
				p = p->right; //������һ����̽ڵ�
				Visit(p->data); //����˺�̽ڵ㣬������ڵ�
			}
			//else if(p->right == link) //��ʾ��������
			p = p->right; //�������������
		}
		return OK;
	}

	//��������������н�����������������:
	//�Ƚ���һ��ͷ���thrt ������ʶ����� ��һ��ָ��preָ��ոշ��ʹ��Ľ��

	//����������������������������,c���԰棬����һ�������ڱ�ͷ���
	int inorder_threading(bithrtree *thrt, bithrtree bt) {
		bithrtree pre;
		*thrt = (bithrtree)malloc(sizeof(bithrnode));//���ٸ����ڱ�ͷ����ڴ�ռ�
		if (!*thrt)
			exit(OVERFLOW);
		/* ��ͷ��������� */
		(*thrt)->ltag = link;
		(*thrt)->rtag = thread;
		(*thrt)->rchild = (*thrt);

		if (!bt)                      /* ��������Ϊ�գ���lchildָ���Լ� */
			(*thrt)->lchild = (*thrt);
		else {
			(*thrt)->lchild = bt;      /* ͷ�����ָ��ָ������ */
			pre = (*thrt);
			in_threading(bt);          /* ��������������������� */
			pre->rchild = *thrt;
			pre->rtag = thread;
			(*thrt)->rchild = pre;
		}
		return OK;
	}
	/* ��������������������� */
	void in_threading(bithrtree t) {
		if (t) {
			in_threading(t->lchild);

			if (!t->lchild) {
				t->ltag = thread;
				t->lchild = pre;
			}
			if (!pre->rchild) {
				pre->rtag = thread;
				pre->rchild = t;
			}
			pre = t;
			in_threading(t->rchild);
		}
	}
	
	//��������������н�����������������:
	//�Ƚ���һ��ͷ���thrt ������ʶ����� ��һ��ָ��preָ��ոշ��ʹ��Ľ��
	bool InOrderthreading(bithrnode<T>*& Thrt, bithrnode<T>*& pre) {
		if (!Thrt = new bithrnode<T>())
			exit(overflow_error);
		Thrt->LTag = link; //��ʼ��ͷ���
		Thrt->RTag = thread;
		Thrt->right = Thrt;
		if (!T) //���������ͷ����leftҲָ��ͷ���
			Thrt->left = T;
		pre = Thrt;
		bithrnode<T>* p = T; //�˽��
		Stack<T> S = new Stack<T>();
		S.Push(S, p);
		while (p || S.IsEmpty()) {
			if (p) {
				S.Push(S, p);
				p = p->left;
			} else {
				S.Pop(p);
				p->LTag = thread;
				p->left = pre;
				if (!pre->right) {
					pre->RTag = thread;
					pre->right = p;
				}
				pre = p;
				p = p->right;
			}
		}
		pre->right = Thrt;
		pre->RTag = thread;
		Thrt->right = pre;
		return true;
	}

};//!_class bithrtree

  //�ȸ�����������Խ��tΪ���������ݹ��㷨
template<typename T>
inline void bithrtree<T>::Preorder(bithrnode<T>* t, ostrem & out) const {
	if (t != NULL) {
		cout << t->data;		//bool(*visit)(TElemType) root node
		Preorder(t->left, out);	//enter left subtree		
		Preorder(t->right, out); //enter right subtree
	}
}

//�и�����������Խ��tΪ��������const��ʾ����Ƿ��ʺ����������޸Ľ�㣬�ݹ��㷨
template<typename T>
inline void bithrtree<T>::Inorder(bithrnode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Inorder(t->left, out);	//enter left subtree
		cout << t->data;		//bool(*visit)(TElemType) root node
		Inorder(t->right, out); //enter right subtree
	}
}

//�������������Խ��tΪ���������ݹ��㷨
template<typename T>
inline void bithrtree<T>::Postorder(bithrnode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Postorder(t->left, out);	//enter left subtree		
		Postorder(t->right, out); //enter right subtree
		cout << t->data;		//bool(*visit)(TElemType) root node
	}
}

