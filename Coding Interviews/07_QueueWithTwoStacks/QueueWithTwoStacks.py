'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-17

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。


'''

# -*- coding:utf-8 -*-
# <分析>：利用两个栈，实现两次进栈出栈（先入后出x2）即可实现队列（先入先出）。
class Solution:
    def __init__(self):
        self.stack1 = []    # 栈A
        self.stack2 = []    # 栈B
    def push(self, node):
        # write code here
        self.stack1.append(node)    # 向栈顶添加元素
    def pop(self):
        # return xx
        if len(self.stack2) > 0:
            return self.stack2.pop()
        # 将栈A的所有元素pop并push至栈B中，
        while len(self.stack1)>0: # 或者 while self.stack1
            self.stack2.append(self.stack1.pop())
        if len(self.stack2) > 0:
            return self.stack2.pop()