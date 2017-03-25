#pragma once
#include "stdafx.h"
#define MAXK 1e7
//class AlgoMath {
//public:
//	AlgoMath() {}
//	virtual ~AlgoMath() {}
//};

//级数求和
//伪 lanmda 写法 
//double Series=（double base, int limit, int Constant） => int constant + sigma{ base^i / i | (1 <= i <= 100) };
//Constant 常数项 , base 底数，limit 极限上界
double Series(double base, int limit, int Constant) {
	double sum = 0.0;
	int i;
	//limit is 1 to 100
	for (i = 1; i <= limit; i++) {
		sum += pow(base, i) / i;
	}
	//sum 初值为1
	sum += Constant;
	return sum;
}
//级数求和,WithTemp
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

//C#级数求和,
//伪 lanmda 写法 
//double Series=（double base, int limit, int Constant） => int constant + sigma{ base^i / i | (1 <= i <= 100) };
//Constant 常数项 , base 底数，limit 极限上界
//double Series(double baseX, int limit, int Constant) {
//    double sum = 0.0;
//    int i;
//    //limit is 1 to 100
//    for (i = 1; i <= limit; i++) {
//        sum += Math.Pow(baseX, i) / i;
//    }
//    //sum 初值为1
//    sum += Constant;
//    return sum;
//}

////C# lanmda mySeries写法
////级数求和 C#真lanmda写法
////Constant 常数项, base 底数，limit 极限上界
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
//	//sum 初值为1
//	sum += Constant;
//	return sum;
//};
