//http://blog.csdn.net/zhou753099943/article/details/52548841
链表基本操作详解
注释：这段时间在参加校招，问了很多链表的问题，虽然都可以完全不错的写出来，但却花了不少时间，一怒之下我就把链表的基本所有操作都重新编写一遍
备注：适合于才学链表和有一些链表操作的经验的同学看，代码全部都可以通过，可以放心使用
头文件：list.h

#include <iostream>
#include <assert.h>
using namespace std;
#include <vector>
struct Node
{
	int value;
	struct Node *next;
	Node(int v=0):value(v),next(NULL)
	{}
};

class List 
{
public:
	void insert(int value=0)
	{
		Node *node=BuyNode(value);
		if(head==NULL)
		{
			head=node;
			return;
		}
		//头插
		node->next=head->next;
		node->next=head;
		head=node;
	}
	void show(Node *Head)
	{
		Node *cur=Head;
		while(cur)
		{
			cout<<cur->value<<" ";
			cur=cur->next;
		}
		cout<<endl;
	}
	void print()
	{
		print(head);
	}
	//链表逆制
	void resver()
	{
		resver(head);
	}
	//从尾打印链表
	void print_tail()
	{
		print_tail(head);
	}
	//在O(1)时间内删除一个链表
	void remove(int value)
	{
		remove(head,value);
	}
	//链表的倒数第k个节点
	Node* get_k(int k)
	{
		return get_k(head,k);
	}
	//寻找两个链表的公共节点
	Node* find_comm_node(List *list1,List *list2)
	{
		if(list1 ==NULL || list2 ==NULL)
			return NULL;
		return find_comm_node(list1->head,list2->head);
	}
	//合并两个有序链表
	Node* megre(List *head,List *phead)
	{
		if(head==NULL || phead==NULL)
			return NULL;
		return megre(head->head,phead->head);
	}
	//链表合并第二种写法
	Node* Megre(List *head,List *phead)
	{
		if(head==NULL || phead==NULL)
			return NULL;
		return Megre(head->head,phead->head);
	}
	//返回链表的长度
	int size()
	{
		return size(head);
	}
	//按值插入
	bool insert_value(int value)
	{
		return insert_value(head,value);
	}
private:
	Node* find_value(Node *head,int value)
	{
		Node *cur=head;
		while(cur && cur->value !=value)
			cur=cur->next;
		return cur;
	}
	bool insert_value(Node *head,int value)
	{
		Node *key=find_value(head,value);
		if(key==NULL)
			return false;
		Node *node=BuyNode(value);
		node->next=key->next;
		key->next=node;
		return true;
	}
	int size(Node *head)
	{
		int len=0;
		while(head)
		{
			++len;
			head=head->next;
		}
		return len;
	}
	Node* Megre(Node *head,Node *phead)
	{
		if(head==NULL || phead==NULL)
			return NULL;
		Node *root=NULL;
		Node *cur=NULL;
		while(head && phead)
		{
			if(head->value <= phead->value)
			{
				if(cur==NULL)
					cur=head;
				else
				{
					cur->next=head;
					cur=cur->next;
				}
				if(root==NULL)
					root=cur;
				head=head->next;
			}else
			{
				if(cur == NULL)
					cur=phead;
				else
				{
					cur->next=phead;					
					cur=cur->next;
				}
				if(root==NULL)
					root=cur;
				phead=phead->next;
			}
		}
		if(head==NULL)
			cur->next=phead;
		else
			cur->next=head;
		return root;
	}
	/////////////////////////
	Node* megre(Node *head,Node *phead)
	{
		if(head==NULL || phead==NULL)
			return NULL;
		
		vector<Node *> v;
		Node *fisrt=head;
		Node *second=phead;
		while(fisrt && second)
		{
			if(fisrt->value <= second->value)
			{
				Node *tmp=fisrt;
				v.push_back(tmp);
				fisrt=fisrt->next;
			}else 
			{
				Node *tmp=second;
				v.push_back(tmp);
				second=second->next;
			}
		}
		Node *root=v[0];
		Node *cur=root;
		int size=v.size();
		for(int i=1; i<size; ++i)
		{
			cur->next=v[i];
			cur=cur->next;
		}
		if(fisrt==NULL)
			cur->next=second;
		else
			cur->next=fisrt;
		return root;
	}
	int GetLen(Node *head)
	{
		Node *cur=head;
		int len=0;
		while(cur)
		{
			cur=cur->next;
			len++;
		}
		return len;
	}
	Node* GetCur(Node *head,int len)
	{
		while(len--)
		{
			head=head->next;
		}
		return head;
	}
	Node* GetCommNode(Node *head,Node *phead)
	{
		while(head && phead && head !=phead)
		{
			head=head->next;
			phead=phead->next;
		}
		return head;
	}
	Node* find_comm_node(Node *head,Node *phead)
	{
		if(head==NULL || phead==NULL)
			return NULL;
		int head_len=GetLen(head);
		int phead_len=GetLen(phead);
		Node *cur=NULL;
		if(head_len > phead_len)
		{
			cur=GetCur(head,head_len-phead_len);
			cur=GetCommNode(cur,phead);
		}else
		{
			cur=GetCur(phead,phead_len-head_len);
			cur=GetCommNode(cur,head);
		}
		return cur;
	}
	Node *get_k(Node *head,int k)
	{
		if(head==NULL)
			return NULL;
		Node *cur=head;
		for(int i=0; i<k; ++i)
		{
			if(cur==NULL)
				return cur;
			cur=cur->next;
		}
		Node *result=head;
		while(cur !=NULL)
		{
			result=result->next;
			cur=cur->next;
		}
		return result;
	}
	void remove(Node *head,int value)
	{
		Node *cur=head;
		while(cur !=NULL)
		{
			//删除非尾节点的情况
			if(cur->value ==value && cur->next !=NULL)
			{
				Node *tmp=cur->next;
				cur->value=tmp->value;
				cur->next=tmp->next;
				delete tmp;
				break;
			}
			if(cur->next ==NULL)
				break;
			cur=cur->next;
		}
		//删除尾节点的情况
		if(cur->next ==NULL)
		{
			Node *cur=head;
			while(cur->next !=NULL && cur->next->value !=value)
				cur=cur->next;
			Node *tmp=cur->next;
			cur->next=NULL;
			delete tmp;
		}
	}
	void print_tail(Node *&head)
	{
		if(head==NULL)
			return;
		else
		{
			print_tail(head->next);
			cout<<head->value<<" ";
		}
	}
	void resver(Node *&head)
	{
		Node *cur=head;
		head=NULL;
		while(cur !=NULL)
		{
			Node *tmp=cur;
			cur=cur->next;
			tmp->next=head;
			head=tmp;
		}
	}
	void print(Node *head)
	{
		Node *cur=head;
		while(cur !=NULL)
		{
			cout<<cur->value<<" ";
			cur=cur->next;
		}
		cout<<endl;
	}
public:
	List(int value=0):head(NULL)
	{}
	~List()
	{
		destory(head);
	}
private:
	Node* BuyNode(int value)
	{
		Node *node=new Node(value);
		return node;
	}
	void destory(Node *&head)
	{
		while(head !=NULL)
		{
			Node *tmp=head;
			head=head->next;
			delete tmp;
			tmp=NULL;
		}
		head=NULL;
	}
private:
	Node *head;
};

