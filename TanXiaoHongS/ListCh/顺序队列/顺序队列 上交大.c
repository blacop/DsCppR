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
//˳�����Q�Ļ������� �з���ֵ �������� 9��CORE
Status InitQueue(SqQueue &Q) //��ʼ��˳�����Q 1
Status DestroyQueue(SqQueue &Q) //����˳�����Q 2
Status ClearQueue(SqQueue &Q) //���˳�����Q 3
Status QueueEmpty(SqQueue Q) //�ж�˳�����Q�Ƿ�Ϊ�� 4
int QueueLength(SqQueue Q) //��˳�����Q�ĳ��� 5
QElemType GetHead(SqQueue Q) //ȡ˳�����Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
Status EnQueue(SqQueue &Q,e) //ѹ���� ����һ�����ж�Ԫ�� 7
Status Dequeue(SqQueue &Q,&e) //������ ����һ�����ж�Ԫ�� 8
Status QueueTraverse(SqQueue Q,visit()) //����˳�����Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
*/
/*
//˳�����Q�Ļ������� �޷���ֵ ��� 9��CORE
InitQueue(&Q) //��ʼ��˳�����Q 1
DestroyQueue(&Q) //����˳�����Q 2
ClearQueue(&Q) //���˳�����Q 3
QueueEmpty(Q) //�ж�˳�����Q�Ƿ�Ϊ�� 4
QueueLength(Q) //��˳�����Q�ĳ��� 5
GetHead(Q) //ȡ˳�����Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
EnQueue(&Q,e) //ѹ���� ����һ�����ж�Ԫ�� 7
Dequeue(&Q,&e) //������ ����һ�����ж�Ԫ�� 8
QueueTraverse(Q,visit()) //����˳�����Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
*/
//---------------˳�����----------------
//˳����� ��ʼ��InitQueue β�巨 ����EnQueue ɾ��Dequeue ����GetHead ����QueueLength
//��� β ������ ͷ
typedef struct SqQueue { //��װһ��˳�����Node Tan,
						 //ѭ�����У����α�ʵ�ַ�
	QElemType *base; //base �����ռ��׵�ַ
	int front;//ָ����е�ͷһ��Ԫ��
	int rear;//ָ���β����һ��Ԫ�أ�������==>top
}SqQueue;
Status InitQueue(SqQueue &Q) { //��ʼ��˳�����Q 1
	//SqQueue &Q ָ������ô����洫����
	Q->base = (SqQueue *)malloc(MAX_QSIZE * sizeof(SqQueue));//���ٿռ�
	if (!Q->front) exit(OVERFLOW);//����ʧ�����˳�
	Q->front = Q.rear = 0;//Q->front.next = NULL; //<==> Q.rear.next = NULL;	
	return TRUE;
}
Status DestroyQueue(SqQueue &Q) //����˳�����Q 2
{}
Status ClearQueue(SqQueue &Q) //���˳�����Q 3
{}
Status QueueEmpty(SqQueue Q) //�ж�˳�����Q�Ƿ�Ϊ�� 4
{
	//���� ���
	if (Q.rear == Q.front)
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status QueueFull(SqQueue Q) //�ж�˳�����Q�Ƿ���
{
	//���� ���,��β��һ����λ��
	if if ((Q.rear + 1) % MAX_QSIZE == Q.front) //��β��һ����λ��
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}
int QueueLength(SqQueue Q) //��˳�����Q�ĳ��� 5
{}
QElemType GetHead(SqQueue Q) //ȡ˳�����Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
{}
Status EnQueue(SqQueue &Q, QElemType e) { //����� ѹ���� ����һ�����ж�Ԫ�� 7
	//ѭ��ָ��++ move ������ģ (rear+1) % MAX_QSIZE
	if (QueueFull()) {
		return FALSE;
	}
	else {
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MAX_QSIZE; //rear++ move//�ؼ���Ҫȡģ
		return TRUE;
	}
}
Status DeQueue(SqQueue &Q, QElemType &e) { //������ ����һ�����ж�Ԫ�� 8
	//ѭ�� ָ��++ move ������ģ (front+1) % MAX_QSIZE
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
Status QueueTraverse(SqQueue Q, visit()) //����˳�����Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
{}
//�Ͻ��� TV 8/29 ,01��00:00/01:19:00
//Mix Type
typedef struct { //��װһ��˳��ջ�ṹ ΪSqStack
	SElemType *base;//����ַָ��,ջ��ָ��,�洢�ռ䣬���ͷ��ַ,Ҳ�ɱ�ʾ��������� ���ַ  ���һ��Ԫ��
	SElemType *top;//ջ��ָ��,SElemType��ָ���С��������������ȷ��
	int stackSize;//��ǰ�洢����
}SqStack, Stack;
typedef struct SqQueue { //��װһ��˳�����Node Tan,
						 //ѭ�����У����α�ʵ�ַ�
	QElemType *base; //base �����ռ��׵�ַ
	int front;//ָ����е�ͷһ��Ԫ��
	int rear;//ָ���β����һ��Ԫ�أ�������==>top
}SqQueue, Queue;

void ReverseQueue(SqQueue &Q) {
	//���ö���
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
	//ѭ������
	int f;//f is sum;
	Q.base = (QElemType *)malloc(K * sizeof(QElemType));//����ַ
	if (!Q.base) exit(OVERFLOW);
	Q.base[0] = 0; Q.base[1] = 1; Q.rear = 2; f = 1;//f is sum;
	while (f <= MAX) {
		Q.base[Q.rear] = f;//se core ��ֵ �����
		Q.rear = (Q.rear + 1) % K; //se core,rearָ�� ++ move ,K is QueueLength ���г���.
		i = (Q.rear - 1 + K) % K;//core,��ģ���㣬������ȵľ���ֵ���������
		j = (Q.rear - 2 + K) % K;//core,��ģ���㣬������ȵľ���ֵ���������
		f = Q.base[i] + Q.base[j];//math function
	}//while
}//Fabonacci
Status EnQueueOS(SqQueue &Q, QElemType e) {
	//EnQueueOSTaskManager
	//ѭ������
	//�������ޣ�С��ƽ��ʱ�����ͷ,�������β
	QElemType t; //ƽ��ʱ��
	if ((Q.rear + 1) % MAX_QSIZE == Q.front) {
		return FALSE;//������
	}
	t = (Q.base[Q.front] + Q.base[(Q.rear - 1) % MAX_QSIZE]) / 2;//����ƽ��ʱ��
	if (e < t) {
		Q.front = (Q.front - 1 + MAX_QSIZE) % MAX_QSIZE;//���ͷ
		Q.base[Q.front] = e;
	}
	else {
		Q.base[Q.rear] = e;//���β
		Q.rear = (Q.rear + 1) % MAX_QSIZE;
	}
	return TRUE;
}//EnQueueOSTaskManager
Status EnQueueTail(SqQueue &Q, QElemType e) { //����� ѹ���� ����һ�����ж�Ԫ�� 7
										  //ѭ��ָ��++ move ������ģ (rear+1) % MAX_QSIZE
	if (QueueFull()) {
		return FALSE;
	}
	else {
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MAX_QSIZE; //rear++ move//�ؼ���Ҫȡģ
		return TRUE;
	}
}
Status EnQueueHead(SqQueue &Q, QElemType e) { //����� ѹ���� ����һ�����ж�Ԫ�� 7
										  //ѭ��ָ��++ move ������ģ (rear+1) % MAX_QSIZE
	if (QueueFull()) {
		return FALSE;
	}
	else {
		Q.front = (Q.front - 1 + MAX_QSIZE) % MAX_QSIZE;//���ͷ
		Q.base[Q.front] = e;
		return TRUE;
	}
}
