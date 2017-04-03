#pragma once
#include "stdafx.h"
//有向图的十字链表存储形式说明

//class OLGraph {
//public:
//
//	OLGraph() {}
//
//	virtual ~OLGraph() {}
//};
//--------------------

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

//有向图的十字链表存储形式说明：
//边表结点
typedef struct ArcBox {
	int tailvex, headvex;
	struct ArcBox *hlink, *tlink;
	InfoType *info;
}ArcBox;
//头结点数组
typedef struct VexNode {
	VertexType data;
	ArcBox *firstin, *firstout;
}VexNode;
//有向图的十字链表存储形式说明
template <typename T>
class OLGraph {
public:
	VexNode xlist[MAX_VERTRIX_NUM]; //头结点数组
	int vexnum; //顶点数
	int arcnum; //弧边数
				//构造十字链表
	bool CreateOLG(OLGraph &G) {
		//初始化邻接表 头结点表, 所有元素手动输入，顶点数，边数，结点信息（权值）
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//顶点数,边数,结点信息（权值）
											   //初始化头结点数组
		for (int i = 0; i < &G.vexnum; ++i) {
			scanf(&G.xlist[i].data);//建顶点向量,输入数据
			G.xlist[i].firstin = NULL; //引用域置空
			G.xlist[i].firstout = NULL; //引用域置空			
		}
		//初始化边表结点 //读入弧并给邻接表 表边结点表 赋值
		for (int k = 0; k < G.arcnum; ++k) {
			//所有元素手动输入，顶点1值，顶点2值，权值
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1); //寻找结点1位置 头
			int j = LocateVex(G, v2); //寻找结点2位置 尾
									  //2个点构成一条边
			p = new ArcBox(); //开辟新的表结点
			p.tailvex = j; //尾顶点的名称 为 v2
			p.headvex = i; //头顶点的名称 为 v1
			p.tlink = G.xlist[i].firstout;//在out尾顶点链表头部后面插入一个表结点 step1
			G.xlist[i].firstout = p;  //在out尾顶点链表头部后面插入一个表结点 step2
			p.hlink = G.xlist[j].firstin; //在in头顶点链表头部后面插入一个表结点 step1
			G.xlist[j].firstin = p;	 //在in头顶点链表头部后面插入一个表结点 step2
			if (IncInfo) Input(*p.info); //输入权值
		}
		return true;
	}//!_bool CreateOLG()
};//!_class OLGraph


