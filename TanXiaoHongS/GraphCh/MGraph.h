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

//�ڽӾ���ȫ�ֱ���,ֵΪȨ
typedef struct AdjMatrix {
	int AdjMatrix[MAX_VERTRIX_NUM][MAX_VERTRIX_NUM];
}AdjMatrix;

//�����������ͣ�������int
typedef struct VertexType {
	//SeqList<int> VertexType;
	int VertexType; //int
}VertexType;

//���ڽӾ���洢��Graph�� ����
template <typename T, typename VRType, typename InfoType>
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

	 //������ȱ���
	bool visited[MAX_VERTRIX_NUM]; //����״̬��
	bool(*VisitFunc)(int v);  //ί�У����ʽ��	
							  //������ȱ���
	void DFSTraverse(MGraph G, bool(*Visit(int v))) { //������ȱ��� Tan
		VisitFunc = Visit; //ί�У����ʽ��;ί�и�ֵ ���ʺ���
		for (int v = 0; v < G.vexnum; ++v)  //��ʼ�� ����״̬��
			visited[v] = false;
		for (int v = 0; v < G.vexnum; ++v) { //���� �ӵ�һ�������һ���ڽӵ�
			if (!visited[v]) DFS(G, v);//������ȱ����㷨 ���� �ݹ����
		}
	}
	void DFS(MGraph G, int v) { //������ȱ����㷨 ���� �ݹ����
		visited[v] = true; //����״̬�����
		VisitFunc(v); //ί�е���
					  //�ҵ���һ���ڽӵ㣬wΪtrue,����һ���ڽӵ�
		for (int w = FirstAdjVex(G��v); w; w = NextAdjVex(G, v, w))
			if (!visited[w]) DFS(G, w); //������ȱ����㷨 ���� �ݹ����
	}

	//������ȱ��� Tan ��α������ƹ�
	void BFSTravese(MGraph G, bool(*Visit(int v))) {
		for (int v = 0; v < G.vexnum; ++v)  //��ʼ�� ����״̬��
			visited[v] = false;
		InitQueue(Q); //new ����
		for (int v = 0; v < G.vexnum; ++v)
			if (!visited[v]) { //��鵽δ���ʣ��ݹ����
				visited[v] = true; //����״̬�����
				Visit(v); //���ʽ��
				EnQueue(Q, u); //���
				while (!QueueEmpty(Q)) { //���� �ǿ�
					DeQueue(Q, u); //����
								   //�ҵ���һ���ڽӵ㣬wΪtrue,����һ���ڽӵ�
					for (int w = FirstAdjVex(G��v); w; w = NextAdjVex(G, v, w))
						if (!visited[w]) {
							visited[w] = true; //����״̬�����
							Visit(w); //���ʽ��
							EnQueue(Q, w); //���
						}//!_if
				}//!_while
			}//!_if
	}//!_BFSTravese

	//Prim�㷨
	void MiniSpanTree_Prim(MGraph G, VertexType u) {
		struct {//��¼�ɶ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
			VertexType adjvex;//������������
			VRType lowcost; //�����ϵ���� ��������int//�ڽӾ���ȫ�ֱ���,ֵΪȨ
							// ͼ���б�����Ϊ1,�ޱ�����Ϊ0 
				//�����б�Ȩֵ���ޱ������
		}closedge[MAX_VERTRIX_NUM];
		K = LocateVex(G, u); //��λu
		for (int j = 0; j < G.vexnum; ++j)
			if (j != k) closedge[j] = { u,G.arcs[k][j].adj };//��������//�ڽӾ���ȫ�ֱ���,ֵΪȨ
		closedge[k].lowcost = 0; //Ȩֵ��Ϊ0
		for (int i = 1; i < G.vexnum; ++i) {
			k = mininum(closedge); //ȡ��СȨֵ
			printf(closedge[k].adjvex, G.vexs[k]); //��� �������� ������������
			closedge[k].lowcost = 0; //Ȩֵ��Ϊ0
			for (int j = 0; j < G.vexnum; ++j)
				if (G.arcs[k][j].adj < closedge[j].lowcost) //�ڽӾ����
					closedge[j] = { G.vexs[k],G.arcs[k][j].adj };
		}

	}//!_MiniSpanTree_Prim()

};//!_class MGraph()



