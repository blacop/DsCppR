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

////c++ lanmda写法 
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
//	//sum 初值为1
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

//最大子列和
//动态规划
//算法4 在线处理,T(N)=O(N)
//在线的意思是指每输入一个数据就进行即时处理，在任何一个地方中止输入，算法都能正确给出当前的解
int MaxSubsequSum4(int A[], int length) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < length; i++) {
		ThisSum += A[i]; //向右累加
		if (ThisSum > MaxSum) 
			MaxSum = ThisSum; //发现更大和则更新当前结果
		else if (ThisSum < 0) //如果当前子列和负
			ThisSum = 0; //则不可能使后面的部分和增大，抛弃之
	}
	return MaxSum;
}

//返回3个整数中的最大值
int Max3(int A, int B, int C) { /* 返回3个整数中的最大值 */
	return A > B ? A > C ? A : C : B > C ? B : C;
}

//分治法求List[left]到List[right]的最大子列和
int DivideAndConquer(int List[], int left, int right) { /* 分治法求List[left]到List[right]的最大子列和 */
	int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
	int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) { /* 递归的终止条件，子列只有1个数字 */
		if (List[left] > 0)  return List[left];
		else return 0;
	}

	/* 下面是"分"的过程 */
	center = (left + right) / 2; /* 找到中分点 */
								 /* 递归求得两边子列的最大和 */
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);

	/* 下面求跨分界线的最大子列和 */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* 从中线向左扫描 */
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* 左边扫描结束 */

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* 从中线向右扫描 */
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* 右边扫描结束 */

	  /* 下面返回"治"的结果 */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int List[], int N) { /* 保持与前2种算法相同的函数接口 */
	return DivideAndConquer(List, 0, N - 1);
}