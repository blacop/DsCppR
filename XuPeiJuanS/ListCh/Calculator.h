#include "stdafx.h"
#include "Stack.h"
//方法的声明实现的 分离写法 容易 报错，IDE还找不到错误的地方
#pragma once
//表达式求值
class Calculator {
private:
	//Calculator's stack,运算存储区
	Stack<double> s;
	//7个方法
public:
	//建立一个空计算器栈
	Calculator(void) {}
	//De建立一个空计算器栈
	virtual ~Calculator() {}
	//将一个double型操作数压入堆栈
	void Enter(double operand) {
		s.Push(operand);
	}
	//弹出2个操作数
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
	//操作符运算
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
	//清空栈
	void Clear();
	//计算表达式的值
	void Run();
};

