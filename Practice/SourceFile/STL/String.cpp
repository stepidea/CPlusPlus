#include <iostream>
#include <string>

using namespace std;

//string 构造
void test01(){

    string s1; //调用无参构造函数
    cout << "s1:" << s1 << endl;

    const char *s = "Hello";
    string s2(s); //把C语言的字符串转为string
    cout << "s2:" << s2 << endl;

    string s3(s2); //调用拷贝构造函数
    cout << "s3:" << s3 << endl;

    string s4(5,'n'); //使用n个字符进行初始化
    cout << "s4:" << s4 << endl;
}

//string 查找、替换
void test02(){
    string s = "asdfghjkl;asdf";

    //int pos = s.find("sd",0); //从左往右查找
    int pos = s.find("sd"); //从左往右查找
    if (pos == -1)
    {
        cout << "找不到对应的字符串。" << endl;
    }else{
        cout << "sd对应的索引为：" << pos << endl;
    }

    pos = s.rfind("sd"); //从右往左查找
    if (pos == -1)
    {
        cout << "找不到对应的字符串。" << endl;
    }else{
        cout << "sd对应的索引为：" << pos << endl;
    }
    
    s.replace(1, 2, "ds");
    cout << "s替换后的值:" << s << endl;

}

//字符串 插入和删除
void test03(){
    string s = "hungbin";
    cout << s << endl;

    s.insert(4,"ze");
    cout << s << endl;

    s.erase(4,2);
    cout << s << endl;
}
//截取字符串
void test04(){
    string mail = "zhangsan@outlook.com";
    int pos = mail.find('@');
    cout << pos << endl;
    cout << "截取到的邮箱用户名：" << mail.substr(0,pos) << endl;
}

int main(){
    
    //test01();
    //test02();
    //test03();
    test04();

    system("pause");

    return 0;
}