//���ṹ��
#pragma once
#include "stdafx.h"

//���������
template <typename T>
typedef class GNode<T> *GList;
//�����������
template <typename T>
class GNode {
public:
	int Tag;//��־��0��ʾ����ǵ�Ԫ�أ�1��ʾ����ǹ����
	union { //�ӱ�ָ����Sublist�뵥Ԫ��������Data���ã������ô洢�ռ�
		T data;
		GList SubList;
	}URegion;
	GList Next; //ָ���̽��

	GNode() {}
	virtual ~GNode() {}
};



