//
//  LeetCode_9_IsPalindrome.cpp
//  arithmetic
//
//  Created by li on 2018/8/9.
//  Copyright © 2018年 li. All rights reserved.
//
//9. 回文数
//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//示例 1:
//
//输入: 121
//输出: true
//示例 2:
//
//输入: -121
//输出: false
//解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
//示例 3:
//
//输入: 10
//输出: false
//解释: 从右向左读, 为 01 。因此它不是一个回文数。
//进阶:
//
//你能不将整数转为字符串来解决这个问题吗？
//解题思路：
//1.找到最左和最右边的数字，判定他们是否相等；
//2.然后排出最左最右的数，得到新数。继续第一步，直到这个新数为0；
//    1221
//     22



#include "LeetCode_9_IsPalindrome.hpp"

int LeetCode_9_IsPalindrom::main(int argc, const char **argv){
   
    LeetCode_9_IsPalindrom leetCode_9_IsPalindrom;
    cout << leetCode_9_IsPalindrom.isPalindrome(1221) << endl;
    
    return 0;
}

bool LeetCode_9_IsPalindrom::isPalindrome(int x){
    
    if(x < 0) return false;
    int div = 1; //这个数的最高位
    while(x / div >=10) div *= 10; //获得最高位数
    while(x > 0){
        int left = x / div; //最左值
        int right = x % 10; //最右值
        if(left != right) return false; //不等返回
        x = (x % div) / 10; //排出最左最右
        div /= 100; //剪掉2位
    }
    return true;
}



