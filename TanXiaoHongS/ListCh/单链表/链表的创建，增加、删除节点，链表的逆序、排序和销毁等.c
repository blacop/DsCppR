//链表的基本操作
//内容包括链表的 1创建，2增加节点、3删除节点，4链表的逆序、5排序和6销毁等。
//http://blog.csdn.net/conanswp/article/details/23275531
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
}Node;
//链表的操作，以有头节点为例，无头节点类似
Node * head = NULL;//声明一个指针
bool initLinkList(Node * head) {
	//初始化 有头节点head
	head = (Node *)malloc(sizeof(Node));
	if (!head) return false;
	head->next = NULL;
}
//创建链表，头结点data=0，next=NULL;
bool createNodeList(){
	head = (Node *) malloc(sizeof(Node));
	if(NULL == head) {
		return false;
	}
	else {
		head->data = 0;
		head->next = NULL;
		return true;
	}
}
bool addNode(Node * node){
	//增加节点，加到最后
	if(NULL == head){
		return false;
	}
	Node * p = head;//node0，前驱 //二个辅助指针
	Node * q = head->next;//node1,后继	 //
	while(NULL != q){ //二个指针交替后移，直到后继指针为NULL
		p = q;//p++
		q = q->next;//q++,最后q为空，p是最后结点,q==null
	}
	p->next = node;
	node->next = NULL;
	return true;	
}
bool deleteNode(int index){
	//删除节点,删除指定order的节点,这个写法是垃圾写法,
	//判断下标越界和移动指针分开写了，复杂度变成了n+n=2n
	//正常写法应该是2个合在一起写
	if(NULL == head){
		return false;
	}
	Node * p = head->next;	//1个辅助指针
	int length = 0;
	while(NULL != p){
		length ++; //得到length
		p = p->next;//p变成null
	}
	if(length < index){
		return false; //判断边界
	}
	else{
		Node * q = head;
		p = head;
		for(int i=0;i<index;i++){ //找到 Loc(index-1)
			q = p;
			p = p->next;
		}
		Node * t = p->next; 
		q->next = t;
		free(p);
		return true;
	}
}
bool reverseLinkList(Node * head){
	//单链表逆序,这个也是垃圾算法
	if(NULL == head)	{
		return;
	}
	//如果链表长度为1
	if(head->next == NULL)	{
		return;
	}
	Node * p = head->next;//node1，前驱
	Node * q = p->next;//node2 ,后继 ，
	Node * t = NULL;// 3个辅助指针
	while(NULL != q){ 
		t = q->next; //node3
		q->next = p;
		p = q;
		q = t;
	}
	head->next->next = NULL;
	head->next = p;
}

//排序(降序)
void sort()
{
	//冒泡排序
	Node * pHead = head;
	if(head == NULL)
	{
		return;
	}
	if(pHead->next == NULL)
	{
		return;
	}
	Node * pi = pHead->next;
	Node * pj = pi->next;
	for(;pi != NULL;pi=pi->next)
	{
		for(pj = pi->next;pj != NULL;pj=pj->next)
		{
			if(pj->data>pi->data)
			{
				int tmp = pj->data;
				pj->data = pi->data;
				pi->data = tmp;
			}
		}
	}
}
//销毁
void destroyNodeList()
{
	if(NULL == head)
	{
		return;
	}
	if(NULL == head->next)
	{
		free(head);
		head = NULL;
		return;
	}
	Node * p = head->next;
	while(NULL != p)
	{
		Node * tmp = p;
		p = p->next;
		free(tmp);
	}
	free(head);
	head = NULL;
}

void main()
{
	createNodeList();

	Node * node1 = (Node *)malloc(sizeof(Node));
	node1->data = 1;
	node1->next = NULL;

	Node * node2 = (Node *)malloc(sizeof(Node));
	node2->data = 2;
	node2->next = NULL;

	addNode(node1);
	addNode(node2);

	reverseNodeList();

	Node * node3 = (Node *)malloc(sizeof(Node));
	node3->data = 3;
	node3->next = NULL;

	addNode(node3);

	sort();

	deleteNode(2);
	
	destroyNodeList();
}