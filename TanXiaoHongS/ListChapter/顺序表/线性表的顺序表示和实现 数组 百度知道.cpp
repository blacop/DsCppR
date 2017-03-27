#include <stdio.h>
#include <stdlib.h>
#define TRUE	    1
#define FALSE		0
#define OK			1
#define ERROR		0
#define INFEASIBLE  -1
#define OVERFLOW	-2
#define ElemType int
#define Status int
typedef int ElemType;
typedef int Status;
//------线性表的动态分配顺序存储结构--------
#define MAXSIZE 20 //线性表存储空间的初始分配量
#define LIST_INIT_SIZE	20	//线性表存储空间的初始分配量
#define LIST_INCREMENT	10	//线性表存储空间的分配增量
typedef struct SqList{
	ElemType data[MAXSIZE];//数组存储数据元素，最大容量为MAXSIZE
	int length;//长度
}SqList;
Status InitList(SqList &L) {

}
#include"iostream.h"
class num
{
private:
 int a[100];
 int length;
public:
 num()
 {
  length=0;
 }
 num(int x[],int len)
 {
  if(len>100)
  {
   cout<<"data overflow!"<<endl;
   num(x,100);
  }
  else
   if(len>=0)
   {
    for(int i(0);i<len;i++)
     a[i]=x[i];
    length=len;
   }
   else
   {
    cout<<"parameter error!"<<endl;
    num();
   }
 }
 void set()//输入
 {
  int len;
  cout<<"input the length"<<endl;
  cin>>len;
  if(len>100||len<0)
  {
   cout<<"parameter error!"<<endl;
  }
  else
  {
   for(int i=0;i<len;i++)
    cin>>a[i];
   length=len;
  }
 } void print()//输出
 {
  for(int i=0;i<length;i++)
   cout<<a[i]<<' ';
  cout<<endl;
 } void fr_print()//前驱后继输出
 {
  int flag;
  cout<<"input the flag"<<endl;
  cin>>flag;
  int f=find(flag,0);
  if(f>0&&f<length-1)
   cout<<a[f-1]<<' '<<a[f+1]<<endl;   
  else
   if(f==0)
    cout<<a[f+1]<<endl;
   else
    if(f==length-1)
     cout<<a[f-1]<<endl;
    else
           cout<<"not find"<<endl;
 } int find(int flag,int n)//从n开始查找
 {
  for(int i=n;i<length;i++)
   if(a[i]==flag)
    break;
  if(i==length)
  {
   return -1;
  }
  else
   return i;                     
 } void insert()//在data后插入flag
 {
  int flag,data;        
  cout<<"input the flag and data"<<endl;
  cin>>flag>>data;
  if(length==100)
   cout<<"can't insert more!"<<endl;
  else
   if(find(flag,0)==-1)
    cout<<"not find!"<<endl;
   else
   {
    int f=find(flag,0);
    do
    {
     
     for(int i=length;i>f;i--)
      a[i+1]=a[i];
     a[i+1]=data;
        f=find(flag,f+2);
     length++;
    }while(f!=-1);  
   }
 }
 void delet()//删除flag
 {
  int flag;
  cout<<"input the delete flag"<<endl;
  cin>>flag;
  if(length==0)
   cout<<"can't delete more!"<<endl;
  else
   if(find(flag,0)==-1) 
    cout<<"not find!"<<endl;
   else
   {
    int f=find(flag,0);
    do
    {
     for(int i=f;i<length;i++)
      a[i]=a[i+1];
     f=find(flag,f);
     length--;
    }while(f!=-1);  
   }
 }
};
void main()
{
 num a;
 char c='Y';
 cout<<"a:输入b:输出(前后继)c:输出d:插入e:删除"<<endl;
 while(c='Y')
 {
  cin>>c;
  switch(c)
  {
  case 'a': a.set();break;
  case 'b': a.fr_print();break;
  case 'c': a.print();break;
  case 'd': a.insert();break;
  case 'e': a.delet();break;
  default:cout<<"error!"<<endl;
  }
  cout<<"continue or not?(Y/N)"<<endl;
  cin>>c;
 }
}

