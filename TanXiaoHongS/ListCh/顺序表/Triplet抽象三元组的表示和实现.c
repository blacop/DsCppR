//Common.h head
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Status int
#define ElemType int
typedef int Status
typedef int ElemType
#define LEN sizeof(ElemType)
#define MLC (ElemType *)malloc
#define MLCS (ElemType *)malloc(sizeof(ElemType))
#define MAX_SIZE 100;//表最大空间
#define LIST_INIT_SIZE = 100;//表初始分配空间
#define LIST_INCREMENT = 10;//空间分配增量
//Common.h end

//Triplet.h head
//抽象数据类型Triplet的表示和实现
//采用动态分配的顺序存储结构---
typedef ElemType * Triplet;//由InitTriplet分配3个元素存储空间
//--------------基本操作的函数，及说明----------------
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
//操作结果：构造了三元组T,元素e1,e2和e3的值分别被赋以参数v1，v2，v3的值。

Status DestroyTriplet(Triplet &T);
//操作结果：三元组T被销毁。

Status Get(Triplet T, int i, ElemType &e);
//初始条件：三元组T已存在，1<=i<=3。
//操作结果：用e返回T的第i元的值

Status Put(Triplet &T, int i, ElemType e);
//初始条件：三元组T已存在，1<=i<=3。
//操作结果：改变T的第i元的值为e。

Status IsAscending(Triplet T);
//初始条件：三元组T已存在。
//操作结果：如果三元组T的3个元素按升序排列，则返回1，否则返回0。

Status IsDescending(Triplet T);
//初始条件：三元组T已存在。
//操作结果：如果三元组T的3个元素按降序排列，则返回1，否则返回0。

Status Max(Triplet T, ElemType &e);
//初始条件：三元组T已存在。
//操作结果：用e返回T的3个元素中的最大值。

Status Min(Triplet T, ElemType &e);
//初始条件：三元组T已存在。
//操作结果：用e返回T的3个元素中的最小值。
//Triplet.h end

//Triplet.cpp head
#include <iostream>
#include <stdlib.h>
#include "Common.h"
#include "Triplet.h"
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{	//操作结果：构造了三元组T,元素e1,e2和e3的值分别被赋以参数v1，v2，v3的值。

	T = (ElemType *)malloc(3 * sizeof(ElemType));
	if (!T) exit(OVERFLOW);	//分配存储空间失败
	T[0] = v1; T[1] = v2; T[2] = v3;
	return OK;
} //InitTriplet

Status DestroyTriplet(Triplet &T)
{	//操作结果：三元组T被销毁。

	free(T);
	T = NULL;
	return OK;
} //DestroyTriplet

Status Get(Triplet T, int i, ElemType &e) {
	//用e返回T的第i元的值

	if (i<1 || i>3)
		return ERROR;
	e = T[i - 1];
	return OK;
} //Get

Status Put(Triplet &T, int i, ElemType e) {
	//1<=i<=3。
	//改变T的第i元的值为e。

	if (i<1 || i>3)
		return ERROR;
	T[i - 1] = e;
	return OK;
} // Put

Status IsAscending(Triplet T) {
	//如果三元组T的3个元素按升序排列，则返回1，否则返回0。

	return (T[0] >= T[1]) && (T[1] >= T[2]);
} //IsAscending

Status IsDescending(Triplet T) {
	//如果三元组T的3个元素按降序排列，则返回1，否则返回0。

	return (T[0] <= T[1]) && (T[1] <= T[2]);
} //IsDescending

Status Max(Triplet T, ElemType &e) {
	//用e返回T的3个元素中的最大值。

	e = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2]) : ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}

Status Min(Triplet T, ElemType &e) {
	//用e返回T的3个元素中的最小值。

	e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}
//Triplet.cpp end

//main.cpp head
#include <iostream>
#include <stdlib.h>
#include "Triplet.h"

int main()
{
	Triplet triplet;  //定义一个三元组
	ElemType  e;
	int i;

	InitTriplet(triplet, 4, 7, 5);

	for (i = 0; i<3; i++)
	{
		Get(triplet, i + 1, e);
		printf("%d %d\n", triplet[i], e);
	}

	e = 13;
	Put(triplet, 2, e);
	for (i = 0; i<3; i++)
		printf("%d ", triplet[i]);
	printf("\n");

	if (IsAscending(triplet))
		printf("升序\n");
	else {
		if (IsDescending(triplet))
			printf("降序\n");
		else
			printf("乱序\n");
	}

	Max(triplet, e);
	printf("最大值： %d\n", e);
	Min(triplet, e);
	printf("最小值： %d\n", e);

	system("pause");
	return 0;
}
//main.cpp end