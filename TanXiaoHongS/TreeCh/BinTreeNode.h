#pragma once
#include "stdafx.h"
//�����������
template <typename T>
class BinTreeNode {
	//��Ԫ��, �����private member˽�г�Ա�ɱ���Ԫ�����
	friend class BinTree;
private:
	//ref domain ������
	BinTreeNode<T>* left;
	BinTreeNode<T>* right;	
	//6������
public:
	//data domain ������
	T data;

	//��������
	BinTreeNode<T>* GetLeft(void) const {
		return left;
	}
	//�����Ӹ���Ϊ���L
	void SetLeft(BinTreeNode<T>* L) {
		left = L;
	}

	//�����Һ���
	BinTreeNode<T>* GetRight(void) const {
		return right;
	}	
	//���Һ��Ӹ���Ϊ���R
	void SetRight(BinTreeNode<T>* R) {
		right = R;
	}

	//���캯��,Constructor()
	BinTreeNode(const T& item, BinTreeNode<T>* lptr = NULL, BinTreeNode<T>* rptr = NULL)
		:data(item), left(lptr), right(rptr) {}

	//Deconstructor()
	virtual ~BinTreeNode() {}

};//!_class BinTreeNode

