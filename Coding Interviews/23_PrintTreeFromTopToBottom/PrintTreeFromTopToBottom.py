'''
Copyright: Amusi
Author:    Amusi
Date:      2018-07-30

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

'''

# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    # 广度优先搜索 BFS, 借助一个队列就可以实现
    def PrintFromTopToBottom(self, root):
        # write code here
        result_list = []
        if root==None:
            return result_list
        q = []
        q.append(root)
        while len(q) > 0:
            node = q.pop(0)
            result_list.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
            
        return result_list