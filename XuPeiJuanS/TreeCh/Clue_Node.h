#pragma once
#include "stdafx.h"
/*�������������������Ľṹ*/
//�������������Ľڵ�ı�־��
enum Flag {
	LINK,      //һ��ָ��ı��    ����
	CLUE       //������ָ��ı��  ����
};
//�������������Ľڵ�Ľṹ
template<typename T>
class Clue_Node {
	//5����
public:
	//������	data domain 
	T _value;
	//������	ref domain 
	Clue_Node *_left, *_right;
	//���ұ�־��
	Flag _left_flag, _right_flag;

	//6������

	//������() {}
	Clue_Node(const T& value)
		:_value(value), _left(NULL), _right(NULL),
		_left_flag(LINK), _right_flag(LINK) {}
	//De������()
	virtual ~Clue_Node() {}

	//��������
	Clue_Node<T>* GetLeft(void) const {
		return left;
	}
	//�����Ӹ���Ϊ���L
	void SetLeft(Clue_Node<T>* L) {
		left = L;
	}

	//�����Һ���
	Clue_Node<T>* GetRight(void) const {
		return right;
	}
	//���Һ��Ӹ���Ϊ���R
	void SetRight(Clue_Node<T>* R) {
		right = R;
	}

	
};




