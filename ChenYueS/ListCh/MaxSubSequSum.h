#pragma once
#include "stdafx.h"

//class MaxSubSequSum {
//public:
//
//	MaxSubSequSum() {}
//
//	virtual ~MaxSubSequSum() {}
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
