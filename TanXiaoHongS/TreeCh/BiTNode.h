#pragma once
#include "stdafx.h"

//C����
//��������Ķ���
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
