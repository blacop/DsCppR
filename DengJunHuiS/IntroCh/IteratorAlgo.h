#pragma once
#include "stdafx.h"

//枚举器
template <typename T, typename Container, typename Object>
class IteratorAlgo {
public:
	IteratorAlgo() {}
	virtual ~IteratorAlgo() {}

	//erase(), 对表lst使用erase() by枚举器
	//从表的起始项开始间隔地删除项
	template <typename Container>
	void removeEveryOtherItem(Container& lst) {
		//new iterator()
		typename Container::iterator itr = lst.begin();
		while (itr != lst.end()) {
			itr = lst.erae(itr);
			if (itr != lst.end())
				++itr;
		}
	}

	//将一个集合里的所有项都改为一个特殊的值，typename可以写多个
	template <typename Container, typename Object>
	void change(Container &c, const Object& newValue) {
		//new iterator()
		typename Container::iterator itr = c.begin();
		while (itr != c.end())
			*itr++ = newValue;
	}

	//使用const iterator打印任意集合
	template <typename Container>
	void printCollection(const Container& c, ostrem &out = cout) {
		if (c.empty())
			out << "(empty)";
		else {
			typename Container::iterator itr = c.begin();
			out << "[" << *itr++; //Print first item

			while (itr != c.end())
				out << "," << *itr++;
			out << "]" << end; //Print last item
		}
	}

};


