#pragma once
#include "stdafx.h"
//Link==0:指针，指向子树;Thread==1:线索，指向前驱后继
typedef enum PointerTag{Link,Thread};
//线索二叉树类的结点类的声明
template <typename T>
class BiThrNode {
	//友元类, 本类的private member私有成员可被友元类操作
	friend class BinTree;
private:
public:
	//data domain 数据域
	T data;
	//ref domain 引用域
	BiThrNode<T>* left;
	BiThrNode<T>* right;
	PointerTag LTag, RTag;//左右标志
	//6个方法

	//返回左孩子
	BiThrNode<T>* GetLeft(void) const {
		return left;
	}
	//将左孩子更新为结点L
	void SetLeft(BiThrNode<T>* L) {
		left = L;
	}
	//返回右孩子
	BiThrNode<T>* GetRight(void) const {
		return right;
	}
	//将右孩子更新为结点R
	void SetRight(BiThrNode<T>* R) {
		right = R;
	}
	//构造函数,Constructor()
	BiThrNode(const T& item, BiThrNode<T>* lptr = NULL, BiThrNode<T>* rptr = NULL)
		:data(item), left(lptr), right(rptr) {}
	//Deconstructor()
	virtual ~BiThrNode() {}
};//!_class BiThrNode



