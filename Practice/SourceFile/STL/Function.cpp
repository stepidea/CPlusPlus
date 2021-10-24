#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

void printVector(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl;
}

void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    printVector(v);
    //使用仿函数模板
    sort(v.begin(),v.end(),greater<int>());
    printVector(v);
}

int main(){
    test01();

    return 0;
}