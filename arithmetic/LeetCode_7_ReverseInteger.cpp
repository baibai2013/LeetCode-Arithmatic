//
//  LeetCode_7_ReverseInteger.cpp
//  arithmetic
//
//  Created by li on 2018/5/24.
//  Copyright © 2018年 li. All rights reserved.
//
//原题
//
//　　Reverse digits of an integer.
//　　Example1: x = 123, return 321
//　　Example2: x = -123, return -321
//
//题目大意
//
//　　输入一个整数对其进行翻转
//
//解题思路
//
//　　通过求余数求商法进行操作。
//
//代码实现


#include "LeetCode_7_ReverseInteger.hpp"


int LeetCode_7_ReverseInteger::main(int argc, const char *argv[]) { 
    
    int res = LeetCode_7_ReverseInteger().reverse(123);
    cout<<"result:"<<res<<"int max :"<<INT_MAX<<endl;
    return 0;
}


int LeetCode_7_ReverseInteger::reverse(int x) { 
    
    int res =0;
    while ( x != 0) {
        if(abs(res) > INT_MAX / 10) return 0; //整数溢出返回0
        res = res * 10 + x % 10; //本次结果 = 上一次结果进位+小于10的余数
        x /= 10; //数据源进位
    }
    return res;
}
