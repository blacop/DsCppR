#pragma once
#include "stdafx.h"
#include "SeqList.h"

//1 ���ڽӾ���洢��Graph��
//Graph������
//ͼ����󶥵����
const int MaxGraphSize = 25;
template <typename T>
class GraphMatrix {
	//4���ֶ�
private:
	SeqList<T> VertexList; //�����	
	int edgeMatrix[MaxGraphSize][MaxGraphSize]; //�ڽӾ���	
	int graphsize; //��ǰ������	
	int CurrentEdges; //��ǰ����
	//2��˽�з���

	//��鶥��vertex�Ƿ��ڶ����L��
	int FindVertex(SeqList<T>&L, const T& vertex);
	//���ض���vertext�ڶ�����е�λ��(���)
	int GetVertexPos(const T& vertex);
	//3�����췽��
public:
	//������
	GraphMatrix(void) {
		//���ڽӾ��������Ԫ����Ϊ0
		for (int i = 0; i < MaxGraphSize; i++)
			for (int j = 0; j < MaxGraphSize; j++)
				edgeMatrix[i][j] = 0;
		graphsize = 0;
	}
	//De������
	virtual ~GraphMatrix() {}
	//���ͼ�Ƿ�Ϊ��
	int GraphEmpty(void) const {
		return VertexList.ListEmpty();
	}

	//�����Ƿ������ݵķ��� 5��

