#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
/*
#define Node ElemTypeNode
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//链栈S的基本操作声明 带返回值 带初始条件 //初始条件:栈S己存在
Status InitStack(LinkStack &S) 
//初始化链栈S
Status DestroyStack(LinkStack &S) 
//初始条件:栈S己存在
//销毁链栈S 
Status ClearStack(LinkStack &S)
//初始条件:栈S己存在
//清空链栈S
Status StackEmpty(LinkStack S)
//初始条件:栈S己存在
//判断链栈S是否为空
int StackLength(LinkStack S)
//初始条件:栈S己存在
//求链栈S的长度
ElemType GetTop(LinkStack S,e)
//初始条件:栈S己存在 且非空
//取链栈S的第i个元素 取得栈的上面顶部出口的元素
Status Push(LinkStack &S,e) 
//初始条件:栈S己存在
//压栈 加入一个栈顶元素
Status Pop(LinkStack &S,&e) 
//初始条件:栈S己存在 且非空
//出栈 弹出一个栈顶元素
Status StackTraverse(LinkStack S,visit()) 
//初始条件:栈S己存在 且非空
//遍历链栈S:依次对S的每个元素调用visit()
*/
/*
//链栈S的基本操作声明带返回值
Status InitStack( &S) //初始化链栈S
Status DestroyStack(LinkStack &S) //销毁链栈S
Status ClearStack(LinkStack &S) //清空链栈S
Status StackEmpty(LinkStack S) //判断链栈S是否为空
int StackLength(LinkStack S) //求链栈S的长度
ElemType GetTop(LinkStack S,e) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Status Push(LinkStack &S,e) //压栈 加入一个栈顶元素
Status Pop(LinkStack &S,&e) //出栈 弹出一个栈顶元素
Status StackTraverse(LinkStack S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
*/
/*
//链栈S的基本操作简版
InitStack(LinkStack &S) //初始化链栈S
DestroyStack(LinkStack &S) //销毁链栈S
ClearStack(LinkStack &S) //清空链栈S
StackEmpty(LinkStack S) //判断链栈S是否为空
StackLength(LinkStack S) //求链栈S的长度
GetTop(LinkStack S) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Push(LinkStack &S,e) //压栈 加入一个栈顶元素
Pop(LinkStack &S,&e) //出栈 弹出一个栈顶元素
StackTraverse(LinkStack S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
*/
//---------------链栈----------------
//链栈 初始化 头插法 长度

typedef struct StackNode { //封装一个链栈 Node
	ElemType data; //数据域
	struct StackNode *next; //指针域 next,保存引用
}StackNode,*StackNodePtr;
typedef struct LinkStack { //二次封装
	struct StackNodePtr top;//top finger node
	int count;//length
}LinkStack,*LinkStackPtr;

//链栈S的基本操作声明 带返回值 带初始条件 //初始条件:栈S己存在
Status InitStack(LinkStackPtr &S) { //初始化链栈S
	/*
	->在C语言中称为间接引用运算符，是二目运算符，优先级同成员运算符“.”。
	用法：
	p->a，其中p是指向一个结构体的指针，a是这个结构体类型的一个成员。
	表达式p->a引用了指针p指向的结构体的成员a。
	S->top==(*S).top
	*/
	S = (StackNodePtr)malloc(sizeof(StackNode));//
	if (!S->top) return FALSE;
	S->top->NULL;
	S->count = 0;
	return TRUE;
}
Status DestroyStack(LinkStack &S) {
//初始条件:栈S己存在
//销毁链栈S

}
Status ClearStack(LinkStack &S)
//初始条件:栈S己存在
//清空链栈S
{}
Status StackEmpty(LinkStack S)
//初始条件:栈S己存在
//判断链栈S是否为空
{}
int StackLength(LinkStack S)
//初始条件:栈S己存在
//求链栈S的长度
{}
ElemType GetTop(LinkStack S,e)
//初始条件:栈S己存在 且非空
//取链栈S的第i个元素 取得栈的上面顶部出口的元素
{}
Status Push(LinkStack &S,e)
//初始条件:栈S己存在
//压栈 加入一个栈顶元素
{}
Status Pop(LinkStack &S,&e)
//初始条件:栈S己存在 且非空
//出栈 弹出一个栈顶元素
{}
Status StackTraverse(LinkStack S,visit())
//初始条件:栈S己存在 且非空
//遍历链栈S:依次对S的每个元素调用visit()
{}
