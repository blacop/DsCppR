#pragma once
#include "stdafx.h"

//SeqList,˳�����Ա�
template <typename T> //ģ���࣬ʵ�ַ���,Tָ�ľ���Ԫ������
class SeqList {
private:
	//��Ԫ�����飬 T * ����ָ�� //��һ��д�� T[] data��	
	T* data;
	//����ָ��
	int last;
	//���Ԫ�ظ���
	int MaxSize; 

	//5������
public:
	//���캯��,className();���û�д���ֵ��Ĭ��Ϊ10,����д�Ͳ���д�޲�����������
	SeqList(int Max = 10) {
		//���캯��
		//ģ���࣬�綨������ҪдSeqList<T>::
		MaxSize = Max;
		data = new T[MaxSize]; //��̬��������
		last = -1; //����ָ��
	}
	//��������,~className(); //delete������ [] ����� �����ͷ�����data������ڴ�ռ�
	virtual ~SeqList() { delete[] data; }
	//���ر���Ԫ��x��λ�ã�����const��ʾ ��Ա�������ܱ��޸ģ�T& x��T�����βΣ�& x���ô�ֵ//const��Ա���������޸ĵ��øú����Ķ���
	int Locate(const T& x) const {
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
	//�ڱ��λ��K������Ԫ��x
	int Insert(int k, const T& x) {
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
	//�ӱ���ɾ��λ��k����Ԫ��x
	int Delete(int k, T& x) {
		//�ӱ���ɾ��λ��k ����Ԫ�� x,return bool
		if (k<0 || k>last) //index illegal
			return 0;
		last--;
		for (int j = k; j <= last; j++) {
			data[j] = data[j + 1];
			return 1;
		}
	}
	//�жϿձ�
	bool ListEmpty() {
		if (last == -1) return true;
		else return false;
	}
};//!_class SeqList,4������ʵ��

