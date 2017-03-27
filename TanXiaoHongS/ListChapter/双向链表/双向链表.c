#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE -1
#define NULL 0
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
#define LEN sizeof(DuLNode)
#define MLC (LinkList)malloc(sizeof(DuLNode))
/*
//���Ա�Ļ��������б�
InitList(&L) //��ʼ�����Ա�L
DestroyList(&L) //�������Ա�L
ClearList(&L) //������Ա�L
ListEmpty(L) //�ж����Ա��Ƿ�Ϊ��
ListLength(L) //�����Ա�L�ĳ���
GetElem(L,i,&e) //ȡ���Ա�L�ĵ�i��Ԫ��
LocateElem(L,e,compare()) //��λ�������Ա�L��Ԫ��e
compare() //�Ƚ�����Ԫ�صĴ�С,����Bool
compareArray() //�Ƚ���������Ĵ�С,����Bool
PriorElem(L,cur_e,&prio_e) //�������Ա�L��Ԫ��e��ֱ��ǰ��Ԫ��
NextElem(L,cur_e,&next_e) //�������Ա�L��Ԫ��e��ֱ�Ӻ��Ԫ��
ListInsert(&L,i,e) //�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e,����Bool
ListDelete(&L,i,e) //ɾ�����Ա�L�ĵ�i��Ԫ��,��ɾ��Ԫ��e��ֵ,����Bool
ListTraverse(L,visit()) //�������Ա�:���ζ�L��ÿ��Ԫ�ص���visit()
visit() //  visit һ����ָ��������ṹ�ж�ĳ���ڵ����ݽ��з��ʵĺ�����
//	����ȡ���ڵ�����ȥ��ĳһ���£�ͨ���㷨�в�д�����庯�����ݡ�
//  ��������ṹ���Զ���ʼ����ĳ��˳��˳��������ĳ���ڵ�Ĺ��̳�Ϊ��������
*/
//-------˫������ Tan--------------
typedef struct DuLNode { //��װ ˫������
	ElemType data;
	struct DuLNode *prior;//ǰ��
	struct DuLNode *next;//���
}DuLNode, *DuLinkList;

//��ʼ�� ˫������ �����Լ�����ָ�� ����һ��ͷ���
DuLinkList DuLinkListInit_Out_Ptr() {
	DuLinkList L = (LinkList)malloc(LEN);
	if (L == NULL)       //�ж��Ƿ����㹻���ڴ�ռ� 
		exit(OVERFLOW);
	L->next = NULL;  //nextָ���Լ�
	L->prior = NULL; //priorָ���Լ�
	return L;
}


Status ListInsert_Dul_Tail_Tan(DuLinkList &L, int i, ElemType e) {
	//�ڴ�ͷ���ĵ�˫��ѭ�������еĵ�i��λ�ò���Ԫ��e
	//Ѱ�ҵ�i-1��Ԫ��p��巨
	int j = 0; //������
	DuLinkList p = L; //p��Ϊ����Ŀ��ָ��
	DuLinkList s;//�½��
	while (j<i - 1 && p) { //Ѱ�ҵ�i-1��Ԫ�أ������i-1��Ԫ�غ���
		p = p->next; //�ƶ�ָ��
		j++; //������+1
	}
	if (!p) { //��ĳ���С��i,�ձ�
		return FALSE;
	}
	s = (DuLinkList)malloc(sizeof(ElemType));//�����ڴ�
	if (!s) { //�ռ䲻�������
		exit(OVERFLOW);
	}
	s->data = e;//������ֵ
				//��i-1��Ԫ��, p�����,
	s->next = p->next;
	s->prior = p;
	(p->next)->prior = s;
	p->next = s;
}
Status ListInsert_Dul_Head_Tan(DuLinkList &L, int i, ElemType e) {
	//�ڴ�ͷ���ĵ�˫��ѭ�������еĵ�i��λ�� ����Ԫ��e
	//Ѱ�ҵ�i��Ԫ��pǰ�巨
	int j = 0; //������
	DuLinkList p = L; //p��Ϊ����Ŀ��ָ��
	DuLinkList s;//�½��
	while (j <= i - 1 && p) { //Ѱ�ҵ�i��Ԫ�أ������i��Ԫ��ǰ��
		p = p->next; //�ƶ�ָ��
		j++;//������+1
	}
	if (!p) {
		return FALSE;//��ĳ���С��i
	}
	s = (DuLinkList)malloc(sizeof(ElemType));
	if (!s) {
		exit(OVERFLOW);//�ռ䲻�������
	}
	s->data = e; //������ֵ
				 //��i��Ԫ��, pǰ����,
	s->next = p;
	s->prior = p->prior;
	(p->prior)->next = s;
	p->prior = s;
}
Status ListDelete_Dul(DuLinkList &L, int i, ElemType e) {
	//�ڴ�ͷ���ĵ�˫��ѭ�������еĵ�i��λ�� ɾ��Ԫ��e
	int j = 0; //������
	DuLinkList p = L; //p��Ϊ����Ŀ��ָ��
	DuLinkList pre;//���ý��pre
	DuLinkList nex;//���ý��nex
	DuLinkList s;//���ý��cur
	while (j <= i - 1 && p) { //Ѱ�ҵ�i��Ԫ�أ������i��Ԫ��ǰ��
		p = p->next; //�ƶ�ָ��
		j++;//������+1
	}
	s = p;
	pre = p->prior;
	nex = p->next;
	e = s->data; //������ֵ
	pre->next = nex->prior;
	nex->prior = pre->next;

	(s->prior)->next = (s->next)->prior;
	(s->next)->prior = (s->prior)->next;


}