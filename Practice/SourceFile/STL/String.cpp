#include <iostream>
#include <string>

using namespace std;

//string ����
void test01(){

    string s1; //�����޲ι��캯��
    cout << "s1:" << s1 << endl;

    const char *s = "Hello";
    string s2(s); //��C���Ե��ַ���תΪstring
    cout << "s2:" << s2 << endl;

    string s3(s2); //���ÿ������캯��
    cout << "s3:" << s3 << endl;

    string s4(5,'n'); //ʹ��n���ַ����г�ʼ��
    cout << "s4:" << s4 << endl;
}

//string ���ҡ��滻
void test02(){
    string s = "asdfghjkl;asdf";

    //int pos = s.find("sd",0); //�������Ҳ���
    int pos = s.find("sd"); //�������Ҳ���
    if (pos == -1)
    {
        cout << "�Ҳ�����Ӧ���ַ�����" << endl;
    }else{
        cout << "sd��Ӧ������Ϊ��" << pos << endl;
    }

    pos = s.rfind("sd"); //�����������
    if (pos == -1)
    {
        cout << "�Ҳ�����Ӧ���ַ�����" << endl;
    }else{
        cout << "sd��Ӧ������Ϊ��" << pos << endl;
    }
    
    s.replace(1, 2, "ds");
    cout << "s�滻���ֵ:" << s << endl;

}

//�ַ��� �����ɾ��
void test03(){
    string s = "hungbin";
    cout << s << endl;

    s.insert(4,"ze");
    cout << s << endl;

    s.erase(4,2);
    cout << s << endl;
}
//��ȡ�ַ���
void test04(){
    string mail = "zhangsan@outlook.com";
    int pos = mail.find('@');
    cout << pos << endl;
    cout << "��ȡ���������û�����" << mail.substr(0,pos) << endl;
}

int main(){
    
    //test01();
    //test02();
    //test03();
    test04();

    system("pause");

    return 0;
}