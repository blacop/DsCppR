//链队列的建立、判空、入队、出队、求长、访头、清空和销毁
//http://blog.csdn.net/stpeace/article/details/8131634
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}Node;

//头指针和尾指针
typedef struct
{
	Node *front;
	Node *rear;
}Queue;

void initQueue(Queue &Q)
{
	Q.front = Q.rear = new Node;
	Q.front->next = NULL;
}

bool isEmptyQueue(Queue &Q)
{
	if(NULL == Q.front) //此时链队列被销毁
	{
		cout << "链队列不存在." << endl;
		exit(1);
	}

	if(Q.rear == Q.front)//此时链队列为空
		return true;

	return false;
}

void enterQueue(Queue &Q, int element)
{
	Node *p = new Node;
	p->next = NULL;
	p->data = element;
	Q.rear->next = p;
	Q.rear = p;
}

int deQueue(Queue &Q)
{
	int outElement;
	if(isEmptyQueue(Q))
		exit(1);

	Node *p = Q.front->next;
	outElement = p->data;

	Q.front->next = p->next;
	if(Q.rear == p)  //需要特殊处理
		Q.rear = Q.front;
	delete p;

	return outElement;
}

int getLength(Queue &Q)
{
	Node *p1 = Q.front;
	Node *p2 = Q.rear;
	int length = 0;
	while(p1 != p2)
	{
		p1 = p1->next;
		length++;
	}

	return length;
}

int getHead(Queue &Q)
{
	if(isEmptyQueue(Q))
		exit(1);

	return Q.front->next->data;
}

void clearQueue(Queue &Q)
{
	while(!isEmptyQueue(Q))
		deQueue(Q);
}

void destroyQueue(Queue &Q)
{
	clearQueue(Q);
	delete Q.front;
	Q.front = Q.rear = NULL;
}

int main()
{
	Queue Q;
	initQueue(Q);
	cout << getLength(Q) << endl;
	
	int i;
	for(i = 1; i <= 10; i++)
		enterQueue(Q, i);
	cout << getHead(Q) << endl;
	cout << getLength(Q) << endl;

	while(!isEmptyQueue(Q))
		cout << deQueue(Q) << " ";
	cout << endl;

	if(isEmptyQueue(Q))
		cout << "yes" << endl;
	else 
		cout << "no" << endl;
	
	destroyQueue(Q);
	if(isEmptyQueue(Q))
		cout << "yes" << endl;
	else 
		cout << "no" << endl;

	return 0;
}

