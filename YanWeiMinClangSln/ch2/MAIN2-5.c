 /* main2-5.c ����bo2-5.c�������� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-4.h"
 #include"bo2-5.c"

 Status compare(ElemType c1,ElemType c2) /* ����Ԫ���ж�����(�ж����) */
 {
   if(c1==c2)
     return TRUE;
   else
     return FALSE;
 }

 void vd(ElemType c) /* ListTraverse()���õĺ���(����һ��) */
 {
   printf("%d ",c);
 }

 void main()
 {
   DuLinkList L;
   int i,n;
   Status j;
   ElemType e;
   InitList(&L);
   for(i=1;i<=5;i++)
     ListInsert(L,i,i); /* �ڵ�i�����֮ǰ����i */
   printf("�������������");
   ListTraverse(L,vd); /* ������� */
   printf("�������������");
   ListTraverseBack(L,vd); /* ������� */
   n=2;
   ListDelete(L,n,&e); /* ɾ�����ͷŵ�n����� */
   printf("ɾ����%d����㣬ֵΪ%d��������Ϊ��",n,e);
   ListTraverse(L,vd); /* ������� */
   printf("������Ԫ�ظ���Ϊ%d\n",ListLength(L));
   printf("�����Ƿ�գ�%d(1:�� 0:��)\n",ListEmpty(L));
   ClearList(L); /* ������� */
   printf("��պ������Ƿ�գ�%d(1:�� 0:��)\n",ListEmpty(L));
   for(i=1;i<=5;i++)
     ListInsert(L,i,i); /* ���²���5����� */
   ListTraverse(L,vd); /* ������� */
   n=3;
   j=GetElem(L,n,&e); /* �������ĵ�n��Ԫ�ظ�ֵ��e */
   if(j)
     printf("�����ĵ�%d��Ԫ��ֵΪ%d\n",n,e);
   else
     printf("�����ڵ�%d��Ԫ��\n",n);
   n=4;
   i=LocateElem(L,n,compare);
   if(i)
     printf("����%d��Ԫ���ǵ�%d��\n",n,i);
   else
     printf("û�е���%d��Ԫ��\n",n);
   j=PriorElem(L,n,&e);
   if(j)
     printf("%d��ǰ����%d\n",n,e);
   else
     printf("������%d��ǰ��\n",n);
   j=NextElem(L,n,&e);
   if(j)
     printf("%d�ĺ����%d\n",n,e);
   else
     printf("������%d�ĺ��\n",n);
   DestroyList(&L);
 }