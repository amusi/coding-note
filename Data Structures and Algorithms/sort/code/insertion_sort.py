''' Summary: 插入排序（Insertion Sort）
* Author: Amusi
* Date:   208-07-16
*
* Reference: 
*   https://en.wikipedia.org/wiki/Insertion_sort
*   https://www.cnblogs.com/wujingqiao/articles/8961890.html
*	
* 插入排序（insertion sort）又称直接插入排序（staright insertion sort），其是将未排序元素一个个插入到已排序列表中。对于未排序元素，在已排序序列中从后向前扫描，找到相应位置把它插进去；在从后向前扫描过程中，需要反复把已排序元素逐步向后挪，为新元素提供插入空间。
*
'''

def InsertionnSort(array):
    lengths = len(array)
    # 从索引位置1开始
    for i in range(1, lengths):
        currentValue = array[i] # 当前索引对应的元素数值
        preIndex = i-1		     # 前一个索引位置
        # 循环条件: 前一个索引对应元素值大于当前值，前一个索引值大于等于0
        while array[preIndex] > currentValue and preIndex>=0:
        	array[preIndex+1] = array[preIndex]	# 前一个索引对应元素值赋值给当前值
        	preIndex -= 1	# 前一个索引位置-1
        # preIndex+1，实现元素交换
        array[preIndex+1] = currentValue
		
    return array


array = [1,3,8,5,2,10,7,16,7,4,5]
print("Original array: ", array)
array = InsertionnSort(array)
print("InsertionnSort: ", array)
