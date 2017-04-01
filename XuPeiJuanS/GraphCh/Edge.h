#pragma once
#include "stdafx.h"
//class Edge {
//public:
//
//	Edge() {}
//
//	virtual ~Edge() {}
//};

//2 用邻接表存储的Graph类
//边结点的结构
template<typename T>
struct Edge {
	//友元类
	friend class Graph<T>;

	int VerAdj; //此邻接顶点序号	data domain 1
	int cost;	//此边的权值	data domain 2
	Edge* link; //指向下一个边结点的指针 ref domain

	//构造函数
	Edge<T>(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
};
