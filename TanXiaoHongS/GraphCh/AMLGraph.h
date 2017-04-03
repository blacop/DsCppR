#pragma once
#include "stdafx.h"
//����ͼ�Ķ�������洢��ʽ����

//���ڽӾ���洢��Graph�� ����
#define INFINITY std::numeric_limits<int>::max() //�������ֵ
#define MAX_VERTRIX_NUM 20 //�������ֵ
typedef enum { DG, DN, AG, AN } GraphKind;//ͼ������
//DGΪ����ͼ��DNΪ������
//AGΪ����ͼ��ANΪ������

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

//���ʱ�ʶ
typedef enum { unvisited, visited } VisitIf;
//�ڽӶ��ر���
typedef struct Ebox {
	VisitIf mark; //���ʱ�ʶ
	int ivex, jvex;
	struct Ebox *ilink, *jlink;
	InfoType *info;
}Ebox;
//���������
typedef struct VexBox {
	VertexType data; //������
	Ebox *firstedge; //������
}VexBox;

//����ͼ�Ķ�������洢��ʽ����
template <typename T>
class AMLGraph {
public:
	VexBox adjmulist[MAX_VERTRIX_NUM]; //���������
	int vexnum; //������
	int arcnum; //������

	//AMLGraph() {}

	//virtual ~AMLGraph() {}
};