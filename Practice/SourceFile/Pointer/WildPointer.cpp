#include <iostream>

using namespace std;

int main(){
    //Ұָ��ָ��Ƿ����ڴ�ռ�
    int * p = (int *)0x1100;

    //���б����޷����з���
    cout<<*p<<endl;

    system("pause");
    
    return 0;
}