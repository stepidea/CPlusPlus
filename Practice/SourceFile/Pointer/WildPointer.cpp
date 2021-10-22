#include <iostream>

using namespace std;

int main(){
    //野指针指向非法的内存空间
    int * p = (int *)0x1100;

    //运行报错，无法进行访问
    cout<<*p<<endl;

    system("pause");
    
    return 0;
}