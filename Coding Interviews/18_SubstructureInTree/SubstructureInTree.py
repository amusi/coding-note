'''
Copyright: Amusi
Author:    Amusi
Date:      2018-07-01

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


'''

# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 递归法
    def HasSubtree(self, pRoot1, pRoot2):
        '''判断pRoot2是不是pRoot1的子树'''
        result = False
        if pRoot1!=None and pRoot2!=None:
            if pRoot1.val==pRoot2.val:
                result = self.DoesTree1HaveTree2(pRoot1, pRoot2)
            if result == False:
                result = self.HasSubtree(pRoot1.left, pRoot2)    # 判断左子树
            if result == False:
                result = self.HasSubtree(pRoot1.right, pRoot2)   # 判断右子树
                
        return result

    def DoesTree1HaveTree2(self, pRoot1, pRoot2):
        '''判断pRoot2是不是pRoot1的子树'''
        if pRoot2==None:
            return True
        if pRoot1==None:
            return False
        if pRoot1.val != pRoot2.val:
            return False
        
        return self.DoesTree1HaveTree2(pRoot1.left,pRoot2.left) and self.DoesTree1HaveTree2(pRoot1.right,pRoot2.right)