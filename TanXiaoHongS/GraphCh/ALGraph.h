#pragma once
#include "stdafx.h"
#include "Queue.h"
#include "Stack.h"
#include "SeqList.h"
//用邻接表存储的Graph类 声明

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

//用邻接矩阵存储的Graph类 //表边弧结点单元的结构 //表示邻接表的边结点
template <typename T, typename VRType, typename InfoType>
class ArcCell {
public:
	VRType adj; //顶点关系类型
	// 图：有边连接为1,无边连接为0 ，可以用int
				//网：有边权值，无边无穷大
	InfoType* info;//顶点表 //指向该弧相关信息指针 ，可以用顶点信息数组type[] *
};

//用邻接表存储的Graph类声明 和弧相关的信息成员结构//弧边权值
typedef struct InfoType {
	int cost; //弧边权值
}InfoType;
//用邻接表存储的Graph类，弧边结点链表，表结点链表 声明
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
	 //class ALGraph {
	 //public:
	 //
	 //	ALGraph() {}
	 //
	 //	virtual ~ALGraph() {}
	 //};

	 //深度优先遍历
	bool visited[MAX_VERTRIX_NUM]; //访问状态表
	bool(*VisitFunc)(int v);  //委托：访问结点	
							  //深度优先遍历
	void DFSTraverse(ALGraph G, bool(*Visit(int v))) { //深度优先遍历 Tan
		VisitFunc = Visit; //委托：访问结点;委托赋值 访问函数
		for (int v = 0; v < G.vexnum; ++v)  //初始化 访问状态表
			visited[v] = false;
		for (int v = 0; v < G.vexnum; ++v) { //遍历 从第一个到最后一个邻接点
			if (!visited[v]) DFS(G, v);//深度优先遍历算法 重载 递归调用
		}
	}
	void DFS(ALGraph G, int v) { //深度优先遍历算法 重载 递归调用
		visited[v] = true; //访问状态表更新
		VisitFunc(v); //委托调用
					  //找到第一个邻接点，w为true,找下一个邻接点
		for (int w = FirstAdjVex(G，v); w; w = NextAdjVex(G, v, w))
			if (!visited[w]) DFS(G, w); //深度优先遍历算法 重载 递归调用
	}

	//广度优先遍历 Tan 层次遍历的推广
	void BFSTravese(ALGraph G, bool(*Visit(int v))) {
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

	 //用邻接表存储的Graph类 顶点表结点的结构
	template<typename T>
	class Vertex {
		friend class Graph<T>;//友元类
	public:
		T VerName; //顶点的名称 	data domain ,store node value
		Edge* adjacent; //边链表的头指针 ref domain
	};

	//用邻接表存储的Graph类 边表结点的结构
	template<typename T>
	class Edge {
		friend class Graph<T>;//友元类
	public:
		int VerAdj; //此邻接顶点序号	data domain 1
		int cost;	//此边的权值	data domain 2	
		Edge<T>* link; //指向下一个边结点的指针 ref domain
					   //构造函数
		Edge(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
	};

	//拓扑排序算法,定义和前置条件：
	//定义：将有向图中的顶点以线性方式进行排序。即对于任何连接自顶点u到顶点v的有向边uv，在最后的排序结果中，顶点u总是在顶点v的前面。
	//	如果这个概念还略显抽象的话，那么不妨考虑一个非常非常经典的例子——选课。我想任何看过数据结构相关书籍的同学都知道它吧。假设我非常想学习一门机器学习的课程，但是在修这么课程之前，我们必须要学习一些基础课程，比如计算机科学概论，C语言程序设计，数据结构，算法等等。那么这个制定选修课程顺序的过程，实际上就是一个拓扑排序的过程，每门课程相当于有向图中的一个顶点，而连接顶点之间的有向边就是课程学习的先后关系。只不过这个过程不是那么复杂，从而很自然的在我们的大脑中完成了。将这个过程以算法的形式描述出来的结果，就是拓扑排序。
	//	那么是不是所有的有向图都能够被拓扑排序呢？显然不是。继续考虑上面的例子，如果告诉你在选修计算机科学概论这门课之前需要你先学习机器学习，你是不是会被弄糊涂？在这种情况下，就无法进行拓扑排序，因为它中间存在互相依赖的关系，从而无法确定谁先谁后。在有向图中，这种情况被描述为存在环路。因此，一个有向图能被拓扑排序的充要条件就是它是一个有向无环图(DAG：Directed Acyclic Graph)。
	/*不难看出该算法的实现十分直观，关键在于需要维护一个入度为0的顶点的集合：
		每次从该集合中取出(没有特殊的取出规则，随机取出也行，使用队列 / 栈也行，下同)一个顶点，将该顶点放入保存结果的List中。
		紧接着循环遍历由该顶点引出的所有边，从图中移除这条边，同时获取该边的另外一个顶点，如果该顶点的入度在减去本条边之后为0，那么也将这个顶点放到入度为0的集合中。然后继续从集合中取出一个顶点…………

		当集合为空之后，检查图中是否还存在任何边，如果存在的话，说明图中至少存在一条环路。不存在的话则返回结果List，此List中的顺序就是对图进行拓扑排序的结果。*/
	public class KahnTopological {
		private List<Integer> result;   // 用来存储结果集  
		private Queue<Integer> setOfZeroIndegree;  // 用来存储入度为0的顶点  
		private int[] indegrees;  // 记录每个顶点当前的入度  
		private int edges;
		private Digraph di;

		public KahnTopological(Digraph di) {
			this.di = di;
			this.edges = di.getE();
			this.indegrees = new int[di.getV()];
			this.result = new ArrayList<Integer>();
			this.setOfZeroIndegree = new LinkedList<Integer>();

			// 对入度为0的集合进行初始化  
			Iterable<Integer>[] adjs = di.getAdj();
			for (int i = 0; i < adjs.length; i++) {
				// 对每一条边 v -> w   
				for (int w : adjs[i]) {
					indegrees[w]++;
				}
			}

			for (int i = 0; i < indegrees.length; i++) {
				if (0 == indegrees[i]) {
					setOfZeroIndegree.enqueue(i);
				}
			}
			process();
		}

		private void process() {
			while (!setOfZeroIndegree.isEmpty()) {
				int v = setOfZeroIndegree.dequeue();

				// 将当前顶点添加到结果集中  
				result.add(v);

				// 遍历由v引出的所有边  
				for (int w : di.adj(v)) {
					// 将该边从图中移除，通过减少边的数量来表示  
					edges--;
					if (0 == --indegrees[w])   // 如果入度为0，那么加入入度为0的集合  
					{
						setOfZeroIndegree.enqueue(w);
					}
				}
			}
			// 如果此时图中还存在边，那么说明图中含有环路  
			if (0 != edges) {
				throw new IllegalArgumentException("Has Cycle !");
			}
		}

		public Iterable<Integer> getResult() {
			return result;
		}
	}

	#define length 10;
	//拓扑排序算法
	TopoOrder() {
		int* count = new int[length]; //new 结点入度数组 静态链表栈 顺序栈 array 
		int top = -1; //空栈
		for (int i = 0; i < length; i++) //初始化入度表顺序栈
			if (count[i] == 0) {  //找到入度为0的顶点 然后入栈
				count[i] = top; //把入度为0的顶点压入栈中//置value为top值，入栈,此value可表示栈中下一个入度为0的元素的index下标
				top = i;  //top 置为i count,top++
			}
		Vertex<T>* head = new Vertex<T>[length];//new 顶点表数组
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

	//输出有向图的拓扑序列的算法
	//1选中入度为0的顶点且输出，就是出栈或出队列
	//2从图中删除该结点和所有以该结点为尾的弧，此邻接点的每个边结点的入度-1,如果-1以后变成0,则入栈
	//3重复上述操作。若可以输出全部顶点，则该图中不存在环，否则存在环
	//算法实现：
	/*以邻接表的方法存储有向图：
	头结点增加信息：顶点入度;
	增加一个栈或队列：用于存放入度为0的顶点。*/
	int* indegree = new int[length]; //入度数组
	bool TopologicalSort(ALGraph G) {
		FindInDegree(G, indegree); //查找入度0,存入入度数组
		Stack<T> S = new Stack<T>; //初始化栈
		for (int i = 0; i < G.vexnum; ++i) if (!indegree[i]) S.Push(S, i); //入度是0,入栈
		int count = 0; //计数器
		while (!S.IsEmpty()) {
			S.Pop(S, i); printf(i, G.vertices[i].data); ++count; //出栈
			for (p = G.vertices[i].firstarc; p; p = p->nextarc) { //删除边
				k = p->adjvex;
				if (!(--indegree[k])) S.Push(S, k); //入度是0,入栈
			}
		}
		if (count < G.vexnum) return false; //说明有回路
		else return true;
	}
	FindInDegree(ALGraph G, indegree) { //查找入度0,存入入度数组
		int* count = new int[length]; //new 结点入度数组 静态链表栈 顺序栈 array 
		int top = -1; //空栈
		for (int i = 0; i < length; i++) //初始化入度表顺序栈
			if (count[i] == 0) {  //找到入度为0的顶点 然后入栈
				count[i] = top; //把入度为0的顶点压入栈中//置value为top值，入栈,此value可表示栈中下一个入度为0的元素的index下标
				top = i;  //top 置为i count,top++
			}
	}

	/*4.Dijkstra算法(Dijkstra's algorithm)

迪杰斯特拉算法（Dijkstra’s algorithm）是由荷兰计算机科学家艾兹赫尔·迪杰斯特拉提出。迪杰斯特拉算法使用了广度优先搜索解决非负权有向图的单源最短路径问题，算法最终得到一个最短路径树。该算法常用于路由算法或者作为其他图算法的一个子模块。

该算法的输入包含了一个有权重的有向图 G，以及G中的一个来源顶点 S。我们以 V 表示 G 中所有顶点的集合。每一个图中的边，都是两个顶点所形成的有序元素对。(u, v) 表示从顶点 u 到 v 有路径相连。我们以 E 表示G中所有边的集合，而边的权重则由权重函数 w : E →[0, ∞] 定义。因此，w(u, v) 就是从顶点 u 到顶点 v 的非负权重（weight）。边的权重可以想像成两个顶点之间的距离。任两点间路径的权重，就是该路径上所有边的权重总和。已知有 V 中有顶点 s 及 t，Dijkstra 算法可以找到 s 到 t的最低权重路径(例如，最短路径)。这个算法也可以在一个图中，找到从一个顶点 s 到任何其他顶点的最短路径。对于不含负权的有向图，Dijkstra 算法是目前已知的最快的单源最短路径算法。

算法步骤：

1.  初始时令 S = { V0 }, T = { 其余顶点 }，T中顶点对应的距离值

若存在<V0, Vi>，d(V0, Vi)为<V0, Vi>弧上的权值

若不存在<V0, Vi>，d(V0, Vi)为∞

2.  从T中选取一个其距离值为最小的顶点W且不在S中，加入S

3.  对其余T中顶点的距离值进行修改：若加进W作中间顶点，从 V0 到 Vi 的距离值缩短，则修改此距离值

重复上述步骤2、3，直到S中包含所有顶点，即W = Vi 为止*/



};//!_bool CreateN(MGraph<T> &G)

