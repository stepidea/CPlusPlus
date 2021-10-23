#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using std::vector;
/*
����Ķȣ�https://leetcode-cn.com/problems/degree-of-an-array/
����ӳ��subArrayMap��ʹ�ü������ֵ������ֵ��ų��ֵĴ�������ȡ�ȣ�����ʼ�ͽ�����������ȡ��ͬ���ֵļ����
�Ƚϳ��ֵĴ��������ӻ�ȡ��ͬ���ֵļ���������Ӧ����������鳤��
*/
class FindShortestSubArray {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> subArrayMap;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (subArrayMap.count(nums[i])) {
        //         subArrayMap[nums[i]][0]++;
        //         subArrayMap[nums[i]][2] = i;
        //     } else {
        //         subArrayMap[nums[i]] = {1, i, i};
        //     }
        // }
        // int maxNum = 0, minLen = 0;
        // for (auto& [_, vec] : subArrayMap) {
        //     if (maxNum < vec[0]) {
        //         maxNum = vec[0];
        //         minLen = vec[2] - vec[1] + 1;
        //     } 
        //     else if (maxNum == vec[0] && minLen > vec[2] - vec[1] + 1) {
        //         minLen = vec[2] - vec[1] + 1;
        //     }
        // }
        int maxNum = 0, minLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (subArrayMap.count(nums[i])) {
                subArrayMap[nums[i]][0]++;
                subArrayMap[nums[i]][2] = i;
            } else {
                subArrayMap[nums[i]] = {1, i, i};
            }
            if (maxNum < subArrayMap[nums[i]][0]) {
                maxNum = subArrayMap[nums[i]][0];
                minLen = subArrayMap[nums[i]][2] - subArrayMap[nums[i]][1] + 1;
            } 
            else if (maxNum == subArrayMap[nums[i]][0] && minLen > subArrayMap[nums[i]][2] - subArrayMap[nums[i]][1] + 1) {
                minLen = subArrayMap[nums[i]][2] - subArrayMap[nums[i]][1] + 1;
            }
        }
        return minLen;
    }
};