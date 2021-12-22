#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
 * @brief 
 * �߳��㽶������:https://leetcode-cn.com/problems/koko-eating-bananas/
 * ʹ�ö������������ж���ѡ�����������ʵ�ֵ
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1,
            // right = pow(10, 9);
            right = *max_element(piles.begin(), piles.end()); //�����ٵ�ʱ��ȽϺ�
        while (left < right) 
        {
            int mid = (left + right) / 2;
            if (verify(piles, mid, h)) 
            {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool verify(vector<int>& piles, int mid, int h)
    {
        int need = 0;
        for (int pile: piles)
        {   
            need += (pile - 1) / mid + 1;
        }
        return need <= h;
    }
};