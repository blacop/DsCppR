#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "Edge.h"
//class Graph {
//public:
//
//	Graph() {}
//
//	virtual ~Graph() {}
//};

//2 ���ڽӱ�洢��Graph��
//Graph�������
template<typename T> class Graph {
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
	Graph(const int sz = default)
		:graphsize(0), MaxGraphSize(sz), NumEdge(0) {
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
			Edge<T>* p = head[v].Adjacent;
			int w = p->VerAdj;
			return w;
		}
		return -1;
	}
	//�������Ϊv1�Ķ�����������Ϊv2�Ķ��㿪ʼ����һ���ڽӶ�������,ʵ���ǽ����ڽӱ�ı߱���Ľṹ
	int GetNextNeighbor(const int v1, const int v2);

	//�������޸�ͼ�ķ��� 2��

	//����һ������,vertex�Ƕ�����
	void InsertVertex(const T& vertex);
	//����һ����(v1,v2),��ȨֵΪweight
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);

};//!_class Graph

