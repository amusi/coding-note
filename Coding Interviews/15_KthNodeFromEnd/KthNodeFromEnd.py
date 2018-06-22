'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-22

题目描述
输入一个链表，输出该链表中倒数第k个结点。


'''

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        # 输入判断
        if(head==None or k==0):
            return None
        
        pHead = head;
        pTail = head;
        # pHead先走 k-1步 
        for i in range(1, k):
            if pHead.next!=None:
                pHead = pHead.next
            else:
                return None;
        # pHead和pTail同时走，最后pTail还差k-1步才能走到最后，即pTail当前是倒数第k个结点。
        while(pHead.next!=None):
            pHead = pHead.next
            pTail = pTail.next
        
        return pTail