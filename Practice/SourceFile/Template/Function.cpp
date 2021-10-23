#include <iostream>

using namespace std;

//����ģ�� ��typename �� class��
//������������ͱ���һ��
template<typename T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

//�������������ĺ���ģ��
//�Ӵ�С
//ѡ�������㷨
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

//���Խ�������
void test01(){
    int a = 9;
    int b = 10;
    // MySwap(a,b);  //ʹ���Զ������Ƶ�,�������ܽ�����ʽ����ת��
    mySwap<int>(a,b); //�������Խ�����ʽ����ת��
    cout << a << "\t" << b << endl;
}
//��������
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