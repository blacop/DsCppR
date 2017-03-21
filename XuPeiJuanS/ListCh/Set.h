#include "stdafx.h"
#pragma once
enum ErrorType { //ö������	
	InvalidMember, //��Ч��Ա
	ExpectRightBrace, //û��������
	MissingValue, //û��ֵ
	MissingComma, //û�ж���
	InvalidChar,
	MissingLeftBrace,
	InvalidInputData,
	EndOfFile,
	OutOfMemory,
	InvalidMemberRef,
	SetsDifferentSize
};
template <typename T> class Set
//������Set������
class Set {
private:
	//������Ԫ�ظ��������ֵ
	int setrange;
	//λ�����Ԫ�ظ���������ָ��
	int arraySize;
	//��Աָ��
	unsigned short *member;
	//ȷ��elt��������member�е��ĸ�����Ԫ��
	int ArrayIndex(const T &elt) const;
	//����һ��16λ�Ķ����������г���elt���ڵ�λֵΪ1�⣬�����λֵΪ0.
	unsign short BitMask(const T &elt) const;

public:

	Set() {}

	virtual ~Set() {}
};

