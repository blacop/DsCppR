#pragma once
#include "stdafx.h"
//class Edge {
//public:
//
//	Edge() {}
//
//	virtual ~Edge() {}
//};

//2 ���ڽӱ�洢��Graph��
//Graph�������
//�߽��Ľṹ
template<typename T>
struct Edge {
	//��Ԫ��
	friend class Graph<T>;
	//�ڽӶ������
	int VerAdj; 
	//�ߵ�Ȩֵ
	int cost;
	//ָ����һ���߽���ָ��
	Edge * link;
	//���캯��
	Edge() {};
	//���캯��
	Edge(int d, int c) :VerAdj(d), cost(c), link(NULL) {}
};
