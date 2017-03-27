//#pragma region Member Field
//#pragma endregion !_Member Field
//#pragma region Member Attribute
//#pragma endregion !_Member Attribute
//#pragma region Member Function Statement
//#pragma endregion !_Member Function Statement
//#pragma region Member Function Definition
//#pragma endregion !_Member Function Definition

// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

//#pragma once是一个比较常用的C/C++杂注，只要在头文件的最开始加入这条杂注，就能够保证头文件只被编译一次。
#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <io.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

////宏展开 属性
//#define AutoProperty(ValueType, GetAccessor, SetAccessor, Variable)	private: ValueType Variable;\
//GetAccessor: ValueType get##Variable() { return Variable; }\
//SetAccessor: void set##Variable(ValueType newValue) { Variable = newValue; }

// TODO:  在此处引用程序需要的其他头文件
