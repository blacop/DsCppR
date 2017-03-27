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
单链表各种操作的C语言实现（一） 2010-07-31 13:41:43
http://blog.chinaunix.net/uid-20788636-id-1841324.html
分类： C/C++
  最近，从新复习了一下数据结构中比较重要的几个部分，现在把自己的成果记录下来，主要就是仿照严蔚敏的《数据结构》（C 语言版），中的例子和后面的习题进行改编的。首先，是单链表的各种实现，其中，包含了一些常考的知识点。例如，单链表的逆置，单链表的合并，找到单链表的中间节点等的算法实现。
下面这个是单链表的结构体的定义： */
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkList;
/*
  下面的基本的单链表的操作：其中，有一些宏，没有给出他们的一些定义，者可以通过，严蔚敏的《数据结构》（C 语言版），查看得到。
  */
Status InitList(struct LNode *L) { /* 功能：构建一个空的带头节点的单链表*/
	(*L) = (struct LNode *)malloc(sizeof(struct LNode)); //产生头节点
	if (!*L)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}
Status DestroyList(struct LNode *L) { /*销毁线性表*/
	//pHead == L
	struct LNode *q;//temp ptr, q <==> L->next
	while (L) {
		q = L->next;//q++
		free(L);//free l //从头开始free(),一直到最后一个
		L = q;//L++
	}
	return OK;
}
Status ClearList(struct LNode *L) { /*将L重置为空表*/
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
Status ListEmpty(LinkList *L) { /*判断链表是否为空表*/
	if (L->next) {
		return FALSE;
	} else {
		return TRUE;
	}
}
int ListLength(struct LNode *L) { /*返回单链表中元素的个数*/
	int i = 0;
	LinkList *p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
Status GetElem(struct LNode *L, int i, ElemType *e) {
	/* L为带头节点的单链表的头指针，当第i个元素存在时，其值赋给e,并返回OK */
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
	/*返回L中第一个与e满足关系compare()的数据元素的位序，
	若给存在返回值为0，compare()是数据元素的判定函数*/
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
	/*所cur_e是L中的数据元素，且给就第一个，则用pre_e返回它的前驱*/
	LinkList *q, *p = L->next;//p<==>node1 //2 assist Ptr
	while (p->next) {
		q = p->next;//q指向p的后继,q++, node2,no head(node0) because it's no data
		if (q->data == cur_e) { //后继's data is matching cur_e
			*pre_e = p->data; //out data is 后继's 前驱
			return OK;
		}
		p = q;//p++
	}
	return INFEASIBLE;
}
Status NextElem(struct LNode *L, ElemType cur_e, ElemType *next_e) {
	/* 若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继*/
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
	/* 在带头节点的单链表L中的第i个位置之前(before i means index == i-2)插入元素e*/
	int j = 0;
	struct LNode *p = L, *s = NULL; //2 assist Ptr,2个辅助指针
	while (p && j < i - 1) {
		//Loc(i)'s index==(i-1),before i means index ==(i-2) 找到 第(i-1)个位置,插入其后
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
	/*在带头节点的单链表中删除第i个元素，并有e返回其值*/
	LinkList *p = L, *q; //2 assist Ptr,2个辅助指针
	int j = 0;
	while (p->next && j < i - 1) { // find Loc(i-1)== find index==(i-2)
		p = p->next; //p++
		j++; // now p's Loc is Loc(i-1).
	}
	if (!p->next || j > i - 1)//becase j must cirle (i-1) times.
		return ERROR;
	q = p->next;//q finger to p's 后继Subsequent,p is i's 前驱precursor,
	p->next = q->next;//
	*e = q->data; //out data
	free(q);
	return OK;
}
Status ListTraverse(struct LNode *L, void(*visit)(ElemType)) {
	/* 依次对L的每个元素调用vi(),打印输出语句*/
	LinkList *p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}