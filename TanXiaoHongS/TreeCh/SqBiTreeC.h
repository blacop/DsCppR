#pragma once
#include "stdafx.h"

//class SqBiTreeC {
//private:
//	TElemType[MAX_TREE_SIZE] head;
//	int length;
//public:
//	SqBiTreeC() {}
//	virtual ~SqBiTreeC() {}
//};

//C���԰�
//������ ˳��洢�ṹ
#define MAX_TREE_SIZE 100
//������
template <typename TElemType>
typedef TElemType SqBiTree[MAX_TREE_SIZE];

//����һ��class
template <typename TElemType>
SqBiTree bt;

