#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
//#define QElemType int
//#define Status int
#define MAX_QSIZE 100
typedef int QElemType;
typedef int ElemType;
typedef int Status;
/*
#define Node LNode
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//顺序队列Q的基本操作 有返回值 参数类型 9个CORE
Status InitQueue(SqQueue &Q) //初始化顺序队列Q 1
Status DestroyQueue(SqQueue &Q) //销毁顺序队列Q 2
Status ClearQueue(SqQueue &Q) //清空顺序队列Q 3
Status QueueEmpty(SqQueue Q) //判断顺序队列Q是否为空 4
int QueueLength(SqQueue Q) //求顺序队列Q的长度 5
QElemType GetHead(SqQueue Q) //取顺序队列Q的 Head 元素 取得队列的 出口的元素 6
Status EnQueue(SqQueue &Q,e) //压队列 加入一个队列顶元素 7
Status Dequeue(SqQueue &Q,&e) //出队列 弹出一个队列顶元素 8
Status QueueTraverse(SqQueue Q,visit()) //遍历顺序队列Q:依次对S的每个元素调用visit() 9
*/
/*
//顺序队列Q的基本操作 无返回值 简版 9个CORE
InitQueue(&Q) //初始化顺序队列Q 1
DestroyQueue(&Q) //销毁顺序队列Q 2
ClearQueue(&Q) //清空顺序队列Q 3
QueueEmpty(Q) //判断顺序队列Q是否为空 4
QueueLength(Q) //求顺序队列Q的长度 5
GetHead(Q) //取顺序队列Q的 Head 元素 取得队列的 出口的元素 6
EnQueue(&Q,e) //压队列 加入一个队列顶元素 7
Dequeue(&Q,&e) //出队列 弹出一个队列顶元素 8
QueueTraverse(Q,visit()) //遍历顺序队列Q:依次对S的每个元素调用visit() 9
*/
//---------------顺序队列----------------
//顺序队列 初始化InitQueue 尾插法 插入EnQueue 删除Dequeue 查找GetHead 长度QueueLength
//入口 尾 ，出口 头
typedef struct SqQueue { //封装一个顺序队列Node Tan,
						 //循环队列，用游标实现法
	QElemType *base; //base 连续空间首地址
	int front;//指向队列的头一个元素
	int rear;//指向队尾的下一个元素，类似于==>top
}SqQueue;
Status InitQueue(SqQueue &Q) { //初始化顺序队列Q 1
	//SqQueue &Q 指针或引用从外面传进来
	Q->base = (SqQueue *)malloc(MAX_QSIZE * sizeof(SqQueue));//开辟空间
	if (!Q->front) exit(OVERFLOW);//开辟失败则退出
	Q->front = Q.rear = 0;//Q->front.next = NULL; //<==> Q.rear.next = NULL;	
	return TRUE;
}
Status DestroyQueue(SqQueue &Q) //销毁顺序队列Q 2
{}
Status ClearQueue(SqQueue &Q) //清空顺序队列Q 3
{}
Status QueueEmpty(SqQueue Q) //判断顺序队列Q是否为空 4
{
	//出队 入队
	if (Q.rear == Q.front)
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status QueueFull(SqQueue Q) //判断顺序队列Q是否满
{
	//出队 入队,队尾留一个空位置
	if if ((Q.rear + 1) % MAX_QSIZE == Q.front) //队尾留一个空位置
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}
int QueueLength(SqQueue Q) //求顺序队列Q的长度 5
{}
QElemType GetHead(SqQueue Q) //取顺序队列Q的 Head 元素 取得队列的 出口的元素 6
{}
Status EnQueue(SqQueue &Q, QElemType e) { //入队列 压队列 加入一个队列顶元素 7
	//循环指针++ move 必须求模 (rear+1) % MAX_QSIZE
	if (QueueFull()) {
		return FALSE;
	}
	else {
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MAX_QSIZE; //rear++ move//关键，要取模
		return TRUE;
	}
}
Status DeQueue(SqQueue &Q, QElemType &e) { //出队列 弹出一个队列顶元素 8
	//循环 指针++ move 必须求模 (front+1) % MAX_QSIZE
	if (QueueEmpty())
	{
		return FALSE;
	}
	else {
		e = Q.base[Q.front];
		Q.front = (Q.front + 1) % MAX_QSIZE;
	}
	return TRUE;
}
Status QueueTraverse(SqQueue Q, visit()) //遍历顺序队列Q:依次对S的每个元素调用visit() 9
{}
//上交大 TV 8/29 ,01：00:00/01:19:00
//Mix Type
typedef struct { //封装一个顺序栈结构 为SqStack
	SElemType *base;//基地址指针,栈底指针,存储空间，存放头地址,也可表示数组的名字 或地址  或第一个元素
	SElemType *top;//栈顶指针,SElemType的指针大小根据数据类型来确定
	int stackSize;//当前存储容量
}SqStack, Stack;
typedef struct SqQueue { //封装一个顺序队列Node Tan,
						 //循环队列，用游标实现法
	QElemType *base; //base 连续空间首地址
	int front;//指向队列的头一个元素
	int rear;//指向队尾的下一个元素，类似于==>top
}SqQueue, Queue;

void ReverseQueue(SqQueue &Q) {
	//逆置队列
	Stack S;
	ElemType d;
	InitStack(S);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, d); //out 1234
		Push(S, d); //in 1234
	}
	while (!StackEmpty(S)) {
		Pop(S, d); //out 4321
		EnQueue(Q, d); //in 4321
	}
}
//---------
//Special
Status Fabonacci(int K, SqQueue &Q; int MAX) {
	//循环队列
	int f;//f is sum;
	Q.base = (QElemType *)malloc(K * sizeof(QElemType));//基地址
	if (!Q.base) exit(OVERFLOW);
	Q.base[0] = 0; Q.base[1] = 1; Q.rear = 2; f = 1;//f is sum;
	while (f <= MAX) {
		Q.base[Q.rear] = f;//se core 赋值 入队列
		Q.rear = (Q.rear + 1) % K; //se core,rear指针 ++ move ,K is QueueLength 队列长度.
		i = (Q.rear - 1 + K) % K;//core,求模运算，算出长度的绝对值，求出周期
		j = (Q.rear - 2 + K) % K;//core,求模运算，算出长度的绝对值，求出周期
		f = Q.base[i] + Q.base[j];//math function
	}//while
}//Fabonacci
Status EnQueueOS(SqQueue &Q, QElemType e) {
	//EnQueueOSTaskManager
	//循环队列
	//插入受限，小于平均时间入队头,否则入队尾
	QElemType t; //平均时间
	if ((Q.rear + 1) % MAX_QSIZE == Q.front) {
		return FALSE;//队列满
	}
	t = (Q.base[Q.front] + Q.base[(Q.rear - 1) % MAX_QSIZE]) / 2;//计算平均时间
	if (e < t) {
		Q.front = (Q.front - 1 + MAX_QSIZE) % MAX_QSIZE;//入队头
		Q.base[Q.front] = e;
	}
	else {
		Q.base[Q.rear] = e;//入队尾
		Q.rear = (Q.rear + 1) % MAX_QSIZE;
	}
	return TRUE;
}//EnQueueOSTaskManager
Status EnQueueTail(SqQueue &Q, QElemType e) { //入队列 压队列 加入一个队列顶元素 7
										  //循环指针++ move 必须求模 (rear+1) % MAX_QSIZE
	if (QueueFull()) {
		return FALSE;
	}
	else {
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MAX_QSIZE; //rear++ move//关键，要取模
		return TRUE;
	}
}
Status EnQueueHead(SqQueue &Q, QElemType e) { //入队列 压队列 加入一个队列顶元素 7
										  //循环指针++ move 必须求模 (rear+1) % MAX_QSIZE
	if (QueueFull()) {
		return FALSE;
	}
	else {
		Q.front = (Q.front - 1 + MAX_QSIZE) % MAX_QSIZE;//入队头
		Q.base[Q.front] = e;
		return TRUE;
	}
}
