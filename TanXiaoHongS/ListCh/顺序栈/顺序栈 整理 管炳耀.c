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

//---------------顺序栈----------------
//顺序栈 初始化 压栈 弹栈 判断为空 求容量
/*
* 类名使用驼峰命名法（Camel Case）：VelocityResponseWriter
* 包名使用小写：com.company.project.ui
* 变量使用首字母小写的驼峰命名法（Mixed Case）：studentName
* 常量使用大写:MAX_PARAMETER_COUNT = 100
* 枚举类（enum class）采用驼峰命名法，枚举值（enum values）采用大写。
* 除了常量和枚举值以外，不要使用下划线’_’
*/
typedef struct { //封装一个顺序栈结构 为SqStack
	SElemType *base;//基地址指针,栈底指针,存储空间，存放头地址,也可表示数组的名字 或地址  或第一个元素
	SElemType *top;//栈顶指针,SElemType的指针大小根据数据类型来确定
	int stackSize;//当前存储容量
}SqStack;
Status InitStack_Sq(SqStack &S) {
	//初始化空的顺序栈S
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));//开内存
	if (!S.base) { //开失败
		exit(OVERFLOW); 
	}
	S.top = S.base; //top指针 指向base指针
	S.stackSize = STACK_INIT_SIZE; //记录当前存储容量
	return TRUE;
}//InitStack_Sq
Status Push_Sq(SqStack &S, SElemType e) {
	//元素e插入到栈中,成为新的栈顶
	if (S.top-S.base >= S.stackSize){ //栈满,则新开,或者可以不开,直接exit(OVERFLOW)
		SElemType *newBase = (SElemType *)realoc(S.base, (S.stackSize + STACK_INCREMENT*sizeof(SElemType)));
		//realloc(baseP,(oldLen+incLen)) 表示新增加内存
		if (!newBase){ //新开失败
			exit(OVERFLOW);
		}
		else{
			S.base = newBase;
		}
		S.top = S.base + S.stackSize;//top++,becase stackSize already+1
		S.stackSize += STACK_INCREMENT;
	}//end if
	*S.top++ = e;
	/*
	S为对象,其属性top为指针
	先算 *S.top=e;
	再 S.top++;

	*S.top = e;//赋值
	S.top++;//top指针++

	压栈 value->top;top++;
	弹栈 top--;	top->value;
	*/
	return TRUE;
}//Push_Sq
Status Pop_Sq(SqStack &S, SElemType &e) {
	//从栈顶读取数据放入e内,栈中下下元素所在位置成为新的栈顶
	if (S.top == S.base){ //栈空
		return FALSE;
	}
	e = *--S.top;
	/*
	优先级 '.' > "--" = '*',
	所以是e = *(--(s.top))
	s是stack
	s.top有两种可能
	一是指向栈顶元素的指针
	二是指向比栈顶元素更高一层的空元素
	从这里的实际情况来看，我判断是第二种情况，当s.top==0时，栈为空。
	--s.top是递减指针，这时s.top就指向真正的栈顶元素了
	*--s.top是是该元素，返回给e

	压栈 value->top;top++;
	弹栈 top--;	top->value;
	*/
	return TRUE;	
}//Pop

Int StackEmpty_Sq(SqStack S) { //判断顺序栈S是否为空
	if S.stackSize = 0 return TURE;
	else return FALSE;
}
int StackSize_Sq(SqStack S) { //求顺序栈S的存储容量
	return S.stackSize;
}