/*
typedef struct {
	ElemType* elem;	//存储空间基址
	int length;			//当前长度
	int listsize;		//当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;
/*
//基本操作
Status InitList(SqList &L);
//操作结果：构造一个空的线性表L。

Status DestroyList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：销毁线性表L。

Status ClearList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：将L重置为空表。

bool ListEmpty(SqList L);
//初始条件：线性表L已存在。
//操作结果：若L为空表，则返回TRUE，否则返回FALSE。

int ListLength(SqList L);
//初始条件：线性表L已存在。
//操作结果：返回L中数据元素的个数。

Status GetElem(SqList L, int i, ElemType &e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//初始条件：线性表L已存在，compare()是数据元素判定函数。
//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0.

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。

Status ListInsert(SqList &L, int i, ElemType e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)+1.
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.

Status ListDelete(SqList &L, int i, ElemType &e);
//初始条件：线性表L已存在且非空，1<=i<=ListLength(L).
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1.

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//初始条件：线性表L已存在
//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。
//SqList.h end
*/
//head SqList.cpp
#include <malloc.h>
#include "SqList.h"
Status InitList(SqList &L) {
	//操作结果：构造一个空的线性表L。
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);	//存储分配失败
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList
Status DestroyList(SqList &L) {
	//操作结果：销毁线性表L。
	free(&L);
	return OK;
}
Status ClearList(SqList &L) {
	//操作结果：将L重置为空表。
	L.length = 0;
	return OK;
}
bool ListEmpty(SqList L) {
	//操作结果：若L为空表，则返回TRUE，否则返回FALSE。
	if (0 == L.length) return true;
	else return false;
}
int ListLength(SqList L) {
	//操作结果：返回L中数据元素的个数。
	return L.length;
}
Status GetElem(SqList L, int i, ElemType &e) {
	//1<=i<=ListLength(L)。
	//操作结果：用e返回L中第i个数据元素的值。
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];	//e=*(L.elem+i-1);
						// <== p +(-)n*sizeof(基类型)
						//p[i] = *(p + i) ;
	//因为数组的指针是连续的,所以才可以这样计算 
	return OK;
}
int LocateElem(SqList L, ElemType e, bool(*equal)(ElemType, ElemType)) {
	//Status (*equal)(ElemType, ElemType)：定义一个“函数指针”，这个“函数指针”用于指向某一函数，该函数要满足以下要求：返回值为Status（也即int），并且有两个类型为ElemType的参数。定义函数指针是为了某些功能上的统一。
	//equal()是数据元素判定函数。
	//返回L中第一个与e满足关系equal()的数据元素的位序。若这样的数据元素不存在，则返回值为0.
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length  &&  !(*equal)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return 0;
}
bool equal(ElemType e1, ElemType e2) {
	//equal()是数据元素判定函数。
	if (e1 == e2) {
		return true;
	}
	else {
		return false;
	}
}
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
	//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length  && !(cur_e == L.elem[i - 1])) ++i;// until, legal && !== node1,i++
	if (i<2 || i>L.length) //i=1 表示没有前驱
		return ERROR;
	pre_e = L.elem[i - 2];//cur_e =L.elem[i - 1]
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
	//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length  && !(cur_e == L.elem[i - 1])) ++i;
	if (i<2 || i>L.length)
		return ERROR;
	next_e = L.elem[i];//cur_e =L.elem[i - 1]
	return OK;
}
Status ListInsert(SqList &L, int i, ElemType e) {
	//1<=i<=ListLength(L)+1. beacause length can +1.
	//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.
	if (i < 1 || i>L.length + 1) return ERROR;	//i值不合法
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType * q = &(L.elem[i - 1]);	//q为插入位置 get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	ElemType * p;
	for (p = &(L.elem[L.length - 1]); p >= q; --p) // p=&(last);p >= q;--p
		*(p + 1) = *p;	//右移 right move , cur+1=cur

	*q = e;//assignment
	++L.length;
	return OK;
}//ListInsert
Status ListDelete(SqList &L, int i, ElemType &e) {
	//1<=i<=ListLength(L).
	//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1.
	if (i<1 || i>L.length) return ERROR; //i值不合法
	ElemType * p = &(L.elem[i - 1]); //p为del位置 get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	e = *p;
	ElemType * q = L.elem + L.length - 1; //q =&(last)
	for (++p; p <= q; ++p) *(p - 1) = *p; // left move , cur-1=cur
	--L.length;
	return OK;
}
Status ListTraverse(SqList L, bool(*visit)(ElemType)) {
	//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && (*visit)(*p++)) ++i;
	return OK;
}
Status visit(ElemType e) {
	//访问节点,返回bool,打印c,值由外部传入
	printf("%d\t", e);
	return TRUE;
}
//end SqList.cpp
*/