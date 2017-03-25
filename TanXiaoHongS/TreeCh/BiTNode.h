#pragma once
#include "stdafx.h"

//C语言
//二叉链表的定义
template <typename TElemType>
class BiTNode {
private:
	TElemType data;
	BiTNode *lchild, *rchild;
public:

	BiTNode() {}

	virtual ~BiTNode() {}
};

template <typename TElemType>
typedef BiTNode<TElemType>* BiTree;
