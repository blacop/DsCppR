/*
�������������
//http://blog.csdn.net/hackbuteer1/article/details/6591486/?reload#
�������
���� ������һ�ֳ�������Ҫ�����ݽṹ�����Ƕ�̬�ؽ��д洢�����һ�ֽṹ�������Ը�����Ҫ�����ڴ浥Ԫ��������һ����ͷָ�롱��������head��ʾ�������һ����ַ���õ�ַָ��һ��Ԫ�ء�������ÿһ��Ԫ�س�Ϊ����㡱��ÿ����㶼Ӧ�����������֣�һΪ�û���Ҫ�õ�ʵ�����ݣ���Ϊ��һ�����ĵ�ַ����ˣ�headָ���һ��Ԫ�أ���һ��Ԫ����ָ��ڶ���Ԫ�أ�������ֱ�����һ��Ԫ�أ���Ԫ�ز���ָ������Ԫ�أ�����Ϊ����β�������ĵ�ַ���ַ�һ����NULL������ʾ���յ�ַ�����������˽�����
        ����ĸ������������ѧϰ��������Ĵ�����ɾ����  ���루�������򣩡������  ����ѡ�񡢲��롢ð�ݣ�������ȵȡ�

       ���������ͼʾ��
       ---->[NULL]
      head

      ͼ1��������

       ---->[p1]---->[p2]...---->[pn]---->[NULL]
      head   p1->next  p2->next   pn->next

      ͼ2����N���ڵ������

      ����n���ڵ������ĺ���Ϊ��
*/

#include "stdlib.h"
#include "stdio.h"
#define NULL 0
#define LEN sizeof(struct student)

struct student{
	int num;			  //ѧ�� 
	float score;	      //������������Ϣ���Լ��������������ֶ�
	struct student *next;		//ָ����һ�ڵ��ָ��
};
int n;	//�ڵ����� 
/*
==========================
���ܣ�����n���ڵ������
���أ�ָ�������ͷ��ָ��
==========================
*/
struct student *Create()
{
	struct student *head;		//ͷ�ڵ�
	struct student *p1 = NULL;	//p1���洴�����½ڵ�ĵ�ַ
	struct student *p2 = NULL;	//p2����ԭ�������һ���ڵ�ĵ�ַ

	n = 0;			//����ǰ����Ľڵ�����Ϊ0��������
	p1 = (struct student *) malloc (LEN);	//����һ���½ڵ�
	p2 = p1;			//����ڵ㿪�ٳɹ�����p2�Ȱ�����ָ�뱣�������Ա�����

	if(p1==NULL)		//�ڵ㿪�ٲ��ɹ�
	{
		printf ("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}
	else				//�ڵ㿪�ٳɹ�
	{
		head = NULL;		//��ʼheadָ��NULL
		printf ("Please input %d node -- num,score: ", n + 1);
		scanf ("%d %f", &(p1->num), &(p1->score));	//¼������
	}
	while(p1->num != 0)		//ֻҪѧ�Ų�Ϊ0���ͼ���¼����һ���ڵ�
	{
		n += 1;			//�ڵ���������1��
		if(n == 1)		//����ڵ�������1����headָ��մ����Ľڵ�p1
		{
			head = p1;
			p2->next = NULL;  //��ʱ��p2����p1,Ҳ����p1->nextָ��NULL��
		}
		else
		{
			p2->next = p1;	//ָ���ϴ�����ոտ��ٵ��½ڵ�
		}

		p2 = p1;			//��p1�ĵ�ַ��p2������Ȼ��p1�����µĽڵ�

		p1 = (struct student *) malloc (LEN);
		printf ("Please input %d node -- num,score: ", n + 1);
		scanf ("%d %f", &(p1->num), &(p1->score));
	}
	p2->next = NULL;		//�˾���Ǹ��ݵ�����������һ���ڵ�Ҫָ��NULL

	free(p1);			//p1->numΪ0��ʱ��������whileѭ���������ͷ�p1
	p1 = NULL;			//�ر�Ҫ���ǰ��ͷŵı��������ΪNULL,����ͱ��"Ұָ��"������ַ��ȷ����ָ��
	return head;	    //���ش��������ͷָ�� 
}