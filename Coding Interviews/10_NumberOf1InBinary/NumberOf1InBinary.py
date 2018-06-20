'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-20

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示


'''

# -*- coding:utf-8 -*-
class Solution:
    # 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
    def NumberOf1(self, n):
        # write code here
        count, bit = 0, 1
        INT_BITS = 32 
        MAX_INT = (1 << (INT_BITS - 1)) - 1  # Maximum Integer for INT_BITS
        while n and bit <= MAX_INT + 1:
            if bit & n:
                count += 1
                n -= bit
            bit = bit << 1
        return count