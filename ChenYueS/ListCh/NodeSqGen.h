//���ṹ��
#pragma once
#include "stdafx.h"

//class LNodeGen {
//public:
//
//	LNodeGen() {}
//
//	virtual ~LNodeGen() {}
//};

//�������Ա� ˳���������
//typedef int Position;
//template <typename T>
//typedef class LNode<T> *List;
//template <typename T>
//class LNode {
//public:
//	T Data[MAXSIZE];
//	Position Last;
//
//	LNode() {}
//	virtual ~LNode() {}
//};

//template <typename ElementType>
//���Ա�˳���������

#define ElementType int
const int MAXSIZE = 50;
typedef int Position;

//template <typename ElementType>
//typedef struct LNode<T>* List;

typedef struct LNode* List;

//template <typename ElementType>
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};


/* ��ʼ�� */
List MakeEmpty() {
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}

/* ���� */
#define ERROR -1

Position Find(List L, ElementType X) {
	Position i = 0;

	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)  return ERROR; /* ���û�ҵ������ش�����Ϣ */
	else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}

/* ���� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Insert(List L, ElementType X, Position P) { /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
	Position i;

	if (L->Last == MAXSIZE - 1) {
		/* ��ռ����������ܲ��� */
		printf("����");
		return false;
	}
	if (P<0 || P>L->Last + 1) { /* ������λ�õĺϷ��� */
		printf("λ�ò��Ϸ�");
		return false;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i + 1] = L->Data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
	L->Data[P] = X;  /* ��Ԫ�ز��� */
	L->Last++;       /* Last��ָ�����Ԫ�� */
	return true;
}

/* ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Delete(List L, Position P) { /* ��L��ɾ��ָ��λ��P��Ԫ�� */
	Position i;

	if (P<0 || P>L->Last) { /* ���ձ�ɾ��λ�õĺϷ��� */
		printf("λ��%d������Ԫ��", P);
		return false;
	}
	for (i = P + 1; i <= L->Last; i++)
		L->Data[i - 1] = L->Data[i]; /* ��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ� */
	L->Last--; /* Last��ָ�����Ԫ�� */
	return true;
}

