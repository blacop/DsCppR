/*
c语言魔术师发牌问题（循环链表）
Coder.Bing 发布于 2015-01-20-04-50 分类：c/c++ / 算法和数据结构 阅读(2042) 评论(0)

本站长承接“企业网站定制服务，有想做网站的客户可联系！站长QQ：739696033 | 微信：bing-0719

[t]问题如下:魔术师手上又13张黑牌，分别为A～K，
现在魔术师将牌正面朝下叠在一起，
只要数数就能抽出相应的牌，
从1数到13，现在我们用c语言解决魔术师手中的牌预先顺序。[/t]

[t]程序如下：[/t]
*/
#include<stdio.h>
#include<stdlib.h>
#define CardNumber 13
typedef struct PokeNode {
	int  data;
	struct PokeNode *next;
}PokeNode, *linklist;

//创建13个节点的循环链表(尾插法)
linklist createLinkList() {
	linklist head = NULL;
	linklist s, r;
	int i;
	r = head;
	for (i = 1; i <= CardNumber; i++) {
		s = (linklist)malloc(sizeof(lPokeNode));
		s->data = 0;    //将所有节点初始化为0
		if (head == NULL)
			head = s;//不带头结点 尾插法
		else
			r->next = s;
		r = s;
	}
	r->next = head;
	return head;
}
//发牌顺序
void Magician(linklist head) {
	linklist p;
	int countnumber = 2;  //从第二次数数开始
	p = head;
	p->data = 1;  //第一张牌为1
	while (1) {
		for (int j = 0; j < countnumber; j++) { //因为魔术师问题的描述条件里面，首先必须数数，所以必须先循环到规定的次数
			p = p->next;
			if (p->data != 0)  //不为0的话，表示此牌已经抽出，不做计算（j–-），就需要再循环--j（意思是多循环一次）.  					
				j = j - 1;
		}
		if (p->data == 0)   //for循环结束后，此时p->data==0，为所需抽出的牌的位置
		{
			p->data = countnumber;  //我们将此位置的牌设为countnumber
			countnumber++;   //自增，如果countnumber<14，并继续执行while中的for循环。。。
			if (countnumber == 14)  //结束条件为==14 
				break;//break跳出的是最近的一个循环，while循环
		}
	}
}

int main() {
	linklist p;
	int i;
	p = createLinkList();
	Magician(p);

	for (i = 0; i < CardNumber; i++) {
		printf(“黑桃%d “, p->data);
		p = p->next;

	}
	return 0;
}

