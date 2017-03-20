#include "stdafx.h"
#pragma once
template<typename T>
class Array {
private:
	T* alist;// T[] data
	int Fsize;//Length
	void Allocate(); //malloc()	
public: //7种方法
	//构造函数，参数 Fsize
	Array(int sz = 50);
	//构造函数，参数 类引用, 复制构造函数，把原对象复制成1个新对象
	Array(const Array<T>& x);
	//De构造函数
	virtual ~Array() {
		delete[] alist;//删除整个数组[]空间
	}
	//重载操作符 '=',让数组可以整体赋值
	Array<T>& operator = (const Array<T>& x);
	//重载操作符 '[]',可以实现索引器功能
	T& operator [] (int i);
	//重载操作符 'T*'，typename转换为指针类型，让对象名可以指向数组空间的首地址,可以实现索引器功能
	Array<T>& operator T* (void)const {
		return alist;
	}
	//Length()
	int ListSize(void) const {
		return Fsize;
	}
};//!_class Array

//malloc()
template<typename T>
inline void Array<T>::Allocate() {
	alist = new T[Fsize];
	if (alist == 0)
		cerr << "Memory Allocation Fail." << endl;
}

//Constructor(int size)
template<typename T>
inline Array<T>::Array(int sz) {
	if (sz = 0) {
		cerr << "Invalid Array Size." << endl;
		return;
	}
	Fsize = sz;
	Allocate();
}

//Constructor(Constructor<T>& x),copy Constructor()
template<typename T>
inline Array<T>::Array(const Array<T>& x) {
	Fsize = x.Fsize;
	Allocate();
	for (int i = 0; i < Fsize; i++)
		alist[i] = x.alist[i];
}