//---------
#include "list.h"

void fun()
{
	List t;
	int value=0;
	while(cin>>value,value !=-1)
	{
		t.insert(value);
	}
	t.print();
	cout<<"size :"<<t.size()<<endl;
	/*while(cin>>value && value !=-1)
	{
		if(t.insert_value(value))
			cout<<"insert success"<<endl;
		else
			cout<<"insert failed"<<endl;
		t.print();
	}*/
	List mylist;
	while(cin>>value,value !=-1)
	{
		mylist.insert(value);
	}
	mylist.print();
	List tmp;
	Node *cur=tmp.Megre(&t,&mylist);
	tmp.show(cur);
	/*
	List mylist;
	while(cin>>value,value !=-1)
	{
		mylist.insert(value);
	}
	mylist.print();
	List tmp;
	Node *cur=tmp.megre(&t,&mylist);
	tmp.show(cur);

	//t.resver();
	//t.print();
	//t.print_tail();
	//cout<<"please enter value :";
	//cin>>value;
	//t.remove(value);
	int k=0;
	cout<<"please enter k:";
	cin>>k;
	Node *head=t.get_k(k);
	if(head !=NULL)
		cout<<head->value<<endl;
	else
		cout<<"get k is NULL"<<endl;
	t.print();*/
}
int main()
{
	fun();
	return 0;
}
