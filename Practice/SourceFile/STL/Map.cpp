#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m){
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }
}
//Map (pair) ����
void test01(){
    map<int, int> m;
    //
    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(2,11));
    m.insert(pair<int, int>(5,11));
    m.insert(pair<int, int>(3,12));
    m.insert(pair<int, int>(4,13));

    printMap(m);

    map<int, int> m1(m);
    printMap(m1);

    map<int, int> m2;
    m2 = m;
    printMap(m1);
}
// ��С�ͽ���������
void test02(){
    map<int, int> m;
    //
    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(2,11));
    m.insert(pair<int, int>(5,11));
    if(m.empty()){
        cout << "mapΪ�ա�" << endl;
    }else{
        cout << m.size() << endl;
    }    

    map<int, int> m1;    
    m1.insert(make_pair(3,12));
    m1.insert(make_pair(4,13));
    cout << "����ǰ��" << endl;
    printMap(m);
    printMap(m1);

    m.swap(m1);
    cout << "������" << endl;
    printMap(m);
    printMap(m1);
}
// ɾ��map���� erase\clear
void test03(){
    map<int, int> m1;    
    m1.insert(make_pair(3,12));
    m1.insert(make_pair(4,13));
    m1.insert(make_pair(1,12));
    m1.insert(make_pair(5,12));  

    printMap(m1);  

    cout << "��С��" << m1.size() << endl;
    cout << "keyΪ 1 �Ĵ�����" << m1.count(1) << endl;
    cout << "keyΪ 10 �Ĵ�����:" << m1.count(10) << endl;

    m1.erase(m1.begin());
    printMap(m1);

    m1.erase(4);
    printMap(m1);

    // m1.erase(m1.begin(),m1.end());
    m1.clear();
    printMap(m1);
}
//������Set����

int main(){
    // test01();
    // test02();
    test03();

    system("pause");

    return 0;
}
