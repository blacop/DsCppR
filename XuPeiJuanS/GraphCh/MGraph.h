#pragma once
#include "stdafx.h"

//template <typename T>
//class MGraph {
//public:
//
//	MGraph() {}
//
//	virtual ~MGraph() {}
//};

//���ڽӾ���洢��Graph��
//Graph������
#define INFINITY INT_MAX //�������ֵ
#define MAX_VERTRIX_NUM 20 //�������ֵ
typedef enum {DG,DN,AG,AN} GraphKind;
//DGΪ����ͼ��DNΪ������
//AGΪ����ͼ��ANΪ������
typedef struct ArcCell {
	// ͼ���б�1,�ޱ�0 ��������int
	//�����б�Ȩֵ���ޱ������
	//VRType adj; 			
	//�����
	//InfoType *info //ָ��û������Ϣָ�� �������ö�����Ϣ����type[] *
}ArcCell;
//�ڽӾ���
// AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM]; 
//���ڽӾ���洢��Graph��
//Graph������
typedef struct {
	//��������
	//VertexType vexs[MAX_VERTRIX_NUM];
	////�ڽӾ���
	//AdjMatrix arcs;
	//�������ͱ���
	int vexnum, arcnum;
	//ͼ������
	GraphKind kind;
}MGraph;
