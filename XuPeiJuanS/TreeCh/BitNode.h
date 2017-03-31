#pragma once
#include "stdafx.h"
//http://blog.csdn.net/u014492609/article/details/40477795

//class BitNode {
//public:
//
//	BitNode() {}
//
//	virtual ~BitNode() {}
//};

/* �������Ķ��������洢�ṹ����*/
typedef enum { Link, Thread }PointerTag;    //Link = 0��ʾָ�����Һ���ָ�룻Thread = 1��ʾָ��ǰ�����̵�����  

typedef struct BitNode {
	char data;                       //�������  
	struct BitNode *lchild, *rchild; //���Һ���ָ��  
	PointerTag  ltag, rtag;          //���ұ�־  
}BitNode, *BiTree;

//��������ʵ�ʾ��ǽ����������еĿ�ָ���Ϊָ��ǰ�����̵�������
//����ǰ���ͺ����Ϣֻ���ڱ����ö�����ʱ���ܵõ���
//���ԣ��������Ĺ��̾����ڱ����Ĺ������޸Ŀ�ָ��Ĺ��̡�
//��������������ĵݹ麯���������£�

//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��  
BiTree pre;
//��������������������� ,����� BitNode* headnode,�������ɵ�����ͷ����
void InThreading(BiTree p) {
	if (p) {
		//�ݹ�������������  
		InThreading(p->lchild); 

		 //=== ���������� ===
		 /*�м䲿�ִ����������������飺
		 ��Ϊ��ʱp���ĺ�̻�û�з��ʵ���
		 ���ֻ�ܶ�����ǰ�����pre����ָ��rchild���жϣ�
		 if(!pre->rchild)��ʾ���Ϊ�գ���p����pre�ĺ�̣�
		 ����pre->rchild = p����������pre->rtag = Thread��
		 ��ɺ�̽�����������*/
		if (!p->lchild)           //û������  
		{
			p->ltag = Thread;    //ǰ������  
			p->lchild = pre; //����ָ��ָ��ǰ��
		}
		/*if (!p->lchild)��ʾ���ĳ������ָ����Ϊ�գ���Ϊ��ǰ�����ոշ��ʹ�����ֵ��pre�����Կ��Խ�pre��ֵ��p->lchild�����޸�p->ltag = Thread��Ҳ���Ƕ���Ϊ1�������ǰ��������������*/
		if (!pre->rchild)     //û���Һ���  
		{
			pre->rtag = Thread;  //�������  
			pre->rchild = p; //ǰ���Һ���ָ��ָ����(��ǰ���p)  
		}
		pre = p; //��ֵ ��ǰ���p �� ǰ�����pre
		//!_=== ���������� ===

		//�ݹ�������������  
		InThreading(p->rchild);
	}
}//!_void InThreading(BiTree p)

//������������ͷ�����head,ʧ���ˣ�д����
//��Σ���ͷ���������������Σ���ͷ����������
BitNode* CreateHeadInThreading(BitNode* p){
	BitNode* head;

	head->ltag = Link;
	head->lchild = p;

	head->rtag = Link;
	head->rchild;
}//!_BiTree CreateHeadInThreading

//tָ��ͷ��㣬ͷ�������lchildָ�����㣬ͷ�������rchildָ��������������һ����㡣  
//�������������������ʾ ����ͷ��������������t
bool InOrderThraverse_Thr(BiTree t) {
	BiTree p; //ͷ���
	p = t->lchild;				    //pָ������  
	while (p != t)                  //�������������ʱp == t  
	{
		while (p->ltag == Link)     //��ltag = 0ʱѭ�����������еĵ�һ�����  
		{
			p = p->lchild;
		}
		printf("%c ", p->data);     //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���  
		while (p->rtag == Thread && p->rchild != t) {
			p = p->rchild;
			printf("%c ", p->data);
		}
		p = p->rchild;              //p������������  
	}//!_while (p != t) 
	return true;
}//!_int InOrderThraverse_Thr(BiTree t)