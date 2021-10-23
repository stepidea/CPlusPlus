#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using std::vector;
/*
数组的度：https://leetcode-cn.com/problems/degree-of-an-array/
创建映射subArrayMap，使用键存放数值，数组值存放出现的次数（获取度），开始和结束索引（获取相同数字的间隔）
比较出现的次数；并从获取相同数字的间隔计算出对应的最短子数组长度
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