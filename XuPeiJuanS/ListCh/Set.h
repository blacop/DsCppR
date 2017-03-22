#include "stdafx.h"
#pragma once
//10��ö��
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

//������Set������
template<typename T>
class Set {
private:
	//������ ��Աָ�� ����ָ�룬ָ��һάԪ�ص��׵�ַ
	unsigned short *member;
	//������Ԫ�ظ��������ֵ
	int setrange;
	//λ�����Ԫ�ظ���
	int arraySize;
	//ȷ��elt��������member�е��ĸ�����Ԫ��
	int ArrayIndex(const T& elt) const;
public: //9������
	//���캯�������������ͼ���
	Set(int setrange);
	//��������
	virtual ~Set(void);
	//����"+"Ϊ�������ϵĲ���,����������
	Set<T> operator + (const Set<T>& x) const;
	//����Ԫ��elt
	void Insert(const T& elt);
	//ɾ��Ԫ��elt
	void Delete(const T& elt);
	//�ж�elt�Ƿ��ڼ�����
	int IsMember(const T& elt);
	//���룬����һ��16λ�Ķ����������г���elt���ڵ�λֵΪ1�⣬�����λֵΪ0.
	unsigned short BitMask(const T& elt) const;
	//λ����ת��������int value,��int
	int ConvertBitMask(int val) {
		int bitMask = 1 << val;
		return bitMask;
	}
	//������ת��������int,��StringBuilder
	StringBuilder ConvertBits(int val) {
		int bitMask = 1 << 31;
		StringBuilder bitBuffer = new StringBuilder(35);
		for (int i = 1; i <= 32; i++) {
			if ((val & bitMask) == 0)
				bitBuffer.Append("0");
			else
				bitBuffer.Append("1");
			val <<= 1;
			if ((i % 8) == 0)
				bitBuffer.Append(" ");
		}
		return bitBuffer;
	} //������ת��������int,��string
};

//ȷ��elt��������member�е��ĸ�����Ԫ��,��������Ԫ�ص�order
template<typename T>
inline int Set<T>::ArrayIndex(const T & elt) const {
	//  elt.value /16
	int listIndex = elt >> 4;
	return listIndex;
}

//���룬����һ��16λ�Ķ����������г���elt���ڵ�λֵΪ1�⣬�����λֵΪ0.
template<typename T>
inline unsigned short Set<T>::BitMask(const T & elt) const {
	//��ֵ���
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	unsigned short mask = 1 << elt;
	return mask;
}

//���캯�������������ͼ���
template<typename T>
inline Set<T>::Set(int setrange) :setrange(setrange) {
	// >>4 => /16, λ����ĳ��ȹ�ʽ: (setrange + 15) >> 4
	int ArraySize = (setrange + 15) >> 4;

	//��������ռ� ,λ����Ĳ����������޷��ŵ�short���� 16λ 2�ֽ�,
	member = new unsigned short[arraySize];
	if (member == NULL)
		Error(OutOfMemory);
	//������λ����Ϊ0,�Դ����ռ�
	for (int i = 0; i < arraySize; i++) {
		member[i] = 0;
	}
}

//����"+"Ϊ�������ϵĲ���,���������� //this + Set<T>& x
template<typename T>
inline Set<T> Set<T>::operator+(const Set<T>& x) const {
	//���ȼ��
	if (setrange != x.setrange)
		Error(SetsDifferentSize);
	//�ü���tmp��Ų���
	Set<T> tmp(setrange);
	//�ʲ�����λֵΪ�������ϵİ�λ��
	for (int i = 0; i < arraySize; i++) {
		tmp.member[i] = member[i] | x.member[i];
		return tmp;
	}
}

//����Ԫ��elt
template<typename T>
inline void Set<T>::Insert(const T & elt) {
	//elt�Ƿ���0~setrange-1֮��
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	//��elt����λֵΪ1
	member[ArrayIndex(elt)] |= BitMask(elt);
}

//ɾ��Ԫ��elt
template<typename T>
inline void Set<T>::Delete(const T & elt) {
	//elt�Ƿ���0~setrange-1֮��
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	//��elt����λֵΪ0
	member[ArrayIndex(elt)] &= (!BitMask(elt));
}

//�ж�elt�Ƿ��ڼ�����
template<typename T>
inline int Set<T>::IsMember(const T & elt) {
	//��ֵ���//�쳣��׽����ֵ����������ֵ��Χ
	if (int(elt) < 0 || int(elt) >= setrange)
		Error(InvalidMemberRef);
	//��elt���ڼ����У�����0;���򣬷���һ����0ֵ
	return member[ArrayIndex(elt)] & BitMask(elt);
}



