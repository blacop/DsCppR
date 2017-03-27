#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
#define ElemType int
#define LIST_INIT_SIZE = 100;//表初始分配空间
#define LIST_INCREMENT = 10;//空间分配增量
/*
#define Node ElemType
typedef struct Node{}Node,*NodePtr; //元素类型重定义指针
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
ADT 线性表 List
数据对象 Data : D = { ai | ai∈ ElemSet,i = 1,2,...,n,n >= 0 }
//线性表的数据对象集合为{ a,a2,--,an }, 每个元素的类型均为DataType
数据关系 Relation : Rl={<ai-1,ai>|ai-1,ai∈ D,i=2,...,n}
基本操作 Operation
	//线性表的基本操作列表 CORE
	InitList(&L) //初始化线性表L  01 初始化
	DestroyList(&L) //销毁线性表L 02 销毁
	ClearList(&L) //清空线性表L 03 清空
	ListEmpty(L) //判断线性表是否为空  04 为空
	ListLength(L) //求线性表L的长度  05 长度
	GetElem(L, i, &e) //取线性表L的第i个元素  06 查找
	LocateElem(L, e, compare(e1, e2)) //定位检索线性表L中元素e  07 定位
	PriorElem(L, cur_e, &prio_e) //返回线性表L中元素e的直接前驱元素 08 前驱
	NextElem(L, cur_e, &next_e) //返回线性表L中元素e的直接后继元素 09 后继
	ListInsert(&L, i, e) //在线性表L的第i个元素之前插入元素e,返回Bool 10 插入
	ListDelete(&L, i, e) //删除线性表L的第i个元素,被删除元素e的值,返回Bool  11 删除
	ListTraverse(L, visit(e)) //遍历线性表:依次对L的每个元素调用visit()  12 遍历
	//----选修Electives----
	visit(e) // 一般是指树型链表结构中对某个节点内容进行访问的函数 13
	compare(e1,e2) //比较两个元素的大小,返回Bool 14.a
	compareList(L1,L2) //比较两个线性表L的大小,返回Bool 14.b
	union() //求并集 15.a
	mergeList(&L1,L2) //求并集&&升序排序， 合并两个线性表L 15.b
	different() //求差集 15.c
	ListAppend() //尾部插入元素,尾插 15.d
	exchange() //交换一个父线性表L中的两个子线性表L 16
endADT List
*/
//---------------线性顺序表----------------
//线性顺序表 初始化 插入 删除，查找，求并集，5合并排序， 6交换 7判断为空 8求长度,求差集,尾插
typedef struct SqList { //封装一个线性表 为SqList
	ElemType *elem;//存储空间，存放头地址,也可表示数组的名字 或地址  或第一个元素
	int length;//线性表当前长度
	int listsize;//当前存储容量
}SqList, List, *ListPtr;
typedef ElemType *PElemType;//重定义指针
Status InitList_Sq(SqList &L) {
	//初始化空的线性表,&L 引用参数表示会修改值
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//分配内存，返回void*指针，类型强转一下
	if (!L.elem) exit(OVERFLOW);//OVERFLOW是返回到OS的
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return TRUE;
}//InitList_Sq
Status ListInsert_Sq_Pointer(SqList &L, int i, ElemType e) {
	//插入线性表 指针法，i表示的是插入位置，不是序号，i的最大值length+1是表示可以在数组的最后位置↑的右边位置↑length+1位置插入 ，E是插入值
	//i的合法值为1<=i<=ListLength_Sq(L)
	/*L.lengath指的是该顺序表的长度，并非指的是第最后一个元素（第length个）。
	所谓的：顺序表插入可以理解为：
	1 把原顺序表A的长度 length + 1后
	2 i位置插入元素e
	（这里的 + 1：已完成了将第 >= “i”位置的数据元素的后移，这里不进行详解了），
	得到一个顺序表B，然后再进行替换。
	*/
	/*
	图示法
		①length + 1，
		②☒㊣㊣㊣→ + 1，
		③↑
		所以length + 1 合法，表示在原表的length + 1, 尾部追加1个新元素，
		① ㊣㊣㊣☒
		② ———↑
	*/
	if (i<1 || i>L.length + 1) return FALSE;//i的合法值为1<=i<=ListLength_Sq(L)
	if (L.length >= L.listsize) { //当前存储空间已满，(realloc就是)增加内存分配，函数realloc()
								  // void* realloc(void* ptr, unsigned newsize);  给一个已经分配了地址的指针重新分配空间,参数ptr为原有的空间地址,newsize是重新申请的地址长度.
		ElemType *newbase = (ElemType *)realloc(L.elem, L.(LIST_INIT_SIZE + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);//存储分配失败
		L.elem = newbase;//新的地址
		L.listsize += LIST_INCREMENT;//增加存储容量       
	}
	ElemType *p, *q;
	q = &(L.elem[i - 1]);
	//q为插入位置
	//i是从1开始，所以要获取元素，必须-1！！因为下标是从0开始的
	for (p = &(L.elem[L.length - 1]); p >= q; --p) { //插入位置及其之后的元素右移
		*(p + 1) = *p;
	}
	*q = e;//插入e 的值
	++L.length;//表长度+1
	return TRUE;
}//ListInsert_Sq
Status ListInsert_Sq_Pointer_Se(SqList &L, int i, ElemType e) { //插入线性表 使用指针 简化写法  不要新开辟内存
	if (i<1 || i>L.length + 1) return FALSE;//i的合法值为1<=i<=ListLength_Sq(L)+1  (L),因为 index <==> i-1
	if (L.length >= L.listsize) exit(OVERFLOW);//超出存储空间，报错退出
	PElemType p, q;
	PElemType pos;
	pos = L.elem[i - 1];
	q = &(L.elem[i - 1]);//q为插入位置 指针
	//i是从1开始，所以要获取元素，必须-1！！因为下标是从0开始的
	for (p = &(L.elem[L.length - 1]); p >= q; --p) {
		//p=&(L.elem[L.length-1]表示最末尾的指针
		//插入位置及其之后的元素右移
		*(p + 1) = *p;//将被插入位置后的元素右移一位
	}
	*q = e;//插入e 的值
	++L.length;//表长度+1
	return TRUE;
}
Status ListInsert_Sq_Index(SqList *L, int i, ElemType e) { //线性表 插入元素 使用下标
	int k; //k表示最末尾下标
	if (i<1 || i>L.length + 1) return FALSE;//i的合法值为1<=i<=ListLength_Sq(L)
	if (L.length >= L.listsize) exit(OVERFLOW);//超出存储空间，报错退出	
	if (i <= L->length) { //被插入的元素不在表尾
		for (k = L->length - 1; p >= i - 1; k--)
			L->data[k + 1] = L->data[k]; //将被插入位置之后的 所有元素 右移一位				
	}
	L->data[i - 1] = e;//插入 新元素e 的值
	L->length++;//表长度+1
	return TRUE;
}
Status ListDelete_Sq_Pointer(SqList &L, int i, ElemType &e) {
	//删除线性表中的第i个元素
	//删除L中第i个元素，后面的元素前移
	ElemType *p, *q;
	if ((i < 1) || (i > L.length)) return FALSE;
	p = &L.elem[i - 1];//p表示删除的地址
	//i是从1开始，所以要获取元素，必须-1！！因为下标是从0开始的
	e = *p;//返回e的值
	q = L.elem + L.length - 1;//q存放的是线性表内最后位置的指针,基地址+(length-1)表示最后位置的地址 
	for (++p; p <= q; ++p) {
		//后面的元素前移，先++p是因为p的位置是删除的位置，所以从删除位置的右边+1算起
		//↓+1
		//☒㊣㊣
		//㊣㊣
		*(p - 1) = *p;//删除位置 后继元素前移
	}
	--L.length;
	return TRUE;
}
Status ListDelete_Sq_Index(SqList *L, int i, ElemType *e) { //线性表 删除元素 使用下标,i就是order
	int k;//控制变量 计数器
	if (L->length == 0) //线性表为空
		return FALSE;
	if (i<1 || i>L.length) // 删除位置错误
		return FALSE;
	*e = L->data[i - 1];//返回删除值e, i-1表示被删除i项目的index
	if (i < L->length) {
		for (k = i; k < length; k++)
			L->data[k - 1] = L->data[k]; //删除位置 后继元素前移
	}
	L->length--;
	return TRULE;
}
Status GetElem(SqList L, int i, ElemType *e) { //获取元素
	if (L.length == 0 || i<1 || i>L.length) {
		return FALSE;
	}
	*e = L.data[i - 1];
	return TRUE;
}
int LocateElem(SqList L, ElemType e) {
	/*成功返回位序 下标法
	函数名：LocateElem()
	参数：sql L, ElemType element
	初始条件：线性表L已存在
	功能：返回顺序表中第一个与element相等的元素的位序
	返回值：若L中存在与element相等的元素，则返回 第一个符合条件的元素位序
	若不存在，则返回0*/
	size_t i; //controller elem，limit i
	//ElemType *p; //temp Ptr p //指针法only
	p = L.elem; //temp Ptr p
	for (i = 0; i < L.length; i++) {
		if (L.elem[i] == e) { //*L.elem == E 指针法only
			L.elem = p;
			return i + 1;//返回i+1就是返回order,
		}
		//L.elem++; //指针法only
	}
	//L.elem = p;//重置指针 //指针法only
	return FALSE;//遍历线性表后 没有找到与element相等的元素
}
Status LocateElem_OutOrderOrBool(sql &L, ElemType E) {
	//指针法
	//成功返回位序 或者 布尔值FALSE
	/*函数名：LocateElem()
	参数：sql L, ElemType element
	初始条件：线性表L已存在
	功能：返回顺序表中第一个与element相等的元素的位序
	返回值：若L中存在与element相等的元素，则返回 第一个符合条件的元素位序
	若不存在，则返回0*/
	size_t i; //controller limit i
	ElemType *p; //temp Ptr p
	p = L.elem; //temp Ptr p
	for (size_t i = 1; i <= L.length; i++)
	{
		if (*L.elem == E) {
			L.elem = p;
			return i;//返回i就是返回order,
		}
		L.elem++;
	}
	L.elem = p;//重置指针
	return FALSE;//遍历线性表后 没有找到与element相等的元素
}

int LocateElem_OutOrder(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	/*函数名：LocateElem()
	参数：sql L, ElemType element
	初始条件：线性表L已存在
	功能：返回顺序表中第一个与element相等的元素的位序
	返回值：若L中存在与element相等的元素，则返回 第一个符合条件的元素位序
	若不存在，则返回0*/
	/*函数指针是指向函数的指针变量。 因而“函数指针”本身首先应是指针变量，只不过该指针变量指向函数。这正如用指针变量可指向整型变量、字符型、数组一样，这里是指向函数。如前所述，C在编译时，每一个函数都有一个入口地址，该入口地址就是函数指针所指向的地址。有了指向函数的指针变量后，可用该指针变量调用函数，就如同用指针变量可引用其他类型变量一样，在这些概念上是大体一致的。函数指针有两个用途：调用函数和做函数的参数。*/
	int i = 0;
	while (i < L.length && (*compare)(L.elem[i], e))
		i++;
	if (i >= L.length)
		return FALSE;
	int order = i + 1;
	return order;
}
int CompareArray(SqList A, SqList B) {
	//比较数组大小的方法
	j = 0;//计数器
	while (j < A.length && j < B.length)
	{
		if (A.elem[j] < B.elem[j]) return -1;
		else if (A.elem[j] > B.elem[j]) return 1;
		else j++;
	}
	if (A.length == B.length) return 0;
	else if (A.length < B.length) return -1;
	else return 1;
}//CompareArray
Status Compare(ElemType e1, ElemType e2) {
	//compare
	//比较2个元素,> 返回 1, < 返回-1, ==返回0	
	if (e1 == e2) return 0;
	if (e1 < e2) return -1;
	return 1;
}
typedef int(*LocateElem_ptr)(ElemType, ElemType);//定义声明一个函数指针,类似于委托

void Union(List &La, List Lb) {
	//线性表 求并集 这个是伪代码，下面的MergeList是真代码
	/*
	定义声明一个函数指针,类似于委托
	typedef int(*function_ptr)(ElemType, ElemType);
	声明然后赋值
	function_ptr max_func;
	max_func=equal([形参列表]);
	function_ptr max_func=equal([形参列表]); //声明（函数指针，委托）变量，然后赋值：
	*/
	//扩大线性表La,将Lb中存在而La中
	//不存在的元素插入到La
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++) {
		ElemType e = GetElem(Lb, i, e);
		if (!LocateElem(La, e, equal())) {
			ListInsert(La, ++La_len, e);
		}
	}//for
}//Union
void MergeSqList(List La, List Lb, List &Lc) {
	//union的具体实现
	//合并顺序表，并且升序排序 到&Lc
	pa = La.elem; pb = Lb.elem;//取头部指针a,b
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));//取指针，分配内存
	if (!Lc.elem) exit(OVERFLOW);//分配内存失败
	pa.last = La.elem + La.length - 1;//取尾部指针a
	pb.last = Lb.elem + Lb.length - 1;//取尾部指针b
	while (pa <= pa.last && pb <= pb.last) { //开始合并
		if (*pa <= *pb) {
			*pc++ = *pa++;//a存入c
		}
		else {
			*pc++ = *pb++;//b存入c
		}
	}
	while (pa <= pa.last) { *pc++ = *pa++; }//剩余元素a存入c 
	while (pb <= pb.last) { *pc++ = *pb++; }//剩余元素b存入c
}//MergeSqList
void SetDifference(List La, List Lb, List &Lc) {
	//求差集	
	//Set_Difference,  A - B .
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	ListPtr Lc = (SqList *)malloc(LIST_INIT_SIZE * sizeof(SqList));
	int LcLastPtr = 0;//temp LcLastPtr指针，指向线性表尾部

	for (i = 1; i <= Lb_len; i++) {
		ElemType e = GetElem(La, i, e);
		if (!LocateElem(Lb, e, equal)) { //La[i]!=Lb[i]
			ListAppend(Lc, Lc[++LcLastPtr], e);// Lc Append data e.
		}
	}//end for
}//Set_Difference
void ListAppend(List La, ElemType e) { //尾部插入元素,尾插，如果有个last指针，就很容易了
	int maxlen = ListLength_Sq(La);
	int lastPtr = maxlen - 1;
	La[lastPtr + 1] = e;
}
void Exchange(SqList &L, int m, int n) {
	//线性表交换前m个元素和后n个元素 整体互换
	SqList w;//temp ptr
	int i, j;
	for (i = 0; i < n; i++) {
		w = L.elem[i + m];
		for (j = m; j >= 1; j--) {//j是末尾--
			L.elem[i + j] = L.elem[i + j - 1];//整体右移,
			//  →
			//㊣㊣▁
			//▁㊣㊣  m是不变的
		}
		L.elem[i] = w;
	}

}

