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
//链表
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
        cout << "l为空" << endl;
    }else{
        cout << "l的大小：" << l.size() << endl;
    }
    //重置大小
    l.resize(10,0);
    printList(l);

    l.resize(2);
    printList(l);
    
}
//交换
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
尾插：push_back
尾删：pop_back
头插：push_front
头删：pop_front
插入：insert
删除：erase
移除：remove
清空：clear
*/
void test03(){
    list<int> l;
    //
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);

    cout << "返回第一个元素：" << l.front() << endl;
    cout << "返回最后一个元素：" << l.back() << endl;

    list<int>::iterator it = l.begin();
    // it = it + 1; //错误，不支持随机访问

    l.push_front(100);
    printList(l);

    //反转
    l.reverse();
    cout << "反转：";
    printList(l);

    //排序,不支持随机访问的，不可以用标准的算法
    //内部有自己的排序算法
    l.sort();
    cout << "排序：";
    printList(l);

}

int main(){
    // test01();
    // test02();
    test03();

    system("pause");

    return 0;
}