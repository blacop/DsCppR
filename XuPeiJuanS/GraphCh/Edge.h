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
//�߽��Ľṹ
template<typename T>
struct Edge {
	//��Ԫ��
	friend class Graph<T>;

	int VerAdj; //���ڽӶ������	data domain 1
	int cost;	//�˱ߵ�Ȩֵ	data domain 2
	Edge* link; //ָ����һ���߽���ָ�� ref domain

	//���캯��
	Edge<T>(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
};
