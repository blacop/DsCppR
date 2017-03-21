#include "stdafx.h"
#pragma once
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
template <typename T> class Set
//集合类Set的声明
class Set {
private:
	//集合中元素个数的最大值
	int setrange;
	//位数组的元素个数和数组指针
	int arraySize;
	//成员指针
	unsigned short *member;
	//确定elt属于数组member中的哪个数组元素
	int ArrayIndex(const T &elt) const;
	//返回一个16位的短整数，其中除了elt所在的位值为1外，其余的位值为0.
	unsign short BitMask(const T &elt) const;

public:

	Set() {}

	virtual ~Set() {}
};

