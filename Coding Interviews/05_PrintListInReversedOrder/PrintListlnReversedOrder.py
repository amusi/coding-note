# coding=utf-8
# Definition for singly-linked list.  
class ListNode():  
    def __init__(self, x):  
        self.val = x 
        self.next = None  

class ListNode_handle:  
    def __init__(self):  
        self.cur_node = None  
		
    def add(self, data):
        '''从后向前添加元素'''
        #add a new node pointed to previous node  
        node = ListNode(data)
        
        node.next = self.cur_node
        self.cur_node = node
         
        return node

    def append(self, data):
        '''从前向后添加新元素'''
        node = ListNode(data)
        if self.cur_node == None:
            self.cur_node = node  # 若为空表，将添加的元素设为第一个元素
        else:
            current = self.cur_node
            while current.next != None:
                current = current.next
            current.next =  node
        return self.cur_node
  
    def print_ListNode(self, node):  
        while node:  
            print '\nnode: ', node, ' value: ', node.val, ' next: ', node.next  
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
l1 = ListNode_handle()  
l1_list = [67,0,24,58]
for i in l1_list:
	l1_node = l1.append(i)
process = Solution()	
print process.printListFromTailToHead(l1_node)
