#include <iostream>
#include <queue>

using namespace std;

void test(){
    queue<int> q;
    //���
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);

    cout << "���д�С��" << q.size() << endl;

    while (!q.empty())
    {
        //�鿴��ͷ
        cout << "��ͷ��" << q.front() << endl;

        //�鿴��β
        cout << "��β��" << q.back() << endl;

        q.pop();//����
    }
    
    cout << "���д�С��" << q.size() << endl;
}

int main(){
    test();

    system("pause");

    return 0;
}