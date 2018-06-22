/*****************************************
Copyright: Amusi
Author:    Amusi
Date:      2018-06-20

��Ŀ����
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���


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
    /* ����1�����淨
    double PowerUnsigned(double base, int exponent){
        double pow = 1;
        for(int i=1;i<=exponent;++i){
            pow *= base;
        }
        return pow;
    }
    }*/
    /*����2���ݹ鷨*/
    double PowerUnsigned(double base, int exponent){
        // �ݹ���ֵ����
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        double pow = PowerUnsigned(base, exponent>>1);    // >>1 ���Ʊ�ʾ����2
        pow *=pow;
        if(exponent & 0x1==1)    // �жϻ�ż��
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