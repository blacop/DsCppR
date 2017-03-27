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
typedef int QElemType;
typedef int ElemType;
typedef int Status;
#define Empty 0;
/*
#define Node LNode
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//链队列Q的基本操作 有返回值 参数类型 9个CORE
Status InitQueue(LinkQueue &Q) //初始化链队列Q 1
Status DestroyQueue(LinkQueue &Q) //销毁链队列Q 2
Status ClearQueue(LinkQueue &Q) //清空链队列Q 3
Status QueueEmpty(LinkQueue Q) //判断链队列Q是否为空 4
int QueueLength(LinkQueue Q) //求链队列Q的长度 5
QElemType GetHead(LinkQueue Q) //取链队列Q的 Head 元素 取得队列的 出口的元素 6
Status EnQueue(LinkQueue &Q,e) //压队列 加入一个队列顶元素 7
Status Dequeue(LinkQueue &Q,&e) //出队列 弹出一个队列顶元素 8
Status QueueTraverse(LinkQueue Q,visit()) //遍历链队列Q:依次对S的每个元素调用visit() 9
*/
/*
//链队列Q的基本操作 无返回值 简版 9个CORE
InitQueue(&Q) //初始化链队列Q 1
DestroyQueue(&Q) //销毁链队列Q 2
ClearQueue(&Q) //清空链队列Q 3
QueueEmpty(Q) //判断链队列Q是否为空 4
QueueLength(Q) //求链队列Q的长度 5
GetHead(Q) //取链队列Q的 Head 元素 取得队列的 出口的元素 6
EnQueue(&Q,e) //压队列 加入一个队列顶元素 7
Dequeue(&Q,&e) //出队列 弹出一个队列顶元素 8
QueueTraverse(Q,visit()) //遍历链队列Q:依次对S的每个元素调用visit() 9
*/
//---------------链队列----------------
//链队列 初始化InitQueue 尾插法 插入EnQueue 删除Dequeue 查找GetHead 长度QueueLength
//入口 尾 ，出口 头
typedef struct Qnode { //封装一个链队列Node Tan
	QElemType data; //数据域
	struct Qnode *next; //指针域 next
}Qnode, QNode, *PQNode;
typedef struct LinkQueue { //封装一个链队列 引用
	PQNode front; //头指针
	PQNode rear; //尾指针
}LinkQueue;
Status InitQueue(LinkQueue &Q) { //初始化链队列Q 1
	//LinkQueue &Q 指针或引用从外面传进来
	Q.front = Q.rear = (PQNode *)malloc(sizeof(QNode));//开辟空间
	if (!Q.front) exit(OVERFLOW);//开辟失败则退出
	Q.front->next = NULL; //<==> Q->rear->next = NULL;
	return TRUE;
}
Status DestroyQueue(LinkQueue &Q) //销毁链队列Q 2
{}
Status ClearQueue(LinkQueue &Q) //清空链队列Q 3
{}
Status QueueEmpty(LinkQueue Q) //判断链队列Q是否为空 4
{}
int QueueLength(LinkQueue Q) //求链队列Q的长度 5
{}
QElemType GetHead(LinkQueue Q) //取链队列Q的 Head 元素 取得队列的 出口的元素 6
{}
Status EnQueue(LinkQueue &Q, QElemType e) { //入队列 压队列 加入一个队列顶元素 7
	PQNode P＝(PQNode)malloc(sizeof(Qnode));//tempPtr,repos, insert new node P
	P->data = e;
	P->next = NULL;//尾插 new node P is tail
	Q.rear->next = p;//尾指 rearPtr finger new node
	Q.rear = P;//rearPtr++ move
}
Status DeQueue(LinkQueue &Q, QElemType &e) { //出队列 弹出一个队列顶元素 8
	if (QueueEmpty(Q)) return exit(Empty);//队列空
	e = Q.front->data;
	PQNode r = Q.front->next;//tempPtr finger node2
	Q.front->next = r->next;//Q.front++ move  
	free(r);
}
Status QueueTraverse(LinkQueue Q, visit()) //遍历链队列Q:依次对S的每个元素调用visit() 9
{}
//-----------------
//Special
//上交大 TV 9/29 , 00:47:05/01:06:27
typedef struct Qnode { //封装一个链队列Node Tan
	QElemType data; //数据域
	struct Qnode *next; //指针域 next
}Qnode, QNode, *PtrQNode, *PQNode;
typedef struct LinkQueue { //封装一个链队列 引用
	//PQNode front; //头指针 禁用
	PQNode rear; //尾指针
}LinkQueue;
Status InitQueueCirle(LinkQueue &Q) {
	//初始化
	//LinkQueue Q; //指针或引用从外面传进来
	Q.rear = (PQNode)malloc(sizeof(QNode);
	Q.rear->next = Q.rear; //Core
	return TRUE;
}
Status EnQueueCircle(LinkQueue &Q, QElemType e) { //入队列 压队列 加入一个队列顶元素 7
	PQNode P＝(PQNode)malloc(sizeof(Qnode));//tempPtr,repos, insert new node P
	P->data = e;
	P->next = Q.rear->next;//尾插 new node P is tail, 指向 head，core
	Q.rear->next = p;//尾指 rearPtr finger new nod, core
	Q.rear = P;//rearPtr++ move // core
}
Status DeQueueCircle(LinkQueue &Q, QElemType &e) { //出队列头部 弹出一个队列顶元素 8
	/* 2Ptr only , 2指针 专属
	e = Q.front->data;
	PQNode r = Q.front->next;//tempPtr finger node2
	Q.front->next = r->next;//Q.front++ move
	free(r);
	*/
	if (Q.rear->next = Q.rear) return exit(Empty);//队列空
	PQNode PtrH = Q.rear->next;//head node,node0
	PQNode R = PtrH->next;//node1 ,out node1
	PtrH->next = R->next;//head points node1.next
	e = R->data;//out data
				//return e;
	if (R = Q.rear) { //判断node only 2
		Q.rear = P; //防止丢失rear指针，circle only？
	}//if	
	free(s);
}
bool QueueEmptyCirle(LinkQueue Q) {//判断链队列Q是否为空 4
	if (Q.rear->next = Q.rear) return true;
	else return false;
}
