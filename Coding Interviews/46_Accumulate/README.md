# 求1+2+3+...+n

# 题目描述

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

# 解题思路

1. 公式法：n*(n+1)/2
2. 循环法：1+2+...+n
   - 构造函数法（仅限于C++）
   - 递归法


# 代码

[C++](Accumulate.cpp) 公式法和构造函数法

```c++
class Temp{
public:
    Temp(){++N; Sum+=N;}
    static void Reset() {N=0;Sum=0;}
    static int GetSum() {return Sum;}
private:
    static int N;
    static int Sum;
    
};

// 类外初始化Temp类中的私有变量
int Temp::N = 0;
int Temp::Sum = 0;

class Solution {
public:
    
    int Sum_Solution(int n) {
        // way1: 利用二维数组实现乘法
        //bool a[n][n+1];
        //return sizeof(a)>>1;
        
        // way2: 构造函数求解法
        Temp::Reset();
        Temp *a = new Temp[n];    // 循环调用构造函数n次，实现1+2+...+n
        delete []a;
        a = NULL;
        return Temp::GetSum();
    }
};
```

[Python](Accumulate.py) 递归法

```python
# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        # write code here
        # 短路法
        ans = n
        temp = ans and self.Sum_Solution(n-1)
        ans += temp
        return ans
```

