#pragma once
#include "stdafx.h"
#include "SeqList.h"

//1 用邻接矩阵存储的Graph类
//Graph类声明
//图的最大顶点个数
const int MaxGraphSize = 25;
template <typename T>
class Graph {
private:
	//顶点表
	SeqList<T> VertexList;
	//邻接矩阵
	int edge[MaxGraphSize][MaxGraphSize];
	//当前顶点数
	int graphsize;
	//当前边数
	int CurrentEdges;
	//检查顶点vertex是否己在顶点表L中
	int FindVertex(SeqList<T>&L, const T& vertex);
	//返回顶点vertext在顶点表中的位置(序号)
	int GetVertexPos(const T& vertex)
public:
	//构造器
	Graph(void);
	//De构造器
	virtual ~Graph() {}
	//检测图是否为空
	int GraphEmpty(void) const {
		return VertexList.ListEmpty();
	}
	//以下是访问数据的方法
	//返回图的顶点个数
	int NumberOfVertices(void) const {
		return graphsize;
	}
};//!_class Graph

