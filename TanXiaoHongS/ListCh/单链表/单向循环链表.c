#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE -1
#define NULL 0
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
#define LEN sizeof(LNode)
#define MLC (LinkList)malloc(sizeof(LNode))
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
//---------单向循环链表-----------
//单向循环链表 初始化 合并
typedef struct LNode{ //封装一个线性单链表 节点 存储结构
	ElemType data; //数据域
	struct LinkListnext; //指针域
}LNode, *LinkList;//类型重定义struct LNode为Lnode，类型重定义 Lnode的*指针 为LinkList

//初始化 线性单向循环链表 函数自己产生指针 产生一个头结点
LinkList LinkListInit_Out_Ptr() {
	LinkList L = (LinkList)malloc(LEN);
	if (L == NULL)          //判断是否有足够的内存空间 
		exit(OVERFLOW);
	L->next = L;           //将next指向自己
	return L;
}

//初始化 线性单向循环链表 产生一个头结点。单链表指针在外面传进来
Status InitList_CirLink(LinkList *&L) {  //初始化线性链表 产生一个头结点
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) { /* 存储分配失败 */
		exit(OVERFLOW);
	}
	L->next = L;/* 指针域指向头结点 */
	return TRUE;
}
linklist *Linklist_Connect(LinkList h1, int l1, LinkList h2, int l2){
	//单循环链表的合并,LinkList h1表示 表1的头结点，int Len1表示表1的长度
	LinkList p1, p2;
	p1 = h1;
	p2 = h2;
	int l = 1;//Counter 计数器
	LinkList p;//临时节点指针
	p1 = h1->next;//h1 Node1
	while (l<l1) {
		l++;
		p1 = p1->next;  //找到链表1的尾结点 rearA
	}
	p2 = h2->next;//h2 Node1
	l = 1;//Reset Counter 重置计数器
	while (l<l2) {
		l++;
		p2 = p2->next; //找到链表2的尾结点 rearB 
	}
	LinkList p = p1->next;//p1 = p1->next; 保存A表的头结点
	p1->next = (p2->next)->next;
	//核心操作：链表1的尾结点指向链表2辅助头节点head的下个节点,不是head节点,链表2的头结点被丢弃了
	p2->next = p; // 链表2的尾部指向链表1 的头结点 <==> 将原A表的头结点赋值给 p2->next
	free(p2->next);             //释放链表的辅助头节点
	return h1;
}
LinkList CirLinklist_Merge_Guan(LinkList h1, int Len1, LinkList h2,int Len2) {
	//单循环链表的合并,LinkList h1表示 表1的头结点，int Len1表示表1的长度
	LinkList p1, p2, rearA, rearB, p; //我自己写一遍感觉吧，最好是把不同作用的指针分开，这样写更便于理解，尽量不要把不同作用的指针合并写成1个指针变量，指针变量合并合并多了代码会变得很难理解
	p1 = h1;//初始化 p1指向h1,必须初始化，防止出现长度非法等错误。
	p2 = h2;//初始化 p2指向h2
	p = h1;//p1 = p1->next; 保存A表的头结点	

	p1 = h1->next;//p1指向 h1's Node1	
	int l = 1;//Counter 计数器	
	while (l<l1) { //防止出现长度非法等错误。
		l++;
		p1 = p1->next;  //找到链表1的尾结点 rearA
	}

	p2 = h2->next;//h2's Node1
	l = 1;//Reset Counter 重置计数器
	while (l<l2) {
		l++;
		p2 = p2->next; //找到链表2的尾结点 rearB 
	}
	rearA = p1;
	rearB = p2;		
	//核心操作：链表1的尾结点指向链表2辅助头节点head的下个节点,不是head节点,链表2的头结点被丢弃了
	rearA->next = (rearB->next)->next; 
	rearB->next = p; // 链表2的尾部指向链表1 的头结点 <==> 将原A表的头结点赋值给 p2->next
	free(p2->next); //释放链表的辅助头节点
	return h1;
}
