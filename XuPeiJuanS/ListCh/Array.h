#pragma once
#include "stdafx.h"
//自定义动态数组类
template<typename T>
class Array {
private:
	T* List;// T[] data
	int Length;//Length
	void Allocate(); //malloc()
public: //7种方法
		//Constructor(int size)
	//构造函数，参数 Length
	Array(int size = 50) {
		if (size = 0) {
			cerr << "Invalid Array Size." << endl;
			return;
		}
		Length = size;
		Allocate(); //malloc()
	}
	//Constructor(Constructor<T>& x),copy Constructor()
	//构造函数，参数 类引用, 复制构造函数，把原对象复制成1个新对象
	//示例 new Array<T>& this(Array<T>& Src);
	Array(const Array<T>& Src) {
		this.Length = Src.Length;
		Allocate();
		for (int i = 0; i < Length; i++)
			this.List[i] = Src.List[i];
	}
	//De构造函数
	virtual ~Array() {
		delete[] List;//删除整个数组[]空间
	}

	//操作符重载'=',让 自定义数组对象 可以整体赋值
	//示例 Array<T>& this = Array<T>& Src;
	Array<T>& operator=(const Array<T>& Src) {
		if (this.Length <= 0 || Src.Length <= 0) { //判断大小 <= 0
			cerr << "invalid Array Size !" << endl;
			return;
		}
		if (this.Length != Src.Length) { //判断大小 不相同	
			cerr << "Array size not match !" << endl;
			return;
		}
		this.Length = Src.Length; //Length
		for (int i = 0; i < Length; i++) {
			this.List[i] = Src.List[i];
		}
	}

	//操作符重载'[]',实现索引器功能
	//示例 Array<T>& this[i]
	Array<T>& operator[](int i) {
		//操作符重载 语法
		//调用成员函数运算符的格式如下：
		//this对象类型说明符 operator 运算符 （形参表）{函数体}
		if (i < 0 || i >= this.Length) {
			cerr << "invalid index." << endl;
			exit(1);
		}
		return this.List[i];
	}

	////操作符重载'[]',实现索引器功能,这个多余，T本来就是数组了
	////示例 T& this[i]
	//T& operator[](int i) {
	//	//操作符重载 语法
	//	//调用成员函数运算符的格式如下：
	//	//this对象类型说明符 operator 运算符 （形参表）{函数体}
	//	if (i<0 || i >= Length) {
	//		cerr << "invalid index." << endl;
	//		exit(1);
	//	}
	//	return List[i];
	//}

	////操作符重载'<<',实现索引器 cout<<功能,写失败了
	////示例 cout << Array<T>& this[i]
	//Array<T>& operator<<(this[i]) {
	//	//操作符重载 语法
	//	//调用成员函数运算符的格式如下：
	//	//this对象类型说明符 operator 运算符 （形参表）{函数体}
	//	if (i < 0 || i >= this.Length) {
	//		cerr << "invalid index." << endl;
	//		exit(1);
	//	}
	//	return List[i];
	//}

	//操作符重载'T*'，重载指针转换操作符，返回当前"对象中"私有数组的首地址//让对象名指向对象的内部数组空间的首地址
	//示例 Array<T>& this*
	Array<T>& operator*(void) const {
		//Array<T>& operator * (void) const {
		//T& operator * (void) const {
		//返回当前"对象中"私有数组的首地址
		return List;
	}
	//Length()
	int ListSize(void) const {
		return Length;
	}
	//修改数组的大小
	void Resize(int newSize);

	//查找-----------分隔线--------------------- 
	//在数组中找最小值
	public static int FindMin(int[] arr) {
		int min = arr[0];
		for (int index = 0; index < arr.Length - 1; index++)
			if (arr[index] < min)
				min = arr[index];
		return min;
	}
	//在数组中找最大值
	public static int FindMax(int[] arr) {
		int max = arr[0];
		for (int index = 0; index < arr.Length - 1; index++)
			if (arr[index] > max)
				max = arr[index];
		return max;
	}
	/*上述两个函数的另外一种替换写法是返回最大值或最小值在数组内的位置，而不是返回实际的数值。*/



};//!_class Array

//malloc()
template<typename T>
inline void Array<T>::Allocate() {
	List = new T[this.Length];
	if (List == 0)
		cerr << "Memory Allocation Fail." << endl;
}

//修改数组的大小
template<typename T>
inline void Array<T>::Resize(int newSize) {
	if (newSize <= 0) { //判断大小 <= 0
		cerr << "invalid Array Size." << endl;
		return;
	}
	T* newArray; //新数组对象的指针
	if (newSize != Length) { //判断大小 不相同
		newArray = new T[newSize]; //malloc()
		if (newArray == 0) {
			cerr << "Memory Allocation Fail." << endl;
			return;
		}
	}
	int n = (newSize <= Length ? newSize : Length); //比大小
	for (int i = 0; i < n; i++) {
		newArray[i] = this.List[i];
	}
	delete[] this.List;
	this.List = newArray;
	this.Length = newSize;
}


