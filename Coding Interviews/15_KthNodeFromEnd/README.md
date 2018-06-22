# 题目描述

输入一个链表，输出该链表中倒数第k个结点。

# 解题思路

此题考查[链表](https://github.com/amusi/coding-note/blob/master/Coding%20Interviews/05_PrintListInReversedOrder/Linkedlist.md)知识点。题目很简短，就是要输出链表中倒数第k个结点，方法有很多，下面介绍两种常见的方法。

注：输出的是结点，而不是结点的value，所以用Python的童鞋不要以为转换成列表，再用list[-k]就可以解决这个问题哦。

**方法1（根据链表长度再计算）：**

1. 计算出链表的长度 length
2. 利用链表list_k，初始情况下，指向输入链表的pListHead，然后移动 length-k位。此时list_k即处于倒数第k个结点的位置。

如链表的长度为100，我们需要输出倒数第7个结点，即需要移动 93 = 100-7位，当前节点即处于倒数第7个结点的位置，实质上是正数第94个节点的位置。为什么是94呢？因为每次移动后，list_k=list_k.next。

**方法2（经典双指针思想：快慢指针）：**

1. 利用两个链表指针，ListNode *nodePre和 ListNode *nodeLast，初始情况下，两者都是指向输入链表pListHead。
2. | k-1 -------->| nodePre 领先 nodeLast k-1 步出发
3. |---------> k-1 | nodePre和 nodeLast一起出发，当 nodePre先到达终点时，nodeLast正好距终点有k-1个节点，而它本身处于倒数第k个结点处。

# 代码

[C++](KthNodeFromEnd.cpp)

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        /*方法2（经典双指针思想：快慢指针）*/
        // 思路: 作者：bigpo
        // 链接：https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a
        // | k-1 -------->| nodePre 领先 nodeLast k-1 步出发
        // |---------> k-1 | 当nodePre先到达终点时，nodeLast正好距终点有k-1个节点,而它本身处于倒数第k个节点处
        
        // 输入判断
        if(pListHead==NULL || k==0)
            return NULL;
        
        ListNode *pTail = pListHead, *pHead = pListHead;
        // pHead先走 k-1步 
        for(int i=1;i<k;++i){
            if(pHead->next!=NULL)
                pHead = pHead->next;
            else
                return NULL;
        }
        // pHead和pTail同时走，最后pTail还差k-1步才能走到最后，即pTail当前是倒数第k个结点。
        while(pHead->next!=NULL){
            pHead = pHead->next;
            pTail = pTail->next;
        }
        return pTail;
        
        /* 方法1（根据链表长度再计算）
        // 缺点：计算量大，无论如何遍历整个链表
        if(pListHead==NULL || k==0)
            return NULL;
        unsigned int length = 0;
        ListNode *ln = pListHead;
        // 计算链表长度
        while(ln!=NULL){
            ++length;
            ln = ln->next;
        }
        if(length<k){
            return NULL;
        }
        ListNode *ln2 = pListHead;
        for(unsigned int i=0;i<length-k;++i){
            ln2 = ln2->next;
        }
        return ln2;*/
           
    }
};
```

[Python](KthNodeFromEnd.py)

```python
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
```

# 参考

https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a