#pragma once
#include "stdafx.h"
//������������Ľ���������
//link==0:ָ�룬ָ������;thread==1:������ָ��ǰ�����
typedef enum { link, thread }pointer_tag;
//������������Ľ���������
template <typename T, typename elemtype>
class bithrnode {
	//��Ԫ��, �����private member˽�г�Ա�ɱ���Ԫ�����
	friend class bithrtree;
private:
	//5����
public:
	//data domain ������	
	T data;
	//ref domain ������	
	bithrnode<T> *lchild, *rchild;
	//���ұ�־
	pointer_tag ltag, rtag;

	//6������

	//��������
	bithrnode<T>* GetLeft(void) const {
		return lchild;
	}
	//�����Ӹ���Ϊ���L
	void SetLeft(bithrnode<T>* L) {
		lchild = L;
	}
	//�����Һ���
	bithrnode<T>* GetRight(void) const {
		return rchild;
	}
	//���Һ��Ӹ���Ϊ���R
	void SetRight(bithrnode<T>* R) {
		rchild = R;
	}
	//���캯��,Constructor()
	bithrnode(const T& item, bithrnode<T>* lptr = NULL, bithrnode<T>* rptr = NULL)
		:data(item), lchild(lptr), rchild(rptr) {}
	//Deconstructor()
	virtual ~bithrnode() {}


};//!_class bithrnode



