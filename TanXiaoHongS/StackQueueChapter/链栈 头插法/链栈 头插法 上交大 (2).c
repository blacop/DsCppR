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
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//链栈S的基本操作声明 带返回值 带初始条件 //初始条件:栈S己存在
Status InitStack(&S) 
//初始化链栈S
Status DestroyStack(&S) 
//初始条件:栈S己存在
//销毁链栈S 
Status ClearStack(&S)
//初始条件:栈S己存在
//清空链栈S
Status StackEmpty(S)
//初始条件:栈S己存在
//判断链栈S是否为空
int StackLength(S)
//初始条件:栈S己存在
//求链栈S的长度
ElemType GetTop(S,e)
//初始条件:栈S己存在 且非空
//取链栈S的第i个元素 取得栈的上面顶部出口的元素
Status Push(&S,e) 
//初始条件:栈S己存在
//压栈 加入一个栈顶元素
Status Pop(&S,&e) 
//初始条件:栈S己存在 且非空
//出栈 弹出一个栈顶元素
Status StackTraverse(S,visit()) 
//初始条件:栈S己存在 且非空
//遍历链栈S:依次对S的每个元素调用visit()
*/
/*
//链栈S的基本操作声明带返回值
Status InitStack(&S) //初始化链栈S
Status DestroyStack(&S) //销毁链栈S
Status ClearStack(&S) //清空链栈S
Status StackEmpty(S) //判断链栈S是否为空
int StackLength(S) //求链栈S的长度
ElemType GetTop(S,e) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Status Push(&S,e) //压栈 加入一个栈顶元素
Status Pop(&S,&e) //出栈 弹出一个栈顶元素
Status StackTraverse(S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
*/
/*
//链栈S的基本操作简版
InitStack(&S) //初始化链栈S
DestroyStack(&S) //销毁链栈S
ClearStack(&S) //清空链栈S
StackEmpty(S) //判断链栈S是否为空
StackLength(S) //求链栈S的长度
GetTop(S) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Push(&S,e) //压栈 加入一个栈顶元素
Pop(&S,&e) //出栈 弹出一个栈顶元素
StackTraverse(S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
//visit() //  visit 一般是指树型链表结构中对某个节点内容进行访问的函数，
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”
*/
//---------------链栈----------------
//链栈 初始化 头插法 长度

typedef struct stack_node { //封装一个链栈 Tan
	ElemType data; //数据域
	struct stack_node *next; //指针域 next
}LinkStack;//注意这里的命名方式有问题 这里的LinkStack实际意思是一个Node，这是上交大的命名法
LinkStack *stk; //这是 声明指针 之后stk  作为Top指针使用

Status InitLinkStack_Head(linkStack &top) {
	//初始化 栈S,头插法，InPtr_OutBool
	top = (sNode *)malloc(sizeof(sNode));//开内存,top指针从外面传入
	if (!top) { //开失败
		exit(OVERFLOW);
	}
	top = NULL;//头插法CORE核心语句就只有这一句, , top指针,新生成的结点的指针 作为top指针
	return TRUE;
}//InitStack_Sq
LinkStack LinkStackInit_OutPtr(){
	//链栈的初始化
	LinkStack top;      //构造一个空栈,内部声明一个top指针
	top = (StackNode *)malloc(sizeof(StackNode));
	if (!top)
		printf("OVERFLOW\n");
	top = NULL;//top指针,新生成的结点的指针 作为top指针
	return top;
}
Status IsEmpty_Head(LinkStackPtr P) {
	//判断头插法 的链栈 是否为空，就是判断数据域是否为空
	if (P==NULL)	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status Push_Head_LinkStack_Tan(LinkStack *oldTop, ElemType x) {
	//入栈 ,stk是外部传入的旧结点指针, x是值 Tan	
	//我怀疑这个代码是错的
	//大概是头插法？？
	LinkStack *newTop; //top 是内部生成 的 新结点指针
	newTop = malloc(sizeof(LinkStack)); //这里的top命名也有点问题，实际是一个临时指针,作为辅助变量来使用，上交大命名法真垃圾
	newTop->data = x; //赋值
	newTop->next = *oldTop; //头插法
							//插入操作的移动指针操作 newNode linkTo OldNode
							//*stk 表示 OldNode的地址 我认为这里的*号加了就是错误的
	*oldTop = newTop;// oldPtr++
					 //1、指针作为参数传递进去的仅仅只是指针的值OldNode，而不是指针的地址，或者说只是指针的一份拷贝：
					 //所有这里*stk 表示的是 地址，不是数值？ 我怀疑上交大的这个代码是错的
					 //*stk 表示 OldNode的地址
					 //LinkStack和SqStack不同点是 最后步骤的newPtr没有++
}
Status Pop_Head(LinkStackPtr top, ElemType &e) {
	//弹栈 from 头插法的链栈
	if (IsEmpty_Head(top)) {
		return FALSE;
	}
	else {
		e = P->data;//从
		return TRUE;
	}
}
Status Pop_Head_Bo_HaveNoTopArea(LSNodePtr p, ElemType &e) {
	//出栈 Tan
	if (IsEmpty(s)) {
		printf("Stack is Empty\n");
		exit(1);//Exception handling and reporting.
	}
	LSNodePtr p = NULL;//clear LSNodePtr 这一步似乎非必须
	p = s->top->next;//p++ 
	free(s->top);//destroy LSNode
	s->top = p;//top++
	s->size--;
	return TRUE;
}
Status Pop_Head_Bo_HaveTopArea(LSNodePtr p,ElemType &e) {
	//出栈
	if (IsEmpty(s))	{
		printf("Stack is Empty\n");
		exit(1);//Exception handling and reporting.
	}
	LSNodePtr p = NULL;//clear LSNodePtr 这一步似乎非必须
	p = s->top->next;//p++ 
	free(s->top);//destroy LSNode
	s->top = p;//top++
	s->size--;
	return TRUE;
}
ElemType GetTop_Head_OutNum(LinkStackPtr ptr) {
	//取 栈顶元素 的值 头插法
	if (ptr->data == NULL)
		return FALSE;
	ElemType num = ptr->data;
	return num;
}
Status GetTop_Head_OutBool(LinkStackPtr ptr, ElemType &e) {
	//取 栈顶元素 的值 头插法
	if (ptr->data == NULL)
		return FALSE;
	e = ptr->data;
	return TRUE;
}
