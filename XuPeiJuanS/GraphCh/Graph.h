#pragma once
#include "stdafx.h"
#include "Queue.h"
#include "Stack.h"
#include "SqStack.h"
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
class Vertex {
	friend class Graph<T>;//友元类
public:
	T VerName; //顶点的名称 	data domain ,store node value
	Edge* adjacent; //边链表的头指针 ref domain
};

//2b 用邻接表存储的Graph类
//边表结点的结构
template<typename T>
class Edge {	
	friend class Graph<T>;//友元类
public:
	int VerAdj; //此邻接顶点序号	data domain 1
	int cost;	//此边的权值	data domain 2	
	Edge<T>* link; //指向下一个边结点的指针 ref domain
	//构造函数
	Edge(int d,int c) : VerAdj(d), cost(c), link(NULL) {}
};

//Prim算法 PrimClosedge边权值和顶点表结点的结构
template<typename T>
class PrimClosedge {
	friend class Graph<T>;//友元类
public:
	int* Lowcost; //权值ArrayList ,data domain 1 //i点与各点的边的权值
	int* vex;	//顶点ArrayList ,data domain 2	
	//构造函数
	PrimClosedge(int _length) : Lowcost(new int[_length]), vex(new int[_length]) {}
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
		for (int i = 0; i < numGraphsize; i++) { 
			cin >> name; //依次输入顶点，插入图中
			InsertVertex(name); //将顶点插入图中
		}

		cin >> edgeCount; //输入边的个数
		for (int i = 0; i < edgeCount; i++) { //依次输入各边			
			cin >> from >> to >> weight; //输入边的始点，终点和权值			
			InsertEdge(from, to, weight); //将边插入图中
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
	BFS(const int v) {
		int *visited = new int[graphsize];  //为辅助数组申请空间 int visited[]		
		for (int k = 0; k < graphsize; k++) //数组初始化
			visited[k] = 0;
		cout << GetName(v) << " "; //输出序号v顶点的名字值，可以换成其他操作语句
		visited[v] = 1; //visited已访问置1
		Queue<int> q; //声明辅助队列
		q.EnQueue(v); //入队v
		while (!q.IsEmpty()) { //队列非空
			v = q.DeQueue();  //出队v
			int w = GetFirstNeighbor(v); //得到顶点v的下一个顶点w
			while (w != -1) { //合法	,如果不存在，返回-1,则递归栈出栈
				if (!visited[w]) { //非0为true，未访问
					cout << GetName(w) << " "; //输出序号v顶点的名字值，可以换成其他操作语句
					visited[w] = 1; //visited已访问置1
					q.EnQueue(w); //入队 顶点v的下一个顶点w
				}
				//else 上一句不成立，表示w已访问	
				w = GetNextNeighbor(v, w); //则找到v相对于w的下一个邻接点
			}//!_while
		}//!_while
		delete[] visited; //释放辅助数组
	}//!_BFS

	//拓扑排序算法
	TopoOrder() {
		int* count = new int[length]; //new 入度表 顺序栈 array 
		int top = -1; //空栈
		for (int i = 0; i < length; i++) //初始化入度表顺序栈
			if (count[i] == 0) {  //找到入度为0的顶点 然后入栈
				count[i] = top; //把入度为0的顶点压入栈中//置value为top值，入栈,此value可表示栈中下一个入度为0的元素的index下标
				top = i;  //top 置为i count,top++
			}
		for (int i = 0; i < length; i++)
			if (top == -1) { //没有入度为0的顶点，则有环路
				cout << "There is a cycle in network !" << endl; return;
			} else { //没有环路
				int j = top; //出栈top到j，top存元素序号
				top = count[top]; //top--，取出游标，count[top]存下一个游标
				cout << j << endl; //输出 出栈的顶点元素值，可替换操作语句 
				Edge<T>* p = head[j].Adjacent; //得到j的下一个邻接点的引用
				while (p != NULL) { //非空
					int k = p->VerAdj; //得到邻接点的序号
					if (--count[k] == 0) { //消掉出边,就是执行此序号的每个邻接点的入度-1，if为0
						count[k] = top; //入栈 静态链表栈 置入游标 游标实现法
						top = k; //top++，cursor switch,游标跳转，游标置为当前元素
					}
					p = p->link; //ptr ++ 下一个链接域
				}
			}//!_for (int i = 0; i < length; i++) 
	}//!_TopoOrder

	//普里姆算法
	Prim() {	
		/*int * closeedge= new int[length];
		for (int i = 0; i < length; i++) {
		closeedge[i] = 0;
		}*/

		//java的Hashtable写法
		//Hashtable ht = new Hashtable();
		//ht.Add(key, value);// key,value可以是任何类型

		////java的Hashtable写法
		//Hashtable closeedge = new Hashtable();
		//closeedge.Add(Lowcost, int * LowcostArray = new int[length]);
		//closeedge.Add(vex, int * vexArray= new int[length]);		
		
		PrimClosedge<T>  closedge = new PrimClosedge<T>(length);
		for (int i = 0; i < length; i++) {
			closedge[i].Lowcost = Edge[0][i]; //i点与各点的边的权值
			closedge[i].vex = 0;
		}
		closeedge[0].vex = -1;
		int count = 0;
	}

	

};//!_class Graph

