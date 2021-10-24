#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
    Person(string name, int age){
        m_age = age;
        m_name = name;
    }

    string m_name;
    int m_age;
};

void test01(){
    vector<Person> v;

    Person p1("asdf", 10);
    Person p2("jkl;", 11);
    Person p3("qwer", 12);
    Person p4("uiop", 13);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "������" << it->m_name << " ���䣺" << it->m_age << endl;
    }
}

void printVector(vector<int> v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl;
}

//��С������
void test02(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);

    if(v.empty()){
        cout << "vΪ��" << endl;
    }else{
        cout << "v��������" << v.capacity() << endl;
        cout << "v�Ĵ�С��" << v.size() << endl;
    }

    v.resize(20,11); //���ô�С
    printVector(v);
    cout << "v��������" << v.capacity() << endl;
    cout << "v�Ĵ�С��" << v.size() << endl;

    v.resize(5); //
    printVector(v);
    cout << "v��������" << v.capacity() << endl;
    cout << "v�Ĵ�С��" << v.size() << endl;
}

//�����ɾ��
void test03(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);

    v.pop_back();//βɾ
    printVector(v);    

    v.insert(v.begin(),2,20);//����
    printVector(v);

    v.erase(v.begin());//ɾ��
    printVector(v);

    v.clear();//���
    printVector(v);
}
//���ݴ�ȡ
void test04(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++){
        //cout << v[i] << " ";
        cout << v.at(i) << " ";
    }

    cout << endl << v.front() << endl;//�׸�Ԫ��
    cout << v.back() << endl;//ĩβԪ��
}

int main(){
    //test01();
    //test02();
    //test03();
    test04();
    system("pause");

    return 0;
}