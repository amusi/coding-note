/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-06-20

题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。


*****************************************/

class Solution {
public:
    double Power(double base, int exponent) {
        int baseSmallFlag = false;
        baseSmallFlag = JudgeSmallNumber(base);
        double pow = 0;
        if(baseSmallFlag && exponent==0)
            return 0;
        if(exponent==0){
            return 1;
        }
        if(exponent > 0){
            pow = PowerUnsigned(base, exponent);
        }
        else{
            exponent = -exponent;
            pow = 1/PowerUnsigned(base, exponent);
        }
        return pow;
    }
    /* 方法1：常规法
    double PowerUnsigned(double base, int exponent){
        double pow = 1;
        for(int i=1;i<=exponent;++i){
            pow *= base;
        }
        return pow;
    }
    }*/
    /*方法2：递归法*/
    double PowerUnsigned(double base, int exponent){
        // 递归中值条件
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        double pow = PowerUnsigned(base, exponent>>1);    // >>1 右移表示除以2
        pow *=pow;
        if(exponent & 0x1==1)    // 判断基偶数
            pow *= base;
        return pow;
    }
  
    bool JudgeSmallNumber(double base){
        if(abs(base - 0.0)< 0.0000001)
            return true;
        else
            return false;
    }
};