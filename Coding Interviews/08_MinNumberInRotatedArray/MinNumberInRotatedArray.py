'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-18

题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。重建二叉树并返回。


'''

# -*- coding:utf-8 -*-
class Solution:
    # 思路: 非递减排序数组呈规律，经过旋转后，还是呈一定规律，前面一段数组是非递减排序的，后面一段数组也是非递减排序的。
    # 但这两段数组间不存在非递减排序规律。如{3,4,5,1,2}中的5和1。因此根据这一特性，找到两段数组相交的位置，输出后一段数组的首元素即可。
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        nums = len(rotateArray);
        if nums == 0:
            return 0
        for i in range(nums):
            if rotateArray[i] > rotateArray[i+1]:
                return rotateArray[i+1]
        return rotateArray[0]