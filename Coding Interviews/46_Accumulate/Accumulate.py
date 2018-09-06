'''
Copyright: Amusi
Author:    Amusi
Date:      2018-09-06

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

'''

# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        # write code here
        # 短路法
        ans = n
        temp = ans and self.Sum_Solution(n-1)
        ans += temp
        return ans