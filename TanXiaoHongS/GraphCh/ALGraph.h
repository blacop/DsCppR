#pragma once
#include "stdafx.h"
//2 ���ڽӱ�洢��Graph�� ����

//�����������飬������SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //����
}VertexType;

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
	VRType adj; //�����ϵ����
	// ͼ���б�����Ϊ1,�ޱ�����Ϊ0 ��������int
				//�����б�Ȩֵ���ޱ������
	InfoType* info;//����� //ָ��û������Ϣָ�� �������ö�����Ϣ����type[] *
};

//2 ���ڽӱ�洢��Graph�� ����
//�ͻ���ص���Ϣ��Ա�ṹ//����Ȩֵ
typedef struct InfoType {
	int cost; //����Ȩֵ
}InfoType;
//2 ���ڽӱ�洢��Graph�࣬���߽�������������� ����
typedef struct ArcNode {
	int adjvex; //�û���ָ�����������е�λ�ã��±꣩ data domain 1
	struct ArcNode* nextarc; //ָ����һ���� ��һ���ڽӵ� ref domain
	InfoType* info; //�ͻ���ص���Ϣ //����Ȩֵ data domain 2
}ArcNode;
//������Ϣ �������飬ͷ������� ��㶨��
typedef struct VNode {
	VertexType data;  //������Ϣ//�����������飬������SeqList��data domain
	ArcNode* firstarc; //ָ����һ���ڽӵ� ref domain
}VNode, AdjList[MAX_VERTRIX_NUM];//������Ϣ��������

//���ڽӱ�洢��Graph�� ����
template<typename T>
class ALGraph {
public:
	AdjList vertices; //ͷ�������
	int vexnum; //������
	int arcnum; //����
	int kind; //��������

	 //�����ڽӾ����ʾ����������ͼ,���췽��
	bool CreateN(MGraph<T> &G) {
		//��ʼ���ڽӱ� ͷ����, ����Ԫ���ֶ����룬�������������������Ϣ��Ȩֵ��
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//�������ͱ���
		for (int i = 0; i < &G.vexnum; ++i) {
			scanf(&G.vertices[i].data);//����������
			G.vertices[i].firstarc = NULL; //�������ÿ�
		}
		//���뻡�����ڽӱ� ��߽��� ��ֵ
		for (int k = 0; k < G.arcnum; ++k) {
			//����Ԫ���ֶ����룬����1ֵ������2ֵ��Ȩֵ
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1); //Ѱ�ҽ��1λ��
			int j = LocateVex(G, v2); //Ѱ�ҽ��2λ��
									  //2���㹹��һ����
			p = new ArcNode(); //�����µı���
			p.adjvex = j; //��������� Ϊ v2
			p.nextarc = G.vertics.firstarc; //��ͷ�������ͷ���������һ������ step1
			G.vertics.firstarc;  //��ͷ�������ͷ���������һ������ step2
			if (IncInfo) Input(*p.info); //����Ȩֵ
		}
		return true;
	}//!_bool CreateN()
	 //class ALGraph {
	 //public:
	 //
	 //	ALGraph() {}
	 //
	 //	virtual ~ALGraph() {}
	 //};

	 //������ȱ���
	bool visited[MAX_VERTRIX_NUM]; //����״̬��
	bool(*VisitFunc)(int v);  //ί�У����ʽ��	
							  //������ȱ���
	void DFSTraverse(ALGraph G, bool(*Visit(int v))) { //������ȱ��� Tan
		VisitFunc = Visit; //ί�У����ʽ��;ί�и�ֵ ���ʺ���
		for (int v = 0; v < G.vexnum; ++v)  //��ʼ�� ����״̬��
			visited[v] = false;
		for (int v = 0; v < G.vexnum; ++v) { //���� �ӵ�һ�������һ���ڽӵ�
			if (!visited[v]) DFS(G, v);//������ȱ����㷨 ���� �ݹ����
		}
	}
	void DFS(ALGraph G, int v) { //������ȱ����㷨 ���� �ݹ����
		visited[v] = true; //����״̬�����
		VisitFunc(v); //ί�е���
					  //�ҵ���һ���ڽӵ㣬wΪtrue,����һ���ڽӵ�
		for (int w = FirstAdjVex(G��v); w; w = NextAdjVex(G, v, w))
			if (!visited[w]) DFS(G, w); //������ȱ����㷨 ���� �ݹ����
	}

	//������ȱ��� Tan ��α������ƹ�
	void BFSTravese(ALGraph G, bool(*Visit(int v))) {
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



};//!_bool CreateN(MGraph<T> &G)

