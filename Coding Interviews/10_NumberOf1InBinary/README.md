# 题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

# 解题思路

此题考查二进制的知识点和将“十进制转换成二进制”在编程语言中的写法。

负数的二进制（[补码](https://www.cnblogs.com/zengguowang/p/6074845.html)）：先取反，再+1。

**思路1（不推荐）：**

1. 先判断输入整数的正负情况；
2. 如果是正数，进入第3步；如果是负数，则转换成补码，再将二进制转换成十进制；
3. 将十进制转换成二进制；
4. 统计二进制中 1的个数。

注：此方法没有技巧，就是大脑初始的想法，操作性极差，故不推荐。

**思路2（推荐）：**

如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。

举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000。也就是说，**把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。**

注：上述方法技巧性十足，很考验观察和推导能力。

# 代码

[C++](NumberOf1InBinary.cpp)

```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n!= 0){
             ++count;
             n = n & (n - 1);
         }
         return count;
         
     }
};
```

[Python](NumberOf1InBinary.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    # 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
    def NumberOf1(self, n):
        # write code here
        count, bit = 0, 1
        INT_BITS = 32 
        MAX_INT = (1 << (INT_BITS - 1)) - 1  # Maximum Integer for INT_BITS
        while n and bit <= MAX_INT + 1:
            if bit & n:
                count += 1
                n -= bit
            bit = bit << 1
        return count
```

# 参考

【1】https://www.nowcoder.com/profile/9536154/codeBookDetail?submissionId=17465787

【2】https://www.cnblogs.com/klchang/p/8017627.html