#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "Edge.h"
//class Graph {
//public:
//
//	Graph() {}
//
//	virtual ~Graph() {}
//};

//2 用邻接表存储的Graph类
//Graph类的声明
template<typename T> class Graph {
privata:
	Vertex<T> *head; //顶点表的头指针
	int graphsize; //当前顶点数
	int MaxGraphSize; //最大顶点数
	int NumEdge; //当前边数
	int MaxNumEdge; //最大边数

	//返回顶点vertex在顶点表中的序号
	int GetVertexPos(const T& vertex);

	//Graph类的实现
public:
	//构造函数
	Graph(const int sz = default)
		:graphsize(0), MaxGraphSize(sz), NumEdge(0) {
		//顶点个数，边数，权值
		int numGraphsize, edgeCount, weight;
		//顶点名字，起点，终点
		T name, from, to;
		//用数组实现顶点表，head指向数组的第一个元素
		head = new Vertex<T>[MaxGraphSize];

		cin >> numGraphsize; //输入顶点个数		
		for (int i = 0; i < numGraphsize; i++) { //依次输入顶点，插入图中
			cin >> name;
			InsertVertex(name);
		}

		cin >> edgeCount; //输入边的个数
		for (int i = 0; i < edgeCount; i++) { //依次输入各边
			//输入边的始点，终点和权值
			cin >> from >> to >> weight;
			//将边插入图中
			InsertEdge(from, to, weight);
		}
	}//!_Graph()
	virtual ~Graph() {} //析构函数

	//数据访问函数 2个

	//返回序号为v的顶点的第一个邻接顶点的序号，实际是建立邻接表的顶点表结点的结构
	int GetFirstNeighbor(const int v) {
		//保证此序号存在
		if (v != -1) {
			Edge<T>* p = head[v].Adjacent;
			int w = p->VerAdj;
			return w;
		}
		return -1;
	}
	//返回序号为v1的顶点相对于序号为v2的顶点开始的下一个邻接顶点的序号,实际是建立邻接表的边表结点的结构
	int GetNextNeighbor(const int v1, const int v2);

	//以下是修改图的方法 2个

	//插入一个顶点,vertex是顶点编号
	void InsertVertex(const T& vertex);
	//插入一条边(v1,v2),边权值为weight
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);

};//!_class Graph

