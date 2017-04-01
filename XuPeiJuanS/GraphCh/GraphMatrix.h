#pragma once
#include "stdafx.h"
#include "SeqList.h"

//1 用邻接矩阵存储的Graph类
//Graph类声明
//图的最大顶点个数
const int MaxGraphSize = 25;
template <typename T>
class GraphMatrix {
	//4个字段
private:
	//顶点表
	SeqList<T> VertexList;
	//邻接矩阵
	int edgeMatrix[MaxGraphSize][MaxGraphSize];
	//当前顶点数
	int graphsize;
	//当前边数
	int CurrentEdges;
	//2个私有方法

	//检查顶点vertex是否己在顶点表L中
	int FindVertex(SeqList<T>&L, const T& vertex);
	//返回顶点vertext在顶点表中的位置(序号)
	int GetVertexPos(const T& vertex);
	//3个构造方法
public:
	//构造器
	GraphMatrix(void) {
		//将邻接矩阵的所有元素设为0
		for (int i = 0; i < MaxGraphSize; i++)
			for (int j = 0; j < MaxGraphSize; j++)
				edgeMatrix[i][j] = 0;
		graphsize = 0;
	}
	//De构造器
	virtual ~GraphMatrix() {}
	//检测图是否为空
	int GraphEmpty(void) const {
		return VertexList.ListEmpty();
	}

	//以下是访问数据的方法 5个

	//返回图的顶点个数
	int NumberOfVertices(void) const {
		return graphsize;
	}
	//返回图的边个数
	int NumberOfEdges(void) const {
		return CurrentEdges;
	}
	//返回指定边的权值，v1到v2的边的权值
	int GetWeight(const T& vertex1, const T& vertex2);
	//返回序号为v的顶点的第一个邻接顶点的序号
	int GetFirstNeighbor(const int v) {
		for (int i = 0; i < graphsize; i++)
			//>0 表示有权值 并且 < int的无穷大，无穷大表示无连接
			if (edgeMatrix[v][i] > 0 && edgeMatrix[v][i] < std::numeric_limits<int>::max() ])
				return i;
		//如果找不到
		return -1;
	}
	//返回序号为v1的顶点相对于序号为v2的顶点开始的下一个邻接顶点的序号
	int GetNextNeighbor(const int v1, const int v2) {
		//保证顶点是存在的
		if (v1 != -1 && v2 != -1) {
			//v2的顶点开始的下一个邻接顶点的序号
			for (int i = v2 + 1; i < graphsize; i++)
				if (edgeMatrix[v1][i] > 0 && edgeMatrix[v1][i] < max)
					return i;
		}
		//如果找不到
		return -1;
	}

	//以下是修改图的方法 4个

	//插入一个顶点,vertex是顶点编号
	void InsertVertex(const T& vertex);
	//插入一条边(v1,v2),边权值为weight
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	//在图中删去顶点vertex和所有与它相关联的边
	void DeleteVertex(const T& vertex);
	//在图中删去边
	void DeleteEdge(const T& vertex1, const T& vertex2);

};//!_class Graph

