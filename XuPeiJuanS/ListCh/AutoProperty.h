#pragma once
//class CEmployee {
//private:
//	int m_old;
//public:
//	_declspec(property(get = GetOld, put = SetOld))int Old;
//
//	int GetOld(void) {
//		return m_old;
//	}
//	void SetOld(int value) {
//		if ((value >0) && (value <60)) {
//			m_old = value;
//		} else {
//			m_old = 20;
//		}
//	}
//};

//#define PROP(T,X) __declspec(property(get= __get##X,put= __put##X))T X;
//#define GETPROP(T,X) __declspec(property(get= __get##X))T X; //只读属性
//#define SETPROP(T,X) __declspec(property(put= __put##X))T X; //只写属必
//#define GET(T,X) T __get##X(void) 
//#define SET(T,X) void __put##X(T value)

//宏展开 属性
#define AutoProperty(ValueType, GetAccessor, SetAccessor, Variable)	private: ValueType Variable;\
GetAccessor: ValueType get##Variable() { return Variable; }\
SetAccessor: void set##Variable(ValueType newValue) { Variable = newValue; }

//class AutoProperty {
//public:
//
//	AutoProperty() {}
//
//	virtual ~AutoProperty() {}
//};


