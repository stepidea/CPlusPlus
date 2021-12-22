#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 
 * 
 * 在D天内送达包裹的能力：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/solution/zai-d-tian-nei-song-da-bao-guo-de-neng-l-ntml/
 * 
 */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        // 大于等于数组中的最大值，小于等于数组的总和（左右边界）
        int left = *max_element(weights.begin(), weights.end()), 
            right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) 
        {
            int midWeight = (left + right) / 2;
            if (verify(weights, midWeight, days)) 
            {
                right = midWeight;
            }
            else {
                left = midWeight + 1;
            }
        }
        return left;
    }
    //验证当前重量是否可以在有限天数内运送完成
    bool verify(vector<int>& weights, int midWeight, int day)
    {
        int needDay = 1, curWeight = 0;
        for (int weight: weights)
        {
            if (curWeight + weight > midWeight) 
            {
                ++needDay;
                curWeight = 0;
            }
            curWeight += weight;
        }
        return needDay <= day;
    }
};