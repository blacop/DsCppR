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
typedef int ElemType;
typedef int Status;
/*
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//���Ա�Ļ���������������

Status InitList(SqList &L);
//�������������һ���յ����Ա�L�� 1

Status DestroyList(SqList &L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//����������������Ա�L�� 2

Status ClearList(SqList &L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������L����Ϊ�ձ� 3

bool ListEmpty(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE�� 4

int ListLength(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�������������L������Ԫ�صĸ����� 5

Status GetElem(SqList L, int i, ElemType &e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)��
//�����������e����L�е�i������Ԫ�ص�ֵ�� 6

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�������
//����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0. 7

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣 8

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣9

Status ListInsert(SqList &L, int i, ElemType e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1.
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1. 10

Status ListDelete(SqList &L, int i, ElemType &e);
//��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L).
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1. 11

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//��ʼ���������Ա�L�Ѵ���
//������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ� 12
*/
/*
//���Ա�Ļ���������������
InitList(&L) //��ʼ�����Ա�L  1
DestroyList(&L) //�������Ա�L  2
ClearList(&L) //������Ա�L  3
ListEmpty(L) //�ж����Ա��Ƿ�Ϊ�� 4
ListLength(L) //�����Ա�L�ĳ��� 5
GetElem(L,i,&e) //ȡ���Ա�L�ĵ�i��Ԫ�� 6
LocateElem(L,e,compare()) //��λ�������Ա�L��Ԫ��e 7
PriorElem(L,cur_e,&prio_e) //�������Ա�L��Ԫ��e��ֱ��ǰ��Ԫ�� 8
NextElem(L,cur_e,&next_e) //�������Ա�L��Ԫ��e��ֱ�Ӻ��Ԫ�� 9
ListInsert(&L,i,e) //�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e,����Bool 10
ListDelete(&L,i,e) //ɾ�����Ա�L�ĵ�i��Ԫ��,��ɾ��Ԫ��e��ֵ,����Bool 11
ListTraverse(L,visit()) //�������Ա�:���ζ�L��ÿ��Ԫ�ص���visit() 12
*/
/*�����㷨
//reverseList(&L1) //���� ������
//mergeList(&L1,L2) //�ϲ� �������Ա�L 15
//visit(e) //  һ����ָ��������ṹ�ж�ĳ���ڵ����ݽ��з��ʵĺ����� 13
//compare(e1,e2) //�Ƚ�����Ԫ�صĴ�С,����Bool 14
//compareList(L1,L2) //�Ƚ��������Ա�L�Ĵ�С,����Bool 14
//mergeList(&L1,L2) //�ϲ��������Ա�L 15
*/
//---------------���Ե�����----------------
//������ ��ʼ�� ���� ͷ�巨 β�巨 ���� ɾ�� ���� �ϲ� ����
typedef struct Node { //��װ �ṹ�� ����Ľ��==����Ԫ��Elem,����ָ��==����==���ݶ���Obj
	ElemType data;  //����Domain ,������item
	struct Node * next; //ָ��,����Reference,������item
}Node, *PNode;
Status InitList(struct Node *L) { /* ���ܣ�����һ���յĴ�ͷ�ڵ�ĵ�����*/
	(*L) = (struct Node *)malloc(sizeof(struct Node)); //����ͷ�ڵ�
	if (!*L)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}
