#pragma once
#include "stdafx.h"

//C++��
//������ ˳��洢�ṹ
template <typename TElemType>
class SqBiTree {
private:
	TElemType* data; //��Ԫ������
	int last;	//����ָ��
	int MAX_TREE_SIZE; //���Ԫ�ظ���
	
public:
	//������
	SqBiTree(int MaxSize) {
		MAX_TREE_SIZE = MaxSize;
		data = new TElemType[MAX_TREE_SIZE]; //��̬��������
		last = -1; //����ָ��
	}

	virtual ~SqBiTree() {}
};

//����һ��class
template <typename TElemType>
SqBiTree bt;




