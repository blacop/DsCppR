#include "stdafx.h"
#pragma once
//自定义动态数组类
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
	//操作符重载'=',让 自定义数组对象 可以整体赋值
	Array<T>& operator = (const Array<T>& x);	
	//操作符重载'[]',实现索引器功能
	Array<T>& operator [] (int i) {
		//操作符重载 语法
		//调用成员函数运算符的格式如下：
		//this对象类型说明符 operator 运算符 （形参表）{函数体}
		if (i<0 || i>Fsize) {
			cerr << "invalid index." << endl;
			exit(1);
		}
		return alist[i];
	}	
	//操作符重载'T*'，重载指针转换操作符，返回当前"对象中"私有数组的首地址//让对象名指向对象的内部数组空间的首地址
	Array<T>& operator * (void) const {
		//Array<T>& operator * (void) const {
		//T& operator * (void) const {
		//返回当前"对象中"私有数组的首地址
		return alist;
	}
	//Length()
	int ListSize(void) const {
		return Fsize;
	}
	//修改数组的大小
	void Resize(int newSize);

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

//重载操作符 '=',让数组可以整体赋值
template<typename T>
inline Array<T>& Array<T>::operator=(const Array<T>& x) {
	// TODO: 在此处插入 return 语句

}



//修改数组的大小
template<typename T>
inline void Array<T>::Resize(int newSize) {
	T* newArray; //新数组对象的指针
	if (newSize <= 0) { //判断大小 <= 0
		cerr << "invalid Array Size." << endl;
		return;
	}
	if (newSize != Fsize) { //判断大小 不相同
		newArray = new T[newSize]; //malloc()
		if (newArray == 0) {
			cerr << "Memory Allocation Fail." << endl;
			return;
		}
	}
	int n = (newSize <= Fsize ? newSize : Fsize); //比大小
	for (int i = 0; i < n; i++) {
		newArray[i] = this.alist[i];
	}
	delete[] this.alist;
	this.alist = newArray;
	this.Fsize = newSize;
}


