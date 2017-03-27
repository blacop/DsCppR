//数据结构--单链表的基本操作（C语言实现）(2012 - 03 - 22 21:55 : 47)转载▼
//http://blog.sina.com.cn/s/blog_7fec44cf0100xgx0.html
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK    1
typedef int status;
typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
} LNode, *LinkList;
void Create_Build(LinkList L) { //建立一个带头结点的单链表
	int n;
	LinkList p, q;
	p = L;
	printf("请输入n和n个数据元素:\n");
	scanf("%d", &n);
	while (n--)	{
		q = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &q->data);
		q->next = NULL;
		p->next = q;
		p = q;
	}
}
void TraversePrint(LinkList L)//计算单链表的长度，然后输出单链表
{
	int num = 0;
	LinkList p;
	p = L->next;
	while (p)
	{
		num++;
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n长度为%d:\n", num);
}
void Tips()
{
	printf("按数字键选择相应操作\n");
	printf("<1> 输出单链表及其长度:\n");
	printf("<2> 查找值为x的直接前驱结点:\n");
	printf("<3> 删除值为x的结点:\n");
	printf("<4> 将表中元素逆置:\n");
	printf("<5> 删除表中所有值大于mink且小于maxk的元素:\n");
	printf("<6> 删除表中所有值相同的多余元素:\n");
	printf("<7> 分解成两个链表:\n");
	printf("<8> 在升序链表插入值为X的结点，使仍然有序:\n");
	printf("<9> 按升序排列:\n");
	printf("<0> 退出:\n");
}
void Find(LinkList L, int x)//查找值为x的直接前驱结点q
{
	LinkList p;
	p = L;
	while (p->next &&p->next->data != x)
		p = p->next;
	if (p->next)
		printf("%d的前驱结点为:%d\n\n", x, p->data);
	else
		printf("没找到!!\n\n");
}
void Delete(LinkList L, int x)//删除值为x的结点
{
	LinkList p, q;
	p = L;
	while (p->next &&p->next->data != x)
		p = p->next;
	if (p->next)
	{
		q = p->next;
		p->next = q->next;
		free(q);
		printf("删除成功!!\n\n");
	}
	else
		printf("链表中没有%d\n\n", x);
}
void NiZhi(LinkList L)//把单向链表中元素逆置,类似于头插法建立链表!
{
	LinkList p, s;
	p = s = L->next;
	L->next = NULL;
	while (p)
	{
		s = s->next;
		p->next = L->next;
		L->next = p;
		p = s;
	}
	printf("逆置成功!!!\n\n");
}

void Delete1(LinkList L)//删除表中所有值大于mink且小于maxk的元素
{
	int maxk, mink;
	LinkList p, q, s;
	printf("请输入mink,maxk:\n");
	scanf("%d %d", &mink, &maxk);
	p = L;
	while (p->next && p->next->data <= mink)
		p = p->next;
	s = p->next;
	while (s && s->data<maxk)
	{
		q = s;
		s = s->next;
		free(q);
	}
	p->next = s;
	printf("删除成功\n\n");
}
void Delete2(LinkList L)//删除表中所有值相同的多余元素（使得操作后的线性表中所有元素的值均不相同），
{
	LinkList p, q, s;
	p = L;
	q = L->next;
	while (q->next)
	{
		if (q->data == q->next->data)
		{
			p->next = q->next;
			s = q;
			q = q->next;
			free(s);
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	printf("删除成功!!!!\n");
}
void fenjie(LinkList L)//利用（1）建立的链表，实现将其分解成两个链表，其中一个全部为奇数，另一个全部为偶数
{
	LinkList s, p, Lb, cur1, cur2;
	Lb = (LinkList)malloc(sizeof(LNode));
	Lb->next = NULL;
	s = L->next;
	L->next = NULL;
	cur1 = L;
	cur2 = Lb;
	while (s)
	{
		p = s;
		s = s->next;
		p->next = NULL;
		if (p->data & 1)
		{
			cur1->next = p;
			cur1 = cur1->next;
		}
		else
		{
			cur2->next = p;
			cur2 = cur2->next;
		}
	}
	cur1 = L->next;
	cur2 = Lb->next;
	printf("元素为奇数的链表:\n");
	while (cur1)
	{
		printf("%d ", cur1->data);
		cur1 = cur1->next;
	}
	printf("\n元素为偶数的链表:\n");
	while (cur2)
	{
		printf("%d ", cur2->data);
		cur2 = cur2->next;
	}
	printf("\n\n");
}
void Insert(LinkList L, LinkList p)//在升序链表插入值为X的结点，使仍然有序
{
	LinkList s;
	s = L;
	while (s->next && s->next->data < p->data)
		s = s->next;
	p->next = s->next;
	s->next = p;
}
status Sort(LinkList L)//按升序排列
{
	LinkList s, r;
	s = L->next;
	L->next = NULL;
	while (s)
	{
		r = s;
		s = s->next;
		r->next = NULL;
		Insert(L, r);
	}
	return OK;
}
int main()
{
	int op, x, flag;
	LinkList L, p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = -1;
	Build(L);
	Tips();
	scanf("%d", &op);
	while (op)
	{
		switch (op)
		{
		case 1:
			Print(L);
			break;
		case 2:
			printf("请输入要查找的元素X:\n");
			scanf("%d", &x);
			Find(L, x);
			break;
		case 3:
			printf("请输入要查找的删除X:\n");
			scanf("%d", &x);
			Delete(L, x);
			break;
		case 4:
			NiZhi(L);
			break;
		case 5:
			Delete1(L);
			break;
		case 6:
			Delete2(L);
			break;
		case 7:
			fenjie(L);
			break;
		case 8:
			printf("请输入要插入的元素X:\n");
			scanf("%d", &x);
			p = (LinkList)malloc(sizeof(LNode));
			p->data = x;
			Insert(L, p);
			printf("插入成功!!!\n\n");
			break;
		case 9:
			flag = Sort(L);
			if (flag)
				printf("排序成功!!\n");
			break;
		}
		Tips();
		scanf("%d", &op);
	}
	return 0;
}