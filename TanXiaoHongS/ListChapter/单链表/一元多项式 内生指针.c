#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE -1
#define OVERFLOW -2

typedef int Status;
//typedef float ElemType;
#define LEN sizeof(Node)
#define MLC (Node*)malloc(sizeof(Node))

//-------链表表示的 一元多项式 --------------
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
*/
typedef struct PolynNode {
	float coef;//  浮点 系数 data域
	int expn;// 整数 指数 data域
	sturct Pnode *next; // ptr域
}ElemType, term, polynomail, PNode, Node, *NodePtr;

////初始化线性表L //内生指针,进void，出ref
//Node* InitList() {
//	//head
//	//☒→NULL☞
//	//表头指针 从函数外面传进来
//	Node* L;
//	L = (Node*)malloc(sizeof(Node));
//	if (!L) { /* 存储分配失败 */
//		exit(OVERFLOW);
//	}
//	L->next = Null;//结尾指向空
//	return L;
//}

//初始化线性表L //外生指针,进ref，出bool
Status InitList(Node *L) {
	//head
	//☒→NULL☞
	//表头指针 从函数外面传进来
	L = (Node *)malloc(sizeof(Node));
	if (!L) { /* 存储分配失败 */
		exit(OVERFLOW);
	}
	L->next = Null;//结尾指向空
	return TRUE;
}

//c CreatePloyn() 建立
Status CreatePloyn(Node *p, int length) {
	//输入各项的系数和指数,建立一元多项式的有序链表p
	InitList(p);
	h = GetHead(p);
	e.coaf = 0.0;//系数
	e.expn = -1;//指数
	SetCurItem(h, e);//设置当前节点
	for (i = 1; i <= length; i++) {
		scanf(e.coef, e.expn); //赋值 系数 指数
		if (!LocateElem(p, e, q, (*cmp)())) {
			if (MakeNode(s, e)) {
				InsFirst(q, s);
			}
		}
	}//end for
	return TRUE;
}//CreatePloyn

//c++ CreatePloyn()
void CreatePloyn(polynomail &p, int m) {
	//输入各项的系数和指数,建立一元多项式的有序链表p
	InitList(p);
	h = GetHead(p);
	e.coaf = 0.0;//系数
	e.expn = -1;//指数
	SetCurItem(h, e);//设置当前节点
	for (i = 1; i <= m; i++) {
		scanf(e.coef, e.expn); //赋值 系数 指数
		if (!LocateElem(p, e, q, (*cmp)())) {
			if (MakeNode(s, e)) {
				InsFirst(q, s);
			}
		}
	}//end for
}//CreatePloyn

