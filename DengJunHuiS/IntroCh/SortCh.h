#pragma once
class SortCh {
public:
	SortCh() {}
	virtual ~SortCh() {}
};

inline void bubblesort1A(int A[], int n) { //起泡排序算法（版本1A）：0 <= n
	bool sorted = false; //整体排序标志，首先假定尚未排序
	while (!sorted) { //在尚未确讣已全尿排序乀前，逐趟迕行扫描交换
		sorted = true; //假定已经排序
		for (int i = 1; i < n; i++) { //自左向右逐对检查弼前范围A[0, n)内癿各相邻元素
			if (A[i - 1] > A[i]) { //一旦A[i - 1]不A[i]逆序，则
				swap(A[i - 1], A[i]); //交换乀，幵
				sorted = false; //因整体排序丌能保证，需要清除排序标志
			}
		}
		n--; //至此末元素必然就位，故可以缩短待排序序列癿有效长度
	}
}//倚劣布尔型标志位sorted，可及时提前退出，而丌致总是蛮力地做n - 1趟扫描交换

inline static int swapXor(int &a, int &b) {
	//Xor Swap Method
	a ^= b;//a=a^b,temp mid data
	b ^= a;//b=b^a^b=a //b=>b^a^b=>a，一个数异或2次 是自身
	a ^= b;//a=a^b //a==a^b^b==a
}
inline static int swap(int &a, int &b) {
	//ref value Swap Method
	int temp;
	temp = b;
	b = a;
	a = temp;
}

//1.3.1 常数O(1)
//考查如下常规元素的选取问题，该问题一种解法如算法1.3所示
//ordinaryElement(S[], n) //从n  3个互异整数中，除最大、最小者以外，取一个“元素”
//三个元素x, y, z  S; //三个元素亦必互异
//通过比较，对它们做排序; //经排序后，依次重命名为：a < b < c
//输出b;

//1.3.2 对数O(logn)
//考查如下问题：对于任意非负整数，统计其二进制展开中数位1的总数。
int countOnes(unsigned int n) { //统计整数n癿二迕刢展开中数位1癿总数：O(logn)
	int ones = 0; //计数器复位
	while (0 < n) { //在n缩减至0乀前，反复地
		ones += (1 & n); //检查最低位，若为1则计数
		n >>= 1; //右秱一位		
	}
	return ones; //迒回计数	
} //等效亍glibc癿内置函数int __builtin_popcount (unsigned int n)

//1.3.3 线性O(n)
//考查如下问题：计算给定n个整数的总和。该问题可由代码1.3中的算法sumI()解决。
int sumI(int A[], int n) { //数组求和算法（迭代版）
	int sum = 0; //刜始化累计器，O(1)
	for (int i = 0; i < n; i++) //对全部共O(n)个元素，逐一
		sum += A[i]; //累计，O(1)
	return sum; //迒回累计值，O(1)
} //O(1) + O(n)*O(1) + O(1) = O(n+2) = O(n)

//1.3.5 指数O(2^n)
// 问题与算法
//考查如下问题：在禁止超过1位的移位运算的前提下，对任意非负整数n，计算幂2n。
__int64 power2BF_I(int n) { //幂函数2^n算法（蛮力迭代版），n >= 0
	__int64 pow = 1; //O(1)：累积器刜始化为2^0
	while (0 < n--) //O(n)：迭代n轮，每轮都--
		pow <<= 1; //O(1)：将累积器翻倍
	return pow; //O(1)：返回累积器
} //O(n) = O(2^r)，r为输入指数n的比特位数
//如代码1.4所示的算法power2BF_I()由n轮迭代组成，各需做一次累乘和一次递减，均属于
//基本操作，故整个算法共需O(n)时间。若以输入指数n的二进制位数r = 1 + log2n作为输入
//规模，则运行时间为O(2r)。稍后在1.4.3节我们将看到，该算法仍有巨大的改进余地。
//一般地，凡运行时间可以表示和度量为T(n) = O(an)形式的算法（a > 1），均属于“指
//数时间复杂度算法”（exponential - time algorithm）。

//图1.5 复杂度癿典型局次：(1)~(7)依次为O(logn)、O(2^/``n)、O(n)、O(nlogn)、O(n^2)、O(n^3)和O(2^n)
//利用大O记号，不仅可以定量地把握算法复杂度的主要部分，而且可以定性地由低至高将复
//杂度划分为若干层次。典型的复杂度层次包括O(1)、O(log*n)、O(loglogn)、O(logn)、
//O(sqrt(n))、O(n)、O(nlog*n)、O(nloglogn)、O(nlogn)、O(n2)、O(n3)、O(nc)、O(2n)
//等，图1.5绘出了其中七个层次复杂度函数对应的渐进增长趋势。
//§1.4 *逑弻 第1章 绪讳
//16
//请注意，在图1.5的左图中，层次(7)的2n显得比层次(6)的n3更低，但这只是在问题规模n
//较小时的暂时现象。从覆盖更大范围的右图可以看出，当问题规模不小于10之后，层次(7)的复
//杂度将远远高于层次(6)。另外，右图还采用了双对数坐标，将层次(6)、(5)、(3)和(2)表示
//为直线，从而更为清晰地显示出各层次之间的高低关系。