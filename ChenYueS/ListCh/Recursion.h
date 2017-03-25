#pragma once
#include "stdafx.h"

//class Recursion {
//public:
//	Recursion() {}
//	virtual ~Recursion() {}
//};

//1.3.3 线性O(n)
//	 问题与算法
//	考查如下问题：计算给定n个整数的总和。该问题可由代码1.3中的算法sumI()解决。
int sumCirle(int A[], int n) { //数组求和算法（迭代版）
	int sum = 0; //刜始化累计器，O(1)
	for (int i = 0; i < n; i++) //对全部共O(n)个元素，逐一
		sum += A[i]; //累计，O(1)
	return sum; //迒回累计值，O(1)
} //O(1) + O(n)*O(1) + O(1) = O(n+2) = O(n)

  //1.4.1 线性递归
//n => Length
int sumLine(int A[], int n) { //数组求和算法（线性逑弻版）
	if (1 > n) //平凡情况，递归基
		return 0; //直接（非递归式）计算
	else //一般情况
		//length = n-1
		return sumLine(A, n - 1) + A[n - 1]; //逑弻：前n - 1顷乀和，再累计第n - 1顷
} //O(1)*逑弻深度 = O(1)*(n + 1) = O(n)


