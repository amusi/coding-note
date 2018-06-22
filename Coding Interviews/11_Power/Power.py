'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-20

题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。


'''

# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        baseSmallFlag = False
        pow = 0
        baseSmallFlag = self.JudgeSmall(base)
        if baseSmallFlag and exponent==0:
            return 0
        if exponent ==0:
            return 1
        if exponent > 0:
            pow = self.PowerUnsigned(base, exponent)
        else:
            exponent = abs(exponent)
            pow = 1/self.PowerUnsigned(base, exponent)
            
        return pow
    # 计算exponent为正数的情况
    def PowerUnsigned(self, base, exponent):
        pow = 1
        for i in range(exponent):
            pow = base*pow
        return pow
    # 判断base是否很小
    def JudgeSmall(self, base):
        if(abs(base-0.0)<0.0000001):
            return True
        else:
            return False