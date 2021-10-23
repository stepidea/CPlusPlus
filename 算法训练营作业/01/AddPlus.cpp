#include <iostream>
#include <vector>

using std::vector;

/*
��һ��https://leetcode-cn.com/problems/plus-one/
��vector���濪ʼ�жϣ�
��һ�Ƿ����9����10����
�ǵĻ���λ�õ�ֵ��Ҫ��Ϊ0��������ǰһλ���ֽ��м�һ��
��Ļ���λ��ֱ�Ӽ�һ�����ؽ����
*/

class Solution{
    public:
        vector<int> AddPlus(vector<int> & digits){
            int len = digits.size();
            for(int i = len-1; i >= 0; --i){
                // if(digits[i]+1>9){
                //     digits[i]=0;
                // }else{
                //     ++digits[i];
                //     return digits;
                // }
                if(++digits[i] > 9){
                    digits[i] = 0;
                }else{
                    return digits;
                }
            }
            digits.insert(digits.begin(),1);        
            return digits;
        }
};