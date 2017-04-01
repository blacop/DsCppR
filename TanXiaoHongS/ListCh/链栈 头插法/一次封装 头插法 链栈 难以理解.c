
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

Status StackTraverse(LinkStack S) {
	LinkStackPtr p;
	p = S.top;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
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