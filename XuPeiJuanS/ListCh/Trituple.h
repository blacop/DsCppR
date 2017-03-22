#pragma once
#include "stdafx.h"

//稀疏矩阵美的声明
//三元组的结点类
template<typename T>
class Trituple {
	friend class SparseMatrix;
private:
	int row, col;
	T value;

public:

	Trituple() {}

	virtual ~Trituple() {}
};

