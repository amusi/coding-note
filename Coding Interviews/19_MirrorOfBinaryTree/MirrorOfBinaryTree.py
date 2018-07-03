'''
Copyright: Amusi
Author:    Amusi
Date:      2018-07-03

题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。

输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

'''

# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        # write code here
        if root==None:
            return
        #(可选) 判断是不是叶子结点
        if root.left==None and root.right==None:
            return
        # 交换非叶子结点
        temp = root.left
        root.left = root.right
        root.right = temp
        # 如果不是非叶子结点，继续递归
        if root.left!=None:
            self.Mirror(root.left)
        if root.right!=None:
            self.Mirror(root.right)