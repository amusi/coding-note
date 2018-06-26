'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-26

题目描述
输入一个链表，反转链表后，输出新链表的表头。


'''

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    # 思路: 即将链表进行反转
    def ReverseList(self, pHead):
        # write code here
        # 输入判断
        if pHead == None or pHead.next == None:
            return pHead
        pre = None
        cur = pHead
        while cur:
            post = cur.next
            cur.next = pre
            pre = cur
            cur = post
        return pre