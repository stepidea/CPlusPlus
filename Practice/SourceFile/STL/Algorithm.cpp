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

// 常用的排序算法 sort、
void test04(){
    srand(unsigned(time(NULL)));

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    //洗牌算法，打乱顺序
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
    //合并两个有序的序列，生成一个有序序列
    vector<int> vTarget;
    vTarget.resize(v.size() + v1.size());
    merge(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), print02());
}

// 常用的算数生成算法 
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

// 常用的集合算法 ：需要有序
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
    //求交集
    auto itEnd = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, print02());

    //并集：set_union
    //差集：set_difference
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