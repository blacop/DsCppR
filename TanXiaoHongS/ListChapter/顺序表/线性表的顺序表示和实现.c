//head Common.h 
#define TRUE	    1
#define FALSE		0
#define OK			1
#define ERROR		0
#define INFEASIBLE  -1
#define OVERFLOW	-2
typedef int Status;
//end Common.h 
//head SqList.h
//------���Ա�Ķ�̬����˳��洢�ṹ--------
#include <stdlib.h>
#include "Common.h"
#define ElemType int
#define LIST_INIT_SIZE	100	//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT	10	//���Ա�洢�ռ�ķ�������
typedef struct {
	ElemType* elem;	//�洢�ռ��ַ
	int length;			//��ǰ����
	int listsize;		//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
} SqList;
/*
//��������
Status InitList(SqList &L);
//�������������һ���յ����Ա�L��

Status DestroyList(SqList &L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//����������������Ա�L��

Status ClearList(SqList &L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������L����Ϊ�ձ�

bool ListEmpty(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��

int ListLength(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�������������L������Ԫ�صĸ�����

Status GetElem(SqList L, int i, ElemType &e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)��
//�����������e����L�е�i������Ԫ�ص�ֵ��

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�������
//����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0.

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣

Status ListInsert(SqList &L, int i, ElemType e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1.
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1.

Status ListDelete(SqList &L, int i, ElemType &e);
//��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L).
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1.

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//��ʼ���������Ա�L�Ѵ���
//������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ�
//SqList.h end
*/
//head SqList.cpp
#include <malloc.h>
#include "SqList.h"
Status InitList(SqList &L) {
	//�������������һ���յ����Ա�L��
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);	//�洢����ʧ��
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList
Status DestroyList(SqList &L) {
	//����������������Ա�L��
	free(&L);
	return OK;
}
Status ClearList(SqList &L) {
	//�����������L����Ϊ�ձ�
	L.length = 0;
	return OK;
}
bool ListEmpty(SqList L) {
	//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��
	if (0 == L.length) return true;
	else return false;
}
int ListLength(SqList L) {
	//�������������L������Ԫ�صĸ�����
	return L.length;
}
Status GetElem(SqList L, int i, ElemType &e) {
	//1<=i<=ListLength(L)��
	//�����������e����L�е�i������Ԫ�ص�ֵ��
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];	//e=*(L.elem+i-1);
						// <== p +(-)n*sizeof(������)
						//p[i] = *(p + i) ;
	//��Ϊ�����ָ����������,���Բſ����������� 
	return OK;
}
int LocateElem(SqList L, ElemType e, bool(*equal)(ElemType, ElemType)) {
	//Status (*equal)(ElemType, ElemType)������һ��������ָ�롱�����������ָ�롱����ָ��ĳһ�������ú���Ҫ��������Ҫ�󣺷���ֵΪStatus��Ҳ��int������������������ΪElemType�Ĳ��������庯��ָ����Ϊ��ĳЩ�����ϵ�ͳһ��
	//equal()������Ԫ���ж�������
	//����L�е�һ����e�����ϵequal()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0.
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length  &&  !(*equal)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return 0;
}
bool equal(ElemType e1, ElemType e2) {
	//equal()������Ԫ���ж�������
	if (e1 == e2) {
		return true;
	}
	else {
		return false;
	}
}
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
	//�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length  && !(cur_e == L.elem[i - 1])) ++i;// until, legal && !== node1,i++
	if (i<2 || i>L.length) //i=1 ��ʾû��ǰ��
		return ERROR;
	pre_e = L.elem[i - 2];//cur_e =L.elem[i - 1]
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
	//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length  && !(cur_e == L.elem[i - 1])) ++i;
	if (i<2 || i>L.length)
		return ERROR;
	next_e = L.elem[i];//cur_e =L.elem[i - 1]
	return OK;
}
Status ListInsert(SqList &L, int i, ElemType e) {
	//1<=i<=ListLength(L)+1. beacause length can +1.
	//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1.
	if (i < 1 || i>L.length + 1) return ERROR;	//iֵ���Ϸ�
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType * q = &(L.elem[i - 1]);	//qΪ����λ�� get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	ElemType * p;
	for (p = &(L.elem[L.length - 1]); p >= q; --p) // p=&(last);p >= q;--p
		*(p + 1) = *p;	//���� right move , cur+1=cur

	*q = e;//assignment
	++L.length;
	return OK;
}//ListInsert
Status ListDelete(SqList &L, int i, ElemType &e) {
	//1<=i<=ListLength(L).
	//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1.
	if (i<1 || i>L.length) return ERROR; //iֵ���Ϸ�
	ElemType * p = &(L.elem[i - 1]); //pΪdelλ�� get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	e = *p;
	ElemType * q = L.elem + L.length - 1; //q =&(last)
	for (++p; p <= q; ++p) *(p - 1) = *p; // left move , cur-1=cur
	--L.length;
	return OK;
}
Status ListTraverse(SqList L, bool(*visit)(ElemType)) {
	//������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ�
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && (*visit)(*p++)) ++i;
	return OK;
}
Status visit(ElemType e) {
	//���ʽڵ�,����bool,��ӡc,ֵ���ⲿ����
	printf("%d\t", e);
	return TRUE;
}
//end SqList.cpp