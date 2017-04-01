
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