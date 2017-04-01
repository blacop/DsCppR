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
//------线性表的动态分配顺序存储结构--------
#include <stdlib.h>
#include "Common.h"
#define ElemType int
#define LIST_INIT_SIZE	100	//线性表存储空间的初始分配量
#define LISTINCREMENT	10	//线性表存储空间的分配增量
typedef struct {
	ElemType* elem;	//存储空间基址
	int length;			//当前长度
	int listsize;		//当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;
/*
//基本操作
Status InitList(SqList &L);
//操作结果：构造一个空的线性表L。

Status DestroyList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：销毁线性表L。

Status ClearList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：将L重置为空表。

bool ListEmpty(SqList L);
//初始条件：线性表L已存在。
//操作结果：若L为空表，则返回TRUE，否则返回FALSE。

int ListLength(SqList L);
//初始条件：线性表L已存在。
//操作结果：返回L中数据元素的个数。

Status GetElem(SqList L, int i, ElemType &e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//初始条件：线性表L已存在，compare()是数据元素判定函数。
//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0.

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。

Status ListInsert(SqList &L, int i, ElemType e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)+1.
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.

Status ListDelete(SqList &L, int i, ElemType &e);
//初始条件：线性表L已存在且非空，1<=i<=ListLength(L).
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1.

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//初始条件：线性表L已存在
//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。
//SqList.h end
*/
//head SqList.cpp
#include <malloc.h>
#include "SqList.h"
Status InitList(SqList &L) {
	//操作结果：构造一个空的线性表L。
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);	//存储分配失败
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList
Status DestroyList(SqList &L) {
	//操作结果：销毁线性表L。
	free(&L);
	return OK;
}
Status ClearList(SqList &L) {
	//操作结果：将L重置为空表。
	L.length = 0;
	return OK;
}
bool ListEmpty(SqList L) {
	//操作结果：若L为空表，则返回TRUE，否则返回FALSE。
	if (0 == L.length) return true;
	else return false;
}
int ListLength(SqList L) {
	//操作结果：返回L中数据元素的个数。
	return L.length;
}
Status GetElem(SqList L, int i, ElemType &e) {
	//1<=i<=ListLength(L)。
	//操作结果：用e返回L中第i个数据元素的值。
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];	//e=*(L.elem+i-1);
						// <== p +(-)n*sizeof(基类型)
						//p[i] = *(p + i) ;
	//因为数组的指针是连续的,所以才可以这样计算 
	return OK;
}
int LocateElem(SqList L, ElemType e, bool(*equal)(ElemType, ElemType)) {
	//Status (*equal)(ElemType, ElemType)：定义一个“函数指针”，这个“函数指针”用于指向某一函数，该函数要满足以下要求：返回值为Status（也即int），并且有两个类型为ElemType的参数。定义函数指针是为了某些功能上的统一。
	//equal()是数据元素判定函数。
	//返回L中第一个与e满足关系equal()的数据元素的位序。若这样的数据元素不存在，则返回值为0.
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length  &&  !(*equal)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return 0;
}
bool equal(ElemType e1, ElemType e2) {
	//equal()是数据元素判定函数。
	if (e1 == e2) {
		return true;
	}
	else {
		return false;
	}
}
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
	//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length  && !(cur_e == L.elem[i - 1])) ++i;// until, legal && !== node1,i++
	if (i<2 || i>L.length) //i=1 表示没有前驱
		return ERROR;
	pre_e = L.elem[i - 2];//cur_e =L.elem[i - 1]
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
	//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
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
	//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.
	if (i < 1 || i>L.length + 1) return ERROR;	//i值不合法
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType * q = &(L.elem[i - 1]);	//q为插入位置 get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	ElemType * p;
	for (p = &(L.elem[L.length - 1]); p >= q; --p) // p=&(last);p >= q;--p
		*(p + 1) = *p;	//右移 right move , cur+1=cur

	*q = e;//assignment
	++L.length;
	return OK;
}//ListInsert
Status ListDelete(SqList &L, int i, ElemType &e) {
	//1<=i<=ListLength(L).
	//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1.
	if (i<1 || i>L.length) return ERROR; //i值不合法
	ElemType * p = &(L.elem[i - 1]); //p为del位置 get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	e = *p;
	ElemType * q = L.elem + L.length - 1; //q =&(last)
	for (++p; p <= q; ++p) *(p - 1) = *p; // left move , cur-1=cur
	--L.length;
	return OK;
}
Status ListTraverse(SqList L, bool(*visit)(ElemType)) {
	//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && (*visit)(*p++)) ++i;
	return OK;
}
Status visit(ElemType e) {
	//访问节点,返回bool,打印c,值由外部传入
	printf("%d\t", e);
	return TRUE;
}
//end SqList.cpp