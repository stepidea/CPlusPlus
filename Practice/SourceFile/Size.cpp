#include<iostream> 
using namespace std; 

int main() { 
    char c;
    bool ischar; 
    int isLowercaseVowel,isUppercaseVowel;
    cout<<"������һ����ĸ��"; 
    cin>>c; 
    ischar=((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
    if(ischar) {
        // Ԫ��Сд��ĸ
        isLowercaseVowel = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'); 
        // Ԫ����д��ĸ
        isUppercaseVowel = (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
        // if ����
        if(isLowercaseVowel||isUppercaseVowel)
            cout<<c<<" ��Ԫ����ĸ"; 
        else 
            cout<<c<<" ����Ԫ����ĸ"; 
    } else {
        cout<<"��������ĸ"; 
    }
        
    return 0; 
}