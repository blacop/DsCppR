#include "stdafx.h"
#include "Stack.h"
//����������ʵ�ֵ� ����д�� ���� ����IDE���Ҳ�������ĵط�
#pragma once
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
	void GetTwoOperands(double &operand1, double &operand2) {
		if (s.IsEmpty()) {
			cerr << "No operand to be pop !" << endl;
			s.Clear();
			exit(1);
		}
		operand1 = s.Pop();
		if (s.IsEmpty) {
			cerr << "No operand to be pop !" << endl;
			s.Clear();
			exit(1);
		}
		operand2 = s.Pop();
	}
	//����������
	void Compute(char op) {
		double operand1, operand2, result;
		GetTwoOperands(operand1, operand2);
		switch (op) {
			case '+': result = operand1 + operand2; break;
			case '-': result = operand1 - operand2; break;
			case '*': result = operand1 * operand2; break;
			case '/': if (operand2 == 0) {
				cerr << "Divided by 0 !" << endl;
				s.Clear();
				exit(1);
			} else
				result = operand1 / operand2; break;
			default:
				break;
		}
		s.Push(result);
	}
	//���ջ
	void Clear();
	//������ʽ��ֵ
	void Run();
};

