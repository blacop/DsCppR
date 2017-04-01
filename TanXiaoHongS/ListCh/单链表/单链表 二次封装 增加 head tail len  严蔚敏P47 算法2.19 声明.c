#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
/*
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
typedef struct LNode { //��װ �ṹ�� ����Ľ��==����Ԫ��Elem,����ָ��==����==���ݶ���Obj
	ElemType data;  //����Domain ,������item
	struct LNode *next; //ָ��,����Reference,������item
}LNode,*Link,*Position;
typedef struct Linklist{ //���η�װ �ṹ��
	Link head;
	Link tail;
	int len;
}Linklist;
//�������� ��ͷβ���� �Ļ��������������� 21��CORE
Status MakeNode(Link &p, ElemType e);
//������pָ���ֵΪe�Ľ��,������TRUE,������ʧ��,�򷵻�FALSE 1
void FreeNode(Link &p); 
//�ͷ�p��ָ���  2
Status InitList(LinkList &L);
//�������������һ���յ���������L�� 3
Status DestroyList(LinkList &L);
//��ʼ��������������L�Ѵ��ڡ�
//���������������������L�� 4
Status ClearList(LinkList &L);
//��ʼ��������������L�Ѵ��ڡ�
//�����������L����Ϊ�ձ� 5
Status InsFirst(Link h, Link s);
//��֪hָ�����������ͷ���,��s��ָ�������ڵ�һ�����֮ǰ 6
Status DelFirst(Link h, Link s);
//��֪hָ�����������ͷ���,ɾ�������еĵ�һ����㲢��q���� 7
Status Append(LinkList &L, Link s);
//��ָ��s��ָ(�˴���ָ������)��һ�������������������L�����һ�����
//֮��,���ı�����L��βָ��ָ���µ�β��� 8
Status Remove(LinkList &L, Link &q);
//ɾ����������L�е�β��㲢��q����,�ı�����L��βָ��ָ���µ�β��� 9
Status InsBefore(LinkList &L, Link &p, Link s);
//��֪hָ�����������һ�����,��s��ָ��������p��ָ���֮ǰ 
//���޸�ָ��pָ���²���Ľ��  10
Status InsAfter(LinkList &L, Link &p, Link s);
//��֪pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮��,
//���޸�ָ��pָ���²���Ľ��  11
ElemType GetCurElem(Link &p, ElemType e);
//��֪pָ����������L�е�һ�����,����p��ָ���������Ԫ�ص�ֵ 12
Status ListEmpty(LinkList L);
//��ʼ��������������L�Ѵ��ڡ�
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��13
int ListLength(LinkList L);
//��ʼ��������������L�Ѵ��ڡ�
//�������������L������Ԫ�صĸ����� 14
Position GetHead(LinkList L);
//������������L��ͷ����λ�� 15
Position GetLast(LinkList L);
//������������L�����һ������λ�� 16
Position PriorPos(LinkList L, Link p);
//��֪pָ����������L�е�һ�����,����p��ָ����ֱ��ǰ����λ��,
//����ǰ��,�򷵻�NULL  17
Position NextPos(LinkList L, Link p);
//��֪pָ����������L�е�һ�����,����p��ָ����ֱ�Ӻ�̵�λ��,
//���޺��,�򷵻�NULL  18
Status LocatePos(LinkList L, int i, Link &p);
//����pָʾ��������L�е�i������λ�ò�����TRUE,iֵ���Ϸ�ʱ����FALSE 19
Position LocateElem(LinkList L, ElemType e, bool(*compare)(ElemType, ElemType));
//��ʼ��������������L�Ѵ��ڣ�compare()������Ԫ���ж�������
//������������L�е�1����e���㺯��compare()�ж���ϵ������Ԫ�ص�λ�á�
//������������Ԫ�ز����ڣ��򷵻�NULL 20
Status ListTraverse(LinkList L, bool(*visit)(ElemType));
//��ʼ��������������L�Ѵ���
//������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ� 21
/*
//----������ѡ----
Status GetElem(LinkList L, int i, ElemType &e);
//��ʼ��������������L�Ѵ��ڣ�1<=i<=ListLength(L)��
//�����������e����L�е�i������Ԫ�ص�ֵ�� 6
int LocateElem(LinkList L, int e, bool(*equal)(ElemType, ElemType));
//��ʼ��������������L�Ѵ��ڣ�compare()������Ԫ���ж�������
//����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0. 7

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
//��ʼ��������������L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣 8

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
//��ʼ��������������L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣9

Status ListInsert(LinkList &L, int i, ElemType e);
//��ʼ��������������L�Ѵ��ڣ�1<=i<=ListLength(L)+1.
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1. 10

Status ListDelete(LinkList &L, int i, ElemType &e);
//��ʼ��������������L�Ѵ����ҷǿգ�1<=i<=ListLength(L).
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1. 11
*/
/*
//��������Ļ���������������
InitList(&L) //��ʼ����������L  1
DestroyList(&L) //������������L  2
ClearList(&L) //�����������L  3
ListEmpty(L) //�ж����������Ƿ�Ϊ�� 4
ListLength(L) //����������L�ĳ��� 5
GetElem(L,i,&e) //ȡ��������L�ĵ�i��Ԫ�� 6
LocateElem(L,e,compare()) //��λ������������L��Ԫ��e 7
PriorElem(L,cur_e,&prio_e) //������������L��Ԫ��e��ֱ��ǰ��Ԫ�� 8
NextElem(L,cur_e,&next_e) //������������L��Ԫ��e��ֱ�Ӻ��Ԫ�� 9
ListInsert(&L,i,e) //����������L�ĵ�i��Ԫ��֮ǰ����Ԫ��e,����Bool 10
ListDelete(&L,i,e) //ɾ����������L�ĵ�i��Ԫ��,��ɾ��Ԫ��e��ֵ,����Bool 11
ListTraverse(L,visit()) //������������:���ζ�L��ÿ��Ԫ�ص���visit() 12
*/
/*�����㷨
//reverseList(&L1) //���� ������ 
//mergeList(&L1,L2) //�ϲ� ������������L 15
//visit(e) 
//  һ����ָ��������ṹ�ж�ĳ���ڵ����ݽ��з��ʵĺ����� 13
//	����ȡ���ڵ�����ȥ��ĳһ���£�ͨ���㷨�в�д�����庯�����ݡ�
//  ��������ṹ���Զ���ʼ����ĳ��˳��˳��������ĳ���ڵ�Ĺ��̳�Ϊ��������
*/