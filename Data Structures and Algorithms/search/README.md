# 二分查找

二分查找（Binary Search）是将查找的键和子数组的中间键作比较，如果被查找的键小于中间键，就在左子数组继续查找；如果大于中间键，就在右子数组中查找，否则中间键就是要找的元素。

[Python代码](binary_search.py)：

```python
import math

def BinarySearch(arr, key):
    left = 0
    right = len(arr)-1

    while left <= right:
        mid = math.ceil((left+right)/2)
        if arr[mid] == key:
            return 1
        elif arr[mid]<key:
            left = mid+1
        else:
            right = mid-1
    return 0


arr = [10,20,-9,-10,100,-100,77,88,33,21]
arr.sort()
if BinarySearch(arr, -9):
    print("Yes")
else:
    print("No")
```

参考：

[二分查找(Binary Search)](https://www.cnblogs.com/yedushusheng/p/5524166.html)

[你真的会写二分查找吗](https://www.cnblogs.com/luoxn28/p/5767571.html)