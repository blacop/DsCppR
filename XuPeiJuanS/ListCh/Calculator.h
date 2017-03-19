#pragma once
#include "stdafx.h"
#include "Stack.h"
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
	void GetTwoOperands(double operand1, double operand2);
	//操作符运算
	void Compute(char op);
	//清空栈
	void Clear();	
	//计算表达式的值
	void Run();
};

