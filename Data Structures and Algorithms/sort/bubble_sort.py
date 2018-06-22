''' Summary: 冒泡排序
* Author: Amusi
* Date:   208-05-27
*
* Reference: 
*	http://en.wikipedia.org/wiki/Bubble_sort
*	https://github.com/xtaci/algorithms/blob/master/include/bubble_sort.h
*   https://zhuanlan.zhihu.com/p/37077924
*
* 冒泡排序说明：比较相邻的两个元素，将值大的元素交换到右边（降序则相反）
*
'''

def BubbleSort(array):
    lengths = len(array)
    for i in range(lengths-1):
        for j in range(lengths-1-i):
            if array[j] > array[j+1]:
               array[j+1], array[j] = array[j], array[j+1]

    return array


array = [1,3,8,5,2,10,7,16,7,4,5]
print("Original array: ", array)
array = BubbleSort(array)
print("BubbleSort: ", array)
