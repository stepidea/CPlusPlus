#include <iostream>

using namespace std;

class Student{
public:
    Student(int age){
        m_Age = new int(age);
    }
    //Éî¿½±´
    Student& operator=(Student& s){
        if(m_Age != nullptr){
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*s.m_Age);
        return *this;
    }

    ~Student(){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
private:
    int *m_Age;
};

void test(){
    Student s1(15);

    Student s2(18);

    s1 = s2;
}

int main(){
    test();

    system("pause");

    return 0;
}