#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE -1
#define OVERFLOW -2
#define Status int
typedef int Status
#define LEN sizeof(SqList)
#define MLC (LinkList)malloc(sizeof(SqList))

#define MAX_SIZE 100;//表最大空间
#define LIST_INIT_SIZE = 100;//表初始分配空间
#define LIST_INCREMENT = 10;//空间分配增量

//-------链表表示的 一元多项式  Tan--------------
//抽象数据类型 一元多项式 的定义
// ADT=(D数据域,R关系,P基本操作)
// 链表表示的 链表表示的 一元多项式 定义
/*
//线性表的基本操作列表
InitList(&L) //初始化线性表L
DestroyList(&L) //销毁线性表L
ClearList(&L) //清空线性表L
ListEmpty(L) //判断线性表是否为空
ListLength(L) //求线性表L的长度
GetElem(L,i,&e) //取线性表L的第i个元素
LocateElem(L,e,compare()) //定位检索线性表L中元素e
compare() //比较两个元素的大小,返回Bool
compareArray() //比较两个数组的大小,返回Bool
PriorElem(L,cur_e,&prio_e) //返回线性表L中元素e的直接前驱元素
NextElem(L,cur_e,&next_e) //返回线性表L中元素e的直接后继元素
ListInsert(&L,i,e) //在线性表L的第i个元素之前插入元素e,返回Bool
ListDelete(&L,i,e) //删除线性表L的第i个元素,被删除元素e的值,返回Bool
ListTraverse(L,visit()) //遍历线性表:依次对L的每个元素调用visit()
visit() //  visit 一般是指树型链表结构中对某个节点内容进行访问的函数，
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”
*/
typedef struct PNode {
	float coef;//  浮点 系数 2个data域
	int expn;// 整数 指数
	sturct Pnode *next; //1个ptr域
}ElemType,term, polynomail;
void CreatePloyn(polynomail &p, int m){
	//输入各项的系数和指数,建立一元多项式的有序链表p
	InitList(p);
	h = GetHead(p);
	e.coaf = 0.0;//系数
	e.expn = -1;//指数
	SetCurItem(h, e);//设置当前节点
	for (i = 1; i <= m; i++) {
		scanf(e.coef, e.expn); //赋值 系数 指数
		if (!LocateElem(p,e,q,(*cmp)())) {
			if (MakeNode(s, e)) {
				InsFirst(q, s);
			}
		}
	}//end for
}//CreatePloyn