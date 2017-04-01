//采用链式存储实现队列的初始化、入队、出队操作。
//http://blog.csdn.net/cddchina/article/details/7479352
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
typedef struct QNode{//创建队成员
 int  data;//数据成员
 struct QNode *next;
}QNode,*QueuePtr;
typedef struct{//队头队尾指针
 QueuePtr  front;
 QueuePtr  rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)//初始化队列
{  
 Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));//开辟空间
 if(!Q.front) exit (OVERFLOW);//开辟失败则退出
 Q.front ->next = NULL;
 //return 1;
}
int EnQueue(LinkQueue &Q)//入队操作 
{  
 int e;
 QueuePtr p;
 printf("请输入入队元素:");
 scanf("%d",&e);
 p=(QueuePtr)malloc(sizeof(QNode));
 if (p==NULL) exit (OVERFLOW);
 p->data = e;  p->next = NULL;
 Q.rear->next=p;//把p插入队尾
 Q.rear=p;//把p变为队尾
 return 1;
}
int DeQueue(LinkQueue &Q)//出队操作 
{ 
 QueuePtr p;
 int e;
 if ( Q.front == Q.rear){ 
  printf("队列为空\n");
  return -1;
 }
 p=Q.front->next;//头指针为空
 e=p->data;
 printf("%d  出对\n",e);
 Q.front->next =p->next;//指针后移
 if (Q.rear == p) Q.rear = Q.front;//如果p为队尾
 free(p);//释放p
 return 1;
}
void tip()
{  
 printf("*************\n");
 printf("*输入1 进队 *\n");
 printf("*输入2 出对 *\n");
 printf("*请选择:    *\n");
 printf("*************\n");
}
int main()
{  
 int k;
 LinkQueue Q; 
 InitQueue(Q);//初始化队列
 tip();
 while(scanf("%d",&k),k)
 { 
  switch(k)
  { 
  case 1: 
   EnQueue(Q);
   tip();
   printf("操作完毕\n");
   break;
  case 2: 
   DeQueue(Q);
   tip();
   printf("操作完毕\n");
   break;
  }
  
 }
 return 0;
}