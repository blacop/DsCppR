#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE  -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
/*节点定义提示
#define Node		 TypeNode
#define LEN			 sizeof(Node)
#define MLC			 (Node *)malloc
#define MLCS	 	 (Node *)malloc(sizeof(Node))
*/
/*串的抽象数据类型的定义如下
//ADT String{
//数据对象： D = { a1|a1 ε CharacterSet, i = 1 , 2,… ，n, n>=O }
//数据关系：R1＝{ < ai-1 , ai> | ai-1 , ai εD, i = 2，…. ,n.}
//基本操作：{
	StrAssign(&T, chars) // Init方法
初始条件:charS是字符串常量．
操作结果:生成一个其值等于 charS的串T.
	StrCopy(&T，S)
初始条件: 串S存在．
操作结果:由串S复制得串T。
	StrEmpty(S)
初始条件g 串S存在．
操作结果:若S为空串，则返回TRUE，否则返回FALSE.
	StrCompare(S, T)
初始条件:串S和T存在
操作结果:若S> T，则返回值＞0;S=T，则返回值＝0；若S< T，则返回值＜ o.
	StrLength(S)
初始条件:串S存在．
操作结果:返回S的元素个数，称为串的长度．
	ClearString(&S)
初始条件:串S存在。
操作结果:将S清为空串。
	Concat(String &T, String S1, String S2)
初始条件:串S1和S2存在。
操作结果:用T返回S1和S2联接而成的新串．
	SubString(&Sub, S, pos, len)
初始条件:串S存在,1<=pos<=StrLength(S) 且 0<=len<=StrLength(S)-pos+1
操作结果:用Sub 返回串S的第pos个字符起长度为len的子串．
	Index(S, T, pos)
初始条件:串S和T存在，T是非空串,1<=pos<=StrLength(S) 。
操作结果: 主串S中存在和串T值相同的子串，
则返回它在主串S中第pos个字符之后第一次出现的位置；否则函数值为0.
	Replace(&S, T, V)
初始条件:串S,T,V存在，T是非空串。
操作结果＝用V替换主串S中出现的所有与T相等的不重叠的子串。
	StrInsert(&S, pos, T)
初始条件:串S和T存在,
操作结果:在串S的第pos个字符之前插入串T.
	StrDelete(&S，pos, len)
初始条件:串S存在
操作结果:从串S中删除第poS个子伺起长度为1团的子串。
	DestroyString(&S)
初始条件:串S存在。
操作结果:串S被销毁、
//	}
//}ADT String
*/
/*ADT串的抽象数据类型定义 简版
StrAssign(&T, chars) {}//串赋值
StrCopy(&T，S) {}//串复制
StrEmpty(S) {}//串空
StrCompare(S, T) {}//串比较
StrLength(S) {}//串长
ClearString(&S) {}//串清除
Concat(&T,S1,S2) {}//串连接
SubString(&Sub, S, pos, len) {}//求子串
Index(S, T, pos) {}//定位
Replace(&S, T, V) {}//串修改
StrInsert(&S, pos, T) {}//串插入
StrDelete(&S，pos, len) {}//串删除
DestroyString(&S) {}//串销毁
*/
/* c4-1.h 串的定长顺序存储表示 */
#define MAXSTRLEN 40 /* 用户可在255以内定义最大串长（1个字节） */
typedef char SString[MAXSTRLEN + 1]; /* 0号单元存放串的长度 */
typedef char String[MAXSTRLEN + 1];
//串不用封装结构体
Status StrAssign(SString T, char *chars) {
	/* 生成一个其值等于chars的串T */
	//StrAssign 就是Init方法 字符串分配	
	//实质是另一种 StrCopy()
	//SString T 指针引用,从外部传入
	//char *chars 指针引用,从外部传入
	//strlen 是C语言自带的strlength方法
	int i;
	if (strlen(chars) > MAXSTRLEN)
		return ERROR;
	else {
		T[0] = strlen(chars); //0号单元存放串的长度
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}/* 生成一个其值等于chars的串T */
Status StrCopy(SString T, SString S) { /* 由串S复制得串T */
	int i;
	for (i = 0; i <= S[0]; i++)
		T[i] = S[i];//Assign
	return OK;
}/* 由串S复制得串T */
Status StrEmpty(SString S) { // 若S为空串,则返回TRUE,否则返回FALSE
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}// 若S为空串,则返回TRUE,否则返回FALSE
int StrCompare(SString S, SString T) {
	// 初始条件: 串S和T存在									   
	// 操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; ++i)
		if (S[i] != T[i])
			return S[i] - T[i];//char值相减 ASCII值相减
	return S[0] - T[0];
}// 初始条件: 串S和T存在	
int StrLength(SString S) { // 返回串的元素个数
	return S[0];
}// 返回串的元素个数
Status ClearString(SString S) { // 初始条件:串S存在。操作结果:将S清为空串
	S[0] = 0;// 令串长为零
	return OK;
}// 初始条件:串S存在。操作结果:将S清为空串
Status Concat(SString T, SString S1, SString S2) // 算法4.2改
{ // 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE
	int i;
	if (S1[0] + S2[0] <= MAXSTRLEN) { // 未截断 //S1[0] =>strlen(S1) 求长度
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i]; //S1[0] =>strlen(S1) 求长度
		T[0] = S1[0] + S2[0];
		return TRUE;
	} else { // 截断S2
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= MAXSTRLEN - S1[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = MAXSTRLEN;
		return FALSE;
	}
}// 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE
Status SubString(SString Sub, SString S, int pos, int len) { // 用Sub返回串S的第pos个字符起长度为len的子串。算法4.3
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)//pos legal ,len legal
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub[i] = S[pos + i - 1];//Assign
	Sub[0] = len;
	return OK;
}// 用Sub返回串S的第pos个字符起长度为len的子串。算法4.3
/*这个大概是错的,逻辑太乱了
int Index(SString S, SString T, int pos) {
	//初始条件:串S和T存在，T是非空串, 1 <= pos <= StrLength(S) 。
	//操作结果 : 主串S中存在和串T值相同的子串，
	//则返回它在主串S中第pos个字符之后第一次出现的位置；否则函数值为0.
	//--------
	// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数值为0。
	// 其中,T非空,1≤pos≤StrLength(S)。算法4.5
	int i, j;
	if (1 <= pos&&pos <= S[0]) {
		i = pos;
		j = 1;
		while (i <= S[0] && j <= T[0])
			if (S[i] == T[j]) { // 继续比较后继字符
				++i;
				++j;
			} else { //不相等, 指针后退重新开始匹配
				i = i - j + 2;//pos-j+2,求range :range=pos-j+1, 去[0]
				j = 1;
			}
		if (j > T[0])
			return i - T[0];//
		else
			return 0;
	} else
		return 0;
}// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数值为0。
*/
int Index(String S, String T, int pos) {
	//初始条件:主串S和子串T存在，子串T是非空串, 1 <= pos <= StrLength(S) 。
	//操作结果 : 主串S中存在和子串T值相同的子串，
	//则返回它在主串S中第pos个字符之后第一次出现的位置；否则函数值为0.
	int n, m, i;
	String sub;
	if (pos > 0) {
		n = StrLength(S);//得主串S的长度
		m = StrLength(T);//得子串T的长度
		i = pos;
		while (i <= n - m + 1) {
			sub = SubString(sub, S, i, m); //从主串取子串
			if (StrCompare(sub, T) != 0) //子串不相等
				++i;
			else //子串相等
				return i;
		}
	}
	return 0; // 若无子串与T 相等,返回0
}
Status StrInsert(SString S, int pos, SString T) {
	// 初始条件: 串S和T存在,1≤pos≤StrLength(S)+1
	// 操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE
	int i;
	if (pos<1 || pos>S[0] + 1)
		return ERROR;
	if (S[0] + T[0] <= MAXSTRLEN) { // 完全插入
		for (i = S[0]; i >= pos; i--)
			S[i + T[0]] = S[i];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = S[0] + T[0];
		return TRUE;
	} else { // 部分插入
		for (i = MAXSTRLEN; i <= pos; i--)
			S[i] = S[i - T[0]];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAXSTRLEN;
		return FALSE;
	}
}

Status StrDelete(SString S, int pos, int len) {
	// 初始条件: 串S存在,1≤pos≤StrLength(S)-len+1												
	// 操作结果: 从串S中删除第pos个字符起长度为len的子串
	int i;
	if (pos<1 || pos>S[0] - len + 1 || len < 0)
		return ERROR;
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];
	S[0] -= len;
	return OK;
}

Status Replace(SString S, SString T, SString V) { // 初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关）
												  // 操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串
	int i = 1; // 从串S的第一个字符起查找串T
	if (StrEmpty(T)) // T是空串
		return ERROR;
	do {
		i = Index(S, T, i); // 结果i为从上一个i之后找到的子串T的位置
		if (i) // 串S中存在串T
		{
			StrDelete(S, i, StrLength(T)); // 删除该串T
			StrInsert(S, i, V); // 在原串T的位置插入串V
			i += StrLength(V); // 在插入的串V后面继续查找串T
		}
	} while (i);
	return OK;
}

void DestroyString() { // 由于SString是定长类型,无法销毁
}

void StrPrint(SString T) { // 输出字符串T。另加
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

