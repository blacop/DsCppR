#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE -1
#define NULL 0
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
#define LinkStack sNode //Tan
#define LinkStack StackNode //Tan
#define LEN sizeof(StackNode)
#define MLC (StackNode)malloc(sizeof(StackNode))

/*
//链栈S的基本操作列表
InitStack(&S) //初始化链栈S
DestroyStack(&S) //销毁链栈S
ClearStack(&S) //清空链栈S
StackEmpty(S) //判断链栈S是否为空
StackLength(S) //求链栈S的长度
GetTop(S) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Push(&S,e) //压栈 加入一个栈顶元素
Pop(&S,&e) //出栈 弹出一个栈顶元素
StackTraverse(S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
visit() //  visit 一般是指树型链表结构中对某个节点内容进行访问的函数，
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”

LocateElem(S,e,compare()) //定位检索链栈S中元素e
compare() //比较两个元素的大小,返回Bool
compareArray() //比较两个数组的大小,返回Bool
PriorElem(S,cur_e,&prio_e) //返回链栈S中元素e的直接前驱元素
NextElem(S,cur_e,&next_e) //返回链栈S中元素e的直接后继元素
StackInsert(&S,i,e) //在链栈S的第i个元素之前插入元素e,返回Bool
StackDelete(&S,i,e) //删除链栈S的第i个元素,被删除元素e的值,返回Bool
*/
//---------------链栈----------------
//链栈 初始化   头插法 尾插法 插入 删除 查找 合并 长度

typedef struct stack_node { //封装一个链栈 Tan
	ElemType data; //数据域
	struct stack_node *next; //指针域 next
}LinkStack;//注意这里的命名方式有问题 这里的LinkStack实际意思是一个Node，这是上交大的命名法
LinkStack *stk; //这是 声明指针 之后stk  作为Top指针使用
typedef LinkStack *OldPtr;//typedef指针 作为栈顶元素*Top使用
typedef LinkStack *LinkStackPtr;//typedef指针 作为栈顶元素*Top使用
//typedef LinkStack *stk;//声明指针 作为栈顶元素*Top使用

typedef struct sNode { //封装一个链栈 Bo
	ElemType data; //数据域
	struct SNode *next; //指针域
}sNode, *linkStack;//声明指针 作为栈顶元素*Top指针使用
 /*
typedef struct StackNode{
	//定义链栈的结构类型 Bo
	//http://www.cnblogs.com/newwy/archive/2010/10/10/1847464.html
	ElemType data;                //栈的数据 
	struct StackNode *next;        //指针域 
} StackNode, *LinkStack;
*/

typedef struct node {
	//结构定义
	//http://www.cnblogs.com/w784319947/p/6429634.html
	elementType data;
	struct node *next;
} LSNode;//链栈节点 
typedef struct {
	//二次封装，重定义封装一个 头指针，变得更好理解
	struct LSNode *top;
	int size;
}*PSTACK;//链栈 
typedef int elementType;

