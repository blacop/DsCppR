#pragma once
#include "stdafx.h"
#include "Clue_Node.h"
/*这里是线索化二叉树的结构*/
template<typename T>
class Clue_Binary_Tree {
	//3个域
private:
	//指向根结点
	Clue_Node<T>* root;
	//输入stop时，终止结点的输入
	T stop;
	//从结点begin开始搜索，返回结点current的父结点
	Clue_Node<T>* father(Clue_Node<T>* begin, Clue_Node<T>* current);
public:
	//构造器() {}
	Clue_Binary_Tree() {}
	//De构造器() {}
	virtual ~Clue_Binary_Tree() {}

	/*前序线索的构建*/
	void Clue_Binary_Tree<T>::_Prev_Creat(Clue_Node<T> * root, Clue_Node<T> *& prev) {
		if (root) {
			if (root->_left == NULL) {		//左 指针域 为 空
				root->_left_flag = CLUE;	//左 标志域 为 线索
				root->_left = prev;			//左 指针域 为 前驱
			}
			if (prev && prev->_right == NULL) {		//右 指针域 为 空
				prev->_right_flag = CLUE;			//右 标志域 为 线索
				prev->_right = root;				//右 指针域 为 根
			}
			prev = root;
			if (!root->_left_flag) {
				_Prev_Creat(root->_left, prev);
			}
			_Prev_Creat(root->_right, prev);
		}
	}//!__Prev_Creat()

	 /*前序线索下的遍历*/
	template<class T>
	void Clue_Binary_Tree<T>::_Prev_Order(Clue_Node<T> * root) {
		cout << "在前序线索下的遍历:" << endl;
		while (root) {
			while (root->_left_flag != CLUE) {
				cout << root->_value << " ";
				root = root->_left;
			}
			cout << root->_value << " ";
			root = root->_right;
		}
		cout << endl;
	}

	/*中序线索的构建*/
	template<class T>
	void Clue_Binary_Tree<T>::_In_Creat(Clue_Node<T> * root, Clue_Node<T> *& prev) {
		if (root) {
			_In_Creat(root->_left, prev);      //左子树
			if (root->_left == NULL) {
				root->_left_flag = CLUE;
				root->_left = prev;
			}
			if (prev && prev->_right == NULL) {
				prev->_right_flag = CLUE;
				prev->_right = root;
			}
			prev = root;
			_In_Creat(root->_right, prev);     //右子树
		}
	}

	/*中序线索下的遍历*/
	template<class T>
	void Clue_Binary_Tree<T>::_In_Order(Clue_Node<T> * root) {
		cout << "中序遍历：" << endl;
		while (root) {
			while (root->_left_flag != CLUE) {
				root = root->_left;
			}
			cout << root->_value << " ";
			while (root->_right_flag != LINK) {
				root = root->_right;
				cout << root->_value << " ";
			}
			root = root->_right;
		}
		cout << endl;
	}

};//!_class Clue_Binary_Tree

