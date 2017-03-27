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
//------线性表的动态分配顺序存储结构--------
#define MAXSIZE 20 //线性表存储空间的初始分配量
#define LIST_INIT_SIZE	20	//线性表存储空间的初始分配量
#define LIST_INCREMENT	10	//线性表存储空间的分配增量
/*
ADT 线性表 List
数据对象 Data : D = { ai | ai∈ ElemSet,i = 1,2,...,n,n >= 0 }
//线性表的数据对象集合为{ a,a2,--,an }, 每个元素的类型均为DataType
数据关系 Relation : Rl={<ai-1,ai>|ai-1,ai∈ D,i=2,...,n}
基本操作 Operation
//线性表的基本操作列表 CORE
InitList(&L) //初始化线性表L  01 初始化
DestroyList(&L) //销毁线性表L 02 销毁
ClearList(&L) //清空线性表L 03 清空
ListEmpty(L) //判断线性表是否为空  04 为空
ListLength(L) //求线性表L的长度  05 长度
GetElem(L, i, &e) //取线性表L的第i个元素  06 查找
LocateElem(L, e, compare(e1, e2)) //定位检索线性表L中元素e  07 定位
PriorElem(L, cur_e, &prio_e) //返回线性表L中元素e的直接前驱元素 08 前驱
NextElem(L, cur_e, &next_e) //返回线性表L中元素e的直接后继元素 09 后继
ListInsert(&L, i, e) //在线性表L的第i个元素之前插入元素e,返回Bool 10 插入
ListDelete(&L, i, e) //删除线性表L的第i个元素,被删除元素e的值,返回Bool  11 删除
ListTraverse(L, visit(e)) //遍历线性表:依次对L的每个元素调用visit()  12 遍历
//----选修Electives----
visit(e) // 一般是指树型链表结构中对某个节点内容进行访问的函数 13
compare(e1,e2) //比较两个元素的大小,返回Bool 14.a
compareList(L1,L2) //比较两个线性表L的大小,返回Bool 14.b
union() //求并集 15.a
mergeList(&L1,L2) //求并集&&升序排序， 合并两个线性表L 15.b
different() //求差集 15.c
ListAppend() //尾部插入元素,尾插 15.d
exchange() //交换一个父线性表L中的两个子线性表L 16
endADT List
*/
typedef struct SqList {
	ElemType data[MAXSIZE];//数组存储数据元素，最大容量为MAXSIZE
	int length;//长度
}SqList;
Status InitList(SqList *L) {
	//书上没写InitList
	//初始化空的线性表,&L 引用参数表示会修改值
	//自己写一下，如果是数组,我记得，base引用放在结构体名字和首元素 数组名字上
	SqList *L;
	L＝L.data = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//分配内存，返回void*指针，类型强转一下
	if (!L) exit(OVERFLOW);//OVERFLOW是返回到OS的
	L.length = 0;
	//L.listSize = LIST_INIT_SIZE;
	return TRUE;
}

/*
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
	while (i <= L.length && !(*equal)(*p++, e)) ++i;
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
	while (i <= L.length && !(cur_e == L.elem[i - 1])) ++i;// until, legal && !== node1,i++
	if (i<2 || i>L.length) //i=1 表示没有前驱
		return ERROR;
	pre_e = L.elem[i - 2];//cur_e =L.elem[i - 1]
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
	//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
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
	//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.
	if (i < 1 || i>L.length + 1) return ERROR;	//i值不合法
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
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
*/