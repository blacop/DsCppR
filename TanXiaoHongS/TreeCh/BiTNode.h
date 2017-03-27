#pragma once
#include "stdafx.h"
//template <typename TElemType>
//typedef BiTNode<TElemType>* BiTree<TElemType>;

//Cpp����
//��������Ķ���
template <typename TElemType>
class BiTNode {
public:
	//data domain
	TElemType data;
	//ref domain
	BiTNode *lchild, *rchild;
	//�޲ι�����, �ú���ָ��ʵ�� ��Ա����	
	BiTNode() {}
	//De������()
	virtual ~BiTNode() {}	
	
	////�ȸ�����������Խ��tΪ������
	//void Preorder(BiTree<TElemType>* t, ostrem& out)const;
	////�и�����������Խ��tΪ������
	//void Inorder(BiTree<TElemType>* t, ostrem& out)const;
	////�������������Խ��tΪ������
	//void Postorder(BiTree<TElemType>* t, ostrem& out)const;

	//������˳����һ�ö�����
	void CreateBiTree(BiTree<TElemType>& T);
	//�ȸ�����������Խ��tΪ������
	void PreOrderTrverse(BiTree T);
	//�и�����������Խ��tΪ������
	void InOrderTrverse(BiTree T);
	//�������������Խ��tΪ������
	void PostOrderTrverse(BiTree T);
	//��α���������
	void LevelOrderTraverse(BiTNode* T);
};




