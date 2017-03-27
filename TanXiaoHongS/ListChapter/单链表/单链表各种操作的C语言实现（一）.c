#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
/*
��������ֲ�����C����ʵ�֣�һ�� 2010-07-31 13:41:43
http://blog.chinaunix.net/uid-20788636-id-1841324.html
���ࣺ C/C++
  ��������¸�ϰ��һ�����ݽṹ�бȽ���Ҫ�ļ������֣����ڰ��Լ��ĳɹ���¼��������Ҫ���Ƿ�����ε���ġ����ݽṹ����C ���԰棩���е����Ӻͺ����ϰ����иı�ġ����ȣ��ǵ�����ĸ���ʵ�֣����У�������һЩ������֪ʶ�㡣���磬����������ã�������ĺϲ����ҵ���������м�ڵ�ȵ��㷨ʵ�֡�
��������ǵ�����Ľṹ��Ķ��壺 */
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkList;
/*
  ����Ļ����ĵ�����Ĳ��������У���һЩ�꣬û�и������ǵ�һЩ���壬�߿���ͨ������ε���ġ����ݽṹ����C ���԰棩���鿴�õ���
  */
Status InitList(struct LNode *L) { /* ���ܣ�����һ���յĴ�ͷ�ڵ�ĵ�����*/
	(*L) = (struct LNode *)malloc(sizeof(struct LNode)); //����ͷ�ڵ�
	if (!*L)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}
Status DestroyList(struct LNode *L) { /*�������Ա�*/
	//pHead == L
	struct LNode *q;//temp ptr, q <==> L->next
	while (L) {
		q = L->next;//q++
		free(L);//free l //��ͷ��ʼfree(),һֱ�����һ��
		L = q;//L++
	}
	return OK;
}
Status ClearList(struct LNode *L) { /*��L����Ϊ�ձ�*/
	LinkList *p, *q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
Status ListEmpty(LinkList *L) { /*�ж������Ƿ�Ϊ�ձ�*/
	if (L->next) {
		return FALSE;
	} else {
		return TRUE;
	}
}
int ListLength(struct LNode *L) { /*���ص�������Ԫ�صĸ���*/
	int i = 0;
	LinkList *p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
Status GetElem(struct LNode *L, int i, ElemType *e) {
	/* LΪ��ͷ�ڵ�ĵ������ͷָ�룬����i��Ԫ�ش���ʱ����ֵ����e,������OK */
	int j = 1;
	LinkList *p = L->next;
	while (p && j < i) { //until i-1
		p = p->next; //p++
		j++;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}
int LocateElem(struct LNode *L, ElemType e, Status(*compare) (ElemType, ElemType)) {
	/*����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��
	�������ڷ���ֵΪ0��compare()������Ԫ�ص��ж�����*/
	int i = 0;
	LinkList *p = L->next;
	while (p) {
		i++;
		if (compare(p->data, e))//compare(*p,e) which SqList
			return i;
		p = p->next;//p++ which SqList
	}
	return 0;
}
Status PriorElem(struct LNode *L, ElemType cur_e, ElemType *pre_e) {
	/*��cur_e��L�е�����Ԫ�أ��Ҹ��͵�һ��������pre_e��������ǰ��*/
	LinkList *q, *p = L->next;//p<==>node1 //2 assist Ptr
	while (p->next) {
		q = p->next;//qָ��p�ĺ��,q++, node2,no head(node0) because it's no data
		if (q->data == cur_e) { //���'s data is matching cur_e
			*pre_e = p->data; //out data is ���'s ǰ��
			return OK;
		}
		p = q;//p++
	}
	return INFEASIBLE;
}
Status NextElem(struct LNode *L, ElemType cur_e, ElemType *next_e) {
	/* ��cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ��*/
	LinkList *p; //1 assist Ptr
	p = L->next; //node1
	while (p->next) { //have node
		if (p->data == cur_e) { //cur's data is matching
			*next_e = p->next->data; //out cur's next data 
			return OK;
		}
		p = p->next;//
	}
	return INFEASIBLE;
}
Status ListInsert(struct LNode *L, int i, ElemType e) {
	/* �ڴ�ͷ�ڵ�ĵ�����L�еĵ�i��λ��֮ǰ(before i means index == i-2)����Ԫ��e*/
	int j = 0;
	struct LNode *p = L, *s = NULL; //2 assist Ptr,2������ָ��
	while (p && j < i - 1) {
		//Loc(i)'s index==(i-1),before i means index ==(i-2) �ҵ� ��(i-1)��λ��,�������
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (struct LNode *)malloc(sizeof(struct LNode));
	if (!s)
		printf("malloc error~\n");
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e) {
	/*�ڴ�ͷ�ڵ�ĵ�������ɾ����i��Ԫ�أ�����e������ֵ*/
	LinkList *p = L, *q; //2 assist Ptr,2������ָ��
	int j = 0;
	while (p->next && j < i - 1) { // find Loc(i-1)== find index==(i-2)
		p = p->next; //p++
		j++; // now p's Loc is Loc(i-1).
	}
	if (!p->next || j > i - 1)//becase j must cirle (i-1) times.
		return ERROR;
	q = p->next;//q finger to p's ���Subsequent,p is i's ǰ��precursor,
	p->next = q->next;//
	*e = q->data; //out data
	free(q);
	return OK;
}
Status ListTraverse(struct LNode *L, void(*visit)(ElemType)) {
	/* ���ζ�L��ÿ��Ԫ�ص���vi(),��ӡ������*/
	LinkList *p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}