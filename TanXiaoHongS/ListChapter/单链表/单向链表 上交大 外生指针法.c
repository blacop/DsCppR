#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
/*
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//线性表的基本操作定义声明

Status InitList(SqList &L);
//操作结果：构造一个空的线性表L。 1

Status DestroyList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：销毁线性表L。 2

Status ClearList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：将L重置为空表。 3

bool ListEmpty(SqList L);
//初始条件：线性表L已存在。
//操作结果：若L为空表，则返回TRUE，否则返回FALSE。 4

int ListLength(SqList L);
//初始条件：线性表L已存在。
//操作结果：返回L中数据元素的个数。 5

Status GetElem(SqList L, int i, ElemType &e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。 6

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//初始条件：线性表L已存在，compare()是数据元素判定函数。
//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0. 7

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。 8

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。9

Status ListInsert(SqList &L, int i, ElemType e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)+1.
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1. 10

Status ListDelete(SqList &L, int i, ElemType &e);
//初始条件：线性表L已存在且非空，1<=i<=ListLength(L).
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1. 11

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//初始条件：线性表L已存在
//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。 12
*/
/*
//线性链表的基本操作定义声明
InitList(&L) //初始化线性表L  1
DestroyList(&L) //销毁线性表L  2
ClearList(&L) //清空线性表L  3
ListEmpty(L) //判断线性表是否为空 4
ListLength(L) //求线性表L的长度 5
GetElem(L,i,&e) //取线性表L的第i个元素 6
LocateElem(L,e,compare()) //定位检索线性表L中元素e 7
PriorElem(L,cur_e,&prio_e) //返回线性表L中元素e的直接前驱元素 8
NextElem(L,cur_e,&next_e) //返回线性表L中元素e的直接后继元素 9
ListInsert(&L,i,e) //在线性表L的第i个元素之前插入元素e,返回Bool 10
ListDelete(&L,i,e) //删除线性表L的第i个元素,被删除元素e的值,返回Bool 11
ListTraverse(L,visit()) //遍历线性表:依次对L的每个元素调用visit() 12
*/
/*进阶算法
//reverseList(&L1) //逆置 单链表
//mergeList(&L1,L2) //合并 两个线性表L 15
//visit(e) //  一般是指树型链表结构中对某个节点内容进行访问的函数， 13
//compare(e1,e2) //比较两个元素的大小,返回Bool 14
//compareList(L1,L2) //比较两个线性表L的大小,返回Bool 14
//mergeList(&L1,L2) //合并两个线性表L 15
//Status AppendBefore(List &L, ElemType e) //头插元素
//Status AppendAfter(List &L, ElemType e) //尾插元素
*/
/*---------------线性单链表----------------
单链表 初始化 创建 头插法 尾插法 插入 删除 查找 合并 长度
*/
typedef struct Node { //封装 结构体 链表的结点==数据元素Elem,结点的指针==链表==数据对象Obj
	ElemType data; //数据Domain ,数据项item
	struct Node *next; //指针,引用Reference	
}Node, *LinkList, *PNode;//类型重定义struct Node为Node，类型重定义 Node的*指针 为LinkList
Status InitList(LinkList &L) { //初始化线性链表 产生一个头结点。单链表指针在外面传进来	
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
Status CreateList_Link_Tail_Guan(LinkList &L, int n) {
	//单向链表的创建过程
	//ptemp辅助指针
	// ↓=head
	// ☒→NULL
	//ptemp
	//   ↓.next +1
	// ☒☑→NULL
	//ptemp
	//    ↓.next +1
	// ☒☑☑→NULL
	/*
	从上面的示意图可以看出，我们需要一个辅助指针一直指向最后一个结点，
	这个辅助结点就是为了让每次添加的结点都放置在最后一个位置。
	*/
	//表头指针 从函数外面传进来
	LinkList head = &L, ptemp, pnew;
	ptemp = head;//ptemp辅助指针 必须保证指向尾部,pointer points at head, CORE
	for (int i = n; i >= 1; --i) { // crete n num Node
		pnew = (LinkList)malloc(sizeof(Node));//生成新结点 SeCORE 开辟新节点
		scanf(%i, &pnew->data);//scanf data to dataArea,  SeCORE 输入数据
		pnew->next = NULL;//the pnew must be tail Node.  CORE	
		ptemp->next = pnew;//对象obj(*ptemp).next 连接link to pnew, CORE
		ptemp = pnew;//ptemp++  CORE
	}
}
void CreateList_Link_Head_Yan(LinkList &L, int n) {
	//头插法 生成单链表 完整表
	//逆位序输入n个元素的值，建立带表头结点的单链线性表L
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;//L->next表示头结点的指针,先建立一个带头结点的单链表
	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(Node));
		scanf(&p->data);//输入元素值
		p->next = L->next;//挪动 头指针的后继
		L->next = p;//挪动 头指针的后继
	}
}
Status Insert_Link(LinkList L, int i, ElemType e) {
	LinkList pre, ins; //pre为前驱结点,ins为新结点
	pre = L;
	int l = 1;
	while (p && j < i - 1) { //寻找第i个结点,指针下移,j最后停在i
		p = p->next; ++j;
	}
	if (!p || j > i) return FALSE;//第i个元素不存在
	ins = (LinkList)malloc(LEN);
	ins->data = e;
	ins->next = pre->next;
	pre->next = ins;
	return TRUE;
}
Status ListInsert(LinkList &L, int i, ElemType e) { //在带head的单链表L中第i个位置之前插入元素e	
	//前插操作需要查找第i个位置的结点的直接前驱。
	p = L; j = 0;//p为指针,被插入的previous Node
	while (p && j < i - 1) { p = p->next; ++j; }//寻找第i-1个结点,指针下移,j最后停在i-2
	if (!p || j > i) return FALSE;

	s = (LinkList)malloc(sizeof(Node));//生成新节点，开辟内存空间 返回指针s,insert
	s->data = e;//s->data域的赋值 assignment

	s->next = p->next;//指针操作 ,=右往左，指针 指向,core
	p->next = s;//core
	return TRUE;
}
Status ListInsert_Post(LinkList &L, int i, ElemType e) { //在带head的单链表L中第i个位置之后插入元素e	
	//后插操作需要查找第i个位置的结点的引用。设p为第i个位置的结点的引用
	p = L; j = 0;//p为指针,被插入的previous Node
	while (p && j < i) { p = p->next; ++j; }//寻找第i-1个结点,指针下移,j最后停在i-2
	if (!p || j > i) return FALSE;

	s = (LinkList)malloc(sizeof(Node));//生成新节点，开辟内存空间 返回指针s,insert
	s->data = e;//s->data域的赋值 assignment

	s->next = p->next;//指针操作 ,=右往左，指针 指向,core
	p->next = s;//core
	return TRUE;
}
Status ListDelete_Link_Yan(LinkList &L, int i, ElemType &e) { //在带head的单链表L中第i个位置 删除元素e		
	p = L; j = 0;//p为指针,被插入的previous Node
	while (p && j < i - 1) { p = p->next; ++j; }//寻找第i个结点,下标最后是i-1,指针下移,j最后停在i
	if (p->next || j > i - 1) return FALSE;//删除位置不合理

	q = p->next; //q是被删除的节点	
	p->next = q->next;//P的next，指向q->next

	e = q->data; //取出 值为e
	free(q);//返回值，释放空间
}
Node *LocateLinkElem(LinkList L, ElemType e) {
	//在L中找到第一个值和e相同的结点，返回其地址，若不存在，返回空值NULL。
	if (!L) return NULL;
	p = L;
	while (p&&p->data != e) { p = p->next };//if(!p) p=null;
	return p;//时间复杂度O(n)
}

