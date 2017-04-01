#pragma once
#include "stdafx.h"
//�Զ��嶯̬������
template<typename T>
class Array {
private:
	T* List;// T[] data
	int Length;//Length
	void Allocate(); //malloc()
public: //7�ַ���
		//Constructor(int size)
	//���캯�������� Length
	Array(int size = 50) {
		if (size = 0) {
			cerr << "Invalid Array Size." << endl;
			return;
		}
		Length = size;
		Allocate(); //malloc()
	}
	//Constructor(Constructor<T>& x),copy Constructor()
	//���캯�������� ������, ���ƹ��캯������ԭ�����Ƴ�1���¶���
	//ʾ�� new Array<T>& this(Array<T>& Src);
	Array(const Array<T>& Src) {
		this.Length = Src.Length;
		Allocate();
		for (int i = 0; i < Length; i++)
			this.List[i] = Src.List[i];
	}
	//De���캯��
	virtual ~Array() {
		delete[] List;//ɾ����������[]�ռ�
	}

	//����������'=',�� �Զ���������� �������帳ֵ
	//ʾ�� Array<T>& this = Array<T>& Src;
	Array<T>& operator=(const Array<T>& Src) {
		if (this.Length <= 0 || Src.Length <= 0) { //�жϴ�С <= 0
			cerr << "invalid Array Size !" << endl;
			return;
		}
		if (this.Length != Src.Length) { //�жϴ�С ����ͬ	
			cerr << "Array size not match !" << endl;
			return;
		}
		this.Length = Src.Length; //Length
		for (int i = 0; i < Length; i++) {
			this.List[i] = Src.List[i];
		}
	}

	//����������'[]',ʵ������������
	//ʾ�� Array<T>& this[i]
	Array<T>& operator[](int i) {
		//���������� �﷨
		//���ó�Ա����������ĸ�ʽ���£�
		//this��������˵���� operator ����� ���βα�{������}
		if (i < 0 || i >= this.Length) {
			cerr << "invalid index." << endl;
			exit(1);
		}
		return this.List[i];
	}

	////����������'[]',ʵ������������,������࣬T��������������
	////ʾ�� T& this[i]
	//T& operator[](int i) {
	//	//���������� �﷨
	//	//���ó�Ա����������ĸ�ʽ���£�
	//	//this��������˵���� operator ����� ���βα�{������}
	//	if (i<0 || i >= Length) {
	//		cerr << "invalid index." << endl;
	//		exit(1);
	//	}
	//	return List[i];
	//}

	////����������'<<',ʵ�������� cout<<����,дʧ����
	////ʾ�� cout << Array<T>& this[i]
	//Array<T>& operator<<(this[i]) {
	//	//���������� �﷨
	//	//���ó�Ա����������ĸ�ʽ���£�
	//	//this��������˵���� operator ����� ���βα�{������}
	//	if (i < 0 || i >= this.Length) {
	//		cerr << "invalid index." << endl;
	//		exit(1);
	//	}
	//	return List[i];
	//}

	//����������'T*'������ָ��ת�������������ص�ǰ"������"˽��������׵�ַ//�ö�����ָ�������ڲ�����ռ���׵�ַ
	//ʾ�� Array<T>& this*
	Array<T>& operator*(void) const {
		//Array<T>& operator * (void) const {
		//T& operator * (void) const {
		//���ص�ǰ"������"˽��������׵�ַ
		return List;
	}
	//Length()
	int ListSize(void) const {
		return Length;
	}
	//�޸�����Ĵ�С
	void Resize(int newSize);

	//����-----------�ָ���--------------------- 
	//������������Сֵ
	public static int FindMin(int[] arr) {
		int min = arr[0];
		for (int index = 0; index < arr.Length - 1; index++)
			if (arr[index] < min)
				min = arr[index];
		return min;
	}
	//�������������ֵ
	public static int FindMax(int[] arr) {
		int max = arr[0];
		for (int index = 0; index < arr.Length - 1; index++)
			if (arr[index] > max)
				max = arr[index];
		return max;
	}
	/*������������������һ���滻д���Ƿ������ֵ����Сֵ�������ڵ�λ�ã������Ƿ���ʵ�ʵ���ֵ��*/



};//!_class Array

//malloc()
template<typename T>
inline void Array<T>::Allocate() {
	List = new T[this.Length];
	if (List == 0)
		cerr << "Memory Allocation Fail." << endl;
}

//�޸�����Ĵ�С
template<typename T>
inline void Array<T>::Resize(int newSize) {
	if (newSize <= 0) { //�жϴ�С <= 0
		cerr << "invalid Array Size." << endl;
		return;
	}
	T* newArray; //����������ָ��
	if (newSize != Length) { //�жϴ�С ����ͬ
		newArray = new T[newSize]; //malloc()
		if (newArray == 0) {
			cerr << "Memory Allocation Fail." << endl;
			return;
		}
	}
	int n = (newSize <= Length ? newSize : Length); //�ȴ�С
	for (int i = 0; i < n; i++) {
		newArray[i] = this.List[i];
	}
	delete[] this.List;
	this.List = newArray;
	this.Length = newSize;
}


