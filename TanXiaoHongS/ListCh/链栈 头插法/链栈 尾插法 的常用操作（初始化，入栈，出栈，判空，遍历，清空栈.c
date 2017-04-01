
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

//链栈的常用操作（初始化，入栈，出栈，判空，遍历，清空栈） (2014-05-05 19:33:08)转载▼
//标签： 杂谈	
//http://blog.sina.com.cn/s/blog_b716ca8d0101dwn0.html
#include
#include
typedef struct Node{
    int data;
    struct Node *pNext;
}NODE, *PNODE;
typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;
void init_stack(PSTACK);//初始化链栈
void push_stack(PSTACK,int);//元素入栈
void is_empty_stack(PSTACK);//判断栈是否为空
void traverse_stack(PSTACK);//遍历栈
void pop_stack(PSTACK);//元素出栈
void clear_stack(PSTACK);//清空栈
int main(int argc, const char * argv[])
{
    STACK S;    
    init_stack(&S);
    push_stack(&S,1);
    push_stack(&S,2);
    printf("栈中的元素为：");
    traverse_stack(&S);

    pop_stack(&S);
    printf("栈中的元素为：");
    traverse_stack(&S);
    
    clear_stack(&S);
    printf("栈中的元素为：");
    traverse_stack(&S);
    
    return 0;
}
//初始化链栈
void init_stack(PSTACK pS){
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop){
        printf("动态分配内存失败！！！\n");
        exit(-1);
    }
    else{
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;//同时pS->pBottom->pNext = NULL
    }
}
//元素入栈
void push_stack(PSTACK pS,int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
    
    return;
}


void is_empty_stack(PSTACK pS)
{
    if (pS->pTop == pS->pBottom) {
        
        printf("栈为空！！！\n");
        exit(-1);
    }
    
    return;
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

//元素出栈一次，并把出栈的元素存入pVal所指向的变量中
void pop_stack(PSTACK pS)
{
    is_empty_stack(pS);
    
    int pVal;
    pVal = pS->pTop->data;
    pS->pTop = pS->pTop->pNext;
    
    printf("出栈的元素为：%d\n",pVal);
    
    return;
}

//清空栈
void clear_stack(PSTACK pS)
{
    is_empty_stack(pS);
    
    PNODE p = pS->pTop;
    PNODE q = NULL;
    
    while (p != pS->pBottom) {
        
        q = p->pNext;
        free(p);
        p = q;
    }
    pS->pTop = pS->pBottom;
    
    return;
}