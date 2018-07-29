/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-07-11


题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

*****************************************/

// 方法1：数据栈和辅助栈相同容量
class Solution {
public:
    // 题目描述: 包含min函数的栈
    // 方法:
    // 自定义两个栈
    stack<int> dataStack;    // 数据栈
    stack<int> helpStack;    // 辅助栈
    
    // 压入元素 O(1)
    void push(int value) {
        dataStack.push(value);
        if (helpStack.empty()){
            helpStack.push(value);
        }else{
            if(value < helpStack.top()){
                helpStack.push(value);
            }else{
                helpStack.push(helpStack.top());
            }
        }
    }
    
    // 弹出元素 O(1)
    void pop() {
        if(dataStack.empty() ||  helpStack.empty())
            return;
        dataStack.pop();
        helpStack.pop();
    }
    // 返回栈顶元素 O(1)
    int top() {
        return dataStack.top();
    }
    
    // 返回栈中最小元素 O(1)
    int min() {
        return helpStack.top();
    }
     
};


// 方法2 数据栈容量大于辅助栈容量
class Solution {
public:
     
    stack<int> stack1,stack2;
     
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value<=stack2.top())
        {
            stack2.push(value);
        }
    }
     
    void pop() {
      	// 判断两个栈顶元素是否相等
        if(stack1.top()==stack2.top())
            stack2.pop();
        stack1.pop();
         
    }
     
    int top() {
        return stack1.top();       
    }
     
    int min() {
        return stack2.top();
    }
     
};