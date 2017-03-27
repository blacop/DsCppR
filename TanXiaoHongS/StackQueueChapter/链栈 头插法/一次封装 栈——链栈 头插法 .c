//链栈只是单链表的一个简单应用，只要理解单链表的头插法，链栈的出栈入栈很好理解//http://blog.csdn.net/yj7758423/article/details/52013831
#include <stdio.h>
#include <malloc.h>
#include <stddef.h>

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node * next;
}LinkStack;

#include "linkstack.h"
void initLinkStack(LinkStack *&ls);
bool push(LinkStack *&ls, ElemType e);
bool pop(LinkStack *&ls, ElemType &e);
bool peek(LinkStack *ls, ElemType &e);
void printStack(LinkStack *ls);

int main() {
    LinkStack * ls;
    initLinkStack(ls);

    push(ls,10);
    push(ls,20);
    push(ls,30);
    printStack(ls);

    ElemType e;
    pop(ls,e);
    printStack(ls);
    return 0;
}
void initLinkStack(LinkStack *&ls){
    ls = (LinkStack *) malloc(sizeof(LinkStack));
    ls->next = NULL;
}

void destroy(LinkStack *&ls){
    LinkStack *p = ls, *q;
    q = p->next;
    while(q != NULL){
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

//入栈，就是一个头插法，很简单
bool push(LinkStack *&ls, ElemType e){
    LinkStack* node = (LinkStack*) malloc(sizeof(LinkStack));
    node->next = ls->next;
    node->data = e;
    ls->next = node;
    return true;
}

//出栈
bool pop(LinkStack *&ls, ElemType &e){
    if(ls->next == NULL){
        printf("栈空，无法出栈");
        return false;
    }
    LinkStack *p = ls->next;
    e = p->data;
    ls->next = p->next;
    free(p);
    return true;
}

//取栈顶
bool peek(LinkStack *ls, ElemType &e){
    if(ls->next == NULL){
        printf("栈空，无栈顶元素");
        return false;
    }
    e = ls->next->data;
    return true;
}

void printStack(LinkStack *ls){
    LinkStack *q = ls->next;
    while(q!=NULL){
        printf("%d\t",q->data);
        q = q->next;
    }
    printf("\n");
}
/*
输出结果为:
30  20  10  
20  10  
*/