# 题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

# 解题思路

考查知识点：

- [栈（Stack）知识点](https://github.com/amusi/coding-note/blob/master/Coding%20Interviews/07_QueueWithTwoStacks/QueueStack.md)
- [C++ STL::Stack用法](http://www.cplusplus.com/reference/stack/stack/)
- [Python list用法](https://docs.python.org/3.8/c-api/list.html)

一开始看到这个题目，觉得很简单。以为是一下子入栈，然后出栈，所以理所当然以为直接判断第一个序列和第二个序列是否是逆序关系。但结果发现是我太单纯了，题目都没有读懂。

为了方便描述，这里定义第一个序列（压入栈）为pushV，第二个序列（弹出栈）为popV。

本题的关键考查对栈（stack）的掌握，其特点是先入后出，返回栈顶元素。

解决此问题的技巧在于，**构建一个辅助栈stack**。该辅助栈stack就是来模拟pushV的弹出情况是否能和popV一致。如果一致，则表示pushV和popV是满足"栈的压入、弹出序列"关系的，否则，不满足关系。

通过将pushV的元素依次压入到stack中，在每压入新元素时，需要将stack栈顶元素与popV栈顶元素进行比较。如果相同，则将stack和popV栈顶元素都弹出；如果不同，则继续压入新元素。当把pushV序列中所有元素压入stack，并进行stack和popV栈顶严元素比较后，判断此时stack是否为空的情况。

如果stack为空，则表示辅助栈stack与popV序列对应关系一致，即pushV和popV是满足"栈的压入、弹出序列"关系的，否则，不满足关系。



# 代码

[C++](StackPushPopOrder.cpp)

```c++
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
```

[Python](StackPushPopOrder.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    def IsPopOrder(self, pushV, popV):
        # 判断输入
        if len(pushV) == 0:
            return False
        # 添加辅助栈
        stack = []
        j = 0
        for i in range(0, len(pushV)):
            # 向辅助栈添加pushV元素
            stack.append(pushV[i])
            # 两个条件缺一不可
            # 条件1: 弹出的数量小于或等于序列长度
            # 条件2: 辅助栈的栈顶元素与对应的popV序列元素值相等
            while j<len(popV) and stack[-1]==popV[j]:
                stack.pop()    # 弹出辅助栈顶元素
                j+=1           # popV序列下一个元素索引
        if len(stack) == 0:
            return True
        return False
```

# 参考

https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106