Status DestroyList(struct Node *L) { /*�������Ա�*/
									  //pHead == L
	struct Node *q;//temp ptr, q <==> L->next
	while (L) {
		q = L->next;//q++
		free(L);//free l //��ͷ��ʼfree(),һֱ�����һ��
		L = q;//L++
	}
	return OK;
}
Status ClearList(struct Node *L) { /*��L����Ϊ�ձ�*/
	Node *p, *q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
Status ListEmpty(Node *L) { /*�ж������Ƿ�Ϊ�ձ�*/
	if (L->next) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
int ListLength(struct Node *L) { /*���ص�������Ԫ�صĸ���*/
	int i = 0;
	Node *p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
Status GetElem(struct Node *L, int i, ElemType *e) {
	/* LΪ��ͷ�ڵ�ĵ������ͷָ�룬����i��Ԫ�ش���ʱ����ֵ����e,������OK */
	int j = 1;
	Node *p = L->next;
	while (p && j < i) { //until i-1
		p = p->next; //p++
		j++;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}
int LocateElem(struct Node *L, ElemType e, Status(*compare) (ElemType, ElemType)) {
	/*����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��
	�������ڷ���ֵΪ0��compare()������Ԫ�ص��ж�����*/
	int i = 0;
	Node *p = L->next;
	while (p) {
		i++;
		if (compare(p->data, e))//compare(*p,e) which SqList
			return i;
		p = p->next;//p++ which SqList
	}
	return 0;
}
Status PriorElem(struct Node *L, ElemType cur_e, ElemType *pre_e) {
	/*��cur_e��L�е�����Ԫ�أ��Ҹ��͵�һ��������pre_e��������ǰ��*/
	Node *q, *p = L->next;//p<==>node1 //2 assist Ptr
	while (p->next) {
		q = p->next;//qָ��p�ĺ��,q++, node2,no head(node0) because it's no data
		if (q->data == cur_e) { //���'s data is matching cur_e
			*pre_e = p->data; //out data is ���'s ǰ��
			return OK;
		}
		p = q;//p++
	}
	return INFEASIBLE;
}
Status NextElem(struct Node *L, ElemType cur_e, ElemType *next_e) {
	/* ��cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ��*/
	Node *p; //1 assist Ptr
	p = L->next; //node1
	while (p->next) { //have node
		if (p->data == cur_e) { //cur's data is matching
			*next_e = p->next->data; //out cur's next data 
			return OK;
		}
		p = p->next;//
	}
	return INFEASIBLE;
}
Status ListInsert(struct Node *L, int i, ElemType e) {
	/* �ڴ�ͷ�ڵ�ĵ�����L�еĵ�i��λ��֮ǰ(before i means index == i-2)����Ԫ��e*/
	int j = 0;
	struct Node *p = L, *s = NULL; //2 assist Ptr,2������ָ��
	while (p && j < i - 1) {
		//Loc(i)'s index==(i-1),before i means index ==(i-2) �ҵ� ��(i-1)��λ��,�������
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (struct Node *)malloc(sizeof(struct Node));
	if (!s)
		printf("malloc error~\n");
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(Node *L, int i, ElemType *e) {
	/*�ڴ�ͷ�ڵ�ĵ�������ɾ����i��Ԫ�أ�����e������ֵ*/
	Node *p = L, *q; //2 assist Ptr,2������ָ��
	int j = 0;
	while (p->next && j < i - 1) { // find Loc(i-1)== find index==(i-2)
		p = p->next; //p++
		j++; // now p's Loc is Loc(i-1).
	}
	if (!p->next || j > i - 1)//becase j must cirle (i-1) times.
		return ERROR;
	q = p->next;//q finger to p's ���Subsequent,p is i's ǰ��precursor,
	p->next = q->next;//
	*e = q->data; //out data
	free(q);
	return OK;
}
Status ListTraverse(struct Node *L, void(*visit)(ElemType)) {
	/* ���ζ�L��ÿ��Ԫ�ص���vi(),��ӡ������*/
	Node *p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
void MergeList_Link_Guan(Node &La, Node &Lb) {
	//��֪La��Lb��������
	//�ϲ��õ��µĵ�����Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	Node pa, pb, p, q;
	pa = La->next;
	pb = Lb->next;
	q = La;//�����ʱָ��,q����pa��ǰ��Ԫ��,q����ʼ����Ϊpa��ǰ��Ԫ��
	t = Lb;
	while (pa && pb) {
		if (pa->data <= pb->data) {//���С��=��pcָ��ָ��pa
			q = pa;//q���� 
			pa = pa->next;//pa����
		}
		else {
			//��� �� ֻ�� ��    pa->data > pb->data,��pb���뵽pa��ǰ��
			//ת�� �ж����� ��� pb->data > pa->data ,��pb���뵽pa��ǰ��
			t = pb;// t ����
			pb = pb->next;//pb����
			t->next = pa;//pb���뵽pa��ǰ��
			q->next = t;
			q = t;//q����ʼ����Ϊpa��ǰ��Ԫ��,���t��ֵ��q
		}//2�������������С����ǰ�棬�������д�����������࿴��,��ΪC��A��Bֻ��������ȥ����ʱpc�������2�������������
	}
	if (pb) { //pb����
		q->next = pb; //��������ʣ���pb
	}
}//MergeList_Link_Yan
void reverse_ite(Node * list) {
	//���� ������ʽ ���д���о�����������
	Node * old_head = NULL;         //ԭ�������ͷ  
	Node * new_head = NULL;      //�������ͷ  
	Node * cur = list;      //���ԭ�������ͷ  
	//ÿ�ν�ԭ�������ͷȡ���������뵽�������У��������������ͷ  
	while (cur != NULL) {
		old_head = cur->next;      //��ԭ�������ͷȡ���������ڶ����ڵ���Ϊͷ�ڵ�  
		cur->next = new_head;   //��ȡ����ͷ��Ϊ�������ͷ  
		new_head = cur;      //�������ͷ����Ŀǰ�������ͷ  
		cur = old_head;     //���Ŵ���  
	}
	List = new_head;
}
void reverse_recursive(Node * old_head, Node * new_head) {
	//���� �ݹ鷽ʽ 
	if (old_head == NULL) {
		List = new_head;
		return;
	}

	Node * tmp = old_head->next;        //��ԭ�������ͷȡ���������ڶ����ڵ���Ϊԭ�������ͷ�ڵ�������һ��ݹ�  
	old_head->next = new_head; //��ȡ����ͷ��Ϊ�������ͷ  
	reverse_recursive(tmp, old_head);         //���Ŵ���  
}
void make_list() {
	//�������� 
	List = (Node *)malloc(sizeof(Node) * LIST_LEN);
	int i = 0;
	for (i = 0; i < (LIST_LEN - 1); i++) {
		(List + i)->data = i + 1;
		(List + i)->next = List + i + 1;
	}
	(List + LIST_LEN - 1)->data = LIST_LEN;
	(List + LIST_LEN - 1)->next = NULL;
} 
void print_list() {
	//��ӡ���� ��data 
	Node * cur = List;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
int main() { //��������
	make_list();
	print_list();
	reverse_ite(List);     //������ʽ  
						   //reverse_recursive(List, NULL);     //�ݹ鷽ʽ  
	print_list();
}

