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
// for_each 常用的遍历算法
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

// transform 常用的遍历算法
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

// 查找算法 find、find_if、adjacent_find、binary_search
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
        cout << "不存在对应的参数" << endl;
    }else{
        cout << "存在对应的参数" << endl;
    }
    
    it = adjacent_find(v.begin(),v.end());//查找相邻重复元素
    if(it == v.end()){
        cout << "找不到" << endl;
    }else{
        cout << "找到相邻重复元素：" << *it << endl;
    }

    //查找的元素需要有序
    bool flag = binary_search(v.begin(),v.end(),4);   
    if(flag){
        cout << "binary_search 找不到" << endl;
    }else{
        cout << "binary_search 存在该值" << endl;
    } 
}

// transform 常用的排序算法
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