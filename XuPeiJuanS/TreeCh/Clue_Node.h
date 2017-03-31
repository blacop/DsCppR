#pragma once
#include "stdafx.h"
/*这里是线索化二叉树的结构*/
//线索化二叉树的节点的标志域
enum Flag {
	LINK,      //一般指针的标记    子树
	CLUE       //线索化指针的标记  线索
};
//线索化二叉树的节点的结构
template<typename T>
class Clue_Node {
	//5个域
public:
	//数据域	data domain 
	T _value;
	//引用域	ref domain 
	Clue_Node *_left, *_right;
	//左右标志域
	Flag _left_flag, _right_flag;

	//6个方法

	//构造器() {}
	Clue_Node(const T& value)
		:_value(value), _left(NULL), _right(NULL),
		_left_flag(LINK), _right_flag(LINK) {}
	//De构造器()
	virtual ~Clue_Node() {}

	//返回左孩子
	Clue_Node<T>* GetLeft(void) const {
		return left;
	}
	//将左孩子更新为结点L
	void SetLeft(Clue_Node<T>* L) {
		left = L;
	}

	//返回右孩子
	Clue_Node<T>* GetRight(void) const {
		return right;
	}
	//将右孩子更新为结点R
	void SetRight(Clue_Node<T>* R) {
		right = R;
	}

	
};




