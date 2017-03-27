#include <stdio.h>
#include <stdlib.h>

#define max 8

int queen[max], sum = 0; /* maxΪ����������� */

void show() /* ������лʺ������ */
{
	int i;//controled limit
	for (i = 0; i < max; i++) {
		printf("(%d,%d) ", i, queen[i]);
	}
	printf("\n");
	sum++;
}

int check(int n) /* ��鵱ǰ���ܷ���ûʺ�,nΪ�ⲿ��κ����� */
{
	int i;//controled limit
	for (i = 0; i < n; i++) /* �����źͶԽ������Ƿ���Է��ûʺ� */
	{
		if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i)) {
			return 1;
		}//queen[i] == queen[n]��ʾ
	}
	return 0;
}

void put(int n) /* ���ݳ��Իʺ�λ��,nΪ������ */
{
	int i;//controled limit
	for (i = 0; i < max; i++) {
		queen[n] = i; /* ���ʺ�ڵ���ǰѭ������λ�� */
		if (!check(n)) {
			if (n == max - 1) {
				show(); /* ���ȫ���ںã���������лʺ������ */
			} else {
				put(n + 1); /* ��������ڷ���һ���ʺ�,�ݹ���� */
			}
		}
	}
}

int main() {
	put(0); /* �Ӻ�����Ϊ0��ʼ���γ��� */
	printf("%d", sum);
	return 0;
}