int ListLength_Link(struct Node *head) {//求线性单链表长度
	struct Node *p = head->next;//Node1
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	head->data = len; //存储长度到头结点的数据域head->data
	return len;
}
Status GetElem_Link_Yan_OutBool(LinkList L, int i, ElemType &e) {
	//取出元素,i是序号,e为值
	//L为带头结点的单链表的头节点
	//L-next为 带头结点的单链表的 头指针 指向第一个结点Node1
	//当第i个元素存在时，将值返回给e,返回TRUE, 否则FALSE
	LinkList p = L->next;//初始化，p指向第一个结点，
	int j = 1;//j为计数器
	while (p && j < i) { //p指针非空，j计数器<i，所以循环的终点是i
		p = p->next; ++j;//指针后移一个,计数器+1一个
	}
	if (!p || j > i) return FALSE;//第i个元素不存在
	e = p->data;//取出第i个元素，值为e
	return TRUE;
}//GetElem_Link_Yan
ElemType GetElem_Link_OutData_Guan(LinkList L, int i) {
	//取出元素,i是序号,e为值
	//L为带头结点的单链表的头节点
	//L-next为 带头结点的单链表的 头指针 指向第一个结点Node1
	//当第i个元素存在时，将值返回给e,返回TRUE, 否则FALSE
	LinkList p = L->next;//初始化，p指向第一个结点，
	int j = 1;//j为计数器
	while (p && j < i) { //p指针非空，j计数器<i，所以循环的终点是i
		p = p->next; ++j;//指针后移一个,计数器+1一个
	}
	if (!p || j > i) return FALSE;//第i个元素不存在
	ElemType e = p->data;//取出第i个元素，值为e
	return e;
}

