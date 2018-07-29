/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-07-29


题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

*****************************************/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 判断输入
        if(pushV.size() == 0)
            return false;
        // 添加辅助栈
        vector<int> stack;    // 辅助栈的目的是与popV进行对比
        for(int i=0,j=0; i<pushV.size();){
            // 
            stack.push_back(pushV[i++]);    //  向辅助栈压入pushV元素
            // 两个条件缺一不可
            // 条件1: 弹出的数量小于或等于序列长度
            // 条件2: 辅助栈的栈顶元素与对应的popV序列元素值相等
            while(j < popV.size() && stack.back() == popV[j]){
                stack.pop_back();    // 弹出辅助栈顶元素
                ++j;                 // popV序列下一个元素索引
            }
        }
        return stack.empty();
    }
};