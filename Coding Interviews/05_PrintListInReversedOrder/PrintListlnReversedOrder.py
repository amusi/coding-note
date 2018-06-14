# coding=utf-8
'''
Copyright: Amusi
Author:    Amusi
Date:      2018-06-013

题目描述
输入一个链表，从尾到头打印链表每个节点的值。
'''

# Definition for singly-linked list.  
# 节点类
class ListNode():  
    def __init__(self, x):  
        self.val = x 
        self.next = None  
# 链表处理类
class ListNode_handle:  
    def __init__(self):  
        self.cur_node = None  
		
    def add(self, data):
        '''从后向前添加元素'''
        # 思想: 将新加节点的next指向当前链表（即在首部加节点），生成新的链表，再赋值给当前链表即可
        #add a new node pointed to previous node  
        node = ListNode(data)
        
        node.next = self.cur_node
        self.cur_node = node
         
        return self.cur_node

    def append(self, data):
        '''从前向后添加新元素'''
        # 思想: 找到当前链表的最后节点，将当前链表最后节点的next指向新的节点，即实现链表的扩展，此时不需要重新赋值（因为是在原来的链表上添加的）
        node = ListNode(data)   # 将元素转换成节点
        if self.cur_node == None:
            self.cur_node = node  # 若为空链表，则将添加的元素设为第一个元素
        else:
            current = self.cur_node
            # 判断是否为最后一个节点
            while  current.next != None:
                 current =  current.next
            current.next =  node
            print(self.cur_node is current)
        return self.cur_node
  
    def print_ListNode(self, node):  
        while node:  
            print('\nnode: ', node, ' value: ', node.val, ' next: ', node.next)
            node = node.next  
  
    def _reverse(self, nodelist):  
        list = []  
        while nodelist:  
            list.append(nodelist.val)  
            nodelist = nodelist.next  
        result = ListNode()  
        result_handle = ListNode_handle()  
        for i in list:  
            result = result_handle.add(i)  
        return result

		
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        result = []
        while listNode != None:
            result.append(listNode.val)
            listNode = listNode.next
        result.reverse()
        return result
#测试用例:
#{67,0,24,58}
#对应输出应该为:[58,24,0,67]
l1 = ListNode_handle()  # 初始化对象
l1_list = [67,0,24,58]  # 定义列表
for i in l1_list:
	l1_node = l1.add(i) # 向列表中添加元素
process = Solution()	
print(process.printListFromTailToHead(l1_node))