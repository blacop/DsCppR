#pragma once
#include "stdafx.h"

//用vector实现矩阵， vector传参必须用模板泛型
template <typename Object>
class matrix {
private:
	//2维的矩阵，2维的vector数组，vector就是一种动态数组
	vector<vector<Object>> array;
public:
	//constructor(), 填充数组（行数）
	matrix(int rows, int cols) :array(rows) {
		for (int i = 0; i < rows; i++)
			//resize(),改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
			array[i].resize(cols);
	}
	//重载操作符[],实现索引器,常量引用传值
	const vector<Object>& operator[](int row)const {
		return array[row];
	}
	//重载操作符[],实现索引器,变量引用传值
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
	virtual ~matrix() {}
	//copy()
	void copy(const matrix<int>& from, matrix<int>& to) {
		for (int i = 0; i < to.numrows; i++) {
			to[i] = from[i];
		}
	}
};

