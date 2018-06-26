/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-06-26

题目描述
输入一个链表，反转链表后，输出新链表的表头。

*****************************************/

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
    // 思路: 将列表进行反转
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;
        
        ListNode* cur = pHead;
        ListNode* pre = NULL;    // ListNode* pre = NULL;
        ListNode* post = NULL;    // ListNode* post = pHead->next;
        while (cur!=NULL){
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        pHead = pre;
        return pHead;
    }
};