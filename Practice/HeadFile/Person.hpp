// ͷ�ļ�h ��Դ�ļ�cpp ����
// ȥ���ظ�����
#pragma once
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//��������Ĭ�ϲ�������
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
    cout << typeid(NameType).name() << endl; //���������� 
    cout << typeid(AgeType).name() << endl;
}
