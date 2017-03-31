#pragma once
#include "stdafx.h"
//http://blog.csdn.net/u010366748/article/details/50769262
//class ThrBiNode {
//public:
//
//	ThrBiNode() {}
//
//	virtual ~ThrBiNode() {}
//};
#include<stdio.h>  
#include<stdlib.h>  

//#define Link 0//指针标志  
//#define Thread 1//线索标志  
typedef char TElemType;
//中序线索二叉树  
typedef enum PointerTag { Link, Thread };
//结点的child域类型，link表示是指针，指向孩子结点，thread表示是线索，指示前驱或后继结点  
//补充：枚举型是一个集合，集合中的元素(枚举成员)是一些命名的整型常量，元素之间用逗号隔开  
//第一个枚举成员的默认值为整型的0，后续枚举成员的值在前一个成员上加1。  
//可以人为设定枚举成员的值，从而自定义某个范围内的整数。  

typedef struct ThrBiNode {
	TElemType data;
	ThrBiNode *lchild, *rchild;//左右孩子指针  
	PointerTag lTag, rTag;//左右标志  
}ThrBiNode, *ThrBiTree;

//3.2中序线索化二叉树
//线索划的过程即为在遍历的过程中修改空指针的过程，为记下遍历过程中访问结点的先后顺序，
//附设指针pre总指向当前访问结点p的前驱结点。

//中序遍历二叉树T，并将其 中序线索化，Thrt指向头结点 ,过程中顺便加头结点head 
void inOrderThreading(ThrBiTree T, ThrBiTree &Thrt) {
	//初始化线索链表，为其建立一个头结点  
	Thrt = (ThrBiTree)malloc(sizeof(ThrBiNode));
	Thrt->lTag = Link;
	Thrt->rTag = Thread;
	//Thrt->rchild = Thrt;//右指针在末尾的时候回指，因为若T为空树的话，只会指向下面的if语句，那么Thrt->rchild  
	if (!T) {//如果二叉树为空树，则Thrt->lchild指针回指  
		Thrt->lchild = Thrt; //左指针回指
		Thrt->rchild = Thrt;//右指针回指 ，这样就形成了一个空的双向循环链表 
	} else { //二叉树非空
		Thrt->lchild = T; //头结点左孩子指向根节点
		ThrBiNode *pre = Thrt;//pre指针总指向当前结点的前驱结点  
		//中序线索化
		inThreading(T, pre);
		//继续为最后一个结点加入线索
		//此时pre应指向最后一个结点
		pre->rTag = Thread;
		pre->rchild = Thrt;//最后一个结点的rchild域指针回指  
		Thrt->rchild = pre;//头结点的rchild域指针指向最后一个结点  
	}
}

//中序遍历进行中序线索化(左、根、右)  
void inThreading(ThrBiTree T, ThrBiTree &pre) {
	if (T) {
		inThreading(T->lchild, pre);//左子树线索化  

		if (!T->lchild) {//当前结点的左孩子为空  
			T->lTag = Thread;
			T->lchild = pre;
		} else {
			T->lTag = Link;
		}

		if (!pre->rchild) {//前驱结点的右孩子为空
			pre->rTag = Thread;
			pre->rchild = T;
		} else {
			pre->rTag = Link;
		}
		pre = T; //前驱结点赋值
		inThreading(T->rchild, pre);//右子树线索化  
	}
}
//3.3中序遍历线索二叉树

//T指向头结点，头结点的lchild链域指针指向二叉树的根结点  
//中序遍历打印二叉线索树T（非递归算法）  
void inOrderTraversePrint(ThrBiTree T) {
	ThrBiNode *p = T->lchild;//p指向根结点  

	while (p != T) {//空树或遍历结束时，p == T  
		while (p->lTag == Link) {
			p = p->lchild;
		}
		//此时p指向中序遍历序列的第一个结点（最左下的结点）  

		printf("%c ", p->data);//打印（访问）其左子树为空的结点  

		while (p->rTag == Thread && p->rchild != T) {
			p = p->rchild;
			printf("%c ", p->data);//访问后继结点  
		}
		//当p所指结点的rchild指向的是孩子结点而不是线索时，p的后继应该是其右子树的最左下的结点，即遍历其右子树时访问的第一个节点  
		p = p->rchild;
	}
	printf("\n");
}

//3.4创建二叉树

//利用先序序列建立一颗二叉树,'.'代表空树   
//测试用例:-+a..*b..-c..d../e..f..#  
void createBiTreeByPreOrder(ThrBiTree &T) {
	//按先序次序输入二叉树中节点的值（一个字符），点号字符表示空树，构造二叉链表表示的二叉树  
	//注意：若输入的字符数（不含#号）为n个，则相应的空树即点号就应该有n+1个  
	char ch;
	scanf("%c", &ch);
	if (ch != '#') {
		if (ch == '.') {
			T = NULL;
		} else {
			T = (ThrBiNode *)malloc(sizeof(ThrBiNode));
			T->data = ch;
			createBiTreeByPreOrder(T->lchild);
			createBiTreeByPreOrder(T->rchild);
		}
	}
}

//测试main
void main() {
	ThrBiTree T;
	printf("请按先序次序输入二叉树各节点的值，以空格表示空树，以#号结束:\n");
	createBiTreeByPreOrder(T);//建立二叉树  

	ThrBiTree Thrt;
	inOrderThreading(T, Thrt);//将二叉树T中序线索化  

	inOrderTraversePrint(Thrt);//中序遍历二叉线索树（通过线索链表，就像访问线性表一样）  
							   //当然之前的不按线索，直接根据二叉树的结构进行遍历依然可以（层次、先序、后序、中序）  
}