/*链栈*/
/*链栈的结构和各种基本操作都类似于线性链表
*只是要注意它的插入和删除操作只能在栈顶进行
*为了方便操作，我们将链表的头部作为栈顶
*/
#include<stdio.h>
#include<stdlib.h>

//结构定义
typedef struct LSNode{
	elementType data;
	struct LSNode *next;
}LSNode;//链栈节点 
typedef struct LinkStack{
	struct LSNode *top;//
	int size;
}LinkStack,*PStack;//链栈 ,LSNodePtr
typedef int elementType;

PStack CreatStack(){
	//基本操作
	//注意：配合CreatStack(),应该有DisposeStack(PStack) 
	PStack p = NULL;
	p = (PStack)malloc(sizeof(*PStack));
	if (p == NULL){
		printf("Cannot malloc for PStack\n");
		//根据内存分配失败，业务是否还能进行选择 
	   //return NULL;
		exit(1);//exit(1)表示异常退出.这个1是返回给操作系统的。
	}
	else{
		p->top = NULL;
		p->size = 0;
		return p;//return LSNodePtr p;
	}
}
int IsEmpty(PStack s){
	if (s == NULL) //只要是空指针就是空栈
		return 1;
	else
		return 0;
}
void PoPStack(PStack s)//出栈 
{
	if (IsEmpty(s))
	{
		printf("Stack is Empty\n");
	}
	else
	{
		LSNode*p = NULL;
		p = s->top->next;
		free(s->top);
		s->top = p;
		s->size--;
	}
}
void MakeEmptyStack(PStack s)//清空栈 
{
	while (s->top != NULL)
	{
		//PoPStack()中有重复判断，不爽大可以重写
		PoPStack(s);
	}
}
void DisposeStack(PStack s)//删除栈 
{
	MakeEmptyStack(s);
	free(s);
}
void PushStack(elementType x, PStack s)//压栈,入栈 
{
	LSNode*p = NULL;
	p = (LSNode*)malloc(sizeof(LSNode));
	if (p == NULL)
	{
		printf("Cannot malloc for LSNode\n");
		//根据内存分配失败，业务是否还能进行选择 
		//return NULL;
		exit(1);
	}
	p->data = x;
	p->next = s->top;
	s->top = p;
	s->size++;
}
elementType ToPStack(PStack s)//取栈顶元素
{
	if (s->top == NULL)
		return NULL;
	else
		return s->top->data;
}
elementType TopAndPop(PStack s)//取栈顶元素，并出栈(栈空时返回NULL）
{
	//因为使用此函数前提是已经判断了栈非空，这里不做重复判断
	elementType x;
	x = ToPStack(s);
	PoPStack(s);
	return x;
}