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
//������н��Ľṹ
template<typename T>
struct Vertex {
	//��Ԫ��
	friend class Graph<T>;

	T VerName; //��������� 	data domain ,store node value
	Edge<T>* adjacent; //�������ͷָ�� ref domain
};

