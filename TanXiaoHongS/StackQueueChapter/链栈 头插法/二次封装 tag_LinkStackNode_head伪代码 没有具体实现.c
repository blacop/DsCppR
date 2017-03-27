#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "linkstack.h"
#include "linklist.h"

typedef struct Teacher   
{  
	LinkListNode listnode;  
	void *item;//栈 业务节点
}Teacher;  

/************************************************************************/
/*  链表的业务结点TLinkStackNode包含一个栈的业务节点                    */
/*  这个结构体 是由Teacher 递推出来的                                   */
/************************************************************************/
typedef struct _tag_LinkStackNode   
{  
	LinkListNode listnode;  
	void *item;//栈 业务节点
}TLinkStackNode; 

//创建一个链栈 相当于创建一个链表
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

/************************************************************************/
/*销毁一个链栈相等于销毁一个链表                                       */
/*先清空 再销毁                                                        */
/************************************************************************/
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
	return;
}

/************************************************************************/
/*清空一个链栈 相等于清空一个链表                                       */
/*但是 所有入栈的结点都是malloc出来的 （栈元素的生命周期管理）          */
/*若要清空一个链栈 需要一个个弹出元素 并释放结点内存                    */
/************************************************************************/
void LinkStack_Clear(LinkStack* stack)
{
	if (stack==NULL)
	{
		return;
	}
	while (LinkStack_Size(stack)>0)
	{
		LinkStack_Pop(stack);//这个函数释放了结点内存
	}
	return;
}

/************************************************************************/
/*向链栈添加一个元素相当于向链表的头部插入元素(头插法？避免弹出元素遍历)*/
/*栈的 业务节点void* item  转换成链表的业务节点                         */
/*所有入栈的元素都是malloc出来的                                        */
/************************************************************************/
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode *tmp = NULL;
	int ret = 0;
	//对LinkList_Insert()而言 本函数LinkStack_Push()是主调函数 我们应该分配内存
	tmp =(TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	memset(tmp,0,sizeof(TLinkStackNode));
	tmp->item = item;
	
	ret = LinkList_Insert(stack,(LinkListNode*)tmp,0);//头插法
	if (ret!=0)
	{
		printf("func LinkStack_Push() err:%d\n",ret);
		if (tmp!=NULL)
		{
			free(tmp);
		}
		return ret ;
	}
	return ret;
}

/************************************************************************/
/*从栈中弹出元素 相当于 从链表的头部删除元素                            */
/*把链表的业务节点 转换成 栈的业务节点                                  */
/*在LinkStack_Push()压栈的时,为栈结点分配了内存,所以弹出应该释放相应内存*/
/************************************************************************/
void* LinkStack_Pop(LinkStack* stack)
{
	void*item= NULL;
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Delete(stack,0);
	if (tmp==NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);//释放内存
	return item;
}
//获取栈顶的元素 相当于获取链表的0号位置
void* LinkStack_Top(LinkStack* stack)
{
	void*item= NULL;
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Get(stack,0);
	if (tmp==NULL)
	{
		return NULL;
	}
	item = tmp->item;
	return item;
}
//求栈的大小 相当于求链表的len
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}