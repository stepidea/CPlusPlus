#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m){
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }
}
//Map (pair) 构造
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
// 大小和交换、插入
void test02(){
    map<int, int> m;
    //
    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(2,11));
    m.insert(pair<int, int>(5,11));
    if(m.empty()){
        cout << "map为空。" << endl;
    }else{
        cout << m.size() << endl;
    }    

    map<int, int> m1;    
    m1.insert(make_pair(3,12));
    m1.insert(make_pair(4,13));
    cout << "交换前：" << endl;
    printMap(m);
    printMap(m1);

    m.swap(m1);
    cout << "交换后：" << endl;
    printMap(m);
    printMap(m1);
}
// 删除map数据 erase\clear
void test03(){
    map<int, int> m1;    
    m1.insert(make_pair(3,12));
    m1.insert(make_pair(4,13));
    m1.insert(make_pair(1,12));
    m1.insert(make_pair(5,12));  

    printMap(m1);  

    cout << "大小：" << m1.size() << endl;
    cout << "key为 1 的次数：" << m1.count(1) << endl;
    cout << "key为 10 的次数：:" << m1.count(10) << endl;

    m1.erase(m1.begin());
    printMap(m1);

    m1.erase(4);
    printMap(m1);

    // m1.erase(m1.begin(),m1.end());
    m1.clear();
    printMap(m1);
}
//排序与Set类似

int main(){
    // test01();
    // test02();
    test03();

    system("pause");

    return 0;
}
