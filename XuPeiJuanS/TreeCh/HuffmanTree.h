#pragma once
#include "stdafx.h"
//class HuffmanTree {
//public:
//
//	HuffmanTree() {}
//
//	virtual ~HuffmanTree() {}
//};

typedef struct HTNode {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree; //��̬��������洢��������
typedef char** HuffmanCode; //��̬��������������

////��������������������������㷨
//void HuffmanCoding(HuffmanTree &HT, HuffmanCode &Hc, int *w, int n) {
//	//n=>length, int *w ���n���ַ���Ȩֵ,*w��һ������
//	//�����������Ht,��n���ַ��Ĺ�������������Hc
//
//	//���������1,�򷵻�
//	if (n <= 1) return;
//	//m���ܵĴ洢�ռ�
//	int m = 2 * (n - 1); // n���ַ� ���ɵĹ������� �ͻ����ܹ���2*n-1������� n��Ҷ�ӽ��	+(n-1)��2�Ƚ��
//	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); //�����ڴ�
//	//������ʱ����
//	HuffmanTree p;
//	int i;
//	//��ʼ�� ǰ���n���洢��Ԫ
//	//��ѭ����ʾ��Ȩֵ*w��ֵ��ÿһ�����
//	for (p = HT, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
//	//��ʼ�� �����n-1���洢��Ԫ
//	//ǰ���forѭ��������i��������ļ���
//	//��ʣ�µĽ�㸳ֵ�� 0
//	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
//	//����������� ��С��������� ���±�
//	int s1, s2;
//	//�����������
//	for (i = n + 1; i <= m; ++i) {
//		select(HT, i - 1, s1, s2); //ѡ��parentΪ0��Ȩֵ��С��������㣺s1,s2
//		HT[s1].parent = i; HT[s2].parent = i;
//		HT[i].lchild = s1; HT[i].rchild = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;
//	}
//}

void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n) /* �㷨6.12 */
{ /* w���n���ַ���Ȩֵ(��>0),����շ�����HT,�����n���ַ��ĺշ�������HC */

	int m, i, s1, s2, start;
	unsigned c, f;
	HuffmanTree p;
	char *cd;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); /* 0�ŵ�Ԫδ�� */
	for (p = *HT + 1, i = 1; i <= n; ++i, ++p, ++w) {
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p)
		(*p).parent = 0;
	for (i = n + 1; i <= m; ++i) /* ���շ����� */
	{ /* ��HT[1~i-1]��ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2 */
		select(*HT, i - 1, &s1, &s2);
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	/* ��Ҷ�ӵ���������ÿ���ַ��ĺշ������� */
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	/* ����n���ַ������ͷָ������([0]����) */
	cd = (char*)malloc(n * sizeof(char)); /* ���������Ĺ����ռ� */
	cd[n - 1] = '\0'; /* ��������� */
	for (i = 1; i <= n; i++) { /* ����ַ���շ������� */
		start = n - 1; /* ���������λ�� */
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)
			/* ��Ҷ�ӵ������������ */
			if ((*HT)[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));
		/* Ϊ��i���ַ��������ռ� */
		strcpy((*HC)[i], &cd[start]); /* ��cd���Ʊ���(��)��HC */
	}
	free(cd); /* �ͷŹ����ռ� */
}


void HuffmanCoding2(HuffmanTree &HT, HuffmanCode&HC, int *w, int n) //sub-function
{
	int m, i, s1, s2, start, c, f;
	HuffmanTree p;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)	//initial HT[1...n]
	{
		p->weight = *w;
		cout << endl << "HT[" << i << "].weight=" << p->weight << "  ";
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (; i <= m; ++i, ++p)			//initial HT[n+1...2*n1]
	{
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	cout << endl << endl << "HuffmanTree is created in folowing order :";
	for (i = n + 1; i <= m; ++i) {
		Select(HT, i - 1, s1, s2);	//s1 is the least, s2 is the second least
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		cout << endl << "HT[" << s1 << "] and HT[" << s2 << "] create";
		cout << " HT[" << i << "], weight=" << HT[i].weight;
	}
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	char *cd;
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	cout << endl << endl << "HuffmanTree Code is as follows :" << endl;
	for (i = 1; i <= n; ++i) {
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
		printf("\nHT[%d] node's Huffman code is: %s", i, HC[i]);
	}
	free(cd);
} //HuffmanCoding() end

void Select(HuffmanTree HT, int i, int &s1, int &s2)  //Select sub-function
{
	int j, k = 1;                	//s1 is the least of HT[].weight
	while (HT[k].parent != 0)	//s2 is the second least of HT[].weight
		k++;
	s1 = k;
	for (j = 1; j <= i; ++j)
		if (HT[j].parent == 0 && HT[j].weight<HT[s1].weight)
			s1 = j;
	k = 1;
	while ((HT[k].parent != 0 || k == s1))
		k++;
	s2 = k;
	for (j = 1; j <= i; ++j)
		if (HT[j].parent == 0 && HT[j].weight<HT[s2].weight&&j != s1)
			s2 = j;
} //Select() end

void select(HuffmanTree t, int i, int *s1, int *s2) { /* s1Ϊ��С������ֵ�����С���Ǹ� */
	int j;

	*s1 = min1(t, i);
	*s2 = min1(t, i);
	if (*s1 > *s2) {
		j = *s1;
		*s1 = *s2;
		*s2 = j;
	}
}

//�ҵ���Сֵ
int min1(HuffmanTree t, int i) { /* ����void select()���� */
	int j, flag;
	unsigned int k = UINT_MAX; /* ȡkΪ��С�ڿ��ܵ�ֵ */
	for (j = 1; j <= i; j++)
		if (t[j].weight < k && t[j].parent == 0)
			k = t[j].weight, flag = j;
	t[flag].parent = 1;
	return flag;
}
