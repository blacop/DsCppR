#pragma once
#include "stdafx.h"
#include "Array.h"

template<typename T>
class Algo {
public:
	Algo() {}
	virtual ~Algo() {}
};

//����,��дģ�巺�;ͻᱨ��û������
template<typename T>
void multiple(void) {
	Array<int> A(10); //����洢������
	int N, count = 0; //N�Ǳ�������
	cout << "N=?";
	cin >> N;
	for (int i = 5; i <= N; i++) {
		if (count == A.ListSize()) { //����
			A.Resize(count + 10);
		}
		if (i % 5 == 0 || i % 7 == 0) { //ȡ5 ��7 �ı���
			A[count++] = i; //��ֵ
		}
	}
	for (int j = 0; j < count; j++) { //�������
		//T temp = A[j]; //��дģ�巺�;ͻᱨ��û������
		cout << A[j] << " ";
		if ((j + 1) % 5 == 0)
			cout << endl;
	}
}//!_void multiple(void)


