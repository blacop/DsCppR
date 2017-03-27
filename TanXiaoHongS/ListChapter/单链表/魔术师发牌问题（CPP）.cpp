/***************************************************
*CopyRight(C)2016年6月14日14:56:54
*Author:邱于涵
*Blog:博客：http://blog.csdn.net/u012997311
*问题名称：魔术师发牌问题
*问题描述：魔术师手里一共有13张牌，全是黑桃，1~13.
*********魔术师需要实现一个魔术：这是十三张牌全部放在桌面上（正面向下），
********第一次摸出第一张，是1，翻过来放在桌面上。
******第二次摸出从上往下数第二张，是2，翻过来 放在桌面上，（第一张放在最下面去，等会儿再摸），
*****第三次摸出从上往下数第三张，是3，翻过来放在桌面上，（第一张和第二张 放在最下面去，等会儿再摸）
***  以此类推 最后一张就是13
*******************************************************/
#include<iostream>  
using namespace std;
/**********************************************************
*数据储存结构：循环链表
**********************************************************/
typedef struct PokeNode {
	int data;//牌的内容  
	PokeNode * nextPtr;// 指针|下一个结点  
}PokeNode;
/**********************************************************
*创建循环链表
**********************************************************/
PokeNode * create(int amount)  //新建牌组13张
{  //amount 是13张
	if (amount <= 0)
		return 0;
	if (amount == 1) {
		PokeNode * Node = new PokeNode;//开辟新结点
		Node->data = 1;  //赋值
		Node->nextPtr = Node;  //指针下移
		return Node;
	} else {     //not 1
		PokeNode * head = new PokeNode;//开辟新结点
		head->data = 0;//head->data = 1; 
		head->nextPtr = head;
		//|上一个结点  
		PokeNode * preNode = head;
		//|当前结点  
		PokeNode * nowNode = 0;
		//|计数  
		int i = 2;  //牌面
		while (i <= amount) {
			nowNode = new PokeNode;
			nowNode->data = 0;//nowNode->data = i;  
							  //|下一个结点为头结点  
			nowNode->nextPtr = head;
			//|插入到上一个结点（尾结点的位置）  
			preNode->nextPtr = nowNode;
			//|当前结点为preNode;  
			preNode = nowNode;
			//|递增（迭代）  
			++i;
		}
		return head;
	}
}
/**********************************************************
*遍历输出（这个主要用于调试）
**********************************************************/
void echoEach(PokeNode * p) {
	PokeNode * head = p;
	cout << p->data << endl;
	PokeNode * tmp = head->nextPtr;
	while (tmp != head) {
		cout << tmp->data << endl;
		//|迭代  
		tmp = tmp->nextPtr;
	}
}
/**********************************************************
*魔术师（发牌顺序）
**********************************************************/
void Magician(PokeNode * head, int amount) {
	//amount 为扑克牌数量 其实 这里可以直接 计算数量的为了 算法的空间复杂度就直接代入好了    
	//|设置扑克牌顺序  
	int i = 1;
	/*************************************************************************
	*需要设置一个临时前缀 类似没有用的 Head头指针
	*用于方便迭代遍历  第一次循环一次 ，第二次循环两次，第三次循环三次
	*如果不这样做的话 就是 第一次循环0次，第二次循环2次，就不好设置
	*****************************************************************************/
	PokeNode * tmpprefix = new PokeNode;
	tmpprefix->nextPtr = head;
	PokeNode * tmp = tmpprefix;
	while (i <= amount) {
		for (int j = 0; j < i; j++) {
			//|迭代  
			tmp = tmp->nextPtr;
			//|如果下一张牌 拿出去了（标上数字了），就需要再循环--j（意思是多循环一次）.  
			if (tmp->data != 0)
				j = j - 1;
		}
		tmp->data = i;
		//|迭代  
		++i;
	}
	delete tmpprefix;
	//|输出扑克牌顺序  

	cout << "扑克牌摆放顺序：";
	tmp = head->nextPtr;
	cout << "黑桃" << head->data << ",";
	while (tmp != head) {
		cout << "黑桃" << tmp->data << ",";
		tmp = tmp->nextPtr;
	}
}
/**********************************************************
*销毁函数
**********************************************************/
void destory(PokeNode *head) {
	if (head->nextPtr == head) {
		delete head;
	} else {
		PokeNode * tmp = head->nextPtr;
		while (tmp != head) {
			PokeNode * tmpdel = tmp;
			tmp = tmp->nextPtr;
			delete tmpdel;
		}
		//|最后释放head  
		delete tmp;
	}
}
/**********************************************************
*主函数
**********************************************************/
int main(int argc, char * argv[]) {

	PokeNode * p = create(13);
	echoEach(p);
	Magician(p, 13);
	destory(p);
	while (1);
	return 1;
}