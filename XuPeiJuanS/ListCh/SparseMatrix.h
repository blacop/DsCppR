#pragma once
#include "stdafx.h"
#include "Trituple.h"

template<typename T>
class SparseMatrix {
private:
	int MaxTerm;
	int Rows, Cols, Count;
	Trituple<T> smArray[MaxTerm];//�洢��Ԫ��������
public:
	//����һ��ϡ�����
	SparseMatrix(int Mrows = 10, int Mcols = 10) {}
	//����һ��ϡ�����
	SparseMatrix(int Mrows = 10, int Mcols = 10, int MSize = 10) :Rows(Mrows), Cols(Mcols), MaxTerm(MSize) {}
	//DE����һ��ϡ�����
	virtual ~SparseMatrix() {}
	//��ת�þ���
	SparseMatrix<T> Transpose();
	//�����ĺ�
	SparseMatrix<T> Add(SparseMatrix<T> b);
	//�����ĳ˻�
	SparseMatrix<T> Multiply(SparseMatrix<T> b);
	
};//!_class SparseMatrix

  //��ת�þ���
template<typename T>
inline SparseMatrix<T> SparseMatrix<T>::Transpose() {
	SparseMatrix<T> b; //תְ��ľ��� Rst Matrix
	b.Rows = this.Cols;
	b.Cols = this.Rows;
	b.Count = this.Count;
	if (Count > 0) {
		int Bnumber = 0;
		for (int k = 0; k < this.Cols; k++) { //Traverse Src Matrix's Cols Field
			for (int i = 0; i < this.Count; i++) { // Src's count limit this Cols
				if (this.smArray[Bnumber].col == k) { //src[bIndex].col== src.Cols filed Trav limit, src[index].col value limt == Src's Field Cols' value limt ,promise Asc Order Append to rst.,��֤ԭ����˳���col����Ϊ0��ʼ����������
					b.smArray[Bnumber].row = k; //Rst Matrix obj.row = Src.col
					b.smArray[Bnumber].col = this.smArray[i].row; //traverse copy :rst.col = src[i].row
					b.smArray[Bnumber].value = this.smArray[i].value; //traverse copy: rst from src. 
					Bnumber++;
				}
			}
		}
	}
	return b;//����ת�þ���b
}
