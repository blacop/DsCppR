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

//邻接矩阵，全局变量,值为权
typedef struct AdjMatrix {
	int AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM];
}AdjMatrix;

//顶点向量类型，可以用int
typedef struct VertexType {
	//SeqList<int> VertexType;
	int VertexType; //int
}VertexType;

//用邻接矩阵存储的Graph类 声明
template <typename T, typename VRType, typename InfoType>
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

	 //深度优先遍历
	bool visited[MAX_VERTRIX_NUM]; //访问状态表
	bool(*VisitFunc)(int v);  //委托：访问结点	
							  //深度优先遍历
	void DFSTraverse(MGraph G, bool(*Visit(int v))) { //深度优先遍历 Tan
		VisitFunc = Visit; //委托：访问结点;委托赋值 访问函数
		for (int v = 0; v < G.vexnum; ++v)  //初始化 访问状态表
			visited[v] = false;
		for (int v = 0; v < G.vexnum; ++v) { //遍历 从第一个到最后一个邻接点
			if (!visited[v]) DFS(G, v);//深度优先遍历算法 重载 递归调用
		}
	}
	void DFS(MGraph G, int v) { //深度优先遍历算法 重载 递归调用
		visited[v] = true; //访问状态表更新
		VisitFunc(v); //委托调用
					  //找到第一个邻接点，w为true,找下一个邻接点
		for (int w = FirstAdjVex(G，v); w; w = NextAdjVex(G, v, w))
			if (!visited[w]) DFS(G, w); //深度优先遍历算法 重载 递归调用
	}

	//广度优先遍历 Tan 层次遍历的推广
	void BFSTravese(MGraph G, bool(*Visit(int v))) {
		for (int v = 0; v < G.vexnum; ++v)  //初始化 访问状态表
			visited[v] = false;
		InitQueue(Q); //new 队列
		for (int v = 0; v < G.vexnum; ++v)
			if (!visited[v]) { //检查到未访问，递归调用
				visited[v] = true; //访问状态表更新
				Visit(v); //访问结点
				EnQueue(Q, u); //入队
				while (!QueueEmpty(Q)) { //队列 非空
					DeQueue(Q, u); //出队
								   //找到第一个邻接点，w为true,找下一个邻接点
					for (int w = FirstAdjVex(G，v); w; w = NextAdjVex(G, v, w))
						if (!visited[w]) {
							visited[w] = true; //访问状态表更新
							Visit(w); //访问结点
							EnQueue(Q, w); //入队
						}//!_if
				}//!_while
			}//!_if
	}//!_BFSTravese

	//Prim算法
	void MiniSpanTree_Prim(MGraph G, VertexType u) {
		struct {//记录由顶点集U到V-U的代价最小的边的辅助数组定义
			VertexType adjvex;//顶点向量数组
			VRType lowcost; //顶点关系类型 ，可以用int//邻接矩阵，全局变量,值为权
							// 图：有边连接为1,无边连接为0 
				//网：有边权值，无边无穷大
		}closedge[MAX_VERTRIX_NUM];
		K = LocateVex(G, u); //定位u
		for (int j = 0; j < G.vexnum; ++j)
			if (j != k) closedge[j] = { u,G.arcs[k][j].adj };//顶点向量//邻接矩阵，全局变量,值为权
		closedge[k].lowcost = 0; //权值定为0
		for (int i = 1; i < G.vexnum; ++i) {
			k = mininum(closedge); //取最小权值
			printf(closedge[k].adjvex, G.vexs[k]); //输出 顶点向量 顶点向量数组
			closedge[k].lowcost = 0; //权值定为0
			for (int j = 0; j < G.vexnum; ++j)
				if (G.arcs[k][j].adj < closedge[j].lowcost) //邻接矩阵的
					closedge[j] = { G.vexs[k],G.arcs[k][j].adj };
		}

	}//!_MiniSpanTree_Prim()

};//!_class MGraph()



