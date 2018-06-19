'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-18

题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39


'''

# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if(n>39) or (n<0):
            return 0
        if(n==1 or n==2):
            return 1
        fn_2 = 1
        fn_1 = 1
        fn = 0
        i = 3
        while(i<=n):
            fn = fn_2 + fn_1
            fn_2 = fn_1
            fn_1 = fn
            i = i+1
        return fn