#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    s.push(1);//入栈
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "栈的大小：" << s.size() <<endl;

    while (!s.empty())
    {
        cout << s.top() <<endl;
        s.pop();
    }
    cout << "栈的大小：" << s.size() <<endl;

    return 0;
}