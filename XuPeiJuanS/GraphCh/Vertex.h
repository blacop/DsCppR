#pragma once
#include "stdafx.h"
#include "Edge.h"
//class Vertex {
//public:
//
//	Vertex() {}
//
//	virtual ~Vertex() {}
//};

//2 ���ڽӱ�洢��Graph��
//Graph�������
//������н��Ľṹ
template<typename T>
struct Vertex {
	//��Ԫ��
	friend class Graph<T>;
	//���������
	T VerName;
	//�������ͷָ��
	Edge* adjacent;
};

