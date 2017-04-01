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
	//�����
	SeqList<T> VertexList;
	//�ڽӾ���
	int edgeMatrix[MaxGraphSize][MaxGraphSize];
	//��ǰ������
	int graphsize;
	//��ǰ����
	int CurrentEdges;
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

};//!_class Graph

