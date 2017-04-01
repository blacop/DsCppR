#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "Edge.h"
#include "Queue.h"
//class Graph {
//public:
//
//	Graph() {}
//
//	virtual ~Graph() {}
//};

//2a  用邻接表存储的Graph类
//顶点表结点的结构
template<typename T>
struct Vertex {
	//友元类
	friend class Graph<T>;

	T VerName; //顶点的名称 	data domain ,store node value
	Edge* adjacent; //边链表的头指针 ref domain
};

//2b 用邻接表存储的Graph类
//边表结点的结构
template<typename T>
struct Edge {
	//友元类
	friend class Graph<T>;

	int VerAdj; //此邻接顶点序号	data domain 1
	int cost;	//此边的权值	data domain 2
	Edge* link; //指向下一个边结点的指针 ref domain

	////构造函数
	//Edge<T>() {}
	//构造函数
	Edge<T>(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
};

//2 用邻接表存储的Graph类
//Graph类的声明
template<typename T>
class Graph {
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
	Graph(const int _MaxGraphSize = default)
		:graphsize(0), MaxGraphSize(_MaxGraphSize), NumEdge(0) {
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
			//顶点表的 边链表的头指针 ref domain
			Edge<T>* p = head[v].Adjacent;
			int w = p->VerAdj;
			//出第一个邻接顶点的序号
			return w;
		}
		//如果没有找到
		return -1;
	}
	//返回序号为v1的顶点相对于序号为v2的顶点开始的下一个邻接顶点的序号,实际是建立邻接表的边表结点的结构
	int GetNextNeighbor(const int v1, const int v2) {
		//序号合法
		if (v1 != -1 && v2 != -1) {
			//顶点表的 边链表的头指针 ref domain
			Edge<T>* p = head[v1].Adjacent;
			//找到v2序号的顶点
			while (p->VerAdj != v2)
				p->link;
			//找到v2的顶点开始的下一个邻接顶点的序号
			p->link;
			return p->VerAdj;
		}
		//else 找不到
		return -1;
	}

	//以下是修改图的方法 2个

	//插入一个顶点,vertex是顶点编号
	void InsertVertex(const T& vertex);
	//插入一条边(v1,v2),边权值为weight
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);

	//深度优先遍历的算法有点类似于迷宫求解
	//从起点出发，访问它的一个不曾访问定的邻接顶点，直至没有未访问的结点，退回上一个被访问的顶点，
	//看它是否还有未访问的邻接顶点，若有，则有，则访问该邻接结点，且从它出发，递归调用此算法，当所有顶点均被访问，则过程终止
	DepthFirstSearch() {		
		int *visited = new int[graphsize]; //为辅助数组申请空间 int visited[]		
		for (int k = 0; k < graphsize; k++) //数组初始化
			visited[k] = 0;
		//从序号为0的顶点出发，深度优先遍历图
		DepthFirstSearch(0, visited[]);
		//释放辅助数组空间
		delete[] visited;
	}
	//深度优先遍历算法 重载 递归调用
	DepthFirstSearch(const int v, int visited[]) {
		cout << GetName(v) << " "; //输出序号v顶点的名字值，可以换成其他操作语句		
		visited[v] = 1; //visited置1		
		int w = GetFirstNeighbor(v); //得到顶点v的下一个顶点w		
		while (w != -1) { //合法	,如果不存在，返回-1,则递归栈出栈		
			if (!visited[w]) //非0为true，未访问				
				DepthFirstSearch(w, visited[]); //递归调用，递归栈入栈 //L:入栈地址
			//else 上一句不成立，表示w已访问				
			w = GetFirstNeighbor(v, w); //则找到v相对于w的下一个邻接点
		}
	}
	//广度优先遍历,迭代算法,队列辅助
	BFS(const int v){		
		int *visited = new int[graphsize]; //为辅助数组申请空间 int visited[]		
		for (int k = 0; k < graphsize; k++) //数组初始化
			visited[k] = 0;
		cout << GetName(v) << " "; //输出序号v顶点的名字值，可以换成其他操作语句
		visited[v] = 1; //visited置1
		Queue<int> q; //队列辅助
		q.EnQueue(v); //入队
	}

};//!_class Graph

