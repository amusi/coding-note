/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-09-06


题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

*****************************************/

class Temp{
public:
    Temp(){++N; Sum+=N;}
    static void Reset() {N=0;Sum=0;}
    static int GetSum() {return Sum;}
private:
    static int N;
    static int Sum;
    
};

// 类外初始化Temp类中的私有变量
int Temp::N = 0;
int Temp::Sum = 0;

class Solution {
public:
    
    int Sum_Solution(int n) {
        // way1: 利用二维数组实现乘法
        //bool a[n][n+1];
        //return sizeof(a)>>1;
        
        // way2: 构造函数求解法
        Temp::Reset();
        Temp *a = new Temp[n];    // 循环调用构造函数n次，实现1+2+...+n
        delete []a;
        a = NULL;
        return Temp::GetSum();
    }
};