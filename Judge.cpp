#include<iostream> 
using namespace std; 

int main() { 
    char c;
    bool ischar; 
    int isLowercaseVowel,isUppercaseVowel;
    cout<<"请输入一个字母："; 
    cin>>c; 
    ischar=((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
    if(ischar) {
        // 元音小写字母
        isLowercaseVowel = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'); 
        // 元音大写字母
        isUppercaseVowel = (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
        // if 条件
        if(isLowercaseVowel||isUppercaseVowel)
            cout<<c<<" 是元音字母"; 
        else 
            cout<<c<<" 不是元音字母"; 
    } else {
        cout<<"请输入字母"; 
    }
        
    return 0; 
}
