#include "stdafx.h"
#pragma once
//�Զ��嶯̬������
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
	//����������'=',�� �Զ���������� �������帳ֵ
	Array<T>& operator = (const Array<T>& x);	
	//����������'[]',ʵ������������
	Array<T>& operator [] (int i) {
		//���������� �﷨
		//���ó�Ա����������ĸ�ʽ���£�
		//this��������˵���� operator ����� ���βα�{������}
		if (i<0 || i>Fsize) {
			cerr << "invalid index." << endl;
			exit(1);
		}
		return alist[i];
	}	
	//����������'T*'������ָ��ת�������������ص�ǰ"������"˽��������׵�ַ//�ö�����ָ�������ڲ�����ռ���׵�ַ
	Array<T>& operator * (void) const {
		//Array<T>& operator * (void) const {
		//T& operator * (void) const {
		//���ص�ǰ"������"˽��������׵�ַ
		return alist;
	}
	//Length()
	int ListSize(void) const {
		return Fsize;
	}
	//�޸�����Ĵ�С
	void Resize(int newSize);

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

//���ز����� '=',������������帳ֵ
template<typename T>
inline Array<T>& Array<T>::operator=(const Array<T>& x) {
	// TODO: �ڴ˴����� return ���

}



//�޸�����Ĵ�С
template<typename T>
inline void Array<T>::Resize(int newSize) {
	T* newArray; //����������ָ��
	if (newSize <= 0) { //�жϴ�С <= 0
		cerr << "invalid Array Size." << endl;
		return;
	}
	if (newSize != Fsize) { //�жϴ�С ����ͬ
		newArray = new T[newSize]; //malloc()
		if (newArray == 0) {
			cerr << "Memory Allocation Fail." << endl;
			return;
		}
	}
	int n = (newSize <= Fsize ? newSize : Fsize); //�ȴ�С
	for (int i = 0; i < n; i++) {
		newArray[i] = this.alist[i];
	}
	delete[] this.alist;
	this.alist = newArray;
	this.Fsize = newSize;
}


