#pragma once
#include "stdafx.h"
#include "Edge.h"
//class Vertex {
//public:
//
//	Vertex() {}
//
//	virtual ~Vertex() {}
//};

//2 用邻接表存储的Graph类
//顶点表中结点的结构
template<typename T>
struct Vertex {
	//友元类
	friend class Graph<T>;

	T VerName; //顶点的名称 	data domain ,store node value
	Edge<T>* adjacent; //边链表的头指针 ref domain
};

