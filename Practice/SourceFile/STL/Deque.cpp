#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d){
    for(deque<int>::const_iterator cit = d.begin(); cit != d.end(); cit++){
        cout << *cit << " ";
    }
    cout << endl;
}

//deque容器构造
void test01(){
    deque<int> d1;
    for(int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int> d3(10,20);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);

}

//插入和删除
void test02(){
    deque<int> d1;
    d1.push_back(10);//头插
    d1.push_back(20);
    d1.push_front(100);//尾插
    d1.push_front(200);
    printDeque(d1);

    d1.pop_back();
    printDeque(d1);

    d1.pop_front();
    printDeque(d1);

    d1.insert(d1.begin(),1000);
    printDeque(d1);

    d1.erase(d1.begin());
    printDeque(d1);

    d1.clear();
    printDeque(d1);

}

int main(){
    // test01();
    test02();

    return 0;
}