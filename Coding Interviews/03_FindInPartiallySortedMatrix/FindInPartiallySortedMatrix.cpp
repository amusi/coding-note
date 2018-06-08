/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-06-08

题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

输入: 二维数组和待查询的整数
输出: 待查询整数是否在二维数组(True, False)


思路:
	二维数组matrix, 二维数组行数: rows，二维数组列数: cols, 待查询数值num
	1.先将二维数组转换成一维数组进行处理
	2.定义判断初始值为左下角元素matrix[row][col]，其中row=rows-1, col=0
	3.将二维数组的左下角元素matrix[row][col]（或者右上角元素）值与带查询num进行比较，
	  如果matrix[row][col] > num，则--row；如果matrix[row][col] < num，则++col。
	4.重复第3步，直到遍历完所有可以遍历的数组元素。


TODO:
	版本1: 仍需要人为输入二维数组的行和列，太不智能化

*****************************************/


// 版本1: char[][]二维数组（手动输入示例）

#include <iostream>

// 定义一个 4*4 的二维数组
const int matrix_cols = 4;
int matrix[][matrix_cols] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, {6, 8, 11, 15} };

bool judge_inter_in_array(int search_num, int *matrix, const int matrix_cols, const int matrix_rows);

int main()
{
	int search_num = 9;

	// 二维数组转换成一维数组处理
	const int matrix_eles = sizeof(matrix) / sizeof(matrix[0][0]);
	const int matrix_rows = matrix_eles / matrix_cols;

	judge_inter_in_array(search_num, (int*)matrix, matrix_cols, matrix_rows);
	
	
	return 0;
}

/**********************************
功能: 判断输入整数是否在数组中
输入: 待查询数字, 二维数组, 数组的列数, 数组的行数
输出: 

***********************************/
bool judge_inter_in_array(int search_num, int *matrix, const int matrix_cols, const int matrix_rows)
{

	bool found = false;
	int row = matrix_rows - 1;
	int col = 0;

	if (matrix!=NULL && matrix_cols > 0 && matrix_rows > 0)
	{
		

		// 限定搜索范围
		while (col < matrix_cols && row >= 0)
		{
			if (matrix[row*matrix_cols + col] == search_num)
			{
				found = true;
				break;
			}
			else if (matrix[row*matrix_cols + col] < search_num)
				++col;
			else
				--row;
		}
	}
	
	if (found == true)
	{
		std::cout << "True" << std::endl;
		// add: 添加元素位置索引的输出语句
		std::cout << search_num << " 位于 "<< row+1 << " 行，第"<< col+1 <<" 列" <<std::endl;
	}
	else
		std::cout << "False" << std::endl;

	return found;
}

// 版本二: vector二维数组（牛客网，系统输入示例）

//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		int matrix_rows = array.size();        // 二维数组行数
//		int matrix_cols = array[0].size();     // 二维数组列数
//		int row = matrix_rows - 1;
//		int col = 0;
//		// 判断输入的二维数组是否符合要求
//		if (matrix_rows == 0 && matrix_cols == 0)
//			return false;
//		// 循环
//		while (row >= 0 && col < matrix_cols)
//		{    // 比较当前元素和待查询元素大小
//			if (target < array[row][col])
//			{
//				--row;    // 减行
//			}
//			else if (target > array[row][col])
//			{
//				++col;    // 加列
//			}
//			else
//				return true;
//		}
//		return false;
//	}
//};