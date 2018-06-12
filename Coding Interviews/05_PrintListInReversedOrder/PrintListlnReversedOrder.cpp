/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> temp;
        vector<int> temp2;
        //while(head != NULL){
        //    temp.push_back(head->val);
        //    head = head->next;
        //}
        // 逆序方法1: for循环
        //for(int i=temp.size()-1; i>=0; --i){
        //    temp2.push_back(temp[i]);
        //}
        
        // 逆序方法2: vector迭代器
        //for (vector<int>::reverse_iterator it = temp.rbegin(); it!= temp.rend(); it++){
        //    temp2.push_back(*it);
        //}
        // 逆序方法3: C++ < algorithm > 中定义的reverse函数
        //reverse(temp.begin(), temp.end());
        // 逆序方法4: 栈
        std::stack<ListNode*> nodes;
        ListNode *pNode = head;
        while(pNode!=NULL){
            nodes.push(pNode);
            pNode = pNode->next;
        }
        while(!nodes.empty()){
            pNode = nodes.top();
            temp.push_back(pNode->val);
            nodes.pop();
        }
        return temp;
    }
};