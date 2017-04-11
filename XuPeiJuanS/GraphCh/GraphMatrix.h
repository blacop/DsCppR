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
	SeqList<T> VertexList; //顶点表	
	int edgeMatrix[MaxGraphSize][MaxGraphSize]; //邻接矩阵	
	int graphsize; //当前顶点数	
	int CurrentEdges; //当前边数
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

	 //2a  用邻接表存储的Graph类
	 //顶点表结点的结构
	template<typename T>
	class Vertex {
		friend class Graph<T>;//友元类
	public:
		T VerName; //顶点的名称 	data domain ,store node value
		Edge* adjacent; //边链表的头指针 ref domain
	};

	////2b 用邻接表存储的Graph类
	////边表结点的结构
	//template<typename T>
	//class Edge {
	//	friend class Graph<T>;//友元类
	//public:
	//	int VerAdj; //此邻接顶点序号	data domain 1
	//	int cost;	//此边的权值	data domain 2	
	//	Edge<T>* link; //指向下一个边结点的指针 ref domain
	//				   //构造函数
	//	Edge(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
	//};

	////2a 用邻接矩阵存储的Graph类
	////边表结点的结构	
	//#define MAX_VERTRIX_NUM 10;
	////邻接矩阵，全局变量,值为权
	//typedef struct AdjMatrix {
	//	int AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM]; //表示此顶点到各顶点的权值 data domain 2
	//}AdjMatrix;

	////2a 用邻接矩阵存储的Graph类
	////边表结点的结构	
	//typedef struct AdjMatrixEdge {
	//	int** cost;	//此矩阵存储 此顶点到各顶点的权值 	data domain 2
	//	AdjMatrixEdge(int _length) :cost(new int[_length][_length]) {} //构造函数，动态分配矩阵内存
	//}AdjMatrixEdge;

	//2a 用邻接矩阵存储的Graph类
	//边表结点的结构	
	typedef struct AdjMatrixEdge {
		int cost;	//此矩阵存储 此顶点到各顶点的权值 	data domain 2
		//AdjMatrixEdge(int _length) :cost(new int[_length][_length]) {} //构造函数，动态分配矩阵内存
	}AdjMatrixEdge;

	//Prim算法 PrimClosedge边权值和顶点表结点的结构，辅助数组,表示此顶点到各顶点的权值
	template<typename T>
	class PrimClosedge { //上面全部终点 辅助权值数组
	public:
		int Lowcost; //权值ArrayList ,data domain 2 //i点与各点的边的权值	
		int vex;	//顶点ArrayList ,data domain 1，order index，静态链表的ref domain
		//PrimClosedge() : Lowcost(0), vex(0) {} //构造函数
	};
	//Prim算法 存放最小生成树边 的集合
	typedef struct TEdge {
		int head;
		int tail;
		int cost;
	}TEdge;

	//普里姆算法
	#define INT_MAX       2147483647    /* maximum (signed) int value */	
	#define length 6 //顶点数量
   //利用普里姆算法从顶点v0出发求出用邻接矩阵edge表示的图的最小支撑树,最小支撑树的边集存于数组T中。n^2
	Prim() {
		PrimClosedge<T>* closedge = new PrimClosedge<T>[length]; //初始化 上面全部终点 辅助数组 patched
		AdjMatrixEdge** AdjMEdge = new AdjMatrixEdge[length][length]; //AdjMEdge权值矩阵的值由 外面传入
		TEdge MinTreeEdge = new TEdge[length];  //Prim算法 存放最小生成树边 的集合
		//初始化 辅助数组,表示此顶点到各顶点的权值
		for (int i = 0; i < length; i++) {
			closedge[i].Lowcost = AdjMEdge[0][i]; //i点与各点的边的权值 从赋值 用邻接矩阵存储的边表结点的结构
			closedge[i].vex = 0; //order index，静态链表的ref domain
		}
		//v0初始化
		closeedge[0].vex = -1; //表示已经进入最小支撑树集合TE //静态链表的 tail ref 为-1，表示null
		int count = 0; //计数器
		for (int i = 1; i < length; i++) { //开始生成
			int min = INT_MAX; //max是c++的最大整数,instance of min Lowcost value
			int v = 0; //order link ref
			for (int j = 0; j < length; j++) {
				if (closedge[j].vex != -1 &&
					closedge[j].Lowcost < min) { //找到 权值最小的 边，存入min
					v = j; //order link ref，下标送给v
					min = closedge[j].Lowcost; //switch min Lowcost value //修改最小值
				}

				if (v != 0) { //有值。存入权值最小的边到MinTreeEdge集合。加入MST最小生成树
					MinTreeEdge[count].head = v; //存放起点的名字
					MinTreeEdge[count].tail = closedge[v].vex; //存放终点的名字
					MinTreeEdge[count].cost = closedge[v].Lowcost; //存放边的权值
					count++; //计数器++
					closedge[v].Lowcost = 0; //清理，标识已free此终点
					closedge[v].vex = -1; //标识已加入TEdge集合，加入MST最小生成树

					for (int j = 0; j < length; j++)
						if (closedge[j].vex != -1 &&
							AdjMEdge[v][j] < closedge[j].Lowcost) { //v是在前面的上一个找到的最小生成树的终点 //邻接矩阵[v][j]的值小于临时权值数组的值，上一个终点v到j与上面全部终点到j进行权值的比较
							closedge[j].Lowcost = AdjMEdge[v][j]; //switch min Lowcost value,权值矩阵[v][j]的值替换修改辅助数组
							closedge[j].vex = v; //order link ref,vex记录边的起点vex order name，j记录终点
						}
				}
			}
		}

	}//!_Prim()

};//!_class Graph

