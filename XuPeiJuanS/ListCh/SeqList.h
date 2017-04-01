#pragma once
#include "stdafx.h"

//SeqList,˳�����Ա�
template <typename T> //ģ���࣬ʵ�ַ���,Tָ�ľ���Ԫ������
class SeqList {
private:
	T* data; //��Ԫ�����飬 T * ����ָ�� //��һ��д�� T[] data��	
	int last;//����ָ��	
	int MaxSize; //���Ԫ�ظ���
public: //5������
	SeqList(int Max = 10);//���캯��,className();���û�д���ֵ��Ĭ��Ϊ10,����д�Ͳ���д�޲�����������
	virtual ~SeqList() { delete[] data; } //��������,~className(); //delete������ [] ����� �����ͷ�����data������ڴ�ռ�
	int Locate(const T& x) const;//���ر���Ԫ��x��λ�ã�����const��ʾ ��Ա�������ܱ��޸ģ�T& x��T�����βΣ�& x���ô�ֵ//const��Ա���������޸ĵ��øú����Ķ���
	int Insert(int k, const T& x);//�ڱ��λ��K������Ԫ��x
	int Delete(int k, T& x);//�ӱ���ɾ��λ��k����Ԫ��x	
};//!_class SeqList,4������ʵ��

template <typename T>
inline SeqList<T>::SeqList(int Max) {
	//���캯��
	//ģ���࣬�綨������ҪдSeqList<T>::
	MaxSize = Max;
	data = new T[MaxSize]; //��̬��������
	last = -1; //����ָ��
}

template <typename T>
inline int SeqList<T>::Locate(const T& x) const {
	//���ұ���Ԫ��x��λ�ã�return index
	//���ر���Ԫ��x��λ��
	//const��Ա���������޸ĵ��øú����Ķ���
	int i = 0; //��ʱָ��
	while (i <= last && data[i] != x)  //˳����ң���ʱָ�� i++
		i++;
	if (i > last)   //����ʧ��
		return -1;
	else			//���ҳɹ�
		return i;
}

template <typename T>
inline bool SeqList<T>::Insert(int k, const T & x) {
	//����Ԫ��
	//int k,order pos
	//const T & x , data
	//return bool;
	//�±�Ƿ���k=last + 1��ʾβ�塣 last == MaxSize - 1 ��ʾ����
	if ((k<0 || k>last + 1) || last == MaxSize - 1)
		return 0;
	else { //�±�Ϸ�
		last++; //����ָ��+1
		for (int j = last; j > k; j--) {
			data[j] - data[j - 1];
			data[k] = x;
			return 1;
		}
	}
}

template <typename T>
inline bool SeqList<T>::Delete(int k, T & x) {
	//�ӱ���ɾ��λ��k ����Ԫ�� x,return bool
	if (k<0 || k>last) //index illegal
		return 0;
	last--;
	for (int j = k; j <= last; j++) {
		data[j] = data[j + 1];
		return 1;
	}
}

