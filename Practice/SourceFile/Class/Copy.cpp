#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(){
        m_age = 0;
        cout << "Ĭ�Ϲ��캯��" << endl;
    }

    Person(int age){
        m_age = age;
        cout << "�����вι��캯��" << endl;    
    }

    Person(const Person & p){
        m_age = p.m_age;        
        cout << "���ø��ƹ��캯��" << endl;
    }

    ~Person(){
        cout << "������������" << endl;
    }


    int m_age;
};

void test01(){
    Person p;
    Person p1(10);

    Person p3(p1);
    Person p4 = p1;
    Person p5 = Person(11);
}

int main(){
    test01();

    return 0;
}