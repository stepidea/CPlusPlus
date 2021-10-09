#include <iostream>
#include <vector>

using std::vector;

/*
加一：https://leetcode-cn.com/problems/plus-one/
从vector后面开始判断，
加一是否大于9（即10），
是的话该位置的值需要改为0，并进行前一位数字进行加一；
否的话该位置直接加一并返回结果。
*/

class Solution{
    public:
        vector<int> AddPlus(vector<int> & digits){
            int len=digits.size();
            for(int i=len-1;i>-1;--i){
                // if(digits[i]+1>9){
                //     digits[i]=0;
                // }else{
                //     ++digits[i];
                //     return digits;
                // }
                if(++digits[i]>9){
                    digits[i]=0;
                }else{
                    return digits;
                }
            }
            digits.insert(digits.begin(),1);        
            return digits;
        }
};