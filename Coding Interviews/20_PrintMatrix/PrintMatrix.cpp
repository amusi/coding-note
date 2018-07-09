/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-07-09


题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

*****************************************/

class Solution {
public:
    // 思路: 
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size()==0)
            return matrix[0];
        vector<vector<int>> resultMatrixTemp;
        
        int rows = matrix.size();        // 矩阵行数
        int columns = matrix[0].size();  // 矩阵列数
        // 设置起始位置
        int start = 0;    // start = start_x = start_y
        //resultMatrix.resize(rows*columns);
        // 根据关系式判断
        while(columns > 2*start && rows > 2*start){
            resultMatrixTemp.push_back(printMatrixInCircle(matrix, start));
            ++start;
        }
        vector<int> resultMatrix;    // 最终输出值
        for(int i=0; i<resultMatrixTemp.size(); ++i){
            for(int j=0; j<resultMatrixTemp[i].size(); ++j){
                resultMatrix.push_back(resultMatrixTemp[i][j]);
            }
        }
        return resultMatrix;
    }
    
    vector<int> printMatrixInCircle(vector<vector<int> >matrix, int start){
        if (matrix.size()==0)
            return matrix[0];
        vector<int> resultMatrix;
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        int endX = columns-1-start;
        int endY = rows-1-start;
        // 从左到右打印一行
        for(int i=start; i<=endX; ++i){
            int number = matrix[start][i];
            resultMatrix.push_back(number);
        }
        // 从上到下打印一列
        if(start < endY){
            for(int i=start+1; i<=endY; ++i){
                int number = matrix[i][endX];
                resultMatrix.push_back(number);
            }
        }
         // 从右到左打印一列
        if(start < endX && start < endY){
            for(int i=endX-1; i>=start; i--){
                int number = matrix[endY][i];
                resultMatrix.push_back(number);
            }
        }
         // 从下到上打印一列
        if(start < endX && start < endY-1){
            for(int i=endY-1; i>=start+1; i--){
                int number = matrix[i][start];
                resultMatrix.push_back(number);
            }
        }
        return resultMatrix;
    }
};