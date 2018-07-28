/* Summary: 插入排序（Insertion Sort）
* Author: Amusi
* Date:   2018-07-16
*
* Reference: 
*   https://en.wikipedia.org/wiki/Insertion_sort
*	
* 插入排序（insertion sort）又称直接插入排序（staright insertion sort），其是将未排序元素一个个插入到已排序列表中。对于未排序元素，在已排序序列中从后向前扫描，找到相应位置把它插进去；在从后向前扫描过程中，需要反复把已排序元素逐步向后挪，为新元素提供插入空间。
*
*/

#include <iostream>

// 插入排序函数
namespace alg{
	template<typename T>
	static void InsertionSort(T list[], int length)
	{
		// 从索引为1的位置开始遍历
		for (int i = 1; i < length; ++i)
		{
			T currentValue = list[i];	// 保存当前值
			int preIndex = i - 1;	// 前一个索引值
			// 循环条件: 前一个索引值对应元素值大于当前值 && 前一个索引值大于等于0
			while (list[preIndex] > currentValue && preIndex >= 0){
				list[preIndex + 1] = list[preIndex];
				preIndex--;
			}
			list[preIndex + 1] = currentValue;
		}
	}
}

using namespace std;
using namespace alg;


int main()
{
	int a[8] = { 5, 2, 5, 7, 1, -3, 99, 56 };
	InsertionSort<int>(a, 8);
	for (auto e : a)
		std::cout << e << " ";

	return 0;
}