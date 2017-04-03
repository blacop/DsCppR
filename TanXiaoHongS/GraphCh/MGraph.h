#pragma once
#include "stdafx.h"
//上交大，代码本身就有错,是伪代码
//用邻接矩阵存储的Graph类 声明

//template <typename T>
//class MGraph {
//public:
//
//	MGraph() {}
//
//	virtual ~MGraph() {}
//};

//用邻接矩阵存储的Graph类 声明
#define INFINITY std::numeric_limits<int>::max() //整数最大值
#define MAX_VERTRIX_NUM 20 //顶点最大值
typedef enum { DG, DN, AG, AN } GraphKind;//图的类型
//DG为有向图，DN为有向网
//AG为无向图，AN为无向网

//用邻接矩阵存储的Graph类
//表边弧结点单元的结构
//表示邻接表的边结点
template <typename T, typename VRType, typename InfoType>
class ArcCell {
public:
	VRType adj; // 图：有边连接为1,无边连接为0 ，可以用int
				//网：有边权值，无边无穷大
	InfoType* info;//顶点表 //指向该弧相关信息指针 ，可以用顶点信息数组type[] *
};

//邻接矩阵，全局变量
typedef struct AdjMatrix {
	int AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM];
}AdjMatrix;

//顶点向量数组，可以用SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //数组
}VertexType;

//用邻接矩阵存储的Graph类 声明
template <typename T>
class MGraph {
public:
	VertexType vexs[MAX_VERTRIX_NUM]; //顶点向量数组，可以用SeqList	
	AdjMatrix arcs; //邻接矩阵，矩阵的定义在外部
	int vexnum; //当前顶点数
	int arcnum; //边数
	GraphKind kind; //图的类型

	//构造方法
	MGraph() {
		vexs = new int[MAX_VERTRIX_NUM]; //动态分配数组
		//将邻接矩阵的所有元素设为0
		for (int i = 0; i < MAX_VERTRIX_NUM; i++)
			for (int j = 0; j < MAX_VERTRIX_NUM; j++)
				arcs[i][j] = 0;
		vexnum = 0;
	}

	//采用邻接矩阵表示法构造有向图,构造方法
	bool CreateDG(MGraph<T> &G) {
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//顶点数和边数
		for (int i = 0; i < &G.vexnum; ++i) scanf(&G.vexs[i]);//建顶点向量
		//初始化邻接矩阵，将邻接矩阵的所有元素设为0
		for (int i = 0; i < &G.vexnum; i++)
			for (int j = 0; j < &G.vexnum; j++)
				G.arcs[i][j] = { INFINITY,NULL }; //这里是把 邻接矩阵 和邻接表 混在一起了
		//读入弧并给邻接矩阵赋值
		for (int k = 0; k < &G.arcnum; ++k) {
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1);
			int j = LocateVex(G, v2);
			G.arcs[i][j].adj = w; //这里是把 邻接矩阵 和邻接表 混在一起了
			if (IncInfo) Input(*G.arcs[i][j].info); //这里是把 邻接矩阵 和邻接表 混在一起了
		}
		return true;
	}//!_bool CreateDG()
};//!_class MGraph()



