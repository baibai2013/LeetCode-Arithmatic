//
//  LeetCode_8_StringToInteger.cpp
//  arithmetic
//
//  Created by li on 2018/7/2.
//  Copyright © 2018年 li. All rights reserved.
// 8. 字符串转整数 (atoi)
//
//
//在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，
//并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
//
//字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
//
//当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
//
//若函数不能执行有效的转换，返回 0。
//示例 1:
//
//输入: "42"
//输出: 42
//
//示例 2:
//
//输入: "   -42"
//输出: -42
//解释: 第一个非空白字符为 '-', 它是一个负号。
//我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

//示例 3:
//
//输入: "4193 with words"
//输出: 4193
//解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
//示例 4:
//
//输入: "words and 987"
//输出: 0
//解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
//因此无法执行有效的转换。
//
//示例 5:
//
//输入: "-91283472332"
//输出: -2147483648
//解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
//因此返回 INT_MIN (−2^31) 。
//

#include "LeetCode_8_StringToInteger.hpp"
int LeetCode_8_StringToInteger::myAtoi(string str){
    if(str.empty()) return 0;
    int sign = 1, base = 0, i = 0, n = str.size();
    while (i < n && str[i] == ' ') {++i;}
    if(str[i] == '+' || str[i] == '-'){//判断正负
        sign = (str[i++] == '+') ? 1:-1;
    }
    //构建数字和排除超出int 范围[-2^31,2^31-1]
    while (i < n && str[i] >= '0' && str[i] <= '9') {
        if(base > INT_MAX / 10  || (base == INT_MAX / 10 && str[i] - '0' > 7)){
            return (sign == 1)? INT_MAX : INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}
int LeetCode_8_StringToInteger::main(int argc, const char * argv[]){
    
    LeetCode_8_StringToInteger leetCode_8_StringToInteger;
//    int atoi = leetCode_8_StringToInteger.myAtoi("42");
//    int atoi = leetCode_8_StringToInteger.myAtoi("   -42");
//    int atoi = leetCode_8_StringToInteger.myAtoi("4193 with words");
    int atoi = leetCode_8_StringToInteger.myAtoi("-91283472332");
    cout<<"atoi:"<<atoi<<endl;

    return 0;
}
