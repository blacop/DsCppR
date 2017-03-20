#include "stdafx.h"
#include "Trituple.h"
#pragma once
template<typename T>
class SparseMatrix {
private:
	int Rows, Cols, Count;
	Trituple<T> smArray[MaxTerm];//存储三元组表的数组
public:

	SparseMatrix() {}

	virtual ~SparseMatrix() {}
};

