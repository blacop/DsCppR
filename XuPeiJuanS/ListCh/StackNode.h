//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition
#pragma once
#include "stdafx.h"
#include "Node.h"

//StackNode
template <class T>
class StackNode : public Node {
	//����ڱ�������������ط�������һ��������������������ǲ������κ���ķǳ�Ա������Ҳ������������ĳ�Ա������������������friend�Ըú��������������˺����ͳ�Ϊ�������Ԫ������һ�������Ԫ�������Է���������е�private��Ա��
	//mean can operated by class Stack<T>
	friend class Stack<T>;
private:
	T data; //data domain
	StackNode<T>* next; //ref domain

public://2������

	//Construct Function()
	StackNode(T d = 0, StackNode<T>* n = NULL)
		:data(d), next(n) {}

	//DeConstruct Function()
	virtual ~StackNode() {}

};//!_class StackNode


