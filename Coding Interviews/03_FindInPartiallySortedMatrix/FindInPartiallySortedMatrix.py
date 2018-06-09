'''
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

'''

'''
版本1
'''
def judge_inter_in_array(matrix, rows, cols, search_num):
	''' 判断数组中是否含有该整数'''
	row = rows-1
	col = 0
	
	if rows==0 or cols==0:
		return False
	
	while rows>=0 and col<cols:
		if matrix[row][col] > search_num:
			row = row-1
		elif matrix[row][col] < search_num:
			col = col+1
		else:
			return True
			
	return False

'''
版本2
'''
# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        # 计算数组的行列
        rows = len(array)    # 计算行数
        cols = len(array[0]) # 计算列数
        
        if rows<=0 or cols<=0:
            return False
        
        row = rows-1
        col = 0
        
        while row >=0 and col <cols:
            if array[row][col] < target:
                col = col+1
            elif array[row][col] > target:
                row = row-1
            else:
                return True
				
        return False
	
	
if __name__ == '__main__':
	matrix = [
		[1, 2, 8, 9],
		[2, 4, 9, 12],
		[4, 7, 10, 13],
		[6, 8, 11, 15]
	]
	
	# 版本1
	print(judge_inter_in_array(matrix, 4, 4, 11))
	
	ss = Solution()
	print(ss.Find(11, matrix))
	
	

