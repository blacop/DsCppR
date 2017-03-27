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
#define MAX_SIZE 1000;//�����ռ�
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
//------��̬����,�α�ʵ�ַ�,������ʵ������----------
//��̬���� ��ʼ�� ��λ Malloc Free ���� ɾ��
typedef struct { //��̬���� �ṹ�嶨�� ��װ
	ElemType data;//����������Ϳ���������Ļ����ͣ���������
	int cur; //�α���(Cursor) == nextָ��,��Ÿ�Ԫ�صĺ���������е��±�,Ϊ0ʱ��ָ��
}Component, SLinkList[MAX_SIZE]; //����ComponentΪSLinkList[MAX_SIZE]
/*
��̬����,�α�ʵ�ַ�,������ʵ������
�����һ�������һ��Ԫ����Ϊ����Ԫ�ش���,��������.
��̬���� ʹ������ʵ������������û��ָ��ı��������ʵ������ṹ
*/
Status InitList_SL_In_Ptr_Out_Bool(SLinkList &space) {
	//��ʼ����̬����
	//space[0].curΪͷָ��,"0"��ʾ��ָ��
	int i;
	//��һά����space�и��������ӳ�һ����������space[0].curΪͷָ�롣
	//��0����ʾ��ָ��
	for (i = 0; i < MAX_SIZE - 1; i++)
		space[i].cur = i + 1;
	//ͷ�α��β�α� ����������������� 
	//ͷ�α걣���һ��û������λ�õ��α� β�α걣���һ��������λ�õ��α�
	//���һ������ֵ�ķ�����cursor�α�Ϊ0
	//δʹ�õ�����Ԫ�س�Ϊ��������
	//����ͷ�α��β�α� ÿ���α걣������һ���ڵ���߼�λ�����
	space[MAX_SIZE - 1].cur = 0;//�������α긳ֵ ,
	return TRUE;
}
int ListLength_SL(SLinkList L){  //��̬������
	int i = 0;
	int len = 0;
	i = L[MAX - 1].cur;//iָ���һ�����
	//h = L->next;//hָ�� ͷָ��L->next, head=>node1
	while (i != NULL) { //��ͷ������β�������ؼ�����
		++len;
		i = L[i].cur;//pointer move 1
	}
	return len;//���صĳ��Ȼ��ʵ��С1��
}
int LocateElem_SL(SLinkList S, ElemType e) { //���ң����ؿ��з������±�
	//�ھ�̬�������Ա�L�в��ҵ�1��ֵΪe��Ԫ��
	//���ҵ����򷵻�����L�е����򣬷��򷵻�0
	i = S[0].cur;//iģ��ָ�� ,iָʾ���е�һ�����
	while (i && S[i].data != e)//�ڱ���˳������
		i = S[i].cur;//ָ������
	return i;
}
int Malloc_SLL(SLinkList space) { //��ȡ��ǰ���������±꣬���ؿ��з������±�,δ��ʹ��,��getCur������⣬
	int i = space[0].cur;	//��ǰ�����һ��Ԫ�ص�cur���ֵ
							//����Ҫ���صĵ�һ�����ÿ��е��±�
	if(space[0].cur) //��0��Ϊ0���ǿ�ָ��==ĩβ==������
		space[0].cur = space[i].cur;
	//����Ҫ�ó�һ��������ʹ����,�������Ǿ͵ð�������һ����������������
	//==ָ������,���з���ָ�����ƣ�0�±���α긳ֵΪi�±��Ӧ���α�
	return i;
}
void Free_SLL(SLinkList &space, int k) { 
	//���±�Ϊk�Ŀ��н����յ���������
	space[k].cur = space[0].cur; //�ѵ�һ��Ԫ��curֵ����Ҫɾ���ķ���cur
	space[0].cur = k;//��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
}//Free_SLL
Status ListInsert(SLinkList L, int i, ElemType e) { //��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e	
	int j, k, l; //l�Ǽ�������i�ǲ���λ��ָ�룬l��i - 1λ�ã��±굱��ָ��ǰ�ڵ��ָ��
	k = MAX_SIZE - 1;//ע��k���������һ��Ԫ�ص��±�
	if (i<1 || i>ListLength(L) + 1) // //�ж�λ���Ƿ���������i��Ԫ�ز�����
		return FALSE;//L+1����Ϊ ListLength()���� ����ֵ��ʵ�ʳ���С1 ��i����=length+1��ʾ���Բ��뵽���һ��λ��
	//�����L+1ʵ�ڸ㲻���װ��������ˣ������ˡ�
	j = Malloc_SLL(L);//��ÿ��з������±�
	if (j){ //not "0" ,Ϊ0��Ϊ�ձ�
		L[j].data = e;//д������
		for (l = 1; l <= i - 1; l++) { //��1��ʼ�ң��ҵ���i��Ԫ��֮ǰ i-1��λ��
			k = L[k].cur;//���ص��ǵ�i���±�ڵ���α�=>next=>Node1�� cur=>next,���һ��Ԫ�ص��α�ָ���һ��Ԫ��
			//k��ʾ��ǰ����ָ�룬����ѭ����ʾָ��k��head��ʼ���ƶ���i-1��,
		}
		L[j].cur = L[k].cur; 
		L[k].cur = j;
		//�ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
		//����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰ��Ԫ�ص�cur
		//��������� new->next = pre->next
		//��������� pre->next = 
		//new���²���Ľڵ㣬pre��i-1λ�õĽڵ�
		return TRUE;
	}
	return FALSE;
}
Status ListDelete_SL_Da(SLinkList L, int i) {
	//ɾ����L�е�i������Ԫ��e, 
	//j������������������ʱָ�룬���׻���
	int j, k;
	j = 0;
	if (i < 1 || ListLength(L)) //�ж�λ���Ƿ����
		return FALSE;
	k = MAX_SIZE - 1;//k.next = head ,  pointer ָ�� end <==> head 
	for (j = 0; j <= i - 1; j++){//Ѱ��i-1��ָ��
		k = L[k].cur;//delNow��ָ��,��ɾ��Ԫ�ص�ָ��
	}
	j = L[k].cur;//jָ���i��λ��
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return TRUE;
}
Status ListDelete_SL_Bo(SLinkList L, int i, int *e) { //ɾ����L�е�i������Ԫ��e
	int k = L[MAX - 1].cur; //k.next = head.next
	int j = 1, m; ////j����������m����ʱָ�룬�����׻���
	if (i<1 || i>ListLength(L))  //�ж�λ���Ƿ����
		exit(0);
	while (k && j<i - 1) { //�ҵ���i-1��λ��	
		++j;
		k = L[k].cur;//�ҵ���i-1��λ�� ,k���ǵ�i-1��λ��
	}
	m = L[k].cur;  //mָ���i��λ�á� , *m = pre.next <==>  *m = *del
				   // m��Ϊһ����ʱָ�룬��Ϊ�˸������Free()������
	*e = L[m].data; //ȡ����ɾ��������
	L[k].cur = L[m].cur;//pre.next = del.next
	Free(L, m); //�����н��m�ͷŵ�����������// free( &L, *m)
}