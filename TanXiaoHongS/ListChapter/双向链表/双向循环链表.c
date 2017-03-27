#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE -1
#define NULL 0
#define OVERFLOW -2
//#define ElemType int
//#define Status int
typedef int ElemType;
typedef int Status;
typedef int size_t;
/*
#define LEN sizeof(Node)
#define MLC (Node *)malloc(sizeof(Node))
*/
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
//-------双向循环链表--------------
//双向循环链表 初始化 插入 删除
typedef struct DuLNode { //封装 双向链表
	ElemType data;
	struct DuLNode *prior;//前驱
	struct DuLNode *next;//后继
}DuLNode, *DuLinkList;

//初始化 双向循环链表 函数自己产生指针 产生一个头结点
DuLinkList DuLinkListInit_Out_Ptr() {
	DuLinkList L = (LinkList)malloc(LEN);
	if (L == NULL)       //判断是否有足够的内存空间 
		exit(OVERFLOW);
	L->next = L;  //next指向自己
	L->prior = L; //prior指向自己
	return L;
}
Status ListInsert_Dul_Tail_Tan(DuLinkList &L, int i, ElemType e) {
	//在带头结点的的双向循环链表中的第i个位置插入元素e
	//寻找第i-1个元素p后插法
	int j = 0; //计数器
	DuLinkList p = L; //p作为工作目标指针
	DuLinkList s;//新结点
	while (j < i - 1 && p) { //寻找第i-1个元素，插入第i-1个元素后面
		p = p->next; //移动指针
		j++; //计数器+1
	}
	if (!p) { //表的长度小于i,空表
		return FALSE;
	}
	s = (DuLinkList)malloc(sizeof(ElemType));//开辟内存
	if (!s) { //空间不够，溢出
		exit(OVERFLOW);
	}
	s->data = e;//数据域赋值
				//第i-1个元素, p后插入,
	s->next = p->next;
	s->prior = p;
	(p->next)->prior = s;
	p->next = s;
}
Status ListInsert_Dul_Head_Tan(DuLinkList &L, int i, ElemType e) {
	//在带头结点的的双向循环链表中的第i个位置 插入元素e
	//寻找第i个元素p前插法
	int j = 0; //计数器
	DuLinkList p = L; //p作为工作目标指针
	DuLinkList s;//新结点
	while (j <= i - 1 && p) { //寻找第i个元素，插入第i个元素前面
		p = p->next; //移动指针
		j++;//计数器+1
	}
	if (!p) {
		return FALSE;//表的长度小于i
	}
	s = (DuLinkList)malloc(sizeof(ElemType));
	if (!s) {
		exit(OVERFLOW);//空间不够，溢出
	}
	s->data = e; //数据域赋值
				 //第i个元素, p前插入,
	s->next = p;
	s->prior = p->prior;
	(p->prior)->next = s;
	p->prior = s;
}
Status ListDelete_Dul(DuLinkList &L, int i, ElemType &e) {
	//在带头结点的的双向循环链表中的第i个位置 删除元素e
	int j = 0; //计数器
	DuLinkList p = L; //p作为工作目标指针
	DuLinkList pre;//作用结点pre
	DuLinkList nex;//作用结点nex
	DuLinkList s;//作用结点cur
	while (j <= i - 1 && p) { //寻找第i个元素，插入第i个元素前面
		p = p->next; //移动指针
		j++;//计数器+1
	}
	s = p;
	pre = p->prior;
	nex = p->next;
	e = s->data; //数据域赋值
	pre->next = nex->prior;
	nex->prior = pre->next;
	free(s);
	return TRUE;
}

Status LocateElem(DuLinkList &L, ElemType x) {
	//定位Elem元素,成功返回sequence，失败返回FALSE
	PDuLNode p, q;
	size_t sequence = 1;
	p = L->next;
	while (p != L && p->data<>x) {//find x node, L mean cirle end a round,L表示转了一圈
		p = p->next;
		sequence++;
	}
	if p = L return FALSE;//p = L mean cirle end a round, L表示转了一圈
	return sequence;
}

//----------------
//上交大，TV 8/29 ,00:36:08/01:19:27 . t 2.38
//Special Node 自动调频
typedef struct DuLNode {
	ElemType data;
	int freq; //频度
	struct DuLNode *prior;//前驱
	struct DuLNode *next;//后继
}DuLNode, *DuLinkList, *PDuLNode;

Status LocateThenFreq_5star(DuLinkList &L, ElemType x) {
	//LocateThenFreq 自动调频,按频度降序排序
	/*
	1.找e的sequence
	2.找e的后继
	3.将p结点插入到 e的后继 q结点 后面
	*/
	PDuLNode p, q;
	p = L->next;
	while (p != L && p->data<>x) //找到x结点，存p，find x node,p = L mean cirle end a round,L表示转了一圈
		p = p->next; //P++ MOVE，p指向x
	if p = L return FALSE;//p = L mean cirle end a round, L表示转了一圈
	p->freq++; //调频+1， 自动调频
	if ((p->prior != L) && (p->prior->freq < p->freq)) { //pri 非head,&& pri.freq < cur.freq
		q = p->prior; // q points cur's pri，q指向 当前结点的前驱
		q->next = p->next;	//将p结点从链表中断开
		p->next->prior = q; //将p结点从链表中断开
		while ((q<>L) && (q->freq < p->freq)) 
			//找到first第1个<小于p->freq频度的结点，降序排列，小于的频度在p的后面
			//所以是找p后面的结点,存q , q的功能发生了变化
			q = q->prior;	//找到p结点应该链接的位置,Q-- MOVE
		p->next = q->next;	//将p结点插入到q结点后面
		p->prior = q;		//将p结点插入到q结点后面
		q->next->prior = p;	//将p结点插入到q结点后面
		q->next = p;		//将p结点插入到q结点后面
	}//if
}//LocateThenFreq

Status AppendAfterElemSuceedByElem(DuLinkList &L, ElemType e,*LocateElem(PDuLNode L, ElemType e)) {
	//好像写这个方法 很多余
	/*
	1.找e的sequence
	2.找e的后继 
	3.将p结点插入到 e的后继 q结点 后面
	这真stupid
	*/
	PDuLNode p, q;
	size_t sequence;
	while (p != L && p->data<>x) //找到x结点，存p，find x node,p = L mean cirle end a round,L表示转了一圈
		p = p->next; //P++ MOVE，p指向x
	if p = L return FALSE;//p = L mean cirle end a round, L表示转了一圈
	
	sequence = LocateElem(PDuLNode L, ElemType e);//定位
	while ((q<>L) && (q->data <> e))
		//找到first第1个<小于p->freq频度的结点，降序排列，小于的频度在p的后面
		//所以是找p后面的结点,存q , q的功能发生了变化
		q = q->prior;	//找到p结点应该链接的位置,Q-- MOVE
	p->next = q->next;	//将p结点插入到q结点后面
	p->prior = q;		//将p结点插入到q结点后面
	q->next->prior = p;	//将p结点插入到q结点后面
	q->next = p;		//将p结点插入到q结点后面
}

Status DisConnectNode(DuLinkList &L, *LocateElem(PDuLNode L, ElemType e)) {
	//好像写这个方法 很多余
	PDuLNode p, q;
	size_t sequence = LocateElem(PDuLNode L, p);//定位
	ListDelete_Dul(DuLinkList &L, sequence, ElemType &e);//删除
	q->next = p->next; //将p结点从链表中断开
	p->next->prior = q; //将p结点从链表中断开
}