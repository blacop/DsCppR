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
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
typedef struct LNode { //封装 结构体 链表的结点==数据元素Elem,结点的指针==链表==数据对象Obj
	ElemType data;  //数据Domain ,数据项item
	struct LNode *next; //指针,引用Reference,数据项item
}LNode,*Link,*Position;
typedef struct Linklist{ //二次封装 结构体
	Link head;
	Link tail;
	int len;
}Linklist;
//线性链表 带头尾引用 的基本操作定义声明 21个CORE
Status MakeNode(Link &p, ElemType e);
//分配由p指向的值为e的结点,并返回TRUE,若分配失败,则返回FALSE 1
void FreeNode(Link &p); 
//释放p所指结点  2
Status InitList(LinkList &L);
//操作结果：构造一个空的线性链表L。 3
Status DestroyList(LinkList &L);
//初始条件：线性链表L已存在。
//操作结果：销毁线性链表L。 4
Status ClearList(LinkList &L);
//初始条件：线性链表L已存在。
//操作结果：将L重置为空表。 5
Status InsFirst(Link h, Link s);
//已知h指向线性链表的头结点,将s所指结点插入在第一个结点之前 6
Status DelFirst(Link h, Link s);
//已知h指向线性链表的头结点,删除链表中的第一个结点并以q返回 7
Status Append(LinkList &L, Link s);
//将指针s所指(彼此以指针相链)的一串结点链接在线性链表L的最后一个结点
//之后,并改变链表L的尾指针指向新的尾结点 8
Status Remove(LinkList &L, Link &q);
//删除线性链表L中的尾结点并以q返回,改变链表L的尾指针指向新的尾结点 9
Status InsBefore(LinkList &L, Link &p, Link s);
//已知h指向线性链表的一个结点,将s所指结点插入在p所指结点之前 
//并修改指针p指向新插入的结点  10
Status InsAfter(LinkList &L, Link &p, Link s);
//已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之后,
//并修改指针p指向新插入的结点  11
ElemType GetCurElem(Link &p, ElemType e);
//已知p指向线性链表L中的一个结点,返回p所指结点中数据元素的值 12
Status ListEmpty(LinkList L);
//初始条件：线性链表L已存在。
//操作结果：若L为空表，则返回TRUE，否则返回FALSE。13
int ListLength(LinkList L);
//初始条件：线性链表L已存在。
//操作结果：返回L中数据元素的个数。 14
Position GetHead(LinkList L);
//返回线性链表L中头结点的位置 15
Position GetLast(LinkList L);
//返回线性链表L中最后一个结点的位置 16
Position PriorPos(LinkList L, Link p);
//已知p指向线性链表L中的一个结点,返回p所指结点的直接前驱的位置,
//若无前驱,则返回NULL  17
Position NextPos(LinkList L, Link p);
//已知p指向线性链表L中的一个结点,返回p所指结点的直接后继的位置,
//若无后继,则返回NULL  18
Status LocatePos(LinkList L, int i, Link &p);
//返回p指示线性链表L中第i个结点的位置并返回TRUE,i值不合法时返回FALSE 19
Position LocateElem(LinkList L, ElemType e, bool(*compare)(ElemType, ElemType));
//初始条件：线性链表L已存在，compare()是数据元素判定函数。
//返回线性链表L中第1个与e满足函数compare()判定关系的数据元素的位置。
//若这样的数据元素不存在，则返回NULL 20
Status ListTraverse(LinkList L, bool(*visit)(ElemType));
//初始条件：线性链表L已存在
//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。 21
/*
//----其他可选----
Status GetElem(LinkList L, int i, ElemType &e);
//初始条件：线性链表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。 6
int LocateElem(LinkList L, int e, bool(*equal)(ElemType, ElemType));
//初始条件：线性链表L已存在，compare()是数据元素判定函数。
//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0. 7

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
//初始条件：线性链表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。 8

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
//初始条件：线性链表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。9

Status ListInsert(LinkList &L, int i, ElemType e);
//初始条件：线性链表L已存在，1<=i<=ListLength(L)+1.
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1. 10

Status ListDelete(LinkList &L, int i, ElemType &e);
//初始条件：线性链表L已存在且非空，1<=i<=ListLength(L).
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1. 11
*/
/*
//线性链表的基本操作定义声明
InitList(&L) //初始化线性链表L  1
DestroyList(&L) //销毁线性链表L  2
ClearList(&L) //清空线性链表L  3
ListEmpty(L) //判断线性链表是否为空 4
ListLength(L) //求线性链表L的长度 5
GetElem(L,i,&e) //取线性链表L的第i个元素 6
LocateElem(L,e,compare()) //定位检索线性链表L中元素e 7
PriorElem(L,cur_e,&prio_e) //返回线性链表L中元素e的直接前驱元素 8
NextElem(L,cur_e,&next_e) //返回线性链表L中元素e的直接后继元素 9
ListInsert(&L,i,e) //在线性链表L的第i个元素之前插入元素e,返回Bool 10
ListDelete(&L,i,e) //删除线性链表L的第i个元素,被删除元素e的值,返回Bool 11
ListTraverse(L,visit()) //遍历线性链表:依次对L的每个元素调用visit() 12
*/
/*进阶算法
//reverseList(&L1) //逆置 单链表 
//mergeList(&L1,L2) //合并 两个线性链表L 15
//visit(e) 
//  一般是指树型链表结构中对某个节点内容进行访问的函数， 13
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”
*/