#pragma once
#include "stdafx.h"
#include "bithrnode.h"
#include "Stack.h"
#include "Queue.h"
//线索二叉树类bithrtree的声明
template <typename T, typename TElemType>
class bithrtree {
private:
	//指向根结点	
	bithrnode<T>* root;
	//输入stop时，终止结点的输入
	T stop;
	//从结点begin开始搜索，返回结点current的父结点
	bithrnode<T>* father(bithrnode<T>* begin, bithrnode<T>* current);
	//10个方法
public:
	//Constructor()
	bithrtree() :root(new bithrnode()) {}
	//Constructor(),构造函数--在声明一棵二叉树时进行初始化，生成一棵空树
	bithrtree() :root(NULL) {}
	//Constructor(),//输入stop时，终止结点的输入
	bithrtree(T mark) :root(NULL), stop(mark) {}
	//DeConstructor(),析构函数--删除整棵二叉树
	virtual ~bithrtree() { DelSubtree root; }
	//在当前结点的位置插入一个结点
	int Insert(bithrnode<T>*& current, const T& item);
	//从结点current开始，搜索数据值为item的结点，返回编号
	int Find(bithrnode<T>*& current, const T& item) const;
	//删除结点current及其左右子树
	void DelSubtree(bithrnode<T>* current);
	//先根遍历并输出以结点t为根的树
	void Preorder(bithrnode<T>* t, ostrem& out)const;
	//中根遍历并输出以结点t为根的树
	void Inorder(bithrnode<T>* t, ostrem& out)const;
	//后根遍历并输出以结点t为根的树
	void Postorder(bithrnode<T>* t, ostrem& out)const;
	//判断二叉树是否为空
	virtual int IsEmpty() {
		return root == NULL ? 1 : 0;
	}
	//计算结点个数,二叉树遍历的应用,
	void countleaf(bithrnode<T>* t, int& count) {
		if (t != NULL) {
			if ((t->left == NULL) && (t->right == NULL))
				count++;
			countleaf(t->left, count);
			countleaf(t->right, count);
		}
	}
	//交换二叉树中每个结点的左子女和右子女,先序可，后序可，中序不可
	void exchange(bithrnode<T>* t) {
		bithrnode<T>* temp;
		if ((t->left != NULL) || (t->right != NULL)) {
			temp = t->left;
			t->left = t->right;
			t->right = temp;
			exchange(t->left);
			exchange(t->right);
		}
	}
	//删除结点current极其左右子树，后序可
	void DelSubtree(bithrnode<T>* current) {
		if (current != NULL) {
			DelSubtree(current->left);
			DelSubtree(current->right);
			delete current;
		}
	}
	//按先序顺序构造一棵二叉树
	void CreateBiTree(BiTree<T>& T);

	//访问结点Func
	typedef bool(*VisitFunc)(TElemType) {
		PrintElement(e);
		return true;
	};

	//访问结点元素
	bool Visit(TElemType e) {
		if (!e) return false;
		PrintElement(T e); //cout << t->data;
		return true;
	}
	//输出结点元素
	bool PrintElement(TElemType e) {
		if (!e) return false;
		cout << e;	   //printf(e);
		return true;
	}

