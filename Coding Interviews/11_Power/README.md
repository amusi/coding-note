# 题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

注：不得使用库函数，同时不需要考虑大数问题。

# 解题思路

本题旨在实现 C++和 python中的pow库函数，这属于经常遇见的面试题，考查对库函数的理解程度。

此题有很多要考虑的特殊情况：

- base=0，exponent=0，由于0的0次方在数学上没有意义，所以输出0或者1都是可以的，但编写代码的人要知道这一点。
- exponent为负数时，如何处理？

**思路1：**

一般来说，考虑如下三种情况即可：

1. base=0，exponent=0
2. exponent>0
3. exponent<0

提示：由于计算机表示小数（包括float和double型小数）都有误差，我们不能直接用等号（==）判断两个小数是否相等。但如果两个小数的差的绝对值很小，比如小于0.0000001，就可以认为它们相等。

**思路2（递归法）:**

如果输入指数为32，那么我们可以看成base的16次方再乘以base的16次方，而base的16次方可以看成两次base的8次方相乘......根据此规律，当n为偶数时，得出a^n = a^(n/2) * a^(n/2)；当n为奇数时，得出a^n=a^(n-1)/2 * a^(n-1)/2 * a。此公式即可以使用递归方法实现。

# 代码

[C++](Power.cpp)

```c++
class Solution {
public:
    double Power(double base, int exponent) {
        int baseSmallFlag = false;
        baseSmallFlag = JudgeSmallNumber(base);
        double pow = 0;
        if(baseSmallFlag && exponent==0)
            return 0;
        if(exponent==0){
            return 1;
        }
        if(exponent > 0){
            pow = PowerUnsigned(base, exponent);
        }
        else{
            exponent = -exponent;
            pow = 1/PowerUnsigned(base, exponent);
        }
        return pow;
    }
    /* 方法1：常规法
    double PowerUnsigned(double base, int exponent){
        double pow = 1;
        for(int i=1;i<=exponent;++i){
            pow *= base;
        }
        return pow;
    }
    }*/
    /*方法2：递归法*/
    double PowerUnsigned(double base, int exponent){
        // 递归中值条件
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        double pow = PowerUnsigned(base, exponent>>1);    // >>1 右移表示除以2
        pow *=pow;
        if(exponent & 0x1==1)    // 判断基偶数
            pow *= base;
        return pow;
    }
  
    bool JudgeSmallNumber(double base){
        if(abs(base - 0.0)< 0.0000001)
            return true;
        else
            return false;
    }
};
```

[Python](Power.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        baseSmallFlag = False
        pow = 0
        baseSmallFlag = self.JudgeSmall(base)
        if baseSmallFlag and exponent==0:
            return 0
        if exponent ==0:
            return 1
        if exponent > 0:
            pow = self.PowerUnsigned(base, exponent)
        else:
            exponent = abs(exponent)
            pow = 1/self.PowerUnsigned(base, exponent)
            
        return pow
    # 计算exponent为正数的情况
    def PowerUnsigned(self, base, exponent):
        pow = 1
        for i in range(exponent):
            pow = base*pow
        return pow
    # 判断base是否很小
    def JudgeSmall(self, base):
        if(abs(base-0.0)<0.0000001):
            return True
        else:
            return False
```
