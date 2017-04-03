#pragma once
#include "stdafx.h"
//�Ͻ��󣬴��뱾����д�,��α����
//���ڽӾ���洢��Graph�� ����

//template <typename T>
//class MGraph {
//public:
//
//	MGraph() {}
//
//	virtual ~MGraph() {}
//};

//���ڽӾ���洢��Graph�� ����
#define INFINITY std::numeric_limits<int>::max() //�������ֵ
#define MAX_VERTRIX_NUM 20 //�������ֵ
typedef enum { DG, DN, AG, AN } GraphKind;//ͼ������
//DGΪ����ͼ��DNΪ������
//AGΪ����ͼ��ANΪ������

//���ڽӾ���洢��Graph��
//��߻���㵥Ԫ�Ľṹ
//��ʾ�ڽӱ�ı߽��
template <typename T, typename VRType, typename InfoType>
class ArcCell {
public:
	VRType adj; // ͼ���б�����Ϊ1,�ޱ�����Ϊ0 ��������int
				//�����б�Ȩֵ���ޱ������
	InfoType* info;//����� //ָ��û������Ϣָ�� �������ö�����Ϣ����type[] *
};

//�ڽӾ���ȫ�ֱ���
typedef struct AdjMatrix {
	int AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM];
}AdjMatrix;

//�����������飬������SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //����
}VertexType;

//���ڽӾ���洢��Graph�� ����
template <typename T>
class MGraph {
public:
	VertexType vexs[MAX_VERTRIX_NUM]; //�����������飬������SeqList	
	AdjMatrix arcs; //�ڽӾ��󣬾���Ķ������ⲿ
	int vexnum; //��ǰ������
	int arcnum; //����
	GraphKind kind; //ͼ������

	//���췽��
	MGraph() {
		vexs = new int[MAX_VERTRIX_NUM]; //��̬��������
		//���ڽӾ��������Ԫ����Ϊ0
		for (int i = 0; i < MAX_VERTRIX_NUM; i++)
			for (int j = 0; j < MAX_VERTRIX_NUM; j++)
				arcs[i][j] = 0;
		vexnum = 0;
	}

	//�����ڽӾ����ʾ����������ͼ,���췽��
	bool CreateDG(MGraph<T> &G) {
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//�������ͱ���
		for (int i = 0; i < &G.vexnum; ++i) scanf(&G.vexs[i]);//����������
		//��ʼ���ڽӾ��󣬽��ڽӾ��������Ԫ����Ϊ0
		for (int i = 0; i < &G.vexnum; i++)
			for (int j = 0; j < &G.vexnum; j++)
				G.arcs[i][j] = { INFINITY,NULL }; //�����ǰ� �ڽӾ��� ���ڽӱ� ����һ����
		//���뻡�����ڽӾ���ֵ
		for (int k = 0; k < &G.arcnum; ++k) {
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1);
			int j = LocateVex(G, v2);
			G.arcs[i][j].adj = w; //�����ǰ� �ڽӾ��� ���ڽӱ� ����һ����
			if (IncInfo) Input(*G.arcs[i][j].info); //�����ǰ� �ڽӾ��� ���ڽӱ� ����һ����
		}
		return true;
	}//!_bool CreateDG()
};//!_class MGraph()



