/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-08-30
Reference: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
           https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
		   https://www.cnblogs.com/dreamer123/p/9159499.html

题目描述：
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5

*****************************************/

// 方法1：暴力求解法：先合并两个数组，然后根据下标索引返回相应的中位数

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int size = nums1.size()+nums2.size();
        vector<int> mergeNums;
        double result;
        //mergeNums.resize(size);
        for(int a=0;a<size;++a){
            if(i==nums1.size()){
                mergeNums.push_back(nums2[j]);
                j++;
                continue;   
            }
            else if(j==nums2.size()){
                mergeNums.push_back(nums1[i]);
                i++;
                continue;
            }
            if(nums1[i] < nums2[j]){
                mergeNums.push_back(nums1[i]);
                i++;
            }
            else{
                mergeNums.push_back(nums2[j]);
                j++;
            }
        }
        if(0 == size%2){
            result = static_cast<double>((mergeNums[size/2 - 1]+mergeNums[size/2])/2.0);
        }
        else
            result = mergeNums[size/2];
        return result;
    }
};

// TODO：分割法

