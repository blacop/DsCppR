#pragma once
#include "stdafx.h"
//无向图的多重链表存储形式定义

//用邻接矩阵存储的Graph类 声明
#define INFINITY std::numeric_limits<int>::max() //整数最大值
#define MAX_VERTRIX_NUM 20 //顶点最大值
typedef enum { DG, DN, AG, AN } GraphKind;//图的类型
//DG为有向图，DN为有向网
//AG为无向图，AN为无向网

//顶点向量数组，可以用SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //数组
}VertexType;

//2 用邻接表存储的Graph类 声明
//和弧相关的信息成员结构//弧边权值
typedef struct InfoType {
	int cost; //弧边权值
}InfoType;

//访问标识
typedef enum { unvisited, visited } VisitIf;
//邻接多重表结点
typedef struct Ebox {
	VisitIf mark; //访问标识
	int ivex, jvex;
	struct Ebox *ilink, *jlink;
	InfoType *info;
}Ebox;
//顶点表数组
typedef struct VexBox {
	VertexType data; //数据域
	Ebox *firstedge; //引用域
}VexBox;

//无向图的多重链表存储形式定义
template <typename T>
class AMLGraph {
public:
	VexBox adjmulist[MAX_VERTRIX_NUM]; //顶点表数组
	int vexnum; //顶点数
	int arcnum; //弧边数

	//AMLGraph() {}

	//virtual ~AMLGraph() {}
};