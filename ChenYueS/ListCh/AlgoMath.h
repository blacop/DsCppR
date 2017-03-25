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
