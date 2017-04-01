/*
链表各类操作详解
//http://blog.csdn.net/hackbuteer1/article/details/6591486/?reload#
链表概述
　　 链表是一种常见的重要的数据结构。它是动态地进行存储分配的一种结构。它可以根据需要开辟内存单元。链表有一个“头指针”变量，以head表示，它存放一个地址。该地址指向一个元素。链表中每一个元素称为“结点”，每个结点都应包括两个部分：一为用户需要用的实际数据，二为下一个结点的地址。因此，head指向第一个元素：第一个元素又指向第二个元素；……，直到最后一个元素，该元素不再指向其它元素，它称为“表尾”，它的地址部分放一个“NULL”（表示“空地址”），链表到此结束。
        链表的各类操作包括：学习单向链表的创建、删除、  插入（无序、有序）、输出、  排序（选择、插入、冒泡）、反序等等。

       单向链表的图示：
       ---->[NULL]
      head

      图1：空链表

       ---->[p1]---->[p2]...---->[pn]---->[NULL]
      head   p1->next  p2->next   pn->next

      图2：有N个节点的链表

      创建n个节点的链表的函数为：
*/

#include "stdlib.h"
#include "stdio.h"
#define NULL 0
#define LEN sizeof(struct student)

struct student{
	int num;			  //学号 
	float score;	      //分数，其他信息可以继续在下面增加字段
	struct student *next;		//指向下一节点的指针
};
int n;	//节点总数 
/*
==========================
功能：创建n个节点的链表
返回：指向链表表头的指针
==========================
*/
struct student *Create()
{
	struct student *head;		//头节点
	struct student *p1 = NULL;	//p1保存创建的新节点的地址
	struct student *p2 = NULL;	//p2保存原链表最后一个节点的地址

	n = 0;			//创建前链表的节点总数为0：空链表
	p1 = (struct student *) malloc (LEN);	//开辟一个新节点
	p2 = p1;			//如果节点开辟成功，则p2先把它的指针保存下来以备后用

	if(p1==NULL)		//节点开辟不成功
	{
		printf ("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}
	else				//节点开辟成功
	{
		head = NULL;		//开始head指向NULL
		printf ("Please input %d node -- num,score: ", n + 1);
		scanf ("%d %f", &(p1->num), &(p1->score));	//录入数据
	}
	while(p1->num != 0)		//只要学号不为0，就继续录入下一个节点
	{
		n += 1;			//节点总数增加1个
		if(n == 1)		//如果节点总数是1，则head指向刚创建的节点p1
		{
			head = p1;
			p2->next = NULL;  //此时的p2就是p1,也就是p1->next指向NULL。
		}
		else
		{
			p2->next = p1;	//指向上次下面刚刚开辟的新节点
		}

		p2 = p1;			//把p1的地址给p2保留，然后p1产生新的节点

		p1 = (struct student *) malloc (LEN);
		printf ("Please input %d node -- num,score: ", n + 1);
		scanf ("%d %f", &(p1->num), &(p1->score));
	}
	p2->next = NULL;		//此句就是根据单向链表的最后一个节点要指向NULL

	free(p1);			//p1->num为0的时候跳出了while循环，并且释放p1
	p1 = NULL;			//特别不要忘记把释放的变量清空置为NULL,否则就变成"野指针"，即地址不确定的指针
	return head;	    //返回创建链表的头指针 
}