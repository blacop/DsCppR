#include "stdafx.h"
#pragma once
//�ַ����ඨ��
//ģʽ���Ӵ���ƥ��
class String {

public:
	char* str; //data domain
	int size; //length
	String() {}
	virtual ~String() {}

	//ģʽ���Ӵ���ƥ�䣬����ƥ��ģʽ
	int Find(String pat) const {
		//ģʽ����Ŀ�괮
		char *p = pat.str, *s = str;
		//sub's length
		int i = 0;
		//sub's length <= size - pat.size means ʣ�೤��
		while (i <= size - pat.size) {
			//ƥ��,ptr++
			while (*p++ == *s++)
				//����ģʽ����end sub string, means ƥ��ɹ�
				if (*p == '\0') return i;
			//else������ƥ��ʧ��, src staart ptr ++ move
			i++; p = pat.str; s = str + i;
		}
		return -1;
	}
};

