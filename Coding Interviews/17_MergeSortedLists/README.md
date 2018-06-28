# 题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

# 解题思路

此题考查[链表](https://github.com/amusi/coding-note/blob/master/Coding%20Interviews/05_PrintListInReversedOrder/Linkedlist.md)知识点。

假设输入两个链表的头结点分别是是ListNode1和ListNode2。

**方法1：非递归法**

非递归法就是新建一个合并链表的头结点pHead，然后将空链表**指向**两个链表中头结点较小的链表（注意这里是指向的思想）。然后再新建一个头结点pCur，其初始化时指向pHead。pCur的目的是不断地给合并链表添加新的结点，因为pHead是头结点，并不能移动（这里试想一下每次移动pHead的后果...）。

每次向合并链表添加新的结点，该新结点其实就是**当前**ListNode1和ListNode2中的最小结点。注意这里为什么要用当前，因为每次添加完结点后，ListNode1或ListNode2都要移向下一个结点。如当前ListNode1的结点值比ListNode2的结点值小，那么就应该是pCur->next = ListNode1，然后ListNode1 = ListNode1->next。

那么什么时候停止添加新结点呢？

答：直到某一个链表的结点全部被遍历时，此刻再将另一个链表剩余的结点添加至合并链表后面即可。

注：添加新结点就等价于链表的尾节点指向新结点。

**方法2：递归法**

递归法真的很重要，很考验思维能力和coding，下面提供了C++版本，还有Python版本的递归法实现代码。这里就不赘述（因为很难描述）。

注：递归要搞清楚输入是什么，输出是什么？以及何时停止问题。

# 代码

[C++](MergeSortedLists.cpp)

方法1：非递归法

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    // 方法1：常规法
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 输入判断
        if(pHead1==NULL && pHead2==NULL){
            return NULL;
        }
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        // 不确定下面初始化要不要赋值NULL
        ListNode* pHead=NULL;    // 输出的合成链表（头结点）
        ListNode* pCur=NULL;     // 指向输出的合成链表（移动结点）
        // 初始化pHead
        if(pHead1->val<=pHead2->val){
            pHead = pHead1;
            pHead1 = pHead1->next;
        }else{
            pHead = pHead2;
            pHead2 = pHead2->next;
        }
        pCur = pHead;    // 指向链表的头结点
        // 给链表添加新结点（单调不减）
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val<=pHead2->val){
                pCur->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                pCur->next = pHead2;
                pHead2 = pHead2->next;
            }
            pCur = pCur->next;
        }
        // 将某链表剩余的结点添加到合并链表的后面
        if(pHead1==NULL){
            pCur->next = pHead2;
        }else{
            pCur->next = pHead1;
        }
        // 返回单调不减的合并链表
        return pHead;
    }
}
```

版本2：递归法

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    /* 方法2：递归法*/
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 输入判断
        if(pHead1==NULL && pHead2==NULL){
            return NULL;
        }
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        
        ListNode* pHead=NULL;
        if(pHead1->val <= pHead2->val){
            pHead = pHead1;
            pHead->next = Merge(pHead1->next, pHead2);
        } else {
            pHead = pHead2;
            pHead->next = Merge(pHead1, pHead2->next);
        }
        
    return pHead;
    }
};
```

[Python](MergeSortedLists.py)

版本2：递归法

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        # 递归法
        if pHead1==None:
            return pHead2
        if pHead2==None:
            return pHead1
        
        if pHead1.val <= pHead2.val:
            pHead1.next = self.Merge(pHead1.next, pHead2)
            return pHead1
        
        if pHead2.val < pHead1.val:
            pHead2.next = self.Merge(pHead1, pHead2.next)
            return pHead2
```

# 参考

https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337