void ReLinkCirleListBefore(Node *s, Node *q) {
	//Link Cirle, s linke before Node q
	//从Node *s开始，找到Node q之前的结点 连接到s,组成一个新的循环链表
	P = s;
	while (p->next != q) p = ->next;
	p->next = s;
}//BackBefore
void ReLinkCirleListBeforeThenReLinkTheReminder(Node *pa, Node *pb) {
	//从Node *pa开始，找到Node pb之前的结点 连接到pa,组成一个新的循环链表，然后，从pb结点开——连接到pa之前的结点，组成一个新的循环链表
	//2次
	//Link Cirle,twice，
	//pa,pb finger LinkStack's two node. a link before b, b linke befor a.
	BackBefore(pa, pb);
	BackBefore(pb, pa);
}//BackBeforeAfterAgain

void Destroy(LinkList* L) {	
	LinkList* p; //temp ptr
	while (L) {
		p = L;
		L = L->next;
		free(p);		
	}
}

Status LinkList_DelBetween(LinkList &L, ElemType mink, ElemType maxk) {
	//删除大于mink小于maxk的所有元素，L是带头结点的单链表
	LinkList P = L; //temp Ptr P finger L's head, then P finger mink's 前驱。
	while (P->next != NULL && P->next->data <= mink) //then P finger mink's 前驱。
		P = P->next;//find the node before mink //找出第last个大于mink的元素
	if (P->next = NULL) return FALSE; //mean mink's 前驱 not 存在 ，( !P->next )
	LinkList Q = P->next; //temp Ptr Q finger mink
	while (!Q && (Q->data < maxk)) { //DestroyList()
		P->next = Q->next; //☊
		free(Q); //✄
		Q = P->next; //☌ ♂
	}
}//LinkList_BetweenDel
Status AppendHead(LinkList &L, ElemType e) { //头插元素
	PNode s = (Node *)malloc(sizeof(Node)); //开辟新节点
	s->data = e; //新节点 数据赋值

	s->next = L->next; //☊ ♎ //头插元素 核心//☊ ♎ //☌ ♂//head 不存数据
	L->next = s; //☌ ♂
}
Status AppendAfter(LinkList &L, ElemType e) { //尾插元素
	PNode s = (Node *)malloc(sizeof(Node));//开辟新节点
	s->data = e; //新节点 数据赋值

	LinkList p;//tempPtr
	p = L;
	while (p->next != NULL) { //找end的precursor前驱
		P = P->next; //找end的precursor前驱，Ptr++ move 
	}
	//尾插元素 核心
	//☊ ♎ //☌ ♂
	P->next = s; //☊ ♎
	s->next = NULL; //☌ ♂
}
void MergeLinkList_ToOld_ASC_Tan_4StarHard(LinkList &La, LinkList &Lb) {
	//已知La和Lb升序排列
	//合并得到新的单链表Lc,Lc的元素也按值非递减排列
	LinkList pa, pb, p, q;
	pa = La->next;
	pb = Lb->next;
	q = La;//存放临时指针,q就是pa的前驱元素,q必须始终作为pa的前驱元素
	t = Lb;
	while (pa && pb) {
		if (pa->data <= pb->data) {//如果小于=，pc指针指向pa
			q = pa;//q下移 
			pa = pa->next;//pa下移
		} else {
			//如果 且 只有 在    pa->data > pb->data,则将pb插入到pa的前面
			//转化 判断条件 如果 pb->data > pa->data ,则将pb插入到pa的前面
			t = pb;// t 下移
			pb = pb->next;//pb下移
			t->next = pa;//pb插入到pa的前面
			q->next = t;
			q = t;//q必须始终作为pa的前驱元素,因此t赋值给q
		}//2个结合起来就是小者排前面，这个代码写的真差，不是人类看的,因为C在A和B只见跳来跳去，临时pc变量拆成2个就容易理解了
	}
	if (pb) { //pb存在
		q->next = pb; //插入所有剩余的pb
	}
}//MergeList_Link_Yan
Status MergeLinkList_ToOld_ASC_3ptr_Tan_4StarHard(LinkList &A, &B, &C) {
	/*
	//合并得到新的单链表Lc，降序
	//已知La和Lb升序排列
	//合并得到新的单链表Lc,Lc的元素 按值
	//非递增排列LinkList p, q, pc;
	//C必须 使用A，B原来的结点空间
	*/
	LinkList p, q; //p & q is TempPtr。必须前提，head不存数据 //neccesory,head no repos data
	LinkList s; //s is TempPtr. finger New Node of C.//s作为c的TempPtr	
	p = A->next; q = B->next; //p q Node1。//p & q 必须始终作为 A & B 的FirstNode元素
	C = B; C->next = NULL; free(A); //InitList(Lc),C use B Repos,C is head
	//MergeList_ToOld_DSC降序合并,思路，比较大小后，把数值小的节点链接到 单链表C上面
	while (p && q) { //同时存在
		if (p->data <= q->data) { //curent min is p
			s = p; p = p->next; //s finger curent min //p++
		} else { //(p->data > q->data) //curent min is q
			s = q; q = q->next; //s finger curent min //q++
		}
		s->next = C->next; //s is current node,头插
		C->next = s; //s node Head AppendBefore() ListC. 头插
	}
	if (!p) p = q; //p is null
	while (p) { // q is null ,q end. p append C
		s = p; // s finger cur
		p = p->next; //p++ move
		s - next = C->next; //s.next finger C.next<==> C node1,头插
		C->next = s; //头插
	}
	/*
	//---------------
	while (p && q) { //p,q 存在
		if (p->data <= q->data) { //如果小于=，pc指针指向p
			AppendBefore(pc, p->data);
			v = p;//v下移
			p = p->next;//p下移
		}
		else { //如果>
			   //如果 且 只有 在    p->data > q->data,则将q插入到p的前面
			   //转化 判断条件 如果 q->data > p->data ,则将q插入到p的前面
			w = q;// w 下移
			q = q->next;//q下移
			w->next = p;//q插入到p的前面
			v->next = w;
			v = w;//v必须始终作为p的前驱元素,因此w赋值给v
		}//2个结合起来就是小者排前面，这个代码写的真差，不是人类看的,因为C在A和B只见跳来跳去，临时pc变量拆成2个就容易理解了
	}//while
	if (q) { //q存在
		v->next = q; //插入所有剩余的q
	}
	//-------------
	*/
}//MergeLinkList_ToOld_DSC_3ptr_Tan
Status MergeLinkList_ToNew_ASC_6Ptr_Guan_3StarHard(LinkList La, LinkList Lb, LinkList &Lc) { //合并得到新的单链表Lc，降序
	//已知La和Lb升序排列
	//合并得到新的单链表Lc,Lc的元素也按值非递减排列
	LinkList pa, pb, pc;
	LinkList p, t, u;

	pa = La->next;
	pb = Lb->next;
	pc = Lc->next;

	q = La; //存放临时指针,q就是pa的前驱元素,q必须始终作为pa的前驱元素
	t = Lb; //存放临时指针,t就是pb的前驱元素,t必须始终作为pb的前驱元素
	u = Lc; //存放临时指针,u就是pc的前驱元素,u必须始终作为pc的前驱元素

	while (pa && pb) { //pa,pb 存在
		if (pa->data <= pb->data) { //如果小于=，pc指针指向pa
			AppendBefore(pc, pa->data);//apd c
			q = pa;//q下移 
			pa = pa->next;//pa下移
		} else { //如果 pb->data < pa->data
			//如果 且 只有 在    pa->data > pb->data,则将pb插入到pa的前面
			//转化 判断条件 如果 pb->data > pa->data ,则将pb插入到pa的前面
			AppendBefore(pc, pb->data);//apd c
			t = pb;// t 下移
			pb = pb->next;//pb下移
			/*
			//t->next = pa;//pb插入到pa的前面
			//q->next = t;
			//q = t;//q必须始终作为pa的前驱元素,因此t赋值给q
			*/
		}//2个结合起来就是小者排前面，这个代码写的真差，不是人类看的,因为C在A和B只见跳来跳去，临时pc变量拆成2个就容易理解了
	}//while
	if (pa) { //pb存在
		u->next = pa; //插入所有剩余的pb
	}
	if (pb) { //pb存在
		u->next = pb; //插入所有剩余的pb
	}
}//MergeList_To_DSC_List

