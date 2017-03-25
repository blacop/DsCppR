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

//C语言版
//二叉树 顺序存储结构
#define MAX_TREE_SIZE 100
//构造器
template <typename TElemType>
typedef TElemType SqBiTree[MAX_TREE_SIZE];

//声明一个class
template <typename TElemType>
SqBiTree bt;

