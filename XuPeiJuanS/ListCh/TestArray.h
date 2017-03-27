#pragma once
class TestArray {
public:

	TestArray() {}

	virtual ~TestArray() {}
};

#include<iostream>
using namespace std;
int median(int n, int a[], int b[], int al, int ah, int bl, int bh) {
	int k = n / 2;
	if (a[(al + ah) / 2] == b[(bl + bh) / 2])	//两个数组中位数相等 
		return a[(al + ah) / 2];	cout << k << al << ah << bl << bh << endl;
	if ((al == ah) && (bl == bh))	//终止条件 子问题规模等于1的时候 
		return a[al] > b[bl] ? a[al] : b[bl];
	if (a[(al + ah) / 2] < b[(bl + bh) / 2])	//A[k]<B[k]
		return median(k, a, b, (al + ah) / 2, (al + ah) / 2 + k, (bl + bh) / 2 - k, (bl + bh) / 2);
	if (a[(al + ah) / 2] > b[(bl + bh) / 2])	//A[k]>B[k]
		return median(k, a, b, (al + ah) / 2 - k, (al + ah) / 2, (bl + bh) / 2, (bl + bh) / 2 + k);
}
int main() {
	int n, i, A[100], B[100];
	cout << "Enter n\nn=";	//输入数组大小n=5
	cin >> n;
	cout << "Enter A[n]...\n";	//输入已排序数组A={1,3,5,7,9}
	for (i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << "Enter B[n]...\n";
	for (i = 0; i < n; i++) {	//输入已排序数组B={2,4,6,8,10}
		cin >> B[i];
	}
	if (n == 1 && A[0] < B[0])	//n=1的情况 
		cout << A[0] << endl;
	if (n == 1 && A[0] > B[0])
		cout << B[0] << endl;
	if (n != 1)
		cout << median(n, A, B, 0, n - 1, 0, n - 1) << endl;
	return 0;

	int m = 10, n = 10;
	int* a[m][n] = new int[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", a[][])
		}
	}
}

