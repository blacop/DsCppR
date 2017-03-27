#include<stdio.h>
int chess[8][8] = { 0 };
int a[8], b[15], c[15];
int sum = 0;                                            //统计所有摆法
void PutQueen(int n) { //n => row 行,col列
	int col, i, j;
	for (col = 0; col < 8; col++) {
		if (a[col] && b[n + col] && c[n - col + 7])                 //判断安全位置
		{
			chess[n][col] = 1;                            //放置皇后
			a[col] = 0;
			b[n + col] = 0;
			c[n - col + 7] = 0;
			if (n == 7) {
				sum++;
				printf("第%d种可能的摆法:/n", sum);    //输出皇后摆法
				for (i = 0; i < 8; i++) {
					printf("/t/t");
					for (j = 0; j < 8; j++)
						printf("%d ", chess[i][j]);
					printf("/n");
				}
				printf("/n");
				//					goto END;                         //输出第一种摆法
				if (sum % 10 == 0)                     //每输出十种暂停
				{
					printf("按回车键继续……");
					getchar();
				}
			} else
				PutQueen(n + 1);                        //递归
			chess[n][col] = 0;                            //取消皇后
			b[n + col] = 1;
			c[n - col + 7] = 1;
			a[col] = 1;
		}
	}
	//END:	return;
}
int main() {
	int i;
	for (i = 0; i < 8; ++i)
		a[i] = 1;
	for (i = 0; i < 15; ++i) {
		b[i] = 1;
		c[i] = 1;
	}
	PutQueen(0);
	printf("八皇后摆法总数: %d/n", sum);
	return 0;
}
