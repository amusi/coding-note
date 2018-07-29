'''
Copyright: Amusi
Author:    Amusi
Date:      2018-07-11

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

'''

# -*- coding:utf-8 -*-
class Solution:
    
    def __init__(self):
        self.data_stack = []
        self.help_stack = []
    # 压入新元素
    def push(self, node):
        self.data_stack.append(node)
        if len(self.help_stack)==0:
            self.help_stack.append(node)
        else:
            if node < self.help_stack[-1]:
                self.help_stack.append(node)
            else:
                self.help_stack.append(self.help_stack[-1])
    # 弹出栈顶元素
    def pop(self):
        self.data_stack.pop()
        self.help_stack.pop()
    
    # 返回栈顶元素
    def top(self):
        return self.data_stack[-1]
        
    # 返回当前栈中最小元素
    def min(self):
        return self.help_stack[-1]