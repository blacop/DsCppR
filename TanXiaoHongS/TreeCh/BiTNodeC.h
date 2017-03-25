//#pragma once
//class BiTNodeC {
//public:
//
//	BiTNodeC() {}
//
//	virtual ~BiTNodeC() {}
//};

#pragma once
#include "stdafx.h"

//C语言
//二叉链表的定义
template <typename TElemType>
typedef struct Node {
	TElemType data;
	BiTNode *lchild, *rchild;

	BiTNode() {}
	virtual ~BiTNode() {}
};

template <typename TElemType>
typedef Node BiTNode;

template <typename TElemType>
typedef Node* BiTree;


