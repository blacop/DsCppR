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
//Graph类的声明
//边结点的结构
template<typename T>
struct Edge {
	//友元类
	friend class Graph<T>;
	//邻接顶点序号
	int VerAdj; 
	//边的权值
	int cost;
	//指向下一个边结点的指针
	Edge * link;
	//构造函数
	Edge() {};
	//构造函数
	Edge(int d, int c) :VerAdj(d), cost(c), link(NULL) {}
};
