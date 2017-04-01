#pragma once
#include "stdafx.h"

//template <typename T>
//class MGraph {
//public:
//
//	MGraph() {}
//
//	virtual ~MGraph() {}
//};

//用邻接矩阵存储的Graph类
//Graph类声明
#define INFINITY INT_MAX //整数最大值
#define MAX_VERTRIX_NUM 20 //顶点最大值
typedef enum {DG,DN,AG,AN} GraphKind;
//DG为有向图，DN为有向网
//AG为无向图，AN为无向网
typedef struct ArcCell {
	// 图：有边1,无边0 ，可以用int
	//网：有边权值，无边无穷大
	//VRType adj; 			
	//顶点表
	//InfoType *info //指向该弧相关信息指针 ，可以用顶点信息数组type[] *
}ArcCell;
//邻接矩阵
// AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM]; 
//用邻接矩阵存储的Graph类
//Graph类声明
typedef struct {
	//顶点向量
	//VertexType vexs[MAX_VERTRIX_NUM];
	////邻接矩阵
	//AdjMatrix arcs;
	//顶点数和边数
	int vexnum, arcnum;
	//图的类型
	GraphKind kind;
}MGraph;
