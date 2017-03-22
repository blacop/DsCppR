#include "stdafx.h"
#pragma once
//10个枚举
enum ErrorType { //枚举类型	
	InvalidMember, //无效成员
	ExpectRightBrace, //没有右括号
	MissingValue, //没有值
	MissingComma, //没有逗号
	InvalidChar,
	MissingLeftBrace,
	InvalidInputData,
	EndOfFile,
	OutOfMemory,
	InvalidMemberRef,
	SetsDifferentSize
};

//集合类Set的声明
template<typename T>
class Set {
private:
	//数据域 成员指针 数组指针，指向一维元素的首地址
	unsigned short *member;
	//集合中元素个数的最大值
	int setrange;
	//位数组的元素个数
	int arraySize;
	//确定elt属于数组member中的哪个数组元素
	int ArrayIndex(const T& elt) const;
public: //9个方法
	//构造函数，创建空整型集合
	Set(int setrange);
	//析构函数
	virtual ~Set(void);
	//定义"+"为两个集合的并集,操作符重载
	Set<T> operator + (const Set<T>& x) const;
	//插入元素elt
	void Insert(const T& elt);
	//删除元素elt
	void Delete(const T& elt);
	//判断elt是否在集合中
	int IsMember(const T& elt);
	//掩码，返回一个16位的短整数，其中除了elt所在的位值为1外，其余的位值为0.
	unsigned short BitMask(const T& elt) const;
	//位掩码转化器，进int value,出int
	int ConvertBitMask(int val) {
		int bitMask = 1 << val;
		return bitMask;
	}
	//二进制转化器，进int,出StringBuilder
	StringBuilder ConvertBits(int val) {
		int bitMask = 1 << 31;
		StringBuilder bitBuffer = new StringBuilder(35);
		for (int i = 1; i <= 32; i++) {
			if ((val & bitMask) == 0)
				bitBuffer.Append("0");
			else
				bitBuffer.Append("1");
			val <<= 1;
			if ((i % 8) == 0)
				bitBuffer.Append(" ");
		}
		return bitBuffer;
	} //二进制转化器，进int,出string
};

//确定elt属于数组member中的哪个数组元素,返回数组元素的order
template<typename T>
inline int Set<T>::ArrayIndex(const T & elt) const {
	//  elt.value /16
	int listIndex = elt >> 4;
	return listIndex;
}

//掩码，返回一个16位的短整数，其中除了elt所在的位值为1外，其余的位值为0.
template<typename T>
inline unsigned short Set<T>::BitMask(const T & elt) const {
	//数值检查
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	unsigned short mask = 1 << elt;
	return mask;
}

//构造函数，创建空整型集合
template<typename T>
inline Set<T>::Set(int setrange) :setrange(setrange) {
	// >>4 => /16, 位数组的长度公式: (setrange + 15) >> 4
	int ArraySize = (setrange + 15) >> 4;

	//申请数组空间 ,位运算的操作对象是无符号的short整数 16位 2字节,
	member = new unsigned short[arraySize];
	if (member == NULL)
		Error(OutOfMemory);
	//将所有位置设为0,以创建空集
	for (int i = 0; i < arraySize; i++) {
		member[i] = 0;
	}
}

//定义"+"为两个集合的并集,操作符重载 //this + Set<T>& x
template<typename T>
inline Set<T> Set<T>::operator+(const Set<T>& x) const {
	//长度检查
	if (setrange != x.setrange)
		Error(SetsDifferentSize);
	//用集合tmp存放并集
	Set<T> tmp(setrange);
	//故并集的位值为两个集合的按位或
	for (int i = 0; i < arraySize; i++) {
		tmp.member[i] = member[i] | x.member[i];
		return tmp;
	}
}

//插入元素elt
template<typename T>
inline void Set<T>::Insert(const T & elt) {
	//elt是否在0~setrange-1之间
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	//置elt所在位值为1
	member[ArrayIndex(elt)] |= BitMask(elt);
}

//删除元素elt
template<typename T>
inline void Set<T>::Delete(const T & elt) {
	//elt是否在0~setrange-1之间
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	//置elt所在位值为0
	member[ArrayIndex(elt)] &= (!BitMask(elt));
}

//判断elt是否在集合中
template<typename T>
inline int Set<T>::IsMember(const T & elt) {
	//数值检查//异常捕捉，数值超出集合数值范围
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	//若elt不在集合中，返回0;否则，返回一个非0值
	return member[ArrayIndex(elt)] & BitMask(elt);
}