//---------------------------
Status InitLinkStack_Head(linkStack &top) {
	//初始化 栈S,头插法，InPtr_OutBool
	top = (sNode *)malloc(sizeof(sNode));//开内存,top指针从外面传入
	if (!top) { //开失败
		exit(OVERFLOW);
	}
	top = NULL;//头插法CORE核心语句就只有这一句, , top指针,新生成的结点的指针 作为top指针
	return TRUE;
}//InitStack_Sq
Status InitLinkStack_Tail(LinkStack &top){
	//初始化 栈,尾插法，InPtr_OutBool
	S = (sNode *)malloc(sizeof(sNode));//开内存,top指针从外面传入
	if (!S) { //开失败
		exit(OVERFLOW);
	}
	top->next = NULL;//尾插法CORE核心语句就只有这一句
}

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
Status IsEmpty_Tail(LinkStackPtr P) {
	//判断尾插法 的链栈 是否为空，就是判断指针域是否为空
	if (P->next == NULL) {
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
LinkStack Push_Tail(LinkStack top, int value) {
	//入栈函数
	StackNode * newp = (StackNode *)malloc(sizeof(StackNode));
	if (newp != NULL)
	{
		newp->data = value;
		newp->next = top->next;
		top->next = newp;
	}
	else
		cout << "No memory available" << endl;
	return top;

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

Status Pop_Tail(LinkStackPtr top, ElemType e) {
	//弹栈 from 尾插法的链栈
	if (IsEmpty_Tail(top))
		return FALSE;
	else {
		StackNode *temp = top->next;
		*element = temp->data;
		top->next = temp->next;
		free(temp);
		return TRUE;
	}
}

/*
因为
链栈其实也是链表的一种形式，
头指针始终指向表的第一个结点（或是头结点），
而栈顶指针则始终指向栈顶，创建链表时有一般有两种方法：
一种是头插法，一种是尾插法。
链栈也是一样的，假设创建的栈没有头结点即第一个结点就开始存储数据，
按头插法建栈时，头指针就是栈顶指针，二者没有区别；
按尾插法建栈时，则头指针就不是栈顶指针了，这时在建栈时就要再定义一个尾指针，
让它始终指向栈的最后一个元素（即最后进栈的元素），这样该尾指针就是栈顶指针了。

所以总结一下
所以链栈 也分为 头插法 和尾插法
没有 头结点的 链栈 用 头插法
  有 头结点的 链栈 用 尾插法
*/

/*
Status Push(Top newNode, ElemType x) {
	//入栈 ,stk是外部传入的新结点指针, x是值 Tan..
	//redef  ??
	//LinkStack *top;
	newNode = malloc(sizeof(LinkStack));
	newNode->data = x; //赋值
	newNode->next = ??;//移动指针
	?? = top;
}
*/
/*
typedef int Status;
typedef int SElemType; // SElemType类型根据实际情况而定，这里假设为int
typedef struct StackNode{
	//封装 链栈结构 
	//http://blog.csdn.net/guoyong10721073/article/details/9077491
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
	//二次封装
	LinkStackPtr top;
	int count;
}LinkStack;

Status Push(LinkStack *Old, SElemType e) {
	// 插入元素e为新的栈顶元素
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = Old->top;// 把当前的栈顶元素赋值给新结点的直接后继，见图中① 
	Old->top = s;  // 将新的结点s赋值给栈顶指针，见图中②
	Old->count++;
	return OK;
}
*/
/*
//http://www.cnblogs.com/gentleming/archive/2010/07/21/1781827.html
#include <iostream>
using namespace std;

typedef struct stacknode
{
int data;
struct stacknode * next;
}StackNode,* LinkStack;

void InitStack(LinkStack top)
{
top->next=NULL;
}

//入栈函数，尾插法
LinkStack Push(LinkStack top,int value)
{
StackNode * newp = (StackNode *)malloc(sizeof(StackNode));
if(newp != NULL)
{
newp->data=value;
newp->next=top->next;
top->next=newp;
}
else
cout<<"No memory available"<<endl;
return top;

}

*/

Status Pop(LinkStack *stk,ElemType &e) {
	//出栈
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
Status GetTop_Tail(LinkStack top, ElementType *element) {
	//取 栈顶元素 的值 尾插法
	// 获取栈顶元素 
	if (top->next == NULL)
		return FALSE;
	*element = top->next->data;
	return TRUE;
}

/*
//http://blog.csdn.net/shuangshuang37278752/article/details/11592825
typedef int ElementType;
typedef struct node {
	ElementType data;
	struct node *next;
}StackNode, *LinkStack;
//实际上尾插法 写起来和理解起来 顺畅多了，头插法很费脑子
// 链栈的初始化
void InitStack(LinkStack top) {
	top->next = NULL;//top指针指向栈顶元素的上一个位置，下同  
}
// 判断栈是否为空 
int IsEmpty(LinkStack top) {
	if (top->next == NULL)
		return TRUE;
	return FALSE;
}

ElemType GetTop_Tail() {
	//取 栈顶元素 的值 尾插法
	// 获取栈顶元素 
	int GetTop(LinkStack top, ElementType *element) {
		if (top->next == NULL)
			return FALSE;
		*element = top->next->data;
		return TRUE;
	}
}
*/