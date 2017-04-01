#include <stdio.h>
#include <stdlib.h>
#define TRUE	    1
#define FALSE		0
#define OK			1
#define ERROR		0
#define INFEASIBLE  -1
#define OVERFLOW	-2
typedef int ElemType;
typedef int Status;
//------���Ա�Ķ�̬����˳��洢�ṹ--------
#define MAXSIZE 20 //���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INIT_SIZE	20	//���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT	10	//���Ա�洢�ռ�ķ�������
/*
ADT ���Ա� List
���ݶ��� Data : D = { ai | ai�� ElemSet,i = 1,2,...,n,n >= 0 }
//���Ա�����ݶ��󼯺�Ϊ{ a,a2,--,an }, ÿ��Ԫ�ص����;�ΪDataType
���ݹ�ϵ Relation : Rl={<ai-1,ai>|ai-1,ai�� D,i=2,...,n}
�������� Operation
//���Ա�Ļ��������б� CORE
InitList(&L) //��ʼ�����Ա�L  01 ��ʼ��
DestroyList(&L) //�������Ա�L 02 ����
ClearList(&L) //������Ա�L 03 ���
ListEmpty(L) //�ж����Ա��Ƿ�Ϊ��  04 Ϊ��
ListLength(L) //�����Ա�L�ĳ���  05 ����
GetElem(L, i, &e) //ȡ���Ա�L�ĵ�i��Ԫ��  06 ����
LocateElem(L, e, compare(e1, e2)) //��λ�������Ա�L��Ԫ��e  07 ��λ
PriorElem(L, cur_e, &prio_e) //�������Ա�L��Ԫ��e��ֱ��ǰ��Ԫ�� 08 ǰ��
NextElem(L, cur_e, &next_e) //�������Ա�L��Ԫ��e��ֱ�Ӻ��Ԫ�� 09 ���
ListInsert(&L, i, e) //�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e,����Bool 10 ����
ListDelete(&L, i, e) //ɾ�����Ա�L�ĵ�i��Ԫ��,��ɾ��Ԫ��e��ֵ,����Bool  11 ɾ��
ListTraverse(L, visit(e)) //�������Ա�:���ζ�L��ÿ��Ԫ�ص���visit()  12 ����
//----ѡ��Electives----
visit(e) // һ����ָ��������ṹ�ж�ĳ���ڵ����ݽ��з��ʵĺ��� 13
compare(e1,e2) //�Ƚ�����Ԫ�صĴ�С,����Bool 14.a
compareList(L1,L2) //�Ƚ��������Ա�L�Ĵ�С,����Bool 14.b
union() //�󲢼� 15.a
mergeList(&L1,L2) //�󲢼�&&�������� �ϲ��������Ա�L 15.b
different() //�� 15.c
ListAppend() //β������Ԫ��,β�� 15.d
exchange() //����һ�������Ա�L�е����������Ա�L 16
endADT List
*/
typedef struct SqList {
	ElemType data[MAXSIZE];//����洢����Ԫ�أ��������ΪMAXSIZE
	int length;//����
}SqList;
Status InitList(SqList *L) {
	//����ûдInitList
	//��ʼ���յ����Ա�,&L ���ò�����ʾ���޸�ֵ
	//�Լ�дһ�£����������,�Ҽǵã�base���÷��ڽṹ�����ֺ���Ԫ�� ����������
	SqList *L;
	L��L.data = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//�����ڴ棬����void*ָ�룬����ǿתһ��
	if (!L) exit(OVERFLOW);//OVERFLOW�Ƿ��ص�OS��
	L.length = 0;
	//L.listSize = LIST_INIT_SIZE;
	return TRUE;
}

/*
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
	while (i <= L.length && !(*equal)(*p++, e)) ++i;
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
	while (i <= L.length && !(cur_e == L.elem[i - 1])) ++i;// until, legal && !== node1,i++
	if (i<2 || i>L.length) //i=1 ��ʾû��ǰ��
		return ERROR;
	pre_e = L.elem[i - 2];//cur_e =L.elem[i - 1]
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
	//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length && !(cur_e == L.elem[i - 1])) ++i;
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
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
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
*/