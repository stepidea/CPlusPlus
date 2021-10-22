#include <iostream>

using namespace std;

struct Student
{
    int no;
    string name;
    int age;
};


int main(){
    struct Student s1;
    s1.no = 1;
    s1.name = "hong";
    s1.age = 10;
    cout << s1.no << s1.name << s1.age << endl;

    Student s2=
    {
        2,"cai",10
    };
    cout << s2.no << s2.name << s2.age << endl;
    
    return 0;
}