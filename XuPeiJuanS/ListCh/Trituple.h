#include "stdafx.h"

#pragma once
//ϡ�������������
//��Ԫ��Ľ����
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

