#include "stdafx.h"
#pragma once
template<typename T>
class Array {
private:
	T* alist;// T[] data
	int Fsize;//Length
	void Allocate(); //malloc()	
public: //7�ַ���
	//���캯�������� Fsize
	Array(int sz = 50);
	//���캯�������� ������, ���ƹ��캯������ԭ�����Ƴ�1���¶���
	Array(const Array<T>& x);
	//De���캯��
	virtual ~Array() {
		delete[] alist;//ɾ����������[]�ռ�
	}
	//���ز����� '=',������������帳ֵ
	Array<T>& operator = (const Array<T>& x);
	//���ز����� '[]',����ʵ������������
	T& operator [] (int i);
	//���ز����� 'T*'��typenameת��Ϊָ�����ͣ��ö���������ָ������ռ���׵�ַ,����ʵ������������
	Array<T>& operator T* (void)const {
		return alist;
	}
	//Length()
	int ListSize(void) const {
		return Fsize;
	}
};//!_class Array

//malloc()
template<typename T>
inline void Array<T>::Allocate() {
	alist = new T[Fsize];
	if (alist == 0)
		cerr << "Memory Allocation Fail." << endl;
}

//Constructor(int size)
template<typename T>
inline Array<T>::Array(int sz) {
	if (sz = 0) {
		cerr << "Invalid Array Size." << endl;
		return;
	}
	Fsize = sz;
	Allocate();
}

//Constructor(Constructor<T>& x),copy Constructor()
template<typename T>
inline Array<T>::Array(const Array<T>& x) {
	Fsize = x.Fsize;
	Allocate();
	for (int i = 0; i < Fsize; i++)
		alist[i] = x.alist[i];
}
