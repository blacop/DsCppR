#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE -1
#define TRUE 1
#define FALSE -1
#define NULL 0
#define OVERFLOW -2
#define ElemType int
#define SElemType int
#define Status int
typedef int ElemType
typedef int SElemType
typedef int Status
//------链栈-------
//链栈 初始化 访问 
#define LEN sizeof(StackNode)
#define MLC (StackNodePtr)malloc(sizeof(StackNode))
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
StackTraverse(S,visit(&e)) //遍历链栈S:依次对S的每个元素调用visit()
visit(&e) //  visit 一般是指树型链表结构中对某个节点内容进行访问的函数，
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”
*/
/*  链栈 头插法实现的好处
栈，首先是一个线性表，也就是说，栈元素具有线性关系，
即前驱后继关系。只不过它是一种特殊的线性表而已。
它的特殊之处在于限制了线性表的插入和删除位置，
它始终在栈顶进行，这就使得栈底是固定的，最先入栈的元素最后才能出栈。
那么，我们根据栈的定义完全可以选用线性表进行模拟。
我们知道线性表的实现由两种方式，即线性表顺序存储（顺序表）和线性表链式存储（链表）。
在这里只能选用线性表的链式存储实现方式来模拟栈的链式存储，
只不过我们只能选择头插法插入数据（相当于最最先入栈的元素排在栈底，以此类推）
为什么选择头插法插入数据呢？或者这样有什么好处呢？假设我们选择尾插法入栈，
当每次出栈的时候，我们会需要遍历整个链栈，浪费时间。如果我们采用头插法入栈，
那么每次出栈的时候直接弹出头部结点即可，而不用遍历。
这就是为什么我们选用链表头插法来模拟入栈的原因。当要弹出数据（出栈）是时，
我们只需在链表头部弹出结点即可（相当于最后入栈的元素最先出栈）。
我们按照栈的定义通过限制链表的插入操作和删除操作模拟了一个链栈。
*/
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

typedef struct StackNode {    //封装 节点 Bo
	ElemType data;           //数据域
	struct StackNode *next;  //指针域
}StackNode,*StackNodePtr;     
typedef struct LinkStack { //二次封装 链栈，便于理解
	StackNodePtr top; //top 指针
	int count;  //计数器,这个是判断有效数字的count
}LinkStack;

Status InitStack(LinkStack &S){
	/*  构造一个空栈S  初始化 */
	//放*S和放&S 都表示S会被改变
	//实际调用的话必须参数是*s	
	//传入指针的引用S，
	//只有C++中才有&引用传递
	//C语言中没有&引用传递，则用*指针传递
	//总结：
	//传入的指针仅仅是一个拷贝，方法不会改变原指针的地址、值，但是可能会改变原指针所指向内存块的数据。
	//总结：
	//参数*指针传递 方法 传入的是 a、b变量地址的拷贝，也叫传值；
    //参数&引用传递 方法 传入的是变量a、b，而不是拷贝（地址相同），又叫传引用。
	S->top = (StackNodePtr)malloc(sizeof(StackNode));//开内存,计数器只要在最外面1个就行了，不用在每个节点都有计数器
	if (!S->top){ //top 是空指针
		return FALSE;
	}
	S->top->next = NULL;//头插法 CORE,第一个节点就是尾部，尾部的next指针就指向NULL
	S->count = 0;//计数器,这个是判断有效数字的count
	return TRUE;
}
Status IsEmptyStack_JudgeEffectiveValueCount(LinkStack S){
	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
	if (S.count == 0){ //这个是判断有效数字的count
		return TRUE;
	}
	else{
		return FALSE;
	}
}
Status IsEmptyStack_JudgeTopPtrIsNull(LinkStack P) {
	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
	//判断头插法 的链栈 Top指针是空指针就可以了
	if (P->top==NULL)	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}
int StackLength(LinkStack S) {
	/* 返回S的元素个数，即栈的长度 */
	return S.count;
}
Status GetTopElem(LinkStack S, SElemType &e) {
	/* 若栈不空，则用e返回S的栈顶元素，并返回TRUE；否则返回FALSE */
	if (S.top == NULL) {
		return FALSE;
	}
	else {
		e = S.top->data;//参数*,改值变量带*,拷贝一个指针。参数&，变量不带&
	}
	return TRUE;
}
Status Push(LinkStack &S, SElemType e) {
	/* 插入元素e为新的栈顶元素 */
	StackNodePtr s = (StackNodePtr)malloc(sizeof(StackNode));
	if (!s) { //Null Ptr
		return FALSE;
	}
	s->data = e; //assignment
	s->next = S->top;/* 把当前的栈顶元素赋值给新结点的直接后继 ☛↘ */
	S->top = s;      /* 将新的结点s赋值给栈顶指针 ☞♐ */
	S->count++; //EffectiveValueCount+1
	return TRUE;
}
Status Pop(LinkStack &S, SElemType &e) {
	/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回TRUE；否则返回FALSE */
	StackNodePtr p;//临时指针
	if (IsEmptyStack(S)) { 
		return FALSE;
	}
	e = S->top->data; //assignment
	p = S->top; /* 将栈顶结点赋值给p， p☞top */
	S->top = S->top->next;/* 使得栈顶指针下移一位，指向后一结点，top++,top☞➷  */
	free(p);              /* 释放结点p ，如果没有临时指针变量，就没法释放内存free()了*/
	S->count--; //EffectiveValueCount-1
	return TRUE;
}
Status visit(SElemType c) {
	//访问节点,返回bool,打印c,值由外部传入
	printf("%d ", c);
	return TRUE;
}
Status StackTraverse(LinkStack S) {
	//遍历
	StackNodePtr p;//临时指针
	p = S.top;
	while (p) { //p not Null,if p== NULL,then LinkStack already Traverse at end.
		visit(p->data);
		p = p->next;//不用修改top
	}
	printf("\n");
	return TRUE;
}

//遍历栈
void traverse_stack(PSTACK pS)
{
	is_empty_stack(pS);

	PNODE pNew = pS->pTop;
	while (pNew != pS->pBottom) {

		printf("%d ", pNew->data);

		pNew = pNew->pNext;
	}
	printf("\n");

	return;
}
