#include <iostream>

using namespace std;

int main(){
    //空指针指向的地址是0；0~255是系统占用的内存，不可以访问
    int * p = NULL;

    //*p = 0;//不可以进行赋值，会报空指针不能进行赋值错误

    return 0;
}