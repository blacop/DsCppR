#include "stdafx.h"
#include "Trituple.h"
#pragma once
template<typename T>
class SparseMatrix {
private:
	int Rows, Cols, Count;
	Trituple<T> smArray[MaxTerm];//�洢��Ԫ��������
public:

	SparseMatrix() {}

	virtual ~SparseMatrix() {}
};

