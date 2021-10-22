#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(){
        m_age = 0;
        cout << "默认构造函数" << endl;
    }

    Person(int age){
        m_age = age;
        cout << "调用有参构造函数" << endl;    
    }

    Person(const Person & p){
        m_age = p.m_age;        
        cout << "调用复制构造函数" << endl;
    }

    ~Person(){
        cout << "调用析构函数" << endl;
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