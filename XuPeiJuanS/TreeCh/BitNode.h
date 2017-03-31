#pragma once
#include "stdafx.h"
//http://blog.csdn.net/u014492609/article/details/40477795

//class BitNode {
//public:
//
//	BitNode() {}
//
//	virtual ~BitNode() {}
//};

/* 二叉树的二叉线索存储结构定义*/
typedef enum { Link, Thread }PointerTag;    //Link = 0表示指向左右孩子指针；Thread = 1表示指向前驱或后继的线索  

typedef struct BitNode {
	char data;                       //结点数据  
	struct BitNode *lchild, *rchild; //左右孩子指针  
	PointerTag  ltag, rtag;          //左右标志  
}BitNode, *BiTree;

//线索化的实质就是将二叉链表中的空指针改为指向前驱或后继的线索。
//由于前驱和后继信息只有在遍历该二叉树时才能得到，
//所以，线索化的过程就是在遍历的过程中修改空指针的过程。
//中序遍历线索化的递归函数代码如下：

//全局变量，始终指向刚刚访问过的结点  
BiTree pre;
//中序遍历进行中序线索化 ,入参是 BitNode* headnode,这里生成的是无头结点的
void InThreading(BiTree p) {
	if (p) {
		//递归左子树线索化  
		InThreading(p->lchild); 

		 //=== 中序线索化 ===
		 /*中间部分代码做了这样的事情：
		 因为此时p结点的后继还没有访问到，
		 因此只能对它的前驱结点pre的右指针rchild做判断，
		 if(!pre->rchild)表示如果为空，则p就是pre的后继，
		 于是pre->rchild = p，并且设置pre->rtag = Thread，
		 完成后继结点的线索化。*/
		if (!p->lchild)           //没有左孩子  
		{
			p->ltag = Thread;    //前驱线索  
			p->lchild = pre; //左孩子指针指向前驱
		}
		/*if (!p->lchild)表示如果某结点的左指针域为空，因为其前驱结点刚刚访问过，赋值了pre，所以可以将pre赋值给p->lchild，并修改p->ltag = Thread（也就是定义为1）以完成前驱结点的线索化。*/
		if (!pre->rchild)     //没有右孩子  
		{
			pre->rtag = Thread;  //后继线索  
			pre->rchild = p; //前驱右孩子指针指向后继(当前结点p)  
		}
		pre = p; //赋值 当前结点p 到 前驱结点pre
		//!_=== 中序线索化 ===

		//递归右子树线索化  
		InThreading(p->rchild);
	}
}//!_void InThreading(BiTree p)

//线索二叉树加头部结点head,失败了，写不出
//入参，无头线索二叉树，出参，有头线索二叉树
BitNode* CreateHeadInThreading(BitNode* p){
	BitNode* head;

	head->ltag = Link;
	head->lchild = p;

	head->rtag = Link;
	head->rchild;
}//!_BiTree CreateHeadInThreading

//t指向头结点，头结点左链lchild指向根结点，头结点右链rchild指向中序遍历的最后一个结点。  
//中序遍历二叉线索树表示 此有头结点的线索二叉树t
bool InOrderThraverse_Thr(BiTree t) {
	BiTree p; //头结点
	p = t->lchild;				    //p指向根结点  
	while (p != t)                  //空树或遍历结束时p == t  
	{
		while (p->ltag == Link)     //当ltag = 0时循环到中序序列的第一个结点  
		{
			p = p->lchild;
		}
		printf("%c ", p->data);     //显示结点数据，可以更改为其他对结点的操作  
		while (p->rtag == Thread && p->rchild != t) {
			p = p->rchild;
			printf("%c ", p->data);
		}
		p = p->rchild;              //p进入其右子树  
	}//!_while (p != t) 
	return true;
}//!_int InOrderThraverse_Thr(BiTree t)