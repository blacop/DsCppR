#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE -1
#define OVERFLOW -2
typedef int Status;
#define LEN sizeof(Node)
#define MLC (Node*)malloc(sizeof(Node))
//-------链表表示的 一元多项式 --------------
typedef struct PNode {
	float coef;		//系数 data域
	int expn;		//指数 data域
	PNode* next;	 //引用 ptr域
	int(*Length)(PList L); //长度
	PNode*(*MakeNode)(PNode* polyElem); //无参构造器, 用函数指针实现 成员函数	
	void(*CreatePloyn)(PList p, int length); //有参构造器,建立链表
}PNode, *PList;

//无参构造器,在c语言里面实现构造器，赋值语句,
PNode* MakeNode() {
	PNode* head = (PNode*)malloc(sizeof(PNode));
	if (!head)  /* 存储分配失败 */
		exit(OVERFLOW);
	coef = 0.0;//赋值语句 默认值
	expn = 0;
	next = NULL;
	return head;
}

//有参构造器，建立有值的多项式链表
void CreateValuePloyn(PList p, int length) {
	PList e = PList.MakeNode();//无参构造器
	for (int i = 0; i < length; i++) {
		scanf("%i,%i", &e->coef, &e->expn); //赋值,系数,指数	//输入各项的系数和指数,建立一元多项式的有序链表p
	}
}

/* 将值为data的结点插入到head链表的最后 */ // AppendByInstanseNode
void AppendNode(PNode *head, double coef, int exp) {
	PNode* pre = head->next;
	PNode* temp; //tempNode*
	temp = (PNode*)malloc(sizeof(PNode));
	temp->coef = coef;
	temp->exp = exp;
	temp->next = NULL;

	if (pre == NULL) {
		head->next = temp;
		return;
	}
	for (; pre->next != NULL; pre = pre->next);
	pre->next = temp;
}

//多项式节点的加法
PNode* Add(PNode *headA, PNode *headB) {
	PNode *currA, *currB, *headC;
	double sum;
	currA = headA->next;
	currB = headB->next;
	headC = Init();
	while (currA != NULL && currB != NULL) {
		if (currA->exp > currB->exp) {
			AppendNode(headC, currA->coef, currA->exp);
			currA = currA->next;
		} else if (currA->exp < currB->exp) {
			AppendNode(headC, currB->coef, currB->exp);
			currB = currB->next;
		} else {
			sum = currA->coef + currB->coef;
			if (sum != 0) {
				AppendNode(headC, sum, currA->exp);
			}
			currA = currA->next;
			currB = currB->next;
		}
	}
	while (currA != NULL) {
		AppendNode(headC, currA->coef, currA->exp);
		currA = currA->next;
	}
	while (currB != NULL) {
		AppendNode(headC, currB->coef, currB->exp);
		currB = currB->next;
	}
	return headC;
}

/* 返回head链表的所有结点的数量 */
int Length(PNode *head) {
	int len = 0;
	PNode *curr;
	for (curr = head->next; curr != NULL; curr = curr->next, len++);
	return len;
}

//访问结点输出
Status visit(PList p) {
	printf("(%lf, %d)\t", p->coef, p->expn);
	return TRUE;
}

//遍历链表输出 :依次对L的每个元素调用visit()
void ListTraverse(PList L, void(*visit)(PNode)) {
	/* 依次对L的每个元素调用vi(),打印输出语句*/
	PList p;  //temp ptr
	p = L->next; //pass the head node
	printf("All nodes's values are : ");
	while (p != NULL) {
		visit(p); //visit and print
		p = p->next;
	}
	printf("\n");
}

//主函数
void main() {
	PNode *headA, *headB, *headC;
	headA = Init();
	headB = Init();
	AppendNode(headA, 1.0, 5);
	AppendNode(headA, -1.0, 3);
	AppendNode(headA, 1, 0);
	AppendNode(headB, 0.5, 5);
	AppendNode(headB, 1.0, 4);
	AppendNode(headB, 1.0, 3);
	ListTraverse(headA);
	ListTraverse(headB);
	headC = Add(headA, headB);
	ListTraverse(headC);
}
