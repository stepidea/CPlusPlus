#include <iostream>

using namespace std;

int main(){
    int p1Value = 10;
    int p2Value = 20;
    //����ָ�� ָ���ָ������޸ģ�ָ���ֵ�������޸�
    const int * p = &p1Value;
    p = &p2Value;
    //*p = 11; //����

    //ָ�볣�� ָ���ָ�򲻿����޸ģ�ָ���ֵ�����޸�
    int * const p1 = &p1Value;
    //p1 = &p2Value;//����
    *p1 = 11; 

    //const ����ָ��ͳ���
    int * const p1 = &p1Value;
    //p1 = &p2Value;//����
    //*p1 = 11; //����
    

    return 0;
}