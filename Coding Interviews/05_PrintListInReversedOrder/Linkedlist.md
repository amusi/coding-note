# 数据结构—链表

链表又称线性表。直观的理解，即所有元素排成了一排！注意是一排！没有分支！

链表的常用操作（operation）：

InitList（*L）：初始化操作，建立一个空的线性表L

ListEmpty（L）：若线性表为空，返回true，否则返回false。

ClearList（*L）：将线性表清空。

GetElem（L, i, *e）：将线性表L中的第i个位置元素值返回给e。

LocateElem（L, e）：在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则，返回0表示失败。

ListInsert（*L, i, e）：在线性表L中的第i个位置插入新元素e。

ListDelete（*L, i, e）：删除线性表L中第i个位置元素，并用e返回其值。

ListLength（L）：返回线性表L对元素个数。



C++

LinkList.h

```c++
/*******************************************************************
Summary: 链表
Author: Amusi
Date: 2018-06-11
Reference: https://blog.csdn.net/starstar1992/article/details/59808706
*******************************************************************/


#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <iostream>

// 节点定义
typedef struct node {
	int data;
	struct node *next;
}NODE;


// 链表类定义
class LinkList
{
private:
	NODE *head;
public:
	LinkList() { head = NULL; }
	~LinkList();
	void clearSqList();
	bool isEmpty() { return head == NULL; }
	int Length();
	bool GetElem(int i, int *e);
	int LocateElem(int e);
	bool PriorElem(int cur_e, int *pre_e);
	bool NextElem(int cur_e, int *next_e);
	bool Insert(int i, int e);
	bool Delete(int i, int *e);
	NODE * Reverse();
};

//析构函数
LinkList::~LinkList()//和清空一样
{
	NODE *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}

// 清空函数 
void LinkList::clearSqList()//清空函数，和析构一样
{
	NODE *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}

//获取链表长度
int LinkList::Length()
{
	NODE *p = head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

// 获取指定位置的元素
bool LinkList::GetElem(int i, int *e)//*e是返回的元素
{
	NODE *p = head;
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	*e = p->data;
	return true;
}

// 查找元素e在链表什么位置（下标位置，从0开始）
int LinkList::LocateElem(int e)
{
	int i = 0;
	NODE *p = head;
	while (p != NULL)
	{
		if (p->data == e)
			return i;
		else p = p->next;
		i++;
	}
	std::cout << "表中不存在指定元素" << std::endl;
	exit(1);
}

// 取上一个元素
bool LinkList::PriorElem(int cur_e, int *pre_e)
{
	NODE *p = head;
	if (p->data == cur_e) return false;//是头结点，不存在上一个元素
	while (p->next != NULL)
	{
		if (p->next->data == cur_e)
		{
			*pre_e = p->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;//遍历完不存在或者只有一个头结点

}

// 取下一个元素
bool LinkList::NextElem(int cur_e, int *next_e)
{
	NODE *p = head;
	if (head == NULL || head->next == NULL) return false;
	while (p->next != NULL)
	{
		if (p->data == cur_e)
		{
			*next_e = p->next->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;
}


// 在指定位置插入元素e
bool LinkList::Insert(int i, int e)
{
	NODE *p = head, *s;
	int j = 0;
	if (i == 0)
	{
		s = (NODE *)new NODE[1];
		s->data = e;
		s->next = p;
		head = s;
		return true;
	}
	while (p&&j < i - 1)
	{
		p = p->next;	// p沿着链表移动j位
		j++;
	}
	if (p == NULL)
		return false;//到队尾了
	// 新建节点
	s = (NODE *)new NODE[1];
	s->data = e;
	s->next = p->next;
	p->next = s;	// 关键
	return true;
}


// 删除指定位置的元素，并把删除的元素赋给*e
bool LinkList::Delete(int i, int *e)
{
	NODE *p = head, *s;
	if (p == NULL) return false;
	int j = 0;
	if (i == 0)
	{
		head = head->next;	
		*e = p->data;
		delete p;
		p = NULL;
		return true;
	}
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;	// p沿着链表移动
	}
	if (p == NULL)
		return false;
	s = p->next;
	p->next = p->next->next;
	*e = s->data;
	delete s;
	s = NULL;
	return true;
}

//反转一个链表
NODE* LinkList::Reverse()
{
	if (head == NULL || head->next == NULL) return head;
	NODE *p = head, *q = head->next, *r;
	head->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}


#endif


```

main.cpp

```c++
/*******************************************************************
Summary: 链表
Author: Amusi
Date: 2018-06-11
Reference: https://blog.csdn.net/starstar1992/article/details/59808706
*******************************************************************/


#include<iostream>
#include "LinkList.h"
using namespace std;
int main()
{
	int a = 0;
	int *p = &a;
	LinkList li;	// 初始化链表
	li.Insert(0, 5);
	li.Insert(1, 4);
	li.Insert(2, 12);
	li.Insert(3, 5);
	li.Insert(3, 6);
	li.Insert(1, 7);
	cout << "链表长度" << li.Length() << endl;
	cout << "各个元素的值是：";
	for (int i = 0; i < li.Length(); i++)//遍历该链表
	{

		if (li.GetElem(i, p))
			cout << *p << "   ";
	}
	cout << endl;
	cout << "反转后各个元素的值是：";
	NODE* re_li = li.Reverse();
	while (re_li)
	{
		cout << re_li->data << "   ";
		re_li = re_li->next;
	}
	cout << endl;
}
```

Python

```python
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
```



# 参考

[链表从无到有](https://www.zhihu.com/question/53645056/answer/139083035)

[数据结构（二）：链表](https://zhuanlan.zhihu.com/p/24720029)

[链表C++实现](https://blog.csdn.net/starstar1992/article/details/59808706)

[Linked List Problems](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)

[Linked List Challenges](https://www.hackerrank.com/domains/data-structures/linked-lists)