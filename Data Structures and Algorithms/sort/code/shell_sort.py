'''
* Summary: 希尔排序（Shell Sort）
* Author: Amusi
* Date:   2018-09-23
*
* Reference:
*   https://en.wikipedia.org/wiki/Shellsort
*   https://www.geeksforgeeks.org/shellsort/
*   希尔排序（shell sort）：设待排序元素序列有n个元素，首先取一个整数increment（小于n）作为间隔将全部元素分为increment个子序列，所有距离为increment的元素放在同一个子序列中，在每一个子序列中分别实行直接插入。
*
*
'''

def ShellSort(array):
    lengths = len(array)
    # 初始化gap
    gap = lengths//2
    # 减少增量，遍历子序列进行插入排序
    while(gap > 0):
        for i in range(gap, lengths):
            # 
            temp = array[i]
            j = i
            # 子序列插入排序
            while j>=gap and array[j-gap]>temp:
                array[j] = array[j-gap]
                j -= gap

            array[j] = temp
        
        gap = gap//2
		
    return array


array = [1,3,8,5,2,10,7,16,7,4,5]
print("Original array: ", array)
array = ShellSort(array)
print("InsertionnSort: ", array)
