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
//Graph类的声明
//顶点表中结点的结构
template<typename T>
struct Vertex {
	//友元类
	friend class Graph<T>;
	//顶点的名称
	T VerName;
	//边链表的头指针
	Edge* adjacent;
};

