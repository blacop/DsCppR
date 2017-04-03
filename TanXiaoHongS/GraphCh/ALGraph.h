#pragma once
#include "stdafx.h"
//2 用邻接表存储的Graph类 声明

//class ALGraph {
//public:
//
//	ALGraph() {}
//
//	virtual ~ALGraph() {}
//};

//----------分隔线----------

//顶点向量数组，可以用SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //数组
}VertexType;

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

//2 用邻接表存储的Graph类 声明
//和弧相关的信息成员结构//弧边权值
typedef struct InfoType {
	int cost; //弧边权值
}InfoType;
//2 用邻接表存储的Graph类，弧边结点链表，表结点链表 声明
typedef struct ArcNode {
	int adjvex; //该弧所指顶点在数组中的位置（下标） data domain 1
	struct ArcNode* nextarc; //指向下一条弧 下一个邻接点 ref domain
	InfoType* info; //和弧相关的信息 //弧边权值 data domain 2
}ArcNode;
//顶点信息 顶点数组，头结点数组 结点定义
typedef struct VNode {
	VertexType data;  //顶点信息//顶点向量数组，可以用SeqList，data domain
	ArcNode* firstarc; //指向下一个邻接点 ref domain
}VNode, AdjList[MAX_VERTRIX_NUM];//顶点信息链表数组
								 //用邻接表存储的Graph类 声明
template<typename T>
class ALGraph {
public:
	AdjList vertices; //头结点数组
	int vexnum; //顶点数
	int arcnum; //边数
	int kind; //弧的类型

			  //采用邻接矩阵表示法构造有向图,构造方法
	bool CreateN(MGraph<T> &G) {
		//初始化邻接表 头结点表, 所有元素手动输入，顶点数，边数，结点信息（权值）
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//顶点数和边数
		for (int i = 0; i < &G.vexnum; ++i) {
			scanf(&G.vertices[i].data);//建顶点向量
			G.vertices[i].firstarc = NULL; //引用域置空
		}
		//读入弧并给邻接表 表边结点表 赋值
		for (int k = 0; k < G.arcnum; ++k) {
			//所有元素手动输入，顶点1值，顶点2值，权值
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1); //寻找结点1位置
			int j = LocateVex(G, v2); //寻找结点2位置
									  //2个点构成一条边
			p = new ArcNode(); //开辟新的表结点
			p.adjvex = j; //顶点的名称 为 v2
			p.nextarc = G.vertics.firstarc; //在头结点链表头部后面插入一个表结点 step1
			G.vertics.firstarc;  //在头结点链表头部后面插入一个表结点 step2
			if (IncInfo) Input(*p.info); //输入权值
		}
		return true;
	}//!_bool CreateN()
};//!_bool CreateN(MGraph<T> &G)

