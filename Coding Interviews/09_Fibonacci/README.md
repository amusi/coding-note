# 题目描述

大家都知道斐波那契数列（Fibonacci sequence），现在要求输入一个整数n，请你输出斐波那契数列的第n项。

n<=39

# 解题思路

此题考查斐波那契数列知识点。请参考[斐波那契数列](Fibonacci.md)

斐波那契数列的特征在于前两个数之后的数是前两个数之和（即当前项是前两项的和）。

​                                                    ![{\displaystyle 1,\;1,\;2,\;3,\;5,\;8,\;13,\;21,\;34,\;55,\;89,\;144,\;\ldots }](https://wikimedia.org/api/rest_v1/media/math/render/svg/0e5d998b257a8bd5307563ca4c7b96edcb5924a2).

根据定义，Fibonacci序列中的前两个数字是1和1（默认），或0和1，具体取决于所选序列的起始点，并且每个后续数字都是前两个数字的和。s

这里，我们使用网上大多数人默认使用1和1作为数列的前两个数值，然后根据斐波那契数列公式进行求解：

![{\displaystyle F_{n}=F_{n-1}+F_{n-2},}](https://wikimedia.org/api/rest_v1/media/math/render/svg/0fff1a1716fcc169546079870357f92757ade5fa)

# 代码

[C++](QueueWithTwoStacks.cpp)

```c++
class Solution {
public:
    int Fibonacci(int n) {
    // 斐波那契数列从1开始，如1,1,2,3,5,8...
        if(n > 39 || n < 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        int i=3;
        int fn_2=1;
        int fn_1=1;
        int fn=0;
        while(i <= n){
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
            ++i;
        }
        return fn;
    }
};
```

[Python](QueueWithTwoStacks.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if(n>39) or (n<0):
            return 0
        if(n==1 or n==2):
            return 1
        fn_2 = 1
        fn_1 = 1
        fn = 0
        i = 3
        while(i<=n):
            fn = fn_2 + fn_1
            fn_2 = fn_1
            fn_1 = fn
            i = i+1
        return fn
```
