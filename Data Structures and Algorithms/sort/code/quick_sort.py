''' Summary: 快速排序（Quick Sort）
* Author: Amusi
* Date:   208-07-28
*
* Reference: 
*   https://en.wikipedia.org/wiki/Quicksort
*   https://www.cnblogs.com/wujingqiao/articles/8961890.html
*	https://github.com/apachecn/LeetCode/blob/master/src/py3.x/sort/QuickSort.py
*   快速排序（quick sort）：通过一趟排序将待排列表分隔成独立的两部分，其中一部分的所有元素均比另一部分的所有元素小，则可分别对这两部分继续重复进行此操作，以达到整个序列有序。（这个过程，我们可以使用递归快速实现）
*
'''

def QuickSort(array, start, end):
    lengths = len(array)
    i = start
    j = end
    # 结束排序（左右两索引值见面，即相等，或者左索引>右索引）
    if i >= j:
        return	# 返回空即可
    # 保存首个数值（以首个数值作为基准）
	# 这个位置很重要，一定要在if i>=j判断语句之后，否则就索引溢出了
    pivot = array[i]
    # 一次排序，i和j的值不断的靠拢，然后最终停止，结束一次排序
    while i < j:
        # 一层循环实现从左边起大于基准的值替换基准的位置，右边起小于基准的值位置替换从左起大于基准值的索引
        # （从右往左）和最右边的比较，如果>=pivot,即满足要求，不需要交换，然后j-1，慢慢左移，即拿基准值与前一个值比较; 如果值<pivot，那么就交换位置
        while i < j and pivot <= array[j]:
            # print(pivot, array[j], '*' * 30)
            j -= 1
        array[i] = array[j]
        # 交换位置后，然后在和最左边的值开始比较，如果<=pivot,然后i+1，慢慢的和后一个值比较;如果值>pivot，那么就交换位置
        while i < j and pivot >= array[i]:
            # print(pivot, array[i], '*' * 30)
            i += 1
        array[j] = array[i]
    # 列表中索引i的位置为基准值，i左边序列都是小于基准值的，i右边序列都是大于基准值的，当前基准值的索引为i，之后不变
    array[i] = pivot
    # 左边排序
    QuickSort(array, start, i-1)
    # 右边排序
    QuickSort(array, i+1, end)
		
    #return array

if __name__ == "__main__":
    array = [1,3,8,5,2,10,7,16,7,4,5]
    print("Original array: ", array)
    #array = QuickSort(array, 0, len(array)-1)
	# 因为python中的list对象是可变对象，所以在函数做"形参"时，是相当于按引用传递
	# 所以不写成返回值的形式，也是OK的
    QuickSort(array, 0, len(array)-1)
    print("QuickSort: ", array)
