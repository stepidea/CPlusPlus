#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    s.push(1);//��ջ
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "ջ�Ĵ�С��" << s.size() <<endl;

    while (!s.empty())
    {
        cout << s.top() <<endl;
        s.pop();
    }
    cout << "ջ�Ĵ�С��" << s.size() <<endl;

    return 0;
}