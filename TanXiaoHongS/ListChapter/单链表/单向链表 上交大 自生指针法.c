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
typedef int ElemType;
typedef int Status;
/*
#define LNode LNode
#define LEN sizeof(LNode)
#define MLC (LNode *)malloc
#define MLCS (LNode *)malloc(sizeof(LNode))
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
//线性表的基本操作定义声明
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
*/
//---------------线性单链表----------------
//单链表 初始化 创建 头插法 尾插法 插入 删除 查找 合并 长度
typedef struct LNode { //封装 结构体 链表的结点==数据元素Elem,结点的指针==链表==数据对象Obj
	ElemType data; //数据Domain ,数据项item
	struct LNode *next; //指针,引用Reference
}LNode, *LinkList;//类型重定义struct LNode为LNode，类型重定义 LNode的*指针 为LinkList
LinkList LinkListInit_Out_Ptr() { //初始化线性链表 函数自己产生指针 产生一个头结点
	LinkList L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)          //判断是否有足够的内存空间 
		exit(OVERFLOW);
	L->next = NULL;         //将next设置为NULL,初始长度为0的单链表 
	return L;
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
	for (int i = n; i >= 1; --i) { // crete n num LNode
		pnew = (LinkList)malloc(sizeof(LNode));//生成新结点 SeCORE 开辟新节点
		scanf(%i, &pnew->data);//scanf data to dataArea,  SeCORE 输入数据
		pnew->next = NULL;//the pnew must be tail LNode.  CORE	
		ptemp->next = pnew;//对象obj(*ptemp).next 连接link to pnew, CORE
		ptemp = pnew;//ptemp++  CORE
	}
}
void CreateList_Link_Head_Yan(LinkList &L, int n) {
	//头插法 生成单链表 完整表
	//逆位序输入n个元素的值，建立带表头结点的单链线性表L
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//L->next表示头结点的指针,先建立一个带头结点的单链表
	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
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
Status ListInsert_Link_Yan(LinkList &L, int i, ElemType e) { //在带head的单链表L中第i个位置之前插入元素e	
	p = L; j = 0;//p为指针,被插入的previous LNode
	while (p && j < i - 1) { p = p->next; ++j; }//寻找第i个结点,指针下移,j最后停在i
	if (!p || j > i) return FALSE;
	s = (LinkList)malloc(sizeof(LNode));//生成新节点，开辟内存空间 返回指针s,insert
	s->data = e;//s->data域的赋值 assignment
	s->next = p->next;//指针操作 ,=右往左，指针 指向 
	p->next = s;
	return TRUE;
}
Status ListDelete_Link_Yan(LinkList &L, int i, ElemType &e) { //在带head的单链表L中第i个位置 删除元素e		
	p = L; j = 0;//p为指针,被插入的previous LNode
	while (p && j < i - 1) { p = p->next; ++j; }//寻找第i个结点,下标最后是i-1,指针下移,j最后停在i
	if (p->next || j > i - 1) return FALSE;//删除位置不合理

	q = p->next; //q是被删除的节点	
	p->next = q->next;//P的next，指向q->next

	e = q->data; //取出 值为e
	free(q);//返回值，释放空间
}
LNode *LocateElem_Link_Yan(LinkList L, ElemType e) {
	//在L中找到第一个值和e相同的结点，返回其地址，若不存在，返回空值NULL。
	if (!L) return NULL;
	p = L;
	while (p&&p->data != e) { p = p->next };//if(!p) p=null;
	return p;//时间复杂度O(n)
}
void MergeList_Link_Tan(LinkList &La, LinkList &Lb) {
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
int ListLength_Link(struct LNode *head) {//求线性单链表长度
	struct LNode *p = head->next;//LNode1
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	head->data = len; //存储长度到头结点的数据域head->data
	return len;
}
Status GetElem_Link_Yan(LinkList L, int i, ElemType &e) {
	//取出元素,i是序号,e为值
	//L为带头结点的单链表的头节点
	//L-next为 带头结点的单链表的 头指针 指向第一个结点LNode1
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

 //c语言　的结构体中可以利用函数指针的方法，实现c++中的成员函数；
 //例如：
struct stu_info {
	char *name;
	int age;
	void(*print_info)(struct stu_info *stu);
};
void print_information(struct stu_info *stu) {

}
int main(void) {
	struct stu_info stu;
	stu.print_info = print_information;
}
//就是采用了“函数指针”来实现了c++中的类的封装。
//函数的指针　功能很强大。

