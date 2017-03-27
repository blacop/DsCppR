#pragma once
#include "stdafx.h"
#include "BinTreeNode.h"
//��������BinTree������
template <typename TElemType>
class BinTree {
	//2������
private:
	//ָ������
	BinTreeNode<TElemType>* root;
	//����stopʱ����ֹ��������
	TElemType stop;

	//�ӽ��begin��ʼ���������ؽ��current�ĸ����
	BinTreeNode<TElemType>* father(BinTreeNode<TElemType>* begin, BinTreeNode<TElemType>* current);
	//11������
public:
	//Constructor(),���캯��--������һ�ö�����ʱ���г�ʼ��������һ�ÿ���
	BinTree() :root(NULL) {}
	//Constructor(),//����stopʱ����ֹ��������
	BinTree(TElemType mark) :root(NULL), stop(mark) {}
	//DeConstructor(),��������--ɾ�����ö�����
	virtual ~BinTree() { DelSubtree root; }
	//�ڵ�ǰ����λ�ò���һ�����
	int Insert(BinTreeNode<TElemType>*& current, const T& item);
	//�ӽ��current��ʼ����������ֵΪitem�Ľ�㣬���ر��
	int Find(BinTreeNode<TElemType>*& current, const T& item) const;
	//ɾ�����current������������
	void DelSubtree(BinTreeNode<TElemType>* current);

	////�ȸ�����������Խ��tΪ������
	//void Preorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////�и�����������Խ��tΪ������
	//void Inorder(BinTreeNode<TElemType>* t, ostrem& out)const;
	////�������������Խ��tΪ������
	//void Postorder(BinTreeNode<TElemType>* t, ostrem& out)const;

	//�ж϶������Ƿ�Ϊ��
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}

	//������˳����һ�ö�����
	void CreateBiTree(BiTree<TElemType>& T);

	//��������������ĵݹ��㷨1
	Status PreOrderTraverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return OK;
	}
	//��������������ĵݹ��㷨2
	//����㷨�д�������û�У��������ͽ���ȥ��
	Status PreOrderTraverse2(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType)) {
		if (T != NULL) {
			if (Visit(T->data))
				//����㷨�д�������û�У��������ͽ���ȥ��
				if (PreOrderTraverse(T->left, Visit(T->data)))
					if (PreOrderTraverse(T->right, Visit(T->data))) return OK;
			return ERROR; //!_else if (!Visit(T->data))
		} else return OK;
	}

	//�и�����������Խ��tΪ������,�ǵݹ��㷨���Խ�ջ
	Status InOrderTrverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType)) {}
	//�������������Խ��tΪ������
	Status PostOrderTrverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType));
	//��α���������
	Status LevelOrderTraverse(BinTreeNode<TElemType>* T, Status(*Visit)(TElemType));

	//���ʽ��
	Status Visit(TElemType e) {
		if (!e) {
			return FALSE;
		}
		//cout << t->data);
		PrintElement(TElemType e);
		return TRUE;
	}

	//������
	Status PrintElement(TElemType e) {
		printf(e);
		return OK;
	}

};//!_class BinTree



