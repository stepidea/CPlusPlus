#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//����
void test01(){
    list<int> l;
    //
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);

    printList(l);

    if (l.empty())
    {
        cout << "lΪ��" << endl;
    }else{
        cout << "l�Ĵ�С��" << l.size() << endl;
    }
    //���ô�С
    l.resize(10,0);
    printList(l);

    l.resize(2);
    printList(l);
    
}
//����
void test02(){
    list<int> l;
    //
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);

    list<int> l1;
    l1.push_back(100);
    l1.push_back(110);
    l1.push_back(120);

    printList(l);
    printList(l1);

    l.swap(l1);
    printList(l);
    printList(l1);
}
/*
β�壺push_back
βɾ��pop_back
ͷ�壺push_front
ͷɾ��pop_front
���룺insert
ɾ����erase
�Ƴ���remove
��գ�clear
*/
void test03(){
    list<int> l;
    //
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);

    cout << "���ص�һ��Ԫ�أ�" << l.front() << endl;
    cout << "�������һ��Ԫ�أ�" << l.back() << endl;

    list<int>::iterator it = l.begin();
    // it = it + 1; //���󣬲�֧���������

    l.push_front(100);
    printList(l);

    //��ת
    l.reverse();
    cout << "��ת��";
    printList(l);

    //����,��֧��������ʵģ��������ñ�׼���㷨
    //�ڲ����Լ��������㷨
    l.sort();
    cout << "����";
    printList(l);

}

int main(){
    // test01();
    // test02();
    test03();

    system("pause");

    return 0;
}