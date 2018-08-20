/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-08-20
Reference: https://leetcode-cn.com/problems/two-sum/solution/
           https://leetcode.com/problems/two-sum/solution/

题目描述
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例 1:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*****************************************/

// 方法1：暴力法
// a+b=sum，转换成b=sum-a问题，即已经a和sum，再去找到b=sum-a。
// 两次for循环，最外层是a，范围是0~n-2；内层是b，范围是1~n-1，因此时间复杂度为O(n^2)，而空间复杂度为O(1)。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size()-1; ++i){
            for(int j=i+1; j<nums.size(); ++j){
                if(target == nums[i] + nums[j]){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

// TODO：排序-二分法



// TODO：哈希表
