// 头文件h 和源文件cpp 构成
// 去掉重复引入
#pragma once
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//可以设置默认参数类型
template<class NameType, class AgeType = int>
class Person{
public:
    Person(NameType name, AgeType age){
        m_name = name;
        m_age = age;
    }

    void showPerson();

    NameType m_name;
    AgeType m_age;
};

template<class NameType, class AgeType>
void Person<NameType, AgeType>::showPerson()
{
    cout << m_name << "\t" << m_age << endl;
    cout << typeid(NameType).name() << endl; //参数的类型 
    cout << typeid(AgeType).name() << endl;
}
