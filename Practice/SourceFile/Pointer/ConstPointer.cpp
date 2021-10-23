#include <iostream>

using namespace std;

int main(){
    int p1Value = 10;
    int p2Value = 20;
    //常量指针 指针的指向可以修改，指针的值不可以修改
    const int * p = &p1Value;
    p = &p2Value;
    //*p = 11; //错误

    //指针常量 指针的指向不可以修改，指针的值可以修改
    int * const p1 = &p1Value;
    //p1 = &p2Value;//错误
    *p1 = 11; 

    //const 修饰指针和常量
    int * const p1 = &p1Value;
    //p1 = &p2Value;//错误
    //*p1 = 11; //错误
    

    return 0;
}