# 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

# 解题思路

考查知识点：

- [栈（Stack）知识点](https://github.com/amusi/coding-note/blob/master/Coding%20Interviews/07_QueueWithTwoStacks/QueueStack.md)
- [C++ STL::Stack用法](http://www.cplusplus.com/reference/stack/stack/)
- [Python list用法](https://docs.python.org/3.8/c-api/list.html)

**方法1：数据栈和辅助栈相同容量**

TODO：待添加描述

缺点: 随着压入栈内的元素增多，占用的"不必要"内存较大。如压入3,4,5,5,6...共n个非减的序列，其实最小值一直是3，如果利用方法2，那么辅助栈只需要保存一个元素3即可。但若使用方法一，则需要多存储n-1个元素。

**方法2：数据栈容量大于辅助栈容量**

TODO：待添加描述



# 代码

[C++](MinInStack.cpp)：方法1

```c++
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
```

方法2：

```c++
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
```



[Python](MinInStack.py)：方法2

```python
# -*- coding:utf-8 -*-
class Solution:
    
    def __init__(self):
        self.data_stack = []
        self.help_stack = []
    # 压入新元素
    def push(self, node):
        self.data_stack.append(node)
        if len(self.help_stack)==0:
            self.help_stack.append(node)
        else:
            if node < self.help_stack[-1]:
                self.help_stack.append(node)
            else:
                self.help_stack.append(self.help_stack[-1])
    # 弹出栈顶元素
    def pop(self):
        self.data_stack.pop()
        self.help_stack.pop()
    
    # 返回栈顶元素
    def top(self):
        return self.data_stack[-1]
        
    # 返回当前栈中最小元素
    def min(self):
        return self.help_stack[-1]
```

# 参考

https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49