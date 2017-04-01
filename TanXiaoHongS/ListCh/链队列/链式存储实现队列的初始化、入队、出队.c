//������ʽ�洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ�����
//http://blog.csdn.net/cddchina/article/details/7479352
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
typedef struct QNode{//�����ӳ�Ա
 int  data;//���ݳ�Ա
 struct QNode *next;
}QNode,*QueuePtr;
typedef struct{//��ͷ��βָ��
 QueuePtr  front;
 QueuePtr  rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)//��ʼ������
{  
 Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));//���ٿռ�
 if(!Q.front) exit (OVERFLOW);//����ʧ�����˳�
 Q.front ->next = NULL;
 //return 1;
}
int EnQueue(LinkQueue &Q)//��Ӳ��� 
{  
 int e;
 QueuePtr p;
 printf("���������Ԫ��:");
 scanf("%d",&e);
 p=(QueuePtr)malloc(sizeof(QNode));
 if (p==NULL) exit (OVERFLOW);
 p->data = e;  p->next = NULL;
 Q.rear->next=p;//��p�����β
 Q.rear=p;//��p��Ϊ��β
 return 1;
}
int DeQueue(LinkQueue &Q)//���Ӳ��� 
{ 
 QueuePtr p;
 int e;
 if ( Q.front == Q.rear){ 
  printf("����Ϊ��\n");
  return -1;
 }
 p=Q.front->next;//ͷָ��Ϊ��
 e=p->data;
 printf("%d  ����\n",e);
 Q.front->next =p->next;//ָ�����
 if (Q.rear == p) Q.rear = Q.front;//���pΪ��β
 free(p);//�ͷ�p
 return 1;
}
void tip()
{  
 printf("*************\n");
 printf("*����1 ���� *\n");
 printf("*����2 ���� *\n");
 printf("*��ѡ��:    *\n");
 printf("*************\n");
}
int main()
{  
 int k;
 LinkQueue Q; 
 InitQueue(Q);//��ʼ������
 tip();
 while(scanf("%d",&k),k)
 { 
  switch(k)
  { 
  case 1: 
   EnQueue(Q);
   tip();
   printf("�������\n");
   break;
  case 2: 
   DeQueue(Q);
   tip();
   printf("�������\n");
   break;
  }
  
 }
 return 0;
}