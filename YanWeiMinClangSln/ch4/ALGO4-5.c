 /* algo4-5.c ����algo4-4.c�������ļ�,������ѯͼ�� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-5.h"
 #include"bo2-6.c"
 #include"c4-2.h"
 #include"bo4-2.c"

 #define MaxBookNum 10 /* ����ֻ��10���齨������ */
 #define MaxKeyNum 25 /* ���������������(�ؼ��ʵ������) */
 #define MaxLineLen 51 /* ��Ŀ��(����+���)buf����󳤶� */

 typedef struct
 {
   HString key; /* �ؼ���(�ѷ�������,c4-2.h) */
   LinkList bnolist; /* ����������������(c2-5.h) */
 }IdxTermType; /* ���������� */

 typedef struct
 {
   IdxTermType item[MaxKeyNum+1];
   int last; /* �ؼ��ʵĸ��� */
 }IdxListType; /* ����������(�����) */

 typedef struct
 {
   char bookname[MaxLineLen]; /* ��Ŀ�� */
   int bookno; /* ��� */
 }BookTermType; /* ��Ŀ������ */

 typedef struct BookListType /* ��Ŀ������(�����) */
 {
   BookTermType item[MaxBookNum];
   int last; /* ��Ŀ������ */
 }BookListType; /* ��Ŀ������(�����) */

 void main()
 {
   FILE *f; /* �κ�ʱ������һ���ļ� */
   IdxListType idxlist; /* ������ */
   BookListType booklist; /* ��Ŀ�� */
   char buf[MaxLineLen+1]; /* ��ǰ��Ŀ��(����'\0') */
   HString ch; /* �����ַ��� */
   int BookNo; /* ��ű��� */
   int i,k,l;
   Link p;
   InitString(&ch); /* ��ʼ��HString���͵ı��� */
   f=fopen("BookIdx.txt","r"); /* �������ؼ����������ļ� */
   if(!f)
     exit(OVERFLOW);
   fscanf(f,"%d",&idxlist.last); /* �����ؼ��ʸ��� */
   for(k=0;k<idxlist.last;k++) /* �ѹؼ����ļ������ݿ���idxlist�� */
   {
     fscanf(f,"%s",buf);
     i=0;
     while(buf[i])
       buf[i++]=tolower(buf[i]); /* ��ĸתΪСд */
     InitString(&idxlist.item[k].key);
     StrAssign(&idxlist.item[k].key,buf);
     InitList(&idxlist.item[k].bnolist); /* ��ʼ��������� bo2-6.c */
     fscanf(f,"%d",&i);
     for(l=0;l<i;l++)
     {
       fscanf(f,"%d",&BookNo);
       if(!MakeNode(&p,BookNo)) /* ����ʧ�� bo2-6.c */
         exit(OVERFLOW);
       p->next=NULL;
       Append(&idxlist.item[k].bnolist,p); /* �����µ�������� bo2-6.c */
     }
   }
   fclose(f);
   f=fopen("BookInfo.txt","r"); /* ����Ŀ�ļ� */
   if(!f)
     exit(FALSE);
   i=0;
   while(!feof(f)) /* ����Ŀ�ļ������ݿ���booklist�� */
   {
     fgets(buf,MaxLineLen,f);
     booklist.item[i].bookno=(buf[0]-'0')*100+(buf[1]-'0')*10+(buf[2]-'0'); /* ǰ��λΪ��� */
     strcpy(booklist.item[i].bookname,buf);
     i++;
   }
   booklist.last=i;
   printf("��������Ŀ�Ĺؼ���(һ��)");
   scanf("%s",buf);
   i=0;
   while(buf[i])
     buf[i++]=tolower(buf[i]); /* ��ĸתΪСд */
   StrAssign(&ch,buf);
   i=0;
   do
   {
     k=StrCompare(ch,idxlist.item[i].key); /* bo4-2.c */
     i++;
   }while(k&&i<=idxlist.last);
   if(!k) /* ���������д˹ؼ��� */
   {
     p=idxlist.item[i-1].bnolist.head->next;
     while(p)
     {
       l=0;
       while(l<booklist.last&&p->data!=booklist.item[l].bookno)
         l++;
       if(l<booklist.last)
         printf("%s",booklist.item[l].bookname);
       p=p->next;
     }
   }
   else
     printf("û�ҵ�\n");
 }