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
//------���Ա�Ķ�̬����˳��洢�ṹ--------
#define MAXSIZE 20 //���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INIT_SIZE	20	//���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT	10	//���Ա�洢�ռ�ķ�������
typedef struct SqList{
	ElemType data[MAXSIZE];//����洢����Ԫ�أ��������ΪMAXSIZE
	int length;//����
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
 void set()//����
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
 } void print()//���
 {
  for(int i=0;i<length;i++)
   cout<<a[i]<<' ';
  cout<<endl;
 } void fr_print()//ǰ��������
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
 } int find(int flag,int n)//��n��ʼ����
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
 } void insert()//��data�����flag
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
 void delet()//ɾ��flag
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
 cout<<"a:����b:���(ǰ���)c:���d:����e:ɾ��"<<endl;
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
	ElemType* elem;	//�洢�ռ��ַ
	int length;			//��ǰ����
	int listsize;		//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
} SqList;
/*
//��������
Status InitList(SqList &L);
//�������������һ���յ����Ա�L��

Status DestroyList(SqList &L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//����������������Ա�L��

Status ClearList(SqList &L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������L����Ϊ�ձ�

bool ListEmpty(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��

int ListLength(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�������������L������Ԫ�صĸ�����

Status GetElem(SqList L, int i, ElemType &e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)��
//�����������e����L�е�i������Ԫ�ص�ֵ��

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�������
//����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0.

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣

Status ListInsert(SqList &L, int i, ElemType e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1.
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1.

Status ListDelete(SqList &L, int i, ElemType &e);
//��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L).
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1.

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//��ʼ���������Ա�L�Ѵ���
//������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ�
//SqList.h end
*/
//head SqList.cpp
#include <malloc.h>
#include "SqList.h"
Status InitList(SqList &L) {
	//�������������һ���յ����Ա�L��
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);	//�洢����ʧ��
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList
Status DestroyList(SqList &L) {
	//����������������Ա�L��
	free(&L);
	return OK;
}
Status ClearList(SqList &L) {
	//�����������L����Ϊ�ձ�
	L.length = 0;
	return OK;
}
bool ListEmpty(SqList L) {
	//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��
	if (0 == L.length) return true;
	else return false;
}
int ListLength(SqList L) {
	//�������������L������Ԫ�صĸ�����
	return L.length;
}
Status GetElem(SqList L, int i, ElemType &e) {
	//1<=i<=ListLength(L)��
	//�����������e����L�е�i������Ԫ�ص�ֵ��
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];	//e=*(L.elem+i-1);
						// <== p +(-)n*sizeof(������)
						//p[i] = *(p + i) ;
	//��Ϊ�����ָ����������,���Բſ����������� 
	return OK;
}
int LocateElem(SqList L, ElemType e, bool(*equal)(ElemType, ElemType)) {
	//Status (*equal)(ElemType, ElemType)������һ��������ָ�롱�����������ָ�롱����ָ��ĳһ�������ú���Ҫ��������Ҫ�󣺷���ֵΪStatus��Ҳ��int������������������ΪElemType�Ĳ��������庯��ָ����Ϊ��ĳЩ�����ϵ�ͳһ��
	//equal()������Ԫ���ж�������
	//����L�е�һ����e�����ϵequal()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0.
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length  &&  !(*equal)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return 0;
}
bool equal(ElemType e1, ElemType e2) {
	//equal()������Ԫ���ж�������
	if (e1 == e2) {
		return true;
	}
	else {
		return false;
	}
}
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
	//�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
	//cur_e =L.elem[i - 1]
	int i = 1;
	while (i <= L.length  && !(cur_e == L.elem[i - 1])) ++i;// until, legal && !== node1,i++
	if (i<2 || i>L.length) //i=1 ��ʾû��ǰ��
		return ERROR;
	pre_e = L.elem[i - 2];//cur_e =L.elem[i - 1]
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
	//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
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
	//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1.
	if (i < 1 || i>L.length + 1) return ERROR;	//iֵ���Ϸ�
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType * q = &(L.elem[i - 1]);	//qΪ����λ�� get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	ElemType * p;
	for (p = &(L.elem[L.length - 1]); p >= q; --p) // p=&(last);p >= q;--p
		*(p + 1) = *p;	//���� right move , cur+1=cur

	*q = e;//assignment
	++L.length;
	return OK;
}//ListInsert
Status ListDelete(SqList &L, int i, ElemType &e) {
	//1<=i<=ListLength(L).
	//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1.
	if (i<1 || i>L.length) return ERROR; //iֵ���Ϸ�
	ElemType * p = &(L.elem[i - 1]); //pΪdelλ�� get_cur_Ptr , cur_Ptr =&(L.elem[i - 1])
	e = *p;
	ElemType * q = L.elem + L.length - 1; //q =&(last)
	for (++p; p <= q; ++p) *(p - 1) = *p; // left move , cur-1=cur
	--L.length;
	return OK;
}
Status ListTraverse(SqList L, bool(*visit)(ElemType)) {
	//������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ�
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && (*visit)(*p++)) ++i;
	return OK;
}
Status visit(ElemType e) {
	//���ʽڵ�,����bool,��ӡc,ֵ���ⲿ����
	printf("%d\t", e);
	return TRUE;
}
//end SqList.cpp
*/