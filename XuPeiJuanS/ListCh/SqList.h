//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition
//#pragma once是一个比较常用的C/C++杂注，只要在头文件的最开始加入这条杂注，就能够保证头文件只被编译一次。
#pragma once
#include "stdafx.h"

template <class T> //模板类，实现泛型,T指的就是元素类型
class SqList {
	#pragma region Member field 成员字段
private:
	T * data; //表元素数组， T * 泛型指针 //另一种写法 T[] data。
	int last; //工作指针 //int n; //现存元素个数			  
	int MaxSize; //最大元素个数	
	#pragma endregion !_Member field 成员字段

	#pragma region Member Methods Interface 成员方法接口声明ADT
public:
	SqList(int Max = 10);//构造函数,className();如果没有传入值，默认为10,这样写就不用写无参数构造器了
	virtual ~SqList() { delete[] data; } //析构函数,~className(); //delete必须有 [] 运算符 才能释放整个data数组的内存空间

	int Locate(const T& x) const;//返回表中元素x的位置，常量const表示 成员变量不能被修改，T& x，T泛型形参，& x引用传值//const成员函数不能修改调用该函数的对象
	int Insert(int k, const T& x);//在表的位置K处插入元素x
	int Delete(int k, T& x);//从表中删除位置k处的元素x
	#pragma endregion !_Member Methods Interface 成员方法接口声明ADT
};

template <class T>
SqList<T>::SqList(int Max) {
	//构造函数
	//模板类，界定符必须要写SqList<T>::
	MaxSize = Max;
	data = new T[MaxSize]; //动态分配数组
	last = -1; //工作指针
}

template<class T>
int SqList<T>::Locate(const T& x) const {
	//查找表中元素x的位置，return index
	//返回表中元素x的位置
	//const成员函数不能修改调用该函数的对象
	int i = 0; //临时指针
	while (i <= last && data[i] != x)  //顺序查找，临时指针 i++
		i++;
	if (i > last)   //查找失败
		return -1;
	else			//查找成功
		return i;
}

template<class T>
bool SqList<T>::Insert(int k, const T & x) {
	//插入元素
	//int k,order pos
	//const T & x , data
	//return bool;
	//下标非法，k=last + 1表示尾插。 last == MaxSize - 1 表示满了
	if ((k<0 || k>last + 1) || last == MaxSize - 1)
		return 0;
	else { //下标合法
		last++; //工作指针+1
		for (int j = last; j > k; j--) {
			data[j] - data[j - 1];
			data[k] = x;
			return 1;
		}
	}
}

template<class T>
bool SqList<T>::Delete(int k, T & x) {
	//从表中删除位置k 处的元素 x,return bool
	if (k<0 || k>last) //index illegal
		return 0;
	last--;
	for (int j = k; j <= last; j++) {
		data[j] = data[j + 1];
		return 1;
	}
}

