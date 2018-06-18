/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-06-17

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。


*****************************************/

class Solution
{
/* 解题思路
<分析>：利用两个栈，实现两次进栈出栈即实现一个队列。
如1,2,3,4,5依次入A栈（此时top为5），出栈并入B栈为：5，4，3，2，1（此时top为1）。此时的B栈即相当于一个队列。
入队：将元素进栈A
出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；
 如果不为空，栈B直接出栈
*/
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            // 将stack1中的所有元素pop，并push到stack2中
            while(!stack1.empty()){
                temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
        // 取栈2的队头元素
        temp = stack2.top();
        stack2.pop();
        return temp;;
    }

private:
    // 使用C++ STL: stack
    int temp;
    stack<int> stack1;    // 队列元素
    stack<int> stack2;    // 
};