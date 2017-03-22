#pragma once
#include "stdafx.h"
#include "Array.h"

template<typename T>
class Algo {
public:
	Algo() {}
	virtual ~Algo() {}
};

//求倍数,不写模板泛型就会报错《没有重载
template<typename T>
void multiple(void) {
	Array<int> A(10); //运算存储数据区
	int N, count = 0; //N是被操作数
	cout << "N=?";
	cin >> N;
	for (int i = 5; i <= N; i++) {
		if (count == A.ListSize()) { //扩容
			A.Resize(count + 10);
		}
		if (i % 5 == 0 || i % 7 == 0) { //取5 或7 的倍数
			A[count++] = i; //赋值
		}
	}
	for (int j = 0; j < count; j++) { //遍历输出
		//T temp = A[j]; //不写模板泛型就会报错《没有重载
		cout << A[j] << " ";
		if ((j + 1) % 5 == 0)
			cout << endl;
	}
}//!_void multiple(void)


