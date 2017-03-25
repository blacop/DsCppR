#pragma once
#include "stdafx.h"

//��vectorʵ�־��� vector���α�����ģ�巺��
template <typename Object>
class Matrix {
private:
	//2ά�ľ���2ά��vector���飬vector����һ�ֶ�̬����
	vector<vector<Object>> array;
public:
	//constructor(), ������飨������
	Matrix(int rows, int cols) :array(rows) {
		for (int i = 0; i < rows; i++)
			//resize(),�ı䵱ǰʹ�����ݵĴ�С��������ȵ�ǰʹ�õĴ������Ĭ��ֵ
			array[i].resize(cols);
	}
	//���ز�����[],ʵ��������,�������ô�ֵ
	const vector<Object>& operator[](int row)const {
		return array[row];
	}
	//���ز�����[],ʵ��������,�������ô�ֵ
	vector<Object> & operator[](int row) {
		return array[row];
	}
	//Length()
	int numrows() const {
		//array.Length()
		return array.size();
	}
	//numcols()
	int numcols() const {
		//numrows() is true;
		return numrows() ? array[0].size() : 0;
	}
	//deconstructor()
	virtual ~Matrix() {}
	//copy()
	void copy(const Matrix<int>& from, Matrix<int>& to) {
		for (int i = 0; i < to.numrows; i++) {
			to[i] = from[i];
		}
	}
};


