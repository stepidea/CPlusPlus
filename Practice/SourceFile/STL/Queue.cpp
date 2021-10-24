#include <iostream>
#include <queue>

using namespace std;

void test(){
    queue<int> q;
    //入队
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);

    cout << "队列大小：" << q.size() << endl;

    while (!q.empty())
    {
        //查看对头
        cout << "队头：" << q.front() << endl;

        //查看队尾
        cout << "队尾：" << q.back() << endl;

        q.pop();//出队
    }
    
    cout << "队列大小：" << q.size() << endl;
}

int main(){
    test();

    system("pause");

    return 0;
}