#include <iostream>

using namespace std;

//函数模板 （typename 或 class）
//传入的数据类型必须一致
template<typename T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

//对数组进行排序的函数模板
//从大到小
//选择排序算法
template<class T>
void mySort(T arr[],int len){
    for(int i = 0; i < len; ++i){
        int max = i;
        for(int j = i + 1; j < len; ++j){
            if(arr[max] < arr[j]){
                max = j;
            }            
        }
        if(i != max){
            mySwap<T>(arr[max],arr[i]);
        }
    }
}

template<class T>
void myPrint(T arr[],int len){
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

//测试交换参数
void test01(){
    int a = 9;
    int b = 10;
    // MySwap(a,b);  //使用自动类型推导,参数不能进行隐式类型转换
    mySwap<int>(a,b); //参数可以进行隐式类型转换
    cout << a << "\t" << b << endl;
}
//测试排序
void test02()
{
    int a[] = {1, 2, 3, 4, 5, 7};
    int len = sizeof(a)/sizeof(int);
    mySort(a, len);
    myPrint(a, len);
}

int main(){
    //test01();

    test02();

    return 0;
}