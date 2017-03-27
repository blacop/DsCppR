#include "stdio.h"
#include "malloc.h"

/* 链表结点结构 */
typedef struct PNode {
	double coef;          /* 系数 */
	int exp;              /* 指数 */
	struct PNode *next;  //ref domain
}PNode;

/* 初始化链表 */
PNode* Init() {
	PNode *head = (PNode*)malloc(sizeof(PNode));
	head->next = NULL;
	return head;
}

/* 将值为data的结点插入到head链表的最后 */ // AppendByInstanseNode
void AddNode(PNode *head, double coef, int exp) {
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

/* 输出head链表的所有结点的值 */
void List(PNode *head) {
	PNode *curr;
	printf("All nodes : ");
	for (curr = head->next; curr != NULL; curr = curr->next) {
		printf("(%lf, %d)\t", curr->coef, curr->exp);
	}
	printf("\n");
}

/* 返回head链表的所有结点的数量 */
int Size(PNode *head) {
	int len = 0;
	PNode *curr;
	for (curr = head->next; curr != NULL; curr = curr->next, len++);
	return len;
}

//多项式链表加法
PNode* Add(PNode *headA, PNode *headB) {
	PNode *currA, *currB, *headC;
	double sum;
	currA = headA->next;
	currB = headB->next;
	headC = Init();
	while (currA != NULL && currB != NULL) {
		if (currA->exp > currB->exp) {
			AddNode(headC, currA->coef, currA->exp);
			currA = currA->next;
		} else if (currA->exp < currB->exp) {
			AddNode(headC, currB->coef, currB->exp);
			currB = currB->next;
		} else {
			sum = currA->coef + currB->coef;
			if (sum != 0) {
				AddNode(headC, sum, currA->exp);
			}
			currA = currA->next;
			currB = currB->next;
		}
	}
	while (currA != NULL) {
		AddNode(headC, currA->coef, currA->exp);
		currA = currA->next;
	}
	while (currB != NULL) {
		AddNode(headC, currB->coef, currB->exp);
		currB = currB->next;
	}
	return headC;
}

//主函数
void main() {
	PNode *headA, *headB, *headC;
	headA = Init();
	headB = Init();
	AddNode(headA, 1.0, 5);
	AddNode(headA, -1.0, 3);
	AddNode(headA, 1, 0);
	AddNode(headB, 0.5, 5);
	AddNode(headB, 1.0, 4);
	AddNode(headB, 1.0, 3);
	List(headA);
	List(headB);
	headC = Add(headA, headB);
	List(headC);

}