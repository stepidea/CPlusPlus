#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s){
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}
// set 为关联容器，使用二叉树存放，不能存放重复值
void test01(){
    set<int> s1;
    //插入
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    s1.insert(9);
    printSet(s1);

    if(s1.empty()){
        cout << "set为空" << endl;
    }else{
        cout << "set的大小：" << s1.size() << endl;
    }

    set<int> s2;
    //插入
    s2.insert(10);
    s2.insert(9);
    printSet(s2);

    s1.swap(s2);
    printSet(s1);
    printSet(s2);

}

// set 删除、清空
void test02(){
    set<int> s1;
    //插入
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    printSet(s1);

    s1.erase(s1.begin());
    cout << "删除:";
    printSet(s1);

    // s1.erase(s1.begin(),s1.end());
    s1.clear();
    cout << "全部删除:";
    printSet(s1);

}

//查找统计
void test03(){
    set<int> s1;
    //插入
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    printSet(s1);
    
    set<int>::iterator it = s1.find(10);
    if(it != s1.end()){
        cout << *it << endl;
    }
    else{
        cout << "找不到对应的值" << endl;
    }    

    it = s1.find(20);
    if(it != s1.end()){
        cout << *it << endl;
    }
    else{
        cout << "找不到对应的值" << endl;
    } 

    int c = s1.count(10);
    cout << c << endl;
}

//set multiset
void test04(){
    set<int> s1;
    //插入
    pair<set<int>::iterator,bool> p = s1.insert(10);
    if(p.second){
        cout << "插入成功。" << endl;
    }
    else{
        cout << "插入失败。" << endl;
    }
    p = s1.insert(10);
    if(p.second){
        cout << "插入成功。" << endl;
    }
    else{
        cout << "插入失败。" << endl;
    }
    //可插入重复数据
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for(auto it = ms.begin(); it != ms.end(); it++){
        cout << *it << " ";
    }
}
//
class MyMapCompare
{
public:
    bool operator()(int a, int b)
    {        
        return a > b;
    }
};
//使用仿函数修改set中的排序(从大大小)
void test05(){
    set<int,MyMapCompare> s1;
    //插入
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    s1.insert(9);
    for (set<int,MyMapCompare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    test05();

    return 0;
}