	//先序遍历二叉树的递归算法1
	bool PreOrderTraverseRec(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		if (T != NULL) {
			Visit(T->data);
			PreOrderTraverse(T->left, Visit(T->data));
			PreOrderTraverse(T->right, Visit(T->data));
			return ERROR;
		} else return true;
	}
	//先根遍历并输出以结点t为根的树,非递归算法，自建栈
	bool PreOrderTrverse(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T; //临时指针
		Stack<T> S = new Stack<T>(); //非递归算法，自建栈,利用栈的特性来实现手动递归		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) {
				Visit(p->data); //访问根结点
				push(S, p);		//根结点入栈
				p = p->left;	//遍历左子树
			} else {	 //根结点出栈，遍历右子树
				pop(S, p);
				p = p->right;
			}//else
		}//while
		return true;
	}

	//中根遍历并输出以结点t为根的树,非递归算法，自建栈
	bool InOrderTrverse(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T; //临时指针
		Stack<T> S = new Stack<T>(); //非递归算法，自建栈,利用栈的特性来实现手动递归		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) { //根结点入栈，遍历左子树
				push(S, p);
				p = p->left;
			} else {  //根结点出栈，访问根结点，遍历右子树
				pop(S, p);
				Visit(p->data);
				p = p->right;
			}//else
		}//while
		return true;
	}
	//后根遍历并输出以结点t为根的树,非递归算法，自建栈
	bool PostOrderTrverse(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T; //临时指针
		Stack<T> S = new Stack<T>(); //非递归算法，自建栈,利用栈的特性来实现手动递归		
		while (p != NULL || !S.IsEmpty()) {
			if (p != NULL) { //根结点入栈，遍历左子树
				push(S, p);
				p = p->left;
			} else {   //根结点出栈，遍历右子树
				pop(S, p);
				p = p->right;
				Visit(p->data);//访问根结点
			}//else
		}//while
		return true;
	}

	//层次遍历二叉树	

	//双向循环线索链表的二叉树中序遍历算法, 遍历带头结点的线索二叉树,T是头结点，*Visit是函数指针
	bool InOrderTraverse_Thr(bithrnode<T>* T, bool(*Visit)(TElemType)) {
		bithrnode<T>* p = T->left; //带头结点的线索二叉树,找到根节点
		while (p != T) { //p=T 表示过了末尾，重新到了头结点
			while (p->LTag == link)  //link表示一直往下找，找到子树的第一个节点
				p = p->left;
			//else if (p->link && p->right == thread) //表示无左子树，已经是叶子节点
			Visit(p->data); //输出此左叶子节点，包括子树的第一个节点，根节点，后继节点
			while (p->right == thread && p->right != T) { //thread表示无右子树，，找后继节点
				p = p->right; //往下找一个后继节点
				Visit(p->data); //输出此后继节点，输出根节点
			}
			//else if(p->right == link) //表示有右子树
			p = p->right; //进入右子树结点
		}
		return OK;
	}

	//在先序遍历过程中建立先序线索化链表:
	//先建立一个头结点thrt 中序访问二叉树 用一个指针pre指向刚刚访问过的结点

	//二叉树的线索化（中序线索化）,c语言版，设立一个辅助哨兵头结点
	int inorder_threading(bithrtree *thrt, bithrtree bt) {
		bithrtree pre;
		*thrt = (bithrtree)malloc(sizeof(bithrnode));//开辟辅助哨兵头结点内存空间
		if (!*thrt)
			exit(OVERFLOW);
		/* 将头结点线索化 */
		(*thrt)->ltag = link;
		(*thrt)->rtag = thread;
		(*thrt)->rchild = (*thrt);

		if (!bt)                      /* 若二叉树为空，则将lchild指向自己 */
			(*thrt)->lchild = (*thrt);
		else {
			(*thrt)->lchild = bt;      /* 头结点左指针指向根结点 */
			pre = (*thrt);
			in_threading(bt);          /* 中序遍历进行中序线索化 */
			pre->rchild = *thrt;
			pre->rtag = thread;
			(*thrt)->rchild = pre;
		}
		return OK;
	}
	/* 中序遍历进行中序线索化 */
	void in_threading(bithrtree t) {
		if (t) {
			in_threading(t->lchild);

			if (!t->lchild) {
				t->ltag = thread;
				t->lchild = pre;
			}
			if (!pre->rchild) {
				pre->rtag = thread;
				pre->rchild = t;
			}
			pre = t;
			in_threading(t->rchild);
		}
	}
	
	//在中序遍历过程中建立中序线索化链表:
	//先建立一个头结点thrt 中序访问二叉树 用一个指针pre指向刚刚访问过的结点
	bool InOrderthreading(bithrnode<T>*& Thrt, bithrnode<T>*& pre) {
		if (!Thrt = new bithrnode<T>())
			exit(overflow_error);
		Thrt->LTag = link; //初始化头结点
		Thrt->RTag = thread;
		Thrt->right = Thrt;
		if (!T) //如空树，则头结点的left也指向头结点
			Thrt->left = T;
		pre = Thrt;
		bithrnode<T>* p = T; //此结点
		Stack<T> S = new Stack<T>();
		S.Push(S, p);
		while (p || S.IsEmpty()) {
			if (p) {
				S.Push(S, p);
				p = p->left;
			} else {
				S.Pop(p);
				p->LTag = thread;
				p->left = pre;
				if (!pre->right) {
					pre->RTag = thread;
					pre->right = p;
				}
				pre = p;
				p = p->right;
			}
		}
		pre->right = Thrt;
		pre->RTag = thread;
		Thrt->right = pre;
		return true;
	}

};//!_class bithrtree

  //先根遍历并输出以结点t为根的树，递归算法
template<typename T>
inline void bithrtree<T>::Preorder(bithrnode<T>* t, ostrem & out) const {
	if (t != NULL) {
		cout << t->data;		//bool(*visit)(TElemType) root node
		Preorder(t->left, out);	//enter left subtree		
		Preorder(t->right, out); //enter right subtree
	}
}

//中根遍历并输出以结点t为根的树，const表示这个是访问函数，不能修改结点，递归算法
template<typename T>
inline void bithrtree<T>::Inorder(bithrnode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Inorder(t->left, out);	//enter left subtree
		cout << t->data;		//bool(*visit)(TElemType) root node
		Inorder(t->right, out); //enter right subtree
	}
}

//后根遍历并输出以结点t为根的树，递归算法
template<typename T>
inline void bithrtree<T>::Postorder(bithrnode<T>* t, ostrem & out) const {
	if (t != NULL) {
		Postorder(t->left, out);	//enter left subtree		
		Postorder(t->right, out); //enter right subtree
		cout << t->data;		//bool(*visit)(TElemType) root node
	}
}

