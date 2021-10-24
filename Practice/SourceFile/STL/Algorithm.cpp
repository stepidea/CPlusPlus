#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <numeric>

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

// ���õ������㷨 sort��
void test04(){
    srand(unsigned(time(NULL)));

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    //ϴ���㷨������˳��
    random_shuffle(v.begin(),v.end());

    for_each(v.begin(), v.end(), print02());
    cout << endl;

    sort(v.begin(), v.end());
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    //�ϲ�������������У�����һ����������
    vector<int> vTarget;
    vTarget.resize(v.size() + v1.size());
    merge(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), print02());
}

// ���õ����������㷨 
void test05(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    int total = accumulate(v.begin(), v.end(), 0);
    cout << total << endl;

    vector<int> v1;
    v1.resize(10);
    fill(v1.begin(),v1.end(),100);
    for_each(v1.begin(),v1.end(),print02());
}

// ���õļ����㷨 ����Ҫ����
void test06(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    
    vector<int> vTarget;
    vTarget.resize(min(v.size(), v1.size()));
    //�󽻼�
    auto itEnd = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, print02());

    //������set_union
    //���set_difference
}

int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();

    return 0;
}