#pragma once
#include "stdafx.h"

//C++版
//二叉树 顺序存储结构
template <typename TElemType>
class SqBiTree {
private:
	TElemType* data; //表元素数组
	int last;	//工作指针
	int MAX_TREE_SIZE; //最大元素个数
	
public:
	//构造器
	SqBiTree(int MaxSize) {
		MAX_TREE_SIZE = MaxSize;
		data = new TElemType[MAX_TREE_SIZE]; //动态分配数组
		last = -1; //工作指针
	}

	virtual ~SqBiTree() {}
};

//声明一个class
template <typename TElemType>
SqBiTree bt;




