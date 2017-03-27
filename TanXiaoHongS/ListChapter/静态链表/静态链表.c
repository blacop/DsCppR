#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE -1
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
#define MAX_SIZE 1000;//表最大空间
/*
//线性表的基本操作列表
InitList(&L) //初始化线性表L
DestroyList(&L) //销毁线性表L
ClearList(&L) //清空线性表L
ListEmpty(L) //判断线性表是否为空
ListLength(L) //求线性表L的长度
GetElem(L,i,&e) //取线性表L的第i个元素
LocateElem(L,e,compare()) //定位检索线性表L中元素e
compare() //比较两个元素的大小,返回Bool
compareArray() //比较两个数组的大小,返回Bool
PriorElem(L,cur_e,&prio_e) //返回线性表L中元素e的直接前驱元素
NextElem(L,cur_e,&next_e) //返回线性表L中元素e的直接后继元素
ListInsert(&L,i,e) //在线性表L的第i个元素之前插入元素e,返回Bool
ListDelete(&L,i,e) //删除线性表L的第i个元素,被删除元素e的值,返回Bool
ListTraverse(L,visit()) //遍历线性表:依次对L的每个元素调用visit()
visit() //  visit 一般是指树型链表结构中对某个节点内容进行访问的函数，
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”
*/
//------静态链表,游标实现法,用数组实现链表----------
//静态链表 初始化 定位 Malloc Free 插入 删除
typedef struct { //静态链表 结构体定义 封装
	ElemType data;//数据域的类型可以是任意的基类型，包括数组
	int cur; //游标域(Cursor) == next指针,存放该元素的后继在数组中的下标,为0时无指向
}Component, SLinkList[MAX_SIZE]; //声明Component为SLinkList[MAX_SIZE]
/*
静态链表,游标实现法,用数组实现链表
数组第一个和最后一个元素作为特殊元素处理,不存数据.
静态链表 使用数组实现链表，可以在没有指针的编程语言中实现链表结构
*/
Status InitList_SL_In_Ptr_Out_Bool(SLinkList &space) {
	//初始化静态链表
	//space[0].cur为头指针,"0"表示空指针
	int i;
	//将一维数组space中各分量链接成一个备用链表，space[0].cur为头指针。
	//“0”表示空指针
	for (i = 0; i < MAX_SIZE - 1; i++)
		space[i].cur = i + 1;
	//头游标和尾游标 的数据区不存放数据 
	//头游标保存第一个没有数据位置的游标 尾游标保存第一个有数据位置的游标
	//最后一个有数值的分量的cursor游标为0
	//未使用的数组元素成为备用链表
	//除了头游标和尾游标 每个游标保存存放下一个节点的逻辑位置序号
	space[MAX_SIZE - 1].cur = 0;//给最后的游标赋值 ,
	return TRUE;
}
int ListLength_SL(SLinkList L){  //求静态链表长度
	int i = 0;
	int len = 0;
	i = L[MAX - 1].cur;//i指向第一个结点
	//h = L->next;//h指向 头指针L->next, head=>node1
	while (i != NULL) { //从头遍历的尾部，返回计数器
		++len;
		i = L[i].cur;//pointer move 1
	}
	return len;//返回的长度会比实际小1？
}
int LocateElem_SL(SLinkList S, ElemType e) { //查找，返回空闲分量的下标
	//在静态单链线性表L中查找第1个值为e的元素
	//若找到，则返回它在L中的依序，否则返回0
	i = S[0].cur;//i模拟指针 ,i指示表中第一个结点
	while (i && S[i].data != e)//在表中顺链查找
		i = S[i].cur;//指针下移
	return i;
}
int Malloc_SLL(SLinkList space) { //获取当前空闲量的下标，返回空闲分量的下标,未被使用,用getCur更好理解，
	int i = space[0].cur;	//当前数组第一个元素的cur存的值
							//就是要返回的第一个备用空闲的下标
	if(space[0].cur) //非0，为0就是空指针==末尾==空链表
		space[0].cur = space[i].cur;
	//由于要拿出一个分量来使用了,所以我们就得把它的下一个分量用来做备用
	//==指针下移,空闲分量指针下移，0下标的游标赋值为i下标对应的游标
	return i;
}
void Free_SLL(SLinkList &space, int k) { 
	//将下标为k的空闲结点回收到备用链表
	space[k].cur = space[0].cur; //把第一个元素cur值赋给要删除的分量cur
	space[0].cur = k;//把要删除的分量下标赋值给第一个元素的cur
}//Free_SLL
Status ListInsert(SLinkList L, int i, ElemType e) { //在L中第i个元素之前插入新的数据元素e	
	int j, k, l; //l是计数器，i是插入位置指针，l是i - 1位置，下标当成指向当前节点的指针
	k = MAX_SIZE - 1;//注意k首先是最后一个元素的下标
	if (i<1 || i>ListLength(L) + 1) // //判断位置是否合理，如果第i个元素不存在
		return FALSE;//L+1是因为 ListLength()方法 返回值比实际长度小1 ？i可以=length+1表示可以插入到最后一个位置
	//这里的L+1实在搞不明白啊？？算了，不管了。
	j = Malloc_SLL(L);//获得空闲分量的下标
	if (j){ //not "0" ,为0则为空表
		L[j].data = e;//写入数据
		for (l = 1; l <= i - 1; l++) { //从1开始找，找到第i个元素之前 i-1的位置
			k = L[k].cur;//返回的是第i个下标节点的游标=>next=>Node1的 cur=>next,最后一个元素的游标指向第一个元素
			//k表示当前工作指针，整个循环表示指针k从head开始，移动了i-1次,
		}
		L[j].cur = L[k].cur; 
		L[k].cur = j;
		//把第i个元素之前的cur赋值给新元素的cur
		//把新元素的下标赋值给第i个元素之前的元素的cur
		//翻译成链表 new->next = pre->next
		//翻译成链表 pre->next = 
		//new是新插入的节点，pre是i-1位置的节点
		return TRUE;
	}
	return FALSE;
}
Status ListDelete_SL_Da(SLinkList L, int i) {
	//删除在L中第i个数据元素e, 
	//j又做计数器，又做临时指针，容易混淆
	int j, k;
	j = 0;
	if (i < 1 || ListLength(L)) //判断位置是否合理
		return FALSE;
	k = MAX_SIZE - 1;//k.next = head ,  pointer 指向 end <==> head 
	for (j = 0; j <= i - 1; j++){//寻找i-1的指针
		k = L[k].cur;//delNow的指针,被删除元素的指针
	}
	j = L[k].cur;//j指向第i个位置
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return TRUE;
}
Status ListDelete_SL_Bo(SLinkList L, int i, int *e) { //删除在L中第i个数据元素e
	int k = L[MAX - 1].cur; //k.next = head.next
	int j = 1, m; ////j做计数器，m做临时指针，不容易混淆
	if (i<1 || i>ListLength(L))  //判断位置是否合理
		exit(0);
	while (k && j<i - 1) { //找到第i-1个位置	
		++j;
		k = L[k].cur;//找到第i-1个位置 ,k就是第i-1个位置
	}
	m = L[k].cur;  //m指向第i个位置↑ , *m = pre.next <==>  *m = *del
				   // m作为一个临时指针，是为了给后面的Free()方法用
	*e = L[m].data; //取出被删除的数据
	L[k].cur = L[m].cur;//pre.next = del.next
	Free(L, m); //将空闲结点m释放到备用链表中// free( &L, *m)
}