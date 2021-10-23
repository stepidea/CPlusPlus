#include <iostream>


using namespace std;

class MyInteger{
    friend ostream& operator<<(ostream& cout,MyInteger m);

public:
    MyInteger(){
        m_Num=0;
    }
    //����ǰ��++�����
    MyInteger& operator++(){
        ++m_Num;
        return *this;
    }
    //����ǰ��--�����
    MyInteger& operator--(){
        --m_Num;
        return *this;
    }

    //���غ���++�����
    MyInteger operator++(int){
        MyInteger temp=*this;
        this->m_Num++;
        return temp;
    }
    //���غ���--�����
    MyInteger operator--(int){
        MyInteger temp=*this;
        --m_Num;
        return temp;
    }

private:
    int m_Num;

};

//�����������
ostream& operator<<(ostream& cout,MyInteger m){
    cout << m.m_Num;   
    return cout;
}

void test01(){
    MyInteger m;//0
    
    cout << ++m << endl;//1

    cout << m++ << endl;//1

    cout << m << endl;//2

    cout << --m << endl;//1

    cout << m-- << endl;//1

    cout << m << endl;//0


}

int main(){
    test01();

    // system("pause");
    // system("cls");

    return 0;
}