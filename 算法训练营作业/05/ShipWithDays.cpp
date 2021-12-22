#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief 
 * 
 * ��D�����ʹ������������https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/solution/zai-d-tian-nei-song-da-bao-guo-de-neng-l-ntml/
 * 
 */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        // ���ڵ��������е����ֵ��С�ڵ���������ܺͣ����ұ߽磩
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
    //��֤��ǰ�����Ƿ�����������������������
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