int ListEmpty_Sq(SqList L) { //判断线性表L是否为空
	if L.length = 0 return TURE;
	else return FALSE;
}
int ListLength_Sq(SqList L) { //求线性表的长度
	return L.length;
}

Status MergeSqList_Union(List La, List Lb, List &Lc) {
	//union的具体实现
	//合并顺序表，并且升序排序 到&Lc
	pa = La.elem; pb = Lb.elem;//取头部指针a,b
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));//取指针，分配内存
	if (!Lc.elem) exit(OVERFLOW);//分配内存失败
	pa.last = La.elem + La.length - 1;//取尾部指针a
	pb.last = Lb.elem + Lb.length - 1;//取尾部指针b
	while (pa <= pa.last && pb <= pb.last) { //开始合并
		if (*pa <= *pb) {
			*pc++ = *pa++;//a存入c
		}
		else {
			*pc++ = *pb++;//b存入c
		}
	}
	while (pa <= pa.last) { *pc++ = *pa++; }//剩余元素a存入c 
	while (pb <= pb.last) { *pc++ = *pb++; }//剩余元素b存入c
	return TRUE;
}//MergeSqList_Union

Status Sq_Detete_In_A_By_B_Inter_C(SqList &A, SqList B, SqList C) {
	//删除A中满足条件的元素：同时在B/C中出现的元素
	ElemType e; //temp data
	for (size_t i = 0; i < length; i++) {
		e = A.elem[i];
		if ((LocateElem(B, e)) && (LocateElem(C, e))) {
			ListDelete(A, i + 1);
		}//if
	}//for
}//Sq_Detete_In_A_By_B_Inter_C



