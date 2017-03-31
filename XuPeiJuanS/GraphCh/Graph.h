#pragma once
#include "stdafx.h"
#include "SeqList.h"

//1 ���ڽӾ���洢��Graph��
//Graph������
//ͼ����󶥵����
const int MaxGraphSize = 25;
template <typename T>
class Graph {
private:
	//�����
	SeqList<T> VertexList;
	//�ڽӾ���
	int edge[MaxGraphSize][MaxGraphSize];
	//��ǰ������
	int graphsize;
	//��ǰ����
	int CurrentEdges;
	//��鶥��vertex�Ƿ��ڶ����L��
	int FindVertex(SeqList<T>&L, const T& vertex);
	//���ض���vertext�ڶ�����е�λ��(���)
	int GetVertexPos(const T& vertex)
public:
	//������
	Graph(void);
	//De������
	virtual ~Graph() {}
	//���ͼ�Ƿ�Ϊ��
	int GraphEmpty(void) const {
		return VertexList.ListEmpty();
	}
	//�����Ƿ������ݵķ���
	//����ͼ�Ķ������
	int NumberOfVertices(void) const {
		return graphsize;
	}
};//!_class Graph

