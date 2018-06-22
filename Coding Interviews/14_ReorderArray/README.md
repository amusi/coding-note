# 题目描述

**输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对顺序不变。**

注：此题是牛客网添加了限制条件的题目，并非原《剑指Offer》第14题：调整数组顺序使奇数位于偶数前面。

原题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

从这里就能看出，牛客网添加了限制条件：保证奇数和奇数，偶数和偶数之间的相对顺序不变。

# 解题思路

**思路1（简单粗暴不推荐）：时间复杂度o(n)**

既然是将数组分成偶数部分和奇数部分，那么可以先遍历一遍整个数组array，分别将奇数和偶数的值拷贝至两个容器中，如奇数容器odd和偶数容器even（此时odd和even各自保持了相对顺序不变）。然后依次将odd和even中的值赋值于array。此时的array即是由相对顺序不变的奇数部分和偶数部分组成。

**思路2（冒泡排序）：时间复杂度o(n^2)**

此题也可以利用冒泡排序的思想，相邻元素进行比较，如果前者是偶数，后者是奇数，则交换两个元素的位置。遍历完第 i次数组，倒数第 i个元素就被确定好，不再进行判断交换。具体的可以查看[冒泡排序](https://en.wikipedia.org/wiki/Bubble_sort)的思想。

- [ ] **思路3（归并、插入、归并和快速排序）**

# 代码

[C++](Power.cpp)

```c++
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        /*方法3（归并、插入、归并和快速排序）：TODO*/
        /*方法2（冒泡排序）：复杂度为o(n2)*/
        int size = array.size();
        if(size == 0){
            return;
        }
        int temp=0;
        for(int i=0;i<size-1;++i){
            for(int j=0;j<size-i-1;++j){
                if((array[j])%2==0 && (array[j+1])%2==1){
                    //temp = array[j];
                    //array[j] = array[j+1];
                    //array[j+1] = temp;
                    swap(array[j+1], array[j]);
                }
            }
        }
        
        /* 方法1（最low的方法）: 复杂度为o(N)
        // 缺点: 用空间换时间
        int size = array.size();
        if(size == 0)
            return;
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<size;++i){
            if(array[i]%2==0)
                even.push_back(array[i]);
            else
                odd.push_back(array[i]);
        }
        
        for(int i=0;i<odd.size();++i){
            array[i]=odd[i];
        }
        for(int i=0;i<even.size();++i){
            array[i+odd.size()]=even[i];
        }*/
    }
};
```

[Python](Power.py)

```python
# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        # 冒泡排序
        size = len(array)
        for i in range(size-1):
            for j in range(size-1-i):
                if array[j]%2==0 and array[j+1]%2==1:
                    array[j], array[j+1] = array[j+1], array[j];
        return array
```
