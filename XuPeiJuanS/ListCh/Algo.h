#include "stdafx.h"
#include "Array.h"
#pragma once
class Algo {
public:
	Algo() {}
	virtual ~Algo() {}
};

//����
void multiple(void) {
	Array<int> A(10);
	int N, count = 0;
	cout << "N=?";
	cin >> N;

	for (int i = 5; i <= N; i++) {
		if (count == A.ListSize()) { //����
			A.Resize(count + 10);
		}
		if (i % 5 == 0 || i % 7 == 0) { //ȡ5 ��7 �ı���
			A[count++] = i;
		}
	}
	for (int j = 0; j < cout; j++) { //�������
		cout << A[j] << " ";
		if ((j + 1) % 5 == 0)
			cout << endl;
	}

}//!_void multiple(void)
