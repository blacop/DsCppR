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

//2a  ���ڽӱ�洢��Graph��
//�������Ľṹ
template<typename T>
class Vertex {
	friend class Graph<T>;//��Ԫ��
public:
	T VerName; //��������� 	data domain ,store node value
	Edge* adjacent; //�������ͷָ�� ref domain
};

//2b ���ڽӱ�洢��Graph��
//�߱���Ľṹ
template<typename T>
class Edge {
	friend class Graph<T>;//��Ԫ��
public:
	int VerAdj; //���ڽӶ������	data domain 1
	int cost;	//�˱ߵ�Ȩֵ	data domain 2	
	Edge<T>* link; //ָ����һ���߽���ָ�� ref domain
	//���캯��
	Edge(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
};

//2 ���ڽӱ�洢��Graph��
//Graph�������
template<typename T>
class Graph {
privata:
	Vertex<T> *head; //������ͷָ��
	int graphsize; //��ǰ������
	int MaxGraphSize; //��󶥵���
	int NumEdge; //��ǰ����
	int MaxNumEdge; //������

	//���ض���vertex�ڶ�����е����
	int GetVertexPos(const T& vertex);

	//Graph���ʵ��
public:
	//���캯��
	Graph(const int _MaxGraphSize = default)
		:graphsize(0), MaxGraphSize(_MaxGraphSize), NumEdge(0) {
		//���������������Ȩֵ
		int numGraphsize, edgeCount, weight;
		//�������֣���㣬�յ�
		T name, from, to;
		//������ʵ�ֶ����headָ������ĵ�һ��Ԫ��
		head = new Vertex<T>[MaxGraphSize];

		cin >> numGraphsize; //���붥�����		
		for (int i = 0; i < numGraphsize; i++) {
			cin >> name; //�������붥�㣬����ͼ��
			InsertVertex(name); //���������ͼ��
		}

		cin >> edgeCount; //����ߵĸ���
		for (int i = 0; i < edgeCount; i++) { //�����������			
			cin >> from >> to >> weight; //����ߵ�ʼ�㣬�յ��Ȩֵ			
			InsertEdge(from, to, weight); //���߲���ͼ��
		}
	}//!_Graph()
	virtual ~Graph() {} //��������

	//���ݷ��ʺ��� 2��

	//�������Ϊv�Ķ���ĵ�һ���ڽӶ������ţ�ʵ���ǽ����ڽӱ�Ķ������Ľṹ
	int GetFirstNeighbor(const int v) {
		//��֤����Ŵ���
		if (v != -1) {
			//������ �������ͷָ�� ref domain
			Edge<T>* p = head[v].Adjacent;
			int w = p->VerAdj;
			//����һ���ڽӶ�������
			return w;
		}
		//���û���ҵ�
		return -1;
	}
	//�������Ϊv1�Ķ�����������Ϊv2�Ķ��㿪ʼ����һ���ڽӶ�������,ʵ���ǽ����ڽӱ�ı߱���Ľṹ
	int GetNextNeighbor(const int v1, const int v2) {
		//��źϷ�
		if (v1 != -1 && v2 != -1) {
			//������ �������ͷָ�� ref domain
			Edge<T>* p = head[v1].Adjacent;
			//�ҵ�v2��ŵĶ���
			while (p->VerAdj != v2)
				p->link;
			//�ҵ�v2�Ķ��㿪ʼ����һ���ڽӶ�������
			p->link;
			return p->VerAdj;
		}
		//else �Ҳ���
		return -1;
	}

	//�������޸�ͼ�ķ��� 2��

	//����һ������,vertex�Ƕ�����
	void InsertVertex(const T& vertex);
	//����һ����(v1,v2),��ȨֵΪweight
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);

	//������ȱ������㷨�е��������Թ����
	//������������������һ���������ʶ����ڽӶ��㣬ֱ��û��δ���ʵĽ�㣬�˻���һ�������ʵĶ��㣬
	//�����Ƿ���δ���ʵ��ڽӶ��㣬���У����У�����ʸ��ڽӽ�㣬�Ҵ����������ݹ���ô��㷨�������ж���������ʣ��������ֹ
	DepthFirstSearch() {
		int *visited = new int[graphsize]; //Ϊ������������ռ� int visited[]		
		for (int k = 0; k < graphsize; k++) //�����ʼ��
			visited[k] = 0;
		//�����Ϊ0�Ķ��������������ȱ���ͼ
		DepthFirstSearch(0, visited[]);
		//�ͷŸ�������ռ�
		delete[] visited;
	}
	//������ȱ����㷨 ���� �ݹ����
	DepthFirstSearch(const int v, int visited[]) {
		cout << GetName(v) << " "; //������v���������ֵ�����Ի��������������		
		visited[v] = 1; //visited��1		
		int w = GetFirstNeighbor(v); //�õ�����v����һ������w		
		while (w != -1) { //�Ϸ�	,��������ڣ�����-1,��ݹ�ջ��ջ		
			if (!visited[w]) //��0Ϊtrue��δ����				
				DepthFirstSearch(w, visited[]); //�ݹ���ã��ݹ�ջ��ջ //L:��ջ��ַ
			//else ��һ�䲻��������ʾw�ѷ���				
			w = GetFirstNeighbor(v, w); //���ҵ�v�����w����һ���ڽӵ�
		}
	}
	//������ȱ���,�����㷨,���и���
	BFS(const int v) {
		int *visited = new int[graphsize];  //Ϊ������������ռ� int visited[]		
		for (int k = 0; k < graphsize; k++) //�����ʼ��
			visited[k] = 0;
		cout << GetName(v) << " "; //������v���������ֵ�����Ի��������������
		visited[v] = 1; //visited�ѷ�����1
		Queue<int> q; //������������
		q.EnQueue(v); //���v
		while (!q.IsEmpty()) { //���зǿ�
			v = q.DeQueue();  //����v
			int w = GetFirstNeighbor(v); //�õ�����v����һ������w
			while (w != -1) { //�Ϸ�	,��������ڣ�����-1,��ݹ�ջ��ջ
				if (!visited[w]) { //��0Ϊtrue��δ����
					cout << GetName(w) << " "; //������v���������ֵ�����Ի��������������
					visited[w] = 1; //visited�ѷ�����1
					q.EnQueue(w); //��� ����v����һ������w
				}
				//else ��һ�䲻��������ʾw�ѷ���	
				w = GetNextNeighbor(v, w); //���ҵ�v�����w����һ���ڽӵ�
			}//!_while
		}//!_while
		delete[] visited; //�ͷŸ�������
	}//!_BFS

