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

//类模板没有自动类型推导
void test(){
    Person<string,int> p("hong",19);
    p.showPerson();  

}

int main(){
    test();

    system("pause");
    system("cls");

    return 0;
}