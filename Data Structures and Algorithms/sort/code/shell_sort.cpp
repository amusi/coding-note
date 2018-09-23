/* Summary: 希尔排序（Shell Sort）
* Author: Amusi
* Date:   2018-09-23
*
* Reference:
*   https://en.wikipedia.org/wiki/Shellsort
*   https://www.geeksforgeeks.org/shellsort/
*   希尔排序（shell sort）：设待排序元素序列有n个元素，首先取一个整数increment（小于n）作为间隔将全部元素分为increment个子序列，所有距离为increment的元素放在同一个子序列中，在每一个子序列中分别实行直接插入。
*
*/

#include <iostream>

// 希尔排序函数（基于快速插入排序）
namespace alg{
	template<typename T>
	static void ShellSort(T list[], int n)
	{
		// 设置增量：以n/2为初始gap，然后逐渐减小gap（每次缩小为上次gap的一半）
		for (int gap = n / 2; gap > 0; gap /= 2){
			// 遍历当前趟，对每个子序列进行插入排序
			for (int i = gap; i < n; i++){
				int temp = list[i];
				int j = 0;
				// 遍历子序列
				for (j = i; j >= gap && list[j - gap]>temp; j -= gap)
					list[j] = list[j - gap];

				list[j] = temp;
			}
		}
	}
}

using namespace std;
using namespace alg;


int main()
{
	int a[8] = { 5, 2, 5, 7, 1, -3, 99, 56 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort<int>(a, n);
	for (auto e : a)
		std::cout << e << " ";

	return 0;
}