Status MergeLinkList_ToNew_Union_ASC_6Ptr_Guan_3StarHard(LinkList La, LinkList Lb, LinkList &Lc) { //合并得到新的单链表Lc，求并集																				 //合并得到新的单链表Lc,Lc的元素也按值非递减排列
	LinkList pa, pb, pc;
	LinkList p, t, u;
	pa = La->next;
	pb = Lb->next;
	pc = Lc->next;
	q = La; //存放临时指针,q就是pa的前驱元素,q必须始终作为pa的前驱元素
	t = Lb; //存放临时指针,t就是pb的前驱元素,t必须始终作为pb的前驱元素
	u = Lc; //存放临时指针,u就是pc的前驱元素,u必须始终作为pc的前驱元素
	ElemType e;// temp data
	while (pa && pb) { //pa,pb 存在
		if (pa->data <= pb->data) { //如果小于=，pc指针指向pa
			e = pa->data;
			if (!LocateLinkElem(Lc, e)) AppendAfter(pc, pa->data);//apd c
			q = pa;//q下移 
			pa = pa->next;//pa下移
		} else {
			/*
			//如果 pb->data < pa->data
			   //如果 且 只有 在    pa->data > pb->data,则将pb插入到pa的前面
			   //转化 判断条件 如果 pb->data > pa->data ,则将pb插入到pa的前面
			*/
			e = pa->data;
			if (!LocateLinkElem(Lc, e)) AppendAfter(pc, pb->data);//apd c
			t = pb;// t 下移
			pb = pb->next;
			/*
			pb下移
			//t->next = pa;//pb插入到pa的前面
			//q->next = t;
			//q = t;//q必须始终作为pa的前驱元素,因此t赋值给q
			*/
		}//2个结合起来就是小者排前面，这个代码写的真差，不是人类看的,因为C在A和B只见跳来跳去，临时pc变量拆成2个就容易理解了
	}//while
	if (pa) { //pb存在
		u->next = pa; //插入所有剩余的pb
	}
	if (pb) { //pb存在
		u->next = pb; //插入所有剩余的pb
	}
}//MergeLinkList_ToNew_Union_ASC_6Ptr_Guan_3StarHard
Status MergeLinkList_ToNew_Intersection_ASC_6Ptr_Guan_3StarHard(LinkList La, LinkList Lb, LinkList &Lc) { //合并得到新的单链表Lc，求交集																				 //合并得到新的单链表Lc,Lc的元素也按值非递减排列
	LinkList pa, pb, pc;
	LinkList p, t, u;
	pa = La->next;
	pb = Lb->next;
	pc = Lc->next;
	q = La; //存放临时指针,q就是pa的前驱元素,q必须始终作为pa的前驱元素
	t = Lb; //存放临时指针,t就是pb的前驱元素,t必须始终作为pb的前驱元素
	u = Lc; //存放临时指针,u就是pc的前驱元素,u必须始终作为pc的前驱元素
	ElemType e;// temp data
	while (pa && pb) { //pa,pb 存在
		if (pa->data <= pb->data) { //如果小于=，pc指针指向pa
			e = pa->data;
			if (LocateLinkElem(La, e) && LocateLinkElem(Lb, e)) AppendAfter(pc, pa->data);//apd c
			q = pa;//q下移 
			pa = pa->next;//pa下移
		} else {
			/*
			//如果 pb->data < pa->data
			//如果 且 只有 在    pa->data > pb->data,则将pb插入到pa的前面
			//转化 判断条件 如果 pb->data > pa->data ,则将pb插入到pa的前面
			*/
			e = pa->data;
			if (LocateLinkElem(La, e) && LocateLinkElem(Lb, e)) AppendAfter(pc, pb->data);//apd c
			t = pb;// t 下移
			pb = pb->next;
			/*
			pb下移
			//t->next = pa;//pb插入到pa的前面
			//q->next = t;
			//q = t;//q必须始终作为pa的前驱元素,因此t赋值给q
			*/
		}//2个结合起来就是小者排前面，这个代码写的真差，不是人类看的,因为C在A和B只见跳来跳去，临时pc变量拆成2个就容易理解了
	}//while
	if (pa) { //pb存在
		u->next = pa; //插入所有剩余的pb
	}
	if (pb) { //pb存在
		u->next = pb; //插入所有剩余的pb
	}
}//MergeLinkList_ToNew_Union_ASC_6Ptr_Guan_3StarHard

