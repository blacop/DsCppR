// TreeCh.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef struct node {
	int a; //4个字节
	double b; //8个字节
}qnode, *qnodePtr;
qnodePtr k = (qnode*)malloc(sizeof(qnode)); //12个字节

int main()
{	
    return 0;
}

