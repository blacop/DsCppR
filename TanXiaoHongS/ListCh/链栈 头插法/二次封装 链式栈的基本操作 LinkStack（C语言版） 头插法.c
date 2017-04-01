//链式栈的基本操作——LinkStack（C语言版） 头插法
//http://blog.csdn.net/guoyong10721073/article/details/9077491
#include "stdafx.h"
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */
/* 链栈结构 */
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*StackNodePtr;

typedef struct LinkStack{
    StackNodePtr top;
    int count;
}LinkStack,*LinkStackPtr;

Status visit(SElemType c){
    printf("%d ",c);
    return TRUE;
}
/*  构造一个空栈S */
Status InitStack(LinkStackPtr &S){ 
    S->top = (StackNodePtr)malloc(sizeof(StackNode));
    if(!S->top)    {
        return FALSE;
    }
    S->top = NULL;
    S->count = 0;
    return TRUE;
}
/* 把S置为空栈 */
Status ClearStack(LinkStackPtr S)
{ 
    StackNodePtr p,q;
    p = S->top;
    while(p)
    {  
        q = p; /* "q" is the prev node of node "p"*/
        p = p->next;
        free(q);
    } 
    S->count=0;

    return TRUE;
}
/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status IsEmptyStack(LinkStack S){ 
    if (S.count == 0)  {
        return TRUE;
    }
    else   {
        return FALSE;
    }
}
/* 返回S的元素个数，即栈的长度 */
int GetStackLength(LinkStack S){ 
    return S.count;
}

Status GetTopElem(LinkStack S,SElemType *e){
	/* 若栈不空，则用e返回S的栈顶元素，并返回TRUE；否则返回FALSE */
    if (S.top == NULL)    {
        return FALSE;
    }
    else    {
        *e = S.top->data;
    }
    return TRUE;
}
Status Push(LinkStackPtr S,SElemType e){
	/* 插入元素e为新的栈顶元素 */
    StackNodePtr s=(StackNodePtr)malloc(sizeof(StackNode));
    if (!s)    {
        return FALSE;
    }
    s->data = e;
    s->next = S->top;/* 把当前的栈顶元素赋值给新结点的直接后继 */
    S->top = s;      /* 将新的结点s赋值给栈顶指针 */
    S->count++;
    return TRUE;
}
Status Pop(LinkStackPtr S,SElemType *e){ 
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回TRUE；否则返回FALSE */
    StackNodePtr p;
    if(IsEmptyStack(*S))    {
        return FALSE;
    }
    *e = S->top->data;
    p = S->top; /* 将栈顶结点赋值给p，见图中③ */
    S->top = S->top->next;/* 使得栈顶指针下移一位，指向后一结点，见图中④ */
    free(p);              /* 释放结点p */        
    S->count--;
    return TRUE;
}
Status StackTraverse(LinkStack S){
    StackNodePtr p;
    p=S.top;
    while(p)  {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return TRUE;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int j;
    LinkStack s;
    int e;
    if(InitStack(&s)==TRUE)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",IsEmptyStack(s));
    GetTopElem(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,GetStackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",IsEmptyStack(s));

    return 0;
}