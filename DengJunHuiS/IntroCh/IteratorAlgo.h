#pragma once
#include "stdafx.h"

//ö����
template <typename T, typename Container, typename Object>
class IteratorAlgo {
public:
	IteratorAlgo() {}
	virtual ~IteratorAlgo() {}

	//erase(), �Ա�lstʹ��erase() byö����
	//�ӱ����ʼ�ʼ�����ɾ����
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

	//��һ����������������Ϊһ�������ֵ��typename����д���
	template <typename Container, typename Object>
	void change(Container &c, const Object& newValue) {
		//new iterator()
		typename Container::iterator itr = c.begin();
		while (itr != c.end())
			*itr++ = newValue;
	}

	//ʹ��const iterator��ӡ���⼯��
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