	//����ͼ�Ķ������
	int NumberOfVertices(void) const {
		return graphsize;
	}
	//����ͼ�ı߸���
	int NumberOfEdges(void) const {
		return CurrentEdges;
	}
	//����ָ���ߵ�Ȩֵ��v1��v2�ıߵ�Ȩֵ
	int GetWeight(const T& vertex1, const T& vertex2);
	//�������Ϊv�Ķ���ĵ�һ���ڽӶ�������
	int GetFirstNeighbor(const int v) {
		for (int i = 0; i < graphsize; i++)
			//>0 ��ʾ��Ȩֵ ���� < int�������������ʾ������
			if (edgeMatrix[v][i] > 0 && edgeMatrix[v][i] < std::numeric_limits<int>::max() ])
				return i;
		//����Ҳ���
		return -1;
	}
	//�������Ϊv1�Ķ�����������Ϊv2�Ķ��㿪ʼ����һ���ڽӶ�������
	int GetNextNeighbor(const int v1, const int v2) {
		//��֤�����Ǵ��ڵ�
		if (v1 != -1 && v2 != -1) {
			//v2�Ķ��㿪ʼ����һ���ڽӶ�������
			for (int i = v2 + 1; i < graphsize; i++)
				if (edgeMatrix[v1][i] > 0 && edgeMatrix[v1][i] < max)
					return i;
		}
		//����Ҳ���
		return -1;
	}

	//�������޸�ͼ�ķ��� 4��

	//����һ������,vertex�Ƕ�����
	void InsertVertex(const T& vertex);
	//����һ����(v1,v2),��ȨֵΪweight
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	//��ͼ��ɾȥ����vertex����������������ı�
	void DeleteVertex(const T& vertex);
	//��ͼ��ɾȥ��
	void DeleteEdge(const T& vertex1, const T& vertex2);

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

	 //���������㷨
	TopoOrder() {
		int* count = new int[length]; //new ��ȱ� ˳��ջ array 
		int top = -1; //��ջ
		for (int i = 0; i < length; i++) //��ʼ����ȱ�˳��ջ
			if (count[i] == 0) {  //�ҵ����Ϊ0�Ķ��� Ȼ����ջ
				count[i] = top; //�����Ϊ0�Ķ���ѹ��ջ��//��valueΪtopֵ����ջ,��value�ɱ�ʾջ����һ�����Ϊ0��Ԫ�ص�index�±�
				top = i;  //top ��Ϊi count,top++
			}
		for (int i = 0; i < length; i++)
			if (top == -1) { //û�����Ϊ0�Ķ��㣬���л�·
				cout << "There is a cycle in network !" << endl; return;
			} else { //û�л�·
				int j = top; //��ջtop��j��top��Ԫ�����
				top = count[top]; //top--��ȡ���α꣬count[top]����һ���α�
				cout << j << endl; //��� ��ջ�Ķ���Ԫ��ֵ�����滻������� 
				Edge<T>* p = head[j].Adjacent; //�õ�j����һ���ڽӵ������
				while (p != NULL) { //�ǿ�
					int k = p->VerAdj; //�õ��ڽӵ�����
					if (--count[k] == 0) { //��������,����ִ�д���ŵ�ÿ���ڽӵ�����-1��ifΪ0
						count[k] = top; //��ջ ��̬����ջ �����α� �α�ʵ�ַ�
						top = k; //top++��cursor switch,�α���ת���α���Ϊ��ǰԪ��
					}
					p = p->link; //ptr ++ ��һ��������
				}
			}//!_for (int i = 0; i < length; i++) 
	}//!_TopoOrder

	 //2a  ���ڽӱ�洢��Graph��
	 //�������Ľṹ
	template<typename T>
	class Vertex {
		friend class Graph<T>;//��Ԫ��
	public:
		T VerName; //��������� 	data domain ,store node value
		Edge* adjacent; //�������ͷָ�� ref domain
	};

	////2b ���ڽӱ�洢��Graph��
	////�߱���Ľṹ
	//template<typename T>
	//class Edge {
	//	friend class Graph<T>;//��Ԫ��
	//public:
	//	int VerAdj; //���ڽӶ������	data domain 1
	//	int cost;	//�˱ߵ�Ȩֵ	data domain 2	
	//	Edge<T>* link; //ָ����һ���߽���ָ�� ref domain
	//				   //���캯��
	//	Edge(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
	//};

	////2a ���ڽӾ���洢��Graph��
	////�߱���Ľṹ	
	//#define MAX_VERTRIX_NUM 10;
	////�ڽӾ���ȫ�ֱ���,ֵΪȨ
	//typedef struct AdjMatrix {
	//	int AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM]; //��ʾ�˶��㵽�������Ȩֵ data domain 2
	//}AdjMatrix;

	////2a ���ڽӾ���洢��Graph��
	////�߱���Ľṹ	
	//typedef struct AdjMatrixEdge {
	//	int** cost;	//�˾���洢 �˶��㵽�������Ȩֵ 	data domain 2
	//	AdjMatrixEdge(int _length) :cost(new int[_length][_length]) {} //���캯������̬��������ڴ�
	//}AdjMatrixEdge;

	//2a ���ڽӾ���洢��Graph��
	//�߱���Ľṹ	
	typedef struct AdjMatrixEdge {
		int cost;	//�˾���洢 �˶��㵽�������Ȩֵ 	data domain 2
		//AdjMatrixEdge(int _length) :cost(new int[_length][_length]) {} //���캯������̬��������ڴ�
	}AdjMatrixEdge;

	//Prim�㷨 PrimClosedge��Ȩֵ�Ͷ������Ľṹ����������,��ʾ�˶��㵽�������Ȩֵ
	template<typename T>
	class PrimClosedge { //����ȫ���յ� ����Ȩֵ����
	public:
		int Lowcost; //ȨֵArrayList ,data domain 2 //i�������ıߵ�Ȩֵ	
		int vex;	//����ArrayList ,data domain 1��order index����̬�����ref domain
		//PrimClosedge() : Lowcost(0), vex(0) {} //���캯��
	};
	//Prim�㷨 �����С�������� �ļ���
	typedef struct TEdge {
		int head;
		int tail;
		int cost;
	}TEdge;

	//����ķ�㷨
	#define INT_MAX       2147483647    /* maximum (signed) int value */	
	#define length 6 //��������
   //��������ķ�㷨�Ӷ���v0����������ڽӾ���edge��ʾ��ͼ����С֧����,��С֧�����ı߼���������T�С�n^2
	Prim() {
		PrimClosedge<T>* closedge = new PrimClosedge<T>[length]; //��ʼ�� ����ȫ���յ� �������� patched
		AdjMatrixEdge** AdjMEdge = new AdjMatrixEdge[length][length]; //AdjMEdgeȨֵ�����ֵ�� ���洫��
		TEdge MinTreeEdge = new TEdge[length];  //Prim�㷨 �����С�������� �ļ���
		//��ʼ�� ��������,��ʾ�˶��㵽�������Ȩֵ
		for (int i = 0; i < length; i++) {
			closedge[i].Lowcost = AdjMEdge[0][i]; //i�������ıߵ�Ȩֵ �Ӹ�ֵ ���ڽӾ���洢�ı߱���Ľṹ
			closedge[i].vex = 0; //order index����̬�����ref domain
		}
		//v0��ʼ��
		closeedge[0].vex = -1; //��ʾ�Ѿ�������С֧��������TE //��̬����� tail ref Ϊ-1����ʾnull
		int count = 0; //������
		for (int i = 1; i < length; i++) { //��ʼ����
			int min = INT_MAX; //max��c++���������,instance of min Lowcost value
			int v = 0; //order link ref
			for (int j = 0; j < length; j++) {
				if (closedge[j].vex != -1 &&
					closedge[j].Lowcost < min) { //�ҵ� Ȩֵ��С�� �ߣ�����min
					v = j; //order link ref���±��͸�v
					min = closedge[j].Lowcost; //switch min Lowcost value //�޸���Сֵ
				}

				if (v != 0) { //��ֵ������Ȩֵ��С�ıߵ�MinTreeEdge���ϡ�����MST��С������
					MinTreeEdge[count].head = v; //�����������
					MinTreeEdge[count].tail = closedge[v].vex; //����յ������
					MinTreeEdge[count].cost = closedge[v].Lowcost; //��űߵ�Ȩֵ
					count++; //������++
					closedge[v].Lowcost = 0; //������ʶ��free���յ�
					closedge[v].vex = -1; //��ʶ�Ѽ���TEdge���ϣ�����MST��С������

					for (int j = 0; j < length; j++)
						if (closedge[j].vex != -1 &&
							AdjMEdge[v][j] < closedge[j].Lowcost) { //v����ǰ�����һ���ҵ�����С���������յ� //�ڽӾ���[v][j]��ֵС����ʱȨֵ�����ֵ����һ���յ�v��j������ȫ���յ㵽j����Ȩֵ�ıȽ�
							closedge[j].Lowcost = AdjMEdge[v][j]; //switch min Lowcost value,Ȩֵ����[v][j]��ֵ�滻�޸ĸ�������
							closedge[j].vex = v; //order link ref,vex��¼�ߵ����vex order name��j��¼�յ�
						}
				}
			}
		}

	}//!_Prim()

};//!_class Graph