Status LL_Detete_In_A_By_B_Inter_C(SqList &A, SqList B, SqList C) {
	//删除A中满足条件的元素：同时在B/C中出现的元素
	PNode p = A; //temp Ptr
	PNode q; //temp Ptr for free() node，临时指针for删除结点
	ElemType e; //temp data
	while (p->next != NULL) {
		e = p->next->data; //赋值
		if ((LocateElem(B, e) != 0) && (LocateElem(C, e) != 0)) {
			q = p->next; //q finger p head after node which node1
			p->next = q->next; //p+2 move
			ListDelete(q); //dispose(q)，ListDelete(q);
		} else p = p->next;//p++ move
	}//while

	/* Sqlist only
	for (size_t i = 0; i < length; i++) {
		e = A.elem[i];
		if ((LocateElem(B, e)) && (LocateElem(C, e))) {
			ListDelete(A, i + 1);
		}//if
	}//for
	*/
}//Sq_Detete_In_A_By_B_Inter_C

Status ReverseLink_InOld(LinkList &h) {
	//就地逆置
	//假设在头结点，H为指向头结点的指针
	//只需将头结点后结点依次加入新链，
	//加入总是放在新链的首元素位置上
	PNode p, q;
	p = h->next;
	h->next = NULL; //h finger head
	while (t != NULL) {
		q = p;//q前驱
		p = p->next;//p后继	 
		q->next = h->next;//头插法
		h->next = q;
	}
	return TRUE;
}//ReverseLink_InOld

 //快速排序 数组的，不是链表的，链表的还不会
