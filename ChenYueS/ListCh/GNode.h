//浙大结构体
#pragma once
#include "stdafx.h"

//广义表链表
template <typename T>
typedef class GNode<T> *GList;
//广义表链表结点
template <typename T>
class GNode {
public:
	int Tag;//标志域：0表示结点是单元素，1表示结点是广义表
	union { //子表指针域Sublist与单元素数据域Data复用，即共用存储空间
		T data;
		GList SubList;
	}URegion;
	GList Next; //指向后继结点

	GNode() {}
	virtual ~GNode() {}
};



