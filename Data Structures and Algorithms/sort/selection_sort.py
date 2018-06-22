''' Summary: 选择排序
* Author: Amusi
* Date:   208-06-22
*
* Reference: 
*   https://en.wikipedia.org/wiki/Selection_sort
*
* 选择排序说明：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
*
'''

def SelectionSort(array):
    lengths = len(array)
    for i in range(lengths-1):
        min_index = i
        for j in range(i, lengths):
            if array[j] < array[min_index]:
               min_index = j
        array[i], array[min_index] = array[min_index], array[i]
		
    return array


array = [1,3,8,5,2,10,7,16,7,4,5]
print("Original array: ", array)
array = SelectionSort(array)
print("SelectionSort: ", array)
