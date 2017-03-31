#pragma once
#include "stdafx.h"
#include "Clue_Node.h"
/*�������������������Ľṹ*/
template<typename T>
class Clue_Binary_Tree {
	//3����
private:
	//ָ������
	Clue_Node<T>* root;
	//����stopʱ����ֹ��������
	T stop;
	//�ӽ��begin��ʼ���������ؽ��current�ĸ����
	Clue_Node<T>* father(Clue_Node<T>* begin, Clue_Node<T>* current);
public:
	//������() {}
	Clue_Binary_Tree() {}
	//De������() {}
	virtual ~Clue_Binary_Tree() {}

	/*ǰ�������Ĺ���*/
	void Clue_Binary_Tree<T>::_Prev_Creat(Clue_Node<T> * root, Clue_Node<T> *& prev) {
		if (root) {
			if (root->_left == NULL) {		//�� ָ���� Ϊ ��
				root->_left_flag = CLUE;	//�� ��־�� Ϊ ����
				root->_left = prev;			//�� ָ���� Ϊ ǰ��
			}
			if (prev && prev->_right == NULL) {		//�� ָ���� Ϊ ��
				prev->_right_flag = CLUE;			//�� ��־�� Ϊ ����
				prev->_right = root;				//�� ָ���� Ϊ ��
			}
			prev = root;
			if (!root->_left_flag) {
				_Prev_Creat(root->_left, prev);
			}
			_Prev_Creat(root->_right, prev);
		}
	}//!__Prev_Creat()

	 /*ǰ�������µı���*/
	template<class T>
	void Clue_Binary_Tree<T>::_Prev_Order(Clue_Node<T> * root) {
		cout << "��ǰ�������µı���:" << endl;
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

	/*���������Ĺ���*/
	template<class T>
	void Clue_Binary_Tree<T>::_In_Creat(Clue_Node<T> * root, Clue_Node<T> *& prev) {
		if (root) {
			_In_Creat(root->_left, prev);      //������
			if (root->_left == NULL) {
				root->_left_flag = CLUE;
				root->_left = prev;
			}
			if (prev && prev->_right == NULL) {
				prev->_right_flag = CLUE;
				prev->_right = root;
			}
			prev = root;
			_In_Creat(root->_right, prev);     //������
		}
	}

	/*���������µı���*/
	template<class T>
	void Clue_Binary_Tree<T>::_In_Order(Clue_Node<T> * root) {
		cout << "���������" << endl;
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

