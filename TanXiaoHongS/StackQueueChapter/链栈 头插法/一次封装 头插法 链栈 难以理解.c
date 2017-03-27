
Status Pop_Head_Bo_HaveNoTopArea(LSNodePtr p, ElemType &e) {
	//��ջ Tan
	if (IsEmpty(s)) {
		printf("Stack is Empty\n");
		exit(1);//Exception handling and reporting.
	}
	LSNodePtr p = NULL;//clear LSNodePtr ��һ���ƺ��Ǳ���
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
	//��ջ
	if (IsEmpty(s))	{
		printf("Stack is Empty\n");
		exit(1);//Exception handling and reporting.
	}
	LSNodePtr p = NULL;//clear LSNodePtr ��һ���ƺ��Ǳ���
	p = s->top->next;//p++ 
	free(s->top);//destroy LSNode
	s->top = p;//top++
	s->size--;
	return TRUE;
}
ElemType GetTop_Head_OutNum(LinkStackPtr ptr) {
	//ȡ ջ��Ԫ�� ��ֵ ͷ�巨
	if (ptr->data == NULL)
		return FALSE;
	ElemType num = ptr->data;
	return num;
}
Status GetTop_Head_OutBool(LinkStackPtr ptr, ElemType &e) {
	//ȡ ջ��Ԫ�� ��ֵ ͷ�巨
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
//ʵ����β�巨 д������������� ˳�����ˣ�ͷ�巨�ܷ�����
// ��ջ�ĳ�ʼ��
void InitStack(LinkStack top) {
	top->next = NULL;//topָ��ָ��ջ��Ԫ�ص���һ��λ�ã���ͬ  
}
// �ж�ջ�Ƿ�Ϊ�� 
int IsEmpty(LinkStack top) {
	if (top->next == NULL)
		return TRUE;
	return FALSE;
}

ElemType GetTop_Tail() {
	//ȡ ջ��Ԫ�� ��ֵ β�巨
	// ��ȡջ��Ԫ�� 
	int GetTop(LinkStack top, ElementType *element) {
		if (top->next == NULL)
			return FALSE;
		*element = top->next->data;
		return TRUE;
	}
}
*/