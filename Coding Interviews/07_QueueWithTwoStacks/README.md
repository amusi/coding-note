# 题目描述

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

（推荐阅读）：[队列和栈（Queue and stack）](QueueStack.md)

# 解题思路

此题考查**队列和栈**的知识点，个人觉得题目不难，但理解数据结构【队列】和【栈】反倒是一件困难的事情。

<分析>：利用两个栈，实现两次进栈出栈（先入后出x2）即可实现队列（先入先出）。

如1，2，3，4，5依次入栈A（此时top为5），出栈并入栈B为：5，4，3，2，1（此时top为1）。此时的栈B即相当于一个队列。

入队：将元素进栈A

出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；

如果不为空，栈B直接出栈。



# 代码

[C++](QueueWithTwoStacks.cpp)

```c++
class Solution
{
/* 解题思路
<分析>：利用两个栈，实现两次进栈出栈（先入后出x2）即可实现队列（先入先出）。
如1,2,3,4,5依次入栈A（此时top为5），出栈并入栈B为：5,4,3,2,1（此时top为1）。此时的栈B即相当于一个队列。
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
```

[Python](QueueWithTwoStacks.py)

```python
# -*- coding:utf-8 -*-
# <分析>：利用两个栈，实现两次进栈出栈（先入后出x2）即可实现队列（先入先出）。
class Solution:
    def __init__(self):
        self.stack1 = []    # 栈A
        self.stack2 = []    # 栈B
    def push(self, node):
        # write code here
        self.stack1.append(node)    # 向栈顶添加元素
    def pop(self):
        # return xx
        if len(self.stack2) > 0:
            return self.stack2.pop()
        # 将栈A的所有元素pop并push至栈B中，
        while len(self.stack1)>0: # 或者 while self.stack1
            self.stack2.append(self.stack1.pop())
        if len(self.stack2) > 0:
            return self.stack2.pop()
```

# 参考

[思路和代码解答](https://www.nowcoder.com/questionTerminal/54275ddae22f475981afa2244dd448c6)

