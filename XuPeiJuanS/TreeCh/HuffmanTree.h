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
}HTNode, *HuffmanTree; //动态分配数组存储哈夫曼树
typedef char** HuffmanCode; //动态分配哈夫曼编码表

////构造哈夫曼树，求哈夫曼编码的算法
//void HuffmanCoding(HuffmanTree &HT, HuffmanCode &Hc, int *w, int n) {
//	//n=>length, int *w 存放n个字符的权值,*w是一个数组
//	//构造哈夫曼树Ht,求n个字符的哈夫曼密码编码表Hc
//
//	//如果长度是1,则返回
//	if (n <= 1) return;
//	//m是总的存储空间
//	int m = 2 * (n - 1); // n个字符 生成的哈夫曼树 就会有总共（2*n-1）个结点 n个叶子结点	+(n-1)个2度结点
//	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); //开辟内存
//	//声明临时变量
//	HuffmanTree p;
//	int i;
//	//初始化 前面的n个存储单元
//	//此循环表示把权值*w赋值给每一个结点
//	for (p = HT, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
//	//初始化 后面的n-1个存储单元
//	//前面的for循环结束后，i接着上面的继续
//	//把剩下的结点赋值成 0
//	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
//	//构造哈夫曼树 最小的两个结点 的下标
//	int s1, s2;
//	//构造哈夫曼树
//	for (i = n + 1; i <= m; ++i) {
//		select(HT, i - 1, s1, s2); //选择parent为0且权值最小的两个结点：s1,s2
//		HT[s1].parent = i; HT[s2].parent = i;
//		HT[i].lchild = s1; HT[i].rchild = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;
//	}
//}

void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n) /* 算法6.12 */
{ /* w存放n个字符的权值(均>0),构造赫夫曼树HT,并求出n个字符的赫夫曼编码HC */

	int m, i, s1, s2, start;
	unsigned c, f;
	HuffmanTree p;
	char *cd;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); /* 0号单元未用 */
	for (p = *HT + 1, i = 1; i <= n; ++i, ++p, ++w) {
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p)
		(*p).parent = 0;
	for (i = n + 1; i <= m; ++i) /* 建赫夫曼树 */
	{ /* 在HT[1~i-1]中选择parent为0且weight最小的两个结点,其序号分别为s1和s2 */
		select(*HT, i - 1, &s1, &s2);
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	/* 从叶子到根逆向求每个字符的赫夫曼编码 */
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	/* 分配n个字符编码的头指针向量([0]不用) */
	cd = (char*)malloc(n * sizeof(char)); /* 分配求编码的工作空间 */
	cd[n - 1] = '\0'; /* 编码结束符 */
	for (i = 1; i <= n; i++) { /* 逐个字符求赫夫曼编码 */
		start = n - 1; /* 编码结束符位置 */
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)
			/* 从叶子到根逆向求编码 */
			if ((*HT)[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));
		/* 为第i个字符编码分配空间 */
		strcpy((*HC)[i], &cd[start]); /* 从cd复制编码(串)到HC */
	}
	free(cd); /* 释放工作空间 */
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

void select(HuffmanTree t, int i, int *s1, int *s2) { /* s1为最小的两个值中序号小的那个 */
	int j;

	*s1 = min1(t, i);
	*s2 = min1(t, i);
	if (*s1 > *s2) {
		j = *s1;
		*s1 = *s2;
		*s2 = j;
	}
}

//找到最小值
int min1(HuffmanTree t, int i) { /* 函数void select()调用 */
	int j, flag;
	unsigned int k = UINT_MAX; /* 取k为不小于可能的值 */
	for (j = 1; j <= i; j++)
		if (t[j].weight < k && t[j].parent == 0)
			k = t[j].weight, flag = j;
	t[flag].parent = 1;
	return flag;
}
