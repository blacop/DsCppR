#pragma once
#include "stdafx.h"
//����ͼ��ʮ������洢��ʽ˵��

//class OLGraph {
//public:
//
//	OLGraph() {}
//
//	virtual ~OLGraph() {}
//};
//--------------------

//�����������飬������SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //����
}VertexType;

//2 ���ڽӱ�洢��Graph�� ����
//�ͻ���ص���Ϣ��Ա�ṹ//����Ȩֵ
typedef struct InfoType {
	int cost; //����Ȩֵ
}InfoType;

//����ͼ��ʮ������洢��ʽ˵����
//�߱���
typedef struct ArcBox {
	int tailvex, headvex;
	struct ArcBox *hlink, *tlink;
	InfoType *info;
}ArcBox;
//ͷ�������
typedef struct VexNode {
	VertexType data;
	ArcBox *firstin, *firstout;
}VexNode;
//����ͼ��ʮ������洢��ʽ˵��
template <typename T>
class OLGraph {
public:
	VexNode xlist[MAX_VERTRIX_NUM]; //ͷ�������
	int vexnum; //������
	int arcnum; //������
				//����ʮ������
	bool CreateOLG(OLGraph &G) {
		//��ʼ���ڽӱ� ͷ����, ����Ԫ���ֶ����룬�������������������Ϣ��Ȩֵ��
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//������,����,�����Ϣ��Ȩֵ��
											   //��ʼ��ͷ�������
		for (int i = 0; i < &G.vexnum; ++i) {
			scanf(&G.xlist[i].data);//����������,��������
			G.xlist[i].firstin = NULL; //�������ÿ�
			G.xlist[i].firstout = NULL; //�������ÿ�			
		}
		//��ʼ���߱��� //���뻡�����ڽӱ� ��߽��� ��ֵ
		for (int k = 0; k < G.arcnum; ++k) {
			//����Ԫ���ֶ����룬����1ֵ������2ֵ��Ȩֵ
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1); //Ѱ�ҽ��1λ�� ͷ
			int j = LocateVex(G, v2); //Ѱ�ҽ��2λ�� β
									  //2���㹹��һ����
			p = new ArcBox(); //�����µı���
			p.tailvex = j; //β��������� Ϊ v2
			p.headvex = i; //ͷ��������� Ϊ v1
			p.tlink = G.xlist[i].firstout;//��outβ��������ͷ���������һ������ step1
			G.xlist[i].firstout = p;  //��outβ��������ͷ���������һ������ step2
			p.hlink = G.xlist[j].firstin; //��inͷ��������ͷ���������һ������ step1
			G.xlist[j].firstin = p;	 //��inͷ��������ͷ���������һ������ step2
			if (IncInfo) Input(*p.info); //����Ȩֵ
		}
		return true;
	}//!_bool CreateOLG()
};//!_class OLGraph