void quicksort(PList v, int left, int right) {
	if (left < right) {
		int key = v[left];
		int low = left;
		int high = right;
		while (low < high) {
			while (low < high && v[high] > key)
				high--;
			v[low] = v[high];

			while (low < high && v[low] < key)
				low++;
			v[high] = v[low];
		}
		v[low] = key;
		quicksort(v, left, low - 1); // 递归调用
		quicksort(v, low + 1, right);
	}
}

//有参构造器,设置工作节点 data domain's value
PNode* SetCurItemValue(PNode* head，float _coef, int _expn) {
	head = (PNode*)malloc(sizeof(PNode));
	if (!head)  /* 存储分配失败 */
		exit(OVERFLOW);
	coef = _coef;//赋值语句
	expn = _expn;
	next = NULL;
	return head;
}

//工作指针设置到当前节点
PList SetCurPtrCur(PList head, PNode e) {
	PList p = head;
	for (; p->next != NULL; p = p->next);
	return PList;
}

//工作指针设置到最后节点
PList SetCurPtrLast(PList head, PNode e) {
	PList p = head;
	for (; p->next != NULL; p = p->next);
	return PList;
}

////c语言　的结构体中可以利用函数指针的方法，实现c++中的成员函数；
////例如：
//struct stu_info {
//	char *name;
//	int age;
//	void(*print_info)(struct stu_info *stu);
//};
//void print_information(struct stu_info *stu) {
//	
//}
//int main(void) {
//	struct stu_info stu;
//	stu.print_info = print_information;
//}
////就是采用了“函数指针”来实现了c++中的类的封装。
////函数的指针　功能很强大。
//
//void(*Constructor)(polyNode* polyElem); //构造器,用函数指针实现 成员构造函数
//void(*DeConstructor)(polyNode* polyElem); //析构器
//
//										  //构造器
//void Constructor(polyNode* polyElem) {
//
//}
////析构器
//void DeConstructor(polyNode* polyElem) {
//
//}


////void(*Constructor)(PNode* polyElem); //构造器, 用函数指针实现 成员函数	
////构造器,在c语言里面实现构造器，赋值语句，默认值先不写了
//PNode* Constructor(float _coef, int _expn) {
//	PNode* head = (PNode*)malloc(sizeof(PNode));
//	if (!head)  /* 存储分配失败 */
//		exit(OVERFLOW);
//	coef = _coef;//赋值语句
//	expn = _expn;
//	next = NULL;
//	return head;
//}

////头插元素
//void AddNodeHead(PList L, PNode e) { //头插元素
//	PList s = (Node *)malloc(sizeof(Node)); //开辟新节点
//	s->data = e; //新节点 数据赋值
//	s->next = L->next; //☊ ♎ //头插元素 核心//☊ ♎ //☌ ♂//head 不存数据
//	L->next = s; //☌ ♂
//}