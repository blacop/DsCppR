#pragma once
#include "stdafx.h"
#include "Stack.h"
//���ʽ��ֵ
class Calculator {
private:
	//Calculator's stack,����洢��
	Stack<double> s;
	//7������
public:
	//����һ���ռ�����ջ
	Calculator(void) {}
	//De����һ���ռ�����ջ
	virtual ~Calculator() {}
	//��һ��double�Ͳ�����ѹ���ջ
	void Enter(double operand) {
		s.Push(operand);
	}
	//����2��������
	void GetTwoOperands(double operand1, double operand2);
	//����������
	void Compute(char op);
	//���ջ
	void Clear();	
	//������ʽ��ֵ
	void Run();
};

