#include <iostream>

using namespace std;

//ָ���������
void ArrPointer(){
    int a[5] = {1,2,3,4,5};
    int *p = a;
    cout << "����ĵ�һ��ֵ��" << *p << endl;
    for(int i = 0; i < 5; i++){
        cout << *p << endl;
        p++;
    }
    return;
}

int main(){
    ArrPointer();
    system("Pause");
    return 0;
}