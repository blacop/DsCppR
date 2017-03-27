/*链栈*/
//http://www.cnblogs.com/w784319947/p/6429634.html
/*链栈的结构和各种基本操作都类似于线性链表
*只是要注意它的插入和删除操作只能在栈顶进行
*为了方便操作，我们将链表的头部作为栈顶
*/
#include<stdio.h>
#include<stdlib.h>

//结构定义
typedef struct node
{
    elementType data;
    struct node *next; 
} LSNode;//链栈节点 
typedef struct
{
    struct LSNode *top;
    int size;
}*PSTACK;//链栈 
typedef int elementType;

//基本操作
//注意：配合CreatStack(),应该有DisposeStack(PSTACK) 
 PSTACK CreatStack()
 {
     PSTACK p=NULL;
    p=(PSTACK)malloc(sizeof(*PSTACK));
     if(p==NULL)
     {
         printf("Cannot malloc for PSTACK\n");
         //根据内存分配失败，业务是否还能进行选择 
        //return NULL;
        exit(1); 
    }
    else
    {
        p->top=NULL;
        p->size=0;
        return p;
    }
 }
 int IsEmpty(PSTACK s)
 {
     if(s==NULL)
         return 1;
    else
        return 0;
 }
 void PopStack(PSTACK s)//出栈 
 {
     if(IsEmpty(s))
     {
        printf("Stack is Empty\n");
    }
    else
    {
        LSNode*p=NULL;
         p=s->top->next;
         free(s->top);
         s->top=p;
         s->size--;
    }
 }
 void MakeEmptyStack(PSTACK s)//清空栈 
 {
     while(s->top!=NULL)
    {
        //PopStack()中有重复判断，不爽大可以重写
        PopStack(s);  
    }
 }
 void DisposeStack(PSTACK s)//删除栈 
{
     MakeEmptyStack(s);
     free(s);
}
void PushStack(elementType x, PSTACK s)//压栈,入栈 
{
    LSNode*p=NULL;
    p=(LSNode*)malloc(sizeof(LSNode));
    if(p==NULL)
    {
        printf("Cannot malloc for LSNode\n");
        //根据内存分配失败，业务是否还能进行选择 
        //return NULL;
        exit(1);
    } 
    p->data=x;
    p->next=s->top;
    s->top=p;
    s->size++;
}
elementType TopStack(PSTACK s)//取栈顶元素
{
    if(s->top==NULL)
        return NULL;
    else 
        return s->top->data;
}
elementType TopAndPop(PSTACK s)//取栈顶元素，并出栈(栈空时返回NULL）
{
    //因为使用此函数前提是已经判断了栈非空，这里不做重复判断
    elementType x;
    x=TopStack(s);
    PopStack(s);
    return x; 
}