#pragma once
//自动属性
#include <functional>
using namespace std;

template<typename ValueType>
class Property {

protected:
	typedef function<ValueType()> GetterType;
	GetterType getter;

	typedef function<void(ValueType)> SetterType;
	SetterType setter;

public:
	Property() {}
	virtual ~Property() {}

	explicit Property(GetterType gt, SetterType st) : getter(gt), setter(st) {}
	operator ValueType() { return getter(); }
	Property& operator = (ValueType value) { setter(value); return *this; }

};

#define AutoProperty(ValueType, Variable)	\
public: Property<ValueType> Variable;\
private: ValueType var##Variable;\
private: ValueType get##Variable() { return var##Variable; }\
private: void set##Variable(ValueType newValue) { var##Variable = newValue; }\

#define AutoPropertyImpl(Variable, Value)	\
var##Variable(Value), Variable(bind(&A::get##Variable, this), bind(&A::set##Variable, this, placeholders::_1))

//class A {
//public:
//	// 任务是否可以运行,只读属性
//	AutoProperty(bool, CanRun);
//
//public:
//	A() : AutoPropertyImpl(CanRun, true) {}
//};
//
//
//
//int main(int argc, char* argv[]) {
//	A a;
//	bool b = a.CanRun;
//	a.CanRun = false;
//
//	return 0;
//}