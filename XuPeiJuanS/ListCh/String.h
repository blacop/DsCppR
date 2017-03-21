#include "stdafx.h"
#pragma once
//字符串类定义
//模式（子串）匹配
class String {

public:
	char* str; //data domain
	int size; //length
	String() {}
	virtual ~String() {}

	//模式（子串）匹配，朴素匹配模式
	int Find(String pat) const {
		//模式串，目标串
		char *p = pat.str, *s = str;
		//sub's length
		int i = 0;
		//sub's length <= size - pat.size means 剩余长度
		while (i <= size - pat.size) {
			//匹配,ptr++
			while (*p++ == *s++)
				//遍历模式串，end sub string, means 匹配成功
				if (*p == '\0') return i;
			//else，遍历匹配失败, src staart ptr ++ move
			i++; p = pat.str; s = str + i;
		}
		return -1;
	}
};

