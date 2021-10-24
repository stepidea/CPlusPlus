#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s){
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}
// set Ϊ����������ʹ�ö�������ţ����ܴ���ظ�ֵ
void test01(){
    set<int> s1;
    //����
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    s1.insert(9);
    printSet(s1);

    if(s1.empty()){
        cout << "setΪ��" << endl;
    }else{
        cout << "set�Ĵ�С��" << s1.size() << endl;
    }

    set<int> s2;
    //����
    s2.insert(10);
    s2.insert(9);
    printSet(s2);

    s1.swap(s2);
    printSet(s1);
    printSet(s2);

}

// set ɾ�������
void test02(){
    set<int> s1;
    //����
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    printSet(s1);

    s1.erase(s1.begin());
    cout << "ɾ��:";
    printSet(s1);

    // s1.erase(s1.begin(),s1.end());
    s1.clear();
    cout << "ȫ��ɾ��:";
    printSet(s1);

}

//����ͳ��
void test03(){
    set<int> s1;
    //����
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    printSet(s1);
    
    set<int>::iterator it = s1.find(10);
    if(it != s1.end()){
        cout << *it << endl;
    }
    else{
        cout << "�Ҳ�����Ӧ��ֵ" << endl;
    }    

    it = s1.find(20);
    if(it != s1.end()){
        cout << *it << endl;
    }
    else{
        cout << "�Ҳ�����Ӧ��ֵ" << endl;
    } 

    int c = s1.count(10);
    cout << c << endl;
}

//set multiset
void test04(){
    set<int> s1;
    //����
    pair<set<int>::iterator,bool> p = s1.insert(10);
    if(p.second){
        cout << "����ɹ���" << endl;
    }
    else{
        cout << "����ʧ�ܡ�" << endl;
    }
    p = s1.insert(10);
    if(p.second){
        cout << "����ɹ���" << endl;
    }
    else{
        cout << "����ʧ�ܡ�" << endl;
    }
    //�ɲ����ظ�����
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for(auto it = ms.begin(); it != ms.end(); it++){
        cout << *it << " ";
    }
}
//
class MyMapCompare
{
public:
    bool operator()(int a, int b)
    {        
        return a > b;
    }
};
//ʹ�÷º����޸�set�е�����(�Ӵ��С)
void test05(){
    set<int,MyMapCompare> s1;
    //����
    s1.insert(10);
    s1.insert(9);
    s1.insert(8);
    s1.insert(7);
    s1.insert(9);
    for (set<int,MyMapCompare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    test05();

    return 0;
}