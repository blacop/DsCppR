/*
多项式加法运算
使用链表实现
*/
#include <iostream>
using namespace std;

//使用不带头结点的单向链表，按照指数递减的顺序排列
typedef struct PolyNode {
	int coef;    //系数
	int expon;    //指数
	PolyNode* link;    //指向下一个节点的指针
}*polynomial, npolynomial;

polynomial PolyAdd(polynomial p1, polynomial p2);
int Compare(int p1e, int p2e);
void Attach(int coef, int expon, polynomial *pRear);
polynomial CreatePoly(int size);

polynomial PolyAdd(polynomial p1, polynomial p2) {
	polynomial front, rear, temp;
	int sum;
	rear = new npolynomial;    //为方便表头插入，先产生一个临时空结点作为结果多项式链表头
	front = rear;    //由front记录结果多项式链表头结点
	while (p1 && p2)    //当两个多项式都有非零项待处理时
	{
		switch (Compare(p1->expon, p2->expon)) {
			case 1:    //p1中的数据项指数较大
				Attach(p1->coef, p1->expon, rear);
				p1 = p1->link;
				break;
			case -1:    //p2中的数据项指数较大
				Attach(p2->coef, p2->expon, rear);
				p2 = p2->link;
				break;
			case 0:    //两数据项指数相等
				sum = p1->coef + p2->coef;
				if (sum)    //判断系数和是否为0
				{
					Attach(sum, p1->expon, rear);
				}
				p1 = p1->link;
				p2 = p2->link;
				break;
		}
	}
	//将未处理完的另一个多项式的所有节点依次复制到结果多项式去
	while (p1) {
		Attach(p1->coef, p1->expon, rear);
		p1 = p1->link;
	}
	while (p2) {
		Attach(p2->coef, p2->expon, rear);
		p2 = p2->link;
	}
	rear->link = NULL;
	temp = front;
	front = front->link;    //使front指向结果多项式第一个非零项目
	delete temp;
	return front;
}

int Compare(int p1e, int p2e) {
	if (p1e > p2e) {
		return 1;
	} else if (p1e < p2e) {
		return -1;
	} else {
		return 0;
	}
}

void Attach(int coef, int expon, polynomial *pRear) {
	//由于本函数需要改变当前结果表达式尾项指针的值；
	//因此函数传递进来的是结点指针的地址，p指向尾项
	polynomial p;

	p = new npolynomial;
	p->coef = coef;
	p->expon = expon;
	//将P指向的新结点插入到当前结果表达式尾项的后面
	pRear->link = p;
	pRear = p;
}

polynomial CreatePolyDSC(int size)    //降序建立多项式
{
	polynomial head, p;
	head = NULL;
	p = NULL;
	for (int i = 0; i < size; i++) {
		p = new npolynomial;
		p->link = NULL;
		p->coef = i;
		p->expon = i;
		if (head != NULL)    //在链表头部插入
		{
			p->link = head;
			head = p;
		} else {
			head = p;
		}
	}
	return head;
}

polynomial CreatePolyASC(int size)    //升序建立多项式
{
	polynomial head, p;
	head = NULL;
	p = NULL;
	for (int i = 0; i < size; i++) {
		p = new npolynomial;
		p->link = NULL;
		p->coef = i;
		p->expon = i;
		if (head != NULL)    //在链表头部插入
		{
			p->link = head;
			head = p;
		} else {
			head = p;
		}
	}
	return head;
}

int main() {
	polynomial p1, p2, sump;
	p1 = CreatePoly(5);
	p2 = CreatePoly(8);

	sump = PolyAdd(p1, p2);

	cout << "p1:" << endl;
	while (p1) {
		cout << p1->coef << "x^" << p1->expon << '+';
		p1 = p1->link;
	}
	cout << endl;

	cout << "p2:" << endl;
	while (p2) {
		cout << p2->coef << "x^" << p2->expon << '+';
		p2 = p2->link;
	}
	cout << endl;

	cout << "sump:" << endl;
	while (sump) {
		cout << sump->coef << "x^" << sump->expon << '+';
		sump = sump->link;
	}
	cout << endl;
	return 0;
}