	//���������㷨,�����ǰ��������
	//���壺������ͼ�еĶ��������Է�ʽ�������򡣼������κ������Զ���u������v�������uv���������������У�����u�����ڶ���v��ǰ�档

	//	������������Գ���Ļ�����ô��������һ���ǳ��ǳ���������ӡ���ѡ�Ρ������κο������ݽṹ����鼮��ͬѧ��֪�����ɡ������ҷǳ���ѧϰһ�Ż���ѧϰ�Ŀγ̣�����������ô�γ�֮ǰ�����Ǳ���ҪѧϰһЩ�����γ̣�����������ѧ���ۣ�C���Գ�����ƣ����ݽṹ���㷨�ȵȡ���ô����ƶ�ѡ�޿γ�˳��Ĺ��̣�ʵ���Ͼ���һ����������Ĺ��̣�ÿ�ſγ��൱������ͼ�е�һ�����㣬�����Ӷ���֮�������߾��ǿγ�ѧϰ���Ⱥ��ϵ��ֻ����������̲�����ô���ӣ��Ӷ�����Ȼ�������ǵĴ���������ˡ�������������㷨����ʽ���������Ľ����������������

	//	��ô�ǲ������е�����ͼ���ܹ������������أ���Ȼ���ǡ�����������������ӣ������������ѡ�޼������ѧ�������ſ�֮ǰ��Ҫ����ѧϰ����ѧϰ�����ǲ��ǻᱻŪ��Ϳ������������£����޷���������������Ϊ���м���ڻ��������Ĺ�ϵ���Ӷ��޷�ȷ��˭��˭��������ͼ�У��������������Ϊ���ڻ�·����ˣ�һ������ͼ�ܱ���������ĳ�Ҫ������������һ�������޻�ͼ(DAG��Directed Acyclic Graph)��
	TopoOrder() {
		int* count = new int[length]; //���� ��ȱ� ��̬����ջ array 
		int top = -1; //��ջ
		for (int i = 0; i < length; i++) //��ʼ����ȱ�˳��ջ
			if (count[i] == 0) {  //�ҵ����Ϊ0�Ķ��� Ȼ����ջ ��̬����ջ
				count[i] = top; //�����Ϊ0�Ķ���ѹ��ջ��//��valueΪtopֵ����ջ,��value�ɱ�ʾջ����һ�����Ϊ0��Ԫ�ص�index�±�
				top = i;  //top ��Ϊi count,top++ ��topָ����������index��int* ��ref domain
			}
		for (int i = 0; i < length; i++)
			if (top == -1) { //û�����Ϊ0�Ķ��㣬���л�·
				cout << "There is a cycle in network !" << endl; return;
			} else { //û�л�·
				int j = top; //��ջtop��j��top��Ԫ�����
				top = count[top]; //top--��ȡ���α꣬count[top]����һ���α�
				cout << j << endl; //��� ��ջ�Ķ���Ԫ��ֵ�����滻������� 
				Edge<T>* p = head[j].Adjacent; //�õ������.[j]����һ���ڽӵ������
				while (p != NULL) { //�ǿգ���ȱ���
					int k = p->VerAdj; //�õ��ڽӵ�����
					if (--count[k] == 0) { //�������ڽӵ�����г���,����ִ�д���ŵ�ÿ���ڽӵ�����-1��if�������ߺ����Ϊ0
						count[k] = top; //��ջ ��̬����ջ �����α� �α�ʵ�ַ�
						top = k; //top++��cursor switch,�α���ת���α���Ϊ��ǰԪ��
					}
					p = p->link; //ptr ++ ��һ��������,��ȱ���
				}
			}//!_for (int i = 0; i < length; i++) 
	}//!_TopoOrder

	 //Prim�㷨 PrimClosedge��Ȩֵ�Ͷ������Ľṹ
	template<typename T>
	class PrimClosedge {
		friend class Graph<T>;//��Ԫ��
	public:
		int* vex;	//����ArrayList ,data domain 1
		int* Lowcost; //ȨֵArrayList ,data domain 2 //i�������ıߵ�Ȩֵ		
					  //���캯��
		PrimClosedge(int _length) : Lowcost(new int[_length]), vex(new int[_length]) {}
	};

	//����ķ�㷨
	Prim() {
		PrimClosedge<T>  closedge = new PrimClosedge<T>(length);
		for (int i = 0; i < length; i++) {
			closedge[i].Lowcost = Edge[0][i]; //i�������ıߵ�Ȩֵ
			closedge[i].vex = 0;
		}
		closeedge[0].vex = -1;
		int count = 0;
	}
		

};//!_class Graph

