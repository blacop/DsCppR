//Common.h head
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Status int
#define ElemType int
typedef int Status
typedef int ElemType
#define LEN sizeof(ElemType)
#define MLC (ElemType *)malloc
#define MLCS (ElemType *)malloc(sizeof(ElemType))
#define MAX_SIZE 100;//�����ռ�
#define LIST_INIT_SIZE = 100;//���ʼ����ռ�
#define LIST_INCREMENT = 10;//�ռ��������
//Common.h end

//Triplet.h head
//������������Triplet�ı�ʾ��ʵ��
//���ö�̬�����˳��洢�ṹ---
typedef ElemType * Triplet;//��InitTriplet����3��Ԫ�ش洢�ռ�
//--------------���������ĺ�������˵��----------------
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
//�����������������Ԫ��T,Ԫ��e1,e2��e3��ֵ�ֱ𱻸��Բ���v1��v2��v3��ֵ��

Status DestroyTriplet(Triplet &T);
//�����������Ԫ��T�����١�

Status Get(Triplet T, int i, ElemType &e);
//��ʼ��������Ԫ��T�Ѵ��ڣ�1<=i<=3��
//�����������e����T�ĵ�iԪ��ֵ

Status Put(Triplet &T, int i, ElemType e);
//��ʼ��������Ԫ��T�Ѵ��ڣ�1<=i<=3��
//����������ı�T�ĵ�iԪ��ֵΪe��

Status IsAscending(Triplet T);
//��ʼ��������Ԫ��T�Ѵ��ڡ�
//��������������Ԫ��T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��

Status IsDescending(Triplet T);
//��ʼ��������Ԫ��T�Ѵ��ڡ�
//��������������Ԫ��T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��

Status Max(Triplet T, ElemType &e);
//��ʼ��������Ԫ��T�Ѵ��ڡ�
//�����������e����T��3��Ԫ���е����ֵ��

Status Min(Triplet T, ElemType &e);
//��ʼ��������Ԫ��T�Ѵ��ڡ�
//�����������e����T��3��Ԫ���е���Сֵ��
//Triplet.h end

//Triplet.cpp head
#include <iostream>
#include <stdlib.h>
#include "Common.h"
#include "Triplet.h"
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{	//�����������������Ԫ��T,Ԫ��e1,e2��e3��ֵ�ֱ𱻸��Բ���v1��v2��v3��ֵ��

	T = (ElemType *)malloc(3 * sizeof(ElemType));
	if (!T) exit(OVERFLOW);	//����洢�ռ�ʧ��
	T[0] = v1; T[1] = v2; T[2] = v3;
	return OK;
} //InitTriplet

Status DestroyTriplet(Triplet &T)
{	//�����������Ԫ��T�����١�

	free(T);
	T = NULL;
	return OK;
} //DestroyTriplet

Status Get(Triplet T, int i, ElemType &e) {
	//��e����T�ĵ�iԪ��ֵ

	if (i<1 || i>3)
		return ERROR;
	e = T[i - 1];
	return OK;
} //Get

Status Put(Triplet &T, int i, ElemType e) {
	//1<=i<=3��
	//�ı�T�ĵ�iԪ��ֵΪe��

	if (i<1 || i>3)
		return ERROR;
	T[i - 1] = e;
	return OK;
} // Put

Status IsAscending(Triplet T) {
	//�����Ԫ��T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��

	return (T[0] >= T[1]) && (T[1] >= T[2]);
} //IsAscending

Status IsDescending(Triplet T) {
	//�����Ԫ��T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��

	return (T[0] <= T[1]) && (T[1] <= T[2]);
} //IsDescending

Status Max(Triplet T, ElemType &e) {
	//��e����T��3��Ԫ���е����ֵ��

	e = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2]) : ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}

Status Min(Triplet T, ElemType &e) {
	//��e����T��3��Ԫ���е���Сֵ��

	e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}
//Triplet.cpp end

//main.cpp head
#include <iostream>
#include <stdlib.h>
#include "Triplet.h"

int main()
{
	Triplet triplet;  //����һ����Ԫ��
	ElemType  e;
	int i;

	InitTriplet(triplet, 4, 7, 5);

	for (i = 0; i<3; i++)
	{
		Get(triplet, i + 1, e);
		printf("%d %d\n", triplet[i], e);
	}

	e = 13;
	Put(triplet, 2, e);
	for (i = 0; i<3; i++)
		printf("%d ", triplet[i]);
	printf("\n");

	if (IsAscending(triplet))
		printf("����\n");
	else {
		if (IsDescending(triplet))
			printf("����\n");
		else
			printf("����\n");
	}

	Max(triplet, e);
	printf("���ֵ�� %d\n", e);
	Min(triplet, e);
	printf("��Сֵ�� %d\n", e);

	system("pause");
	return 0;
}
//main.cpp end