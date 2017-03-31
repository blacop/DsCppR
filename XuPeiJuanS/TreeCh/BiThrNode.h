#pragma once
#include "stdafx.h"
//线索二叉树类的结点类的声明
//link==0:指针，指向子树;thread==1:线索，指向前驱后继
typedef enum { link, thread }pointer_tag;
//线索二叉树类的结点类的声明
template <typename T, typename elemtype>
class bithrnode {
	//友元类, 本类的private member私有成员可被友元类操作
	friend class bithrtree;
private:
	//5个域
public:
	//data domain 数据域	
	T data;
	//ref domain 引用域	
	bithrnode<T> *lchild, *rchild;
	//左右标志
	pointer_tag ltag, rtag;

	//6个方法

	//返回左孩子
	bithrnode<T>* GetLeft(void) const {
		return lchild;
	}
	//将左孩子更新为结点L
	void SetLeft(bithrnode<T>* L) {
		lchild = L;
	}
	//返回右孩子
	bithrnode<T>* GetRight(void) const {
		return rchild;
	}
	//将右孩子更新为结点R
	void SetRight(bithrnode<T>* R) {
		rchild = R;
	}
	//构造函数,Constructor()
	bithrnode(const T& item, bithrnode<T>* lptr = NULL, bithrnode<T>* rptr = NULL)
		:data(item), lchild(lptr), rchild(rptr) {}
	//Deconstructor()
	virtual ~bithrnode() {}


};//!_class bithrnode



