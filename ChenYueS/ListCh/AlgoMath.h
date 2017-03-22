#pragma once
#include "stdafx.h"
#define MAXK 1e7
//class AlgoMath {
//public:
//	AlgoMath() {}
//	virtual ~AlgoMath() {}
//};

//�������
//α lanmda д�� 
//double Series=��double base, int limit, int Constant�� => int constant + sigma{ base^i / i | (1 <= i <= 100) };
//Constant ������ , base ������limit �����Ͻ�
double Series(double base, int limit, int Constant) {
	double sum = 0.0;
	int i;
	//limit is 1 to 100
	for (i = 1; i <= limit; i++) {
		sum += pow(base, i) / i;
	}
	//sum ��ֵΪ1
	sum += Constant;
	return sum;
}
//�������,WithTemp
double SeriesHaveTemp(int Constant, double base, int limit) {
	double sum = 1.0;
	double temp = 1;
	int i;
	//limit is 1 to 100
	for (i = 1; i <= limit; i++) {
		temp = pow(base, i);
		sum = sum + temp / i;
	}
	return sum;
}

////c++ lanmdaд�� 
//double base;
//double sum = 0.0;
//int limit, int Constant;
//double Series = [&](double base, int limit, int  Constant) -> double {
//	sum = 0.0;
//	int i;
//	//limit is 1 to 100
//	for (i = 1; i <= limit; i++) {
//		sum += pow(base, i) / i;
//	}
//	//sum ��ֵΪ1
//	sum += Constant;
//	return sum;
//}

//void main() {
//	int i;
//	clock_t start, end;
//	double duration;//used to stored top - end
//	start = clock();
//	for (i = 0; i < MAXK; i++) {
//		fun1(1.1, 100);
//	}
//	end = clock();
//	duration = ((double)(end - start)) / CLK_TCK / MAXK;
//	printf("every method fun1 using average time:%f\n", duration);
//
//	start = clock();
//	for (i = 0; i < MAXK; i++) {
//		fun2(1.1, 100);
//	}
//	end = clock();
//	duration = ((double)(end - start)) / CLK_TCK / MAXK;
//	printf("every method fun2 using average time:%f\n", duration);
//
//}

//C#�������,
//α lanmda д�� 
//double Series=��double base, int limit, int Constant�� => int constant + sigma{ base^i / i | (1 <= i <= 100) };
//Constant ������ , base ������limit �����Ͻ�
//double Series(double baseX, int limit, int Constant) {
//    double sum = 0.0;
//    int i;
//    //limit is 1 to 100
//    for (i = 1; i <= limit; i++) {
//        sum += Math.Pow(baseX, i) / i;
//    }
//    //sum ��ֵΪ1
//    sum += Constant;
//    return sum;
//}

////C# lanmda mySeriesд��
////������� C#��lanmdaд��
////Constant ������, base ������limit �����Ͻ�
//double baseX;
//int limit;
//int Constant;
//delegate double del(double baseX, int limit, int Constant);
//del mySeries = (baseX, limit, Constant) = > {
//	double sum = 0.0;
//	int i;
//	// limit is 1 to 100
//	for (i = 1; i <= limit; i++) {
//		sum += Math.Pow(baseX, i) / i;
//	}
//	//sum ��ֵΪ1
//	sum += Constant;
//	return sum;
//};

//������к�
//��̬�滮
//�㷨4 ���ߴ���,T(N)=O(N)
//���ߵ���˼��ָÿ����һ�����ݾͽ��м�ʱ�������κ�һ���ط���ֹ���룬�㷨������ȷ������ǰ�Ľ�
int MaxSubsequSum4(int A[], int length) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < length; i++) {
		ThisSum += A[i]; //�����ۼ�
		if (ThisSum > MaxSum) 
			MaxSum = ThisSum; //���ָ��������µ�ǰ���
		else if (ThisSum < 0) //�����ǰ���к͸�
			ThisSum = 0; //�򲻿���ʹ����Ĳ��ֺ���������֮
	}
	return MaxSum;
}

//����3�������е����ֵ
int Max3(int A, int B, int C) { /* ����3�������е����ֵ */
	return A > B ? A > C ? A : C : B > C ? B : C;
}

//���η���List[left]��List[right]��������к�
int DivideAndConquer(int List[], int left, int right) { /* ���η���List[left]��List[right]��������к� */
	int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
	int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) { /* �ݹ����ֹ����������ֻ��1������ */
		if (List[left] > 0)  return List[left];
		else return 0;
	}

	/* ������"��"�Ĺ��� */
	center = (left + right) / 2; /* �ҵ��зֵ� */
								 /* �ݹ�����������е����� */
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);

	/* �������ֽ��ߵ�������к� */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* ����������ɨ�� */
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* ���ɨ����� */

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* ����������ɨ�� */
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* �ұ�ɨ����� */

	  /* ���淵��"��"�Ľ�� */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int List[], int N) { /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
	return DivideAndConquer(List, 0, N - 1);
}