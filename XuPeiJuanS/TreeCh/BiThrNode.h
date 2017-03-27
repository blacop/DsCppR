#pragma once
#include "stdafx.h"
//Link==0:ָ�룬ָ������;Thread==1:������ָ��ǰ�����
typedef enum PointerTag{Link,Thread};
//������������Ľ���������
template <typename T>
class BiThrNode {
	//��Ԫ��, �����private member˽�г�Ա�ɱ���Ԫ�����
	friend class BinTree;
private:
public:
	//data domain ������
	T data;
	//ref domain ������
	BiThrNode<T>* left;
	BiThrNode<T>* right;
	PointerTag LTag, RTag;//���ұ�־
	//6������

	//��������
	BiThrNode<T>* GetLeft(void) const {
		return left;
	}
	//�����Ӹ���Ϊ���L
	void SetLeft(BiThrNode<T>* L) {
		left = L;
	}
	//�����Һ���
	BiThrNode<T>* GetRight(void) const {
		return right;
	}
	//���Һ��Ӹ���Ϊ���R
	void SetRight(BiThrNode<T>* R) {
		right = R;
	}
	//���캯��,Constructor()
	BiThrNode(const T& item, BiThrNode<T>* lptr = NULL, BiThrNode<T>* rptr = NULL)
		:data(item), left(lptr), right(rptr) {}
	//Deconstructor()
	virtual ~BiThrNode() {}
};//!_class BiThrNode



