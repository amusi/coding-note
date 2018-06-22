/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-06-22

题目描述
输入一个链表，输出该链表中倒数第k个结点。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        /*方法2（经典双指针思想：快慢指针）*/
        // 思路: 作者：bigpo
        // 链接：https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a
        // | k-1?-------->|?nodePre?领先?nodeLast?k-1?步出发
????????// |--------->?k-1?|?当nodePre先到达终点时，nodeLast正好距终点有k-1个节点,而它本身处于倒数第k个节点处
        
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