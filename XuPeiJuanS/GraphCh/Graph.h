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

//2a  ���ڽӱ�洢��Graph��
//�������Ľṹ
template<typename T>
struct Vertex {
	//��Ԫ��
	friend class Graph<T>;

	T VerName; //��������� 	data domain ,store node value
	Edge* adjacent; //�������ͷָ�� ref domain
};

//2b ���ڽӱ�洢��Graph��
//�߱���Ľṹ
template<typename T>
struct Edge {
	//��Ԫ��
	friend class Graph<T>;

	int VerAdj; //���ڽӶ������	data domain 1
	int cost;	//�˱ߵ�Ȩֵ	data domain 2
	Edge* link; //ָ����һ���߽���ָ�� ref domain

	////���캯��
	//Edge<T>() {}
	//���캯��
	Edge<T>(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
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
		for (int i = 0; i < numGraphsize; i++) { //�������붥�㣬����ͼ��
			cin >> name;
			InsertVertex(name);
		}

		cin >> edgeCount; //����ߵĸ���
		for (int i = 0; i < edgeCount; i++) { //�����������
			//����ߵ�ʼ�㣬�յ��Ȩֵ
			cin >> from >> to >> weight;
			//���߲���ͼ��
			InsertEdge(from, to, weight);
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
	BFS(const int v){		
		int *visited = new int[graphsize]; //Ϊ������������ռ� int visited[]		
		for (int k = 0; k < graphsize; k++) //�����ʼ��
			visited[k] = 0;
		cout << GetName(v) << " "; //������v���������ֵ�����Ի��������������
		visited[v] = 1; //visited��1
		Queue<int> q; //���и���
		q.EnQueue(v); //���
	}

};//!_class Graph

