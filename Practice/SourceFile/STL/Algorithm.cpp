#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

// void printVector(vector<int> &v){
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " " ;
//     }
//     cout << endl;
// }

void print01(int i){
    cout << i << " ";
}

class print02{
public:
    void operator()(int i){
        cout << i << " ";
    }
};
// for_each ���õı����㷨
void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    for_each(v.begin(),v.end(),print01);
    cout << endl;

    for_each(v.begin(),v.end(),print02());
    cout << endl;
}

class Transform
{
public:
    int operator()(int i){
        return i + 10;
    }
};

// transform ���õı����㷨
void test02(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    vector<int> vTarget;
    vTarget.resize(v.size());
    transform(v.begin(),v.end(),vTarget.begin(),Transform());

    for_each(vTarget.begin(),vTarget.end(),print02());
    cout << endl;
}

// �����㷨 find��find_if��adjacent_find��binary_search
void test03(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    
    vector<int>::iterator it = find(v.begin(),v.end(),4);
    if(it == v.end()){
        cout << "�����ڶ�Ӧ�Ĳ���" << endl;
    }else{
        cout << "���ڶ�Ӧ�Ĳ���" << endl;
    }
    
    it = adjacent_find(v.begin(),v.end());//���������ظ�Ԫ��
    if(it == v.end()){
        cout << "�Ҳ���" << endl;
    }else{
        cout << "�ҵ������ظ�Ԫ�أ�" << *it << endl;
    }

    //���ҵ�Ԫ����Ҫ����
    bool flag = binary_search(v.begin(),v.end(),4);   
    if(flag){
        cout << "binary_search �Ҳ���" << endl;
    }else{
        cout << "binary_search ���ڸ�ֵ" << endl;
    } 
}

// transform ���õ������㷨
void test04(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    vector<int> vTarget;
    vTarget.resize(v.size());
    transform(v.begin(),v.end(),vTarget.begin(),Transform());

    for_each(vTarget.begin(),vTarget.end(),print02());
    cout << endl;
}

int main(){
    // test01();
    // test02();
    test03();

    return 0;
}