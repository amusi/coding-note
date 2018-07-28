/* Summary: 冒泡排序
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
*/

#include <iostream>

// 冒泡函数
namespace alg{
	template<typename T>
	static void BubbleSort(T list[], int length)
	{

#if 1
		// 版本1：两层for循环 
		for (int i = 0; i < length-1; ++i)
		{ 
			for (int j = 0; j < length - i -1; ++j)
			{
				// 两两相邻元素比较大小，从小到大排序
				// if (list[j] < list[j + 1]) : 从大到小排序
				if (list[j] > list[j + 1])
				{
					int temp = list[j + 1];
					list[j + 1] = list[j];
					list[j] = temp;
				}
			}
		}

#else
		// 版本2：while+一层for循环
		bool swapped = false;
		while (!swapped)
		{
			swapped = true;
	
			for (int i = 0; i < length - 1; ++i)
			{
				// 两两相邻元素比较大小，从小到大排序
				// if (list[j] < list[j + 1]) : 从大到小排序
				if (list[i] > list[i + 1])
				{
					int temp = list[i + 1];
					list[i + 1] = list[i];
					list[i] = temp;
				}
				swapped = false;
			}
			length--;
		}
			
#endif

	}
}

using namespace std;
using namespace alg;


int main()
{
	int a[8] = { 5, 2, 5, 7, 1, -3, 99, 56 };
	BubbleSort<int>(a, 8);
	for (auto e : a)
		std::cout << e << " ";

	